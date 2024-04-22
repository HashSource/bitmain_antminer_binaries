
/* WARNING: Unknown calling convention */

uint clear_uart_send_fifo(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  uint chain_send_ready_addr;
  uint chain_send_buffer_addr;
  int iVar3;
  uint address;
  int iVar4;
  pthread_mutex_t *__mutex;
  
  uVar1 = (uint)which_chain;
  __mutex = (pthread_mutex_t *)(uart_send_mutex + uVar1);
  pthread_mutex_lock(__mutex);
  switch(uVar1) {
  case 0:
    iVar4 = 0x18;
    chain_send_buffer_addr = 0x65;
    chain_send_ready_addr = 100;
    address = 0x60;
    break;
  case 1:
    iVar4 = 0x10;
    chain_send_buffer_addr = 0x67;
    chain_send_ready_addr = 0x66;
    address = 0x60;
    break;
  case 2:
    iVar4 = 8;
    chain_send_buffer_addr = 0x69;
    chain_send_ready_addr = 0x68;
    address = 0x60;
    break;
  case 3:
    iVar4 = 0;
    chain_send_buffer_addr = 0x6b;
    chain_send_ready_addr = 0x6a;
    address = 0x60;
    break;
  case 4:
    iVar4 = 0x18;
    chain_send_buffer_addr = 0x6d;
    chain_send_ready_addr = 0x6c;
    address = 0x61;
    break;
  case 5:
    iVar4 = 0x10;
    chain_send_buffer_addr = 0x6f;
    chain_send_ready_addr = 0x6e;
    address = 0x61;
    break;
  case 6:
    iVar4 = 8;
    chain_send_buffer_addr = 0x71;
    chain_send_ready_addr = 0x70;
    address = 0x61;
    break;
  case 7:
    iVar4 = 0;
    chain_send_buffer_addr = 0x73;
    chain_send_ready_addr = 0x72;
    address = 0x61;
    break;
  case 8:
    iVar4 = 0x18;
    chain_send_buffer_addr = 0x75;
    chain_send_ready_addr = 0x74;
    address = 0x62;
    break;
  case 9:
    iVar4 = 0x10;
    chain_send_buffer_addr = 0x77;
    chain_send_ready_addr = 0x76;
    address = 0x62;
    break;
  default:
    printf("%s: The uart%d is not supported!!!\n",DAT_00016228,uVar1);
    pthread_mutex_unlock(__mutex);
    return 1;
  }
  iVar3 = 0x15;
  printf("--- %s: chain_send_ready_addr %d, chain_send_buffer_addr %d\n",DAT_00016228,
         chain_send_ready_addr,chain_send_buffer_addr);
  do {
    uVar2 = read_axi_fpga(address);
    uVar2 = uVar2 >> iVar4 & 0xff;
    if (uVar2 == 0xff) {
      pthread_mutex_unlock(__mutex);
      return 0;
    }
    printf("%s: waiting fpga uart%d clear send fifo space ...\n",DAT_00016228,uVar1);
    usleep(3000);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  printf("%s: uart%d always dose not has enough send fifo space, break\n",DAT_00016228,uVar1);
  pthread_mutex_unlock(__mutex);
  return uVar2;
}

