
/* WARNING: Unknown calling convention */

int32_t uart_send(uint32_t chain_id,void *data,uint32_t size)

{
  int32_t iVar1;
  uint32_t val;
  char *__format;
  int iVar2;
  byte *pbVar3;
  uint send_data_len;
  pthread_mutex_t *__mutex;
  uint uVar4;
  uint uVar5;
  uint chain_send_fifo_status_addr;
  uint chain_send_ready_addr;
  uint chain_send_buffer_addr;
  uint max_fpga_can_send_uart_data_len;
  uint bit_shift_num;
  uchar send_buf [256];
  char tmp42 [2048];
  
  memset(send_buf,0,0x100);
  __mutex = (pthread_mutex_t *)(uart_send_mutex + chain_id);
  chain_send_fifo_status_addr = 0;
  chain_send_ready_addr = 0;
  chain_send_buffer_addr = 0;
  max_fpga_can_send_uart_data_len = 0;
  bit_shift_num = 0;
  pthread_mutex_lock(__mutex);
  iVar1 = get_send_address_info
                    (chain_id,&bit_shift_num,&chain_send_fifo_status_addr,&chain_send_ready_addr,
                     &chain_send_buffer_addr);
  if (iVar1 != 0) {
    snprintf(tmp42,0x800,"get_send_address_info error, chain_id = %d\n",chain_id);
    _applog(0,tmp42,false);
    pthread_mutex_unlock(__mutex);
    return 0;
  }
  iVar2 = 0x15;
  do {
    fpga_read(chain_send_fifo_status_addr,&max_fpga_can_send_uart_data_len);
    max_fpga_can_send_uart_data_len =
         max_fpga_can_send_uart_data_len >> (bit_shift_num & 0xff) & 0xff;
    if (size <= max_fpga_can_send_uart_data_len) {
      iVar2 = 0x16;
      do {
        fpga_read(chain_send_ready_addr,&max_fpga_can_send_uart_data_len);
        if (-1 < (int)max_fpga_can_send_uart_data_len) {
          memcpy(send_buf,data,size);
          uVar4 = size >> 2;
          if (uVar4 != 0) {
            uVar5 = 0;
            pbVar3 = send_buf;
            do {
              uVar5 = uVar5 + 1;
              fpga_write(chain_send_buffer_addr,
                         (uint)pbVar3[1] << 0x10 | (uint)*pbVar3 << 0x18 | (uint)pbVar3[3] |
                         (uint)pbVar3[2] << 8);
              pbVar3 = pbVar3 + 4;
            } while (uVar4 != uVar5);
          }
          uVar5 = size & 3;
          if (uVar5 != 0) {
            if (uVar5 == 2) {
              val = (uint)send_buf[uVar4 * 4] << 0x18 | (uint)send_buf[uVar4 * 4 + 1] << 0x10;
            }
            else if (uVar5 == 3) {
              val = (uint)send_buf[uVar4 * 4 + 2] << 8 | (uint)send_buf[uVar4 * 4 + 1] << 0x10 |
                    (uint)send_buf[uVar4 * 4] << 0x18;
            }
            else {
              val = (uint)send_buf[uVar4 * 4] << 0x18;
            }
            fpga_write(chain_send_buffer_addr,val);
          }
          fpga_write(chain_send_ready_addr,size | 0x80000000);
          pthread_mutex_unlock(__mutex);
          return size;
        }
        usleep(3000);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      pthread_mutex_unlock(__mutex);
      __format = "%s: uart%d always busy, break\n";
      goto LAB_000c0b9e;
    }
    usleep(3000);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pthread_mutex_unlock(__mutex);
  __format = "%s: uart%d always dose not has enough send fifo space, break\n";
LAB_000c0b9e:
  snprintf(tmp42,0x800,__format,"uart_send",chain_id);
  _applog(0,tmp42,false);
  return 0;
}

