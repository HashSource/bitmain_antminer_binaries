
/* WARNING: Unknown calling convention */

uint uart_send(uchar which_uart,uchar *buf,uint length)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint address;
  uint send_data_len;
  uint uVar5;
  uint uVar6;
  pthread_mutex_t *__mutex;
  uint address_00;
  uchar send_buf [512];
  
  uVar6 = (uint)which_uart;
  memset(send_buf,0,0x200);
  __mutex = (pthread_mutex_t *)(uart_send_mutex + uVar6);
  pthread_mutex_lock(__mutex);
  switch(uVar6) {
  case 0:
    iVar3 = 0x18;
    address = 0x65;
    address_00 = 100;
    uVar5 = 0x60;
    break;
  case 1:
    iVar3 = 0x10;
    address = 0x67;
    address_00 = 0x66;
    uVar5 = 0x60;
    break;
  case 2:
    iVar3 = 8;
    address = 0x69;
    address_00 = 0x68;
    uVar5 = 0x60;
    break;
  case 3:
    iVar3 = 0;
    address = 0x6b;
    address_00 = 0x6a;
    uVar5 = 0x60;
    break;
  case 4:
    iVar3 = 0x18;
    address = 0x6d;
    address_00 = 0x6c;
    uVar5 = 0x61;
    break;
  case 5:
    iVar3 = 0x10;
    address = 0x6f;
    address_00 = 0x6e;
    uVar5 = 0x61;
    break;
  case 6:
    iVar3 = 8;
    address = 0x71;
    address_00 = 0x70;
    uVar5 = 0x61;
    break;
  case 7:
    iVar3 = 0;
    address = 0x73;
    address_00 = 0x72;
    uVar5 = 0x61;
    break;
  case 8:
    iVar3 = 0x18;
    address = 0x75;
    address_00 = 0x74;
    uVar5 = 0x62;
    break;
  case 9:
    iVar3 = 0x10;
    address = 0x77;
    address_00 = 0x76;
    uVar5 = 0x62;
    break;
  default:
    printf("%s: The uart is not supported!!!\n",DAT_00016054);
    return 0;
  }
  iVar2 = 0x15;
  do {
    uVar1 = read_axi_fpga(uVar5);
    if (length <= (uVar1 >> iVar3 & 0xff)) {
      iVar3 = 0x16;
      while( true ) {
        uVar5 = read_axi_fpga(address_00);
        if (-1 < (int)uVar5) {
          memcpy(send_buf,buf,length);
          if (length >> 2 != 0) {
            uVar6 = 0;
            pbVar4 = send_buf;
            do {
              uVar6 = uVar6 + 1;
              write_axi_fpga(address,(uint)pbVar4[1] << 0x10 | (uint)*pbVar4 << 0x18 |
                                     (uint)pbVar4[3] | (uint)pbVar4[2] << 8);
              pbVar4 = pbVar4 + 4;
            } while (length >> 2 != uVar6);
          }
          uVar6 = length & 3;
          if (uVar6 != 0) {
            if (uVar6 == 2) {
              uVar6 = (uint)send_buf[length & 0xfffffffc] << 0x18 |
                      (uint)send_buf[(length & 0xfffffffc) + 1] << 0x10;
            }
            else if (uVar6 == 3) {
              uVar6 = (uint)send_buf[(length & 0xfffffffc) + 2] << 8 |
                      (uint)send_buf[(length & 0xfffffffc) + 1] << 0x10 |
                      (uint)send_buf[length & 0xfffffffc] << 0x18;
            }
            else {
              uVar6 = (uint)send_buf[length & 0xfffffffc] << 0x18;
            }
            write_axi_fpga(address,uVar6);
          }
          write_axi_fpga(address_00,length | 0x80000000);
          pthread_mutex_unlock(__mutex);
          return length;
        }
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) break;
        usleep(3000);
      }
      pthread_mutex_unlock(__mutex);
      printf("%s: uart%d always busy, break\n",DAT_00016054,uVar6);
      return 0;
    }
    usleep(3000);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pthread_mutex_unlock(__mutex);
  printf("%s: uart%d always dose not has enough send fifo space, break\n",DAT_00016054,uVar6);
  return 0;
}

