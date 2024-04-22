
/* WARNING: Unknown calling convention */

uint clear_uart_rx_fifo(uchar which_chain)

{
  int iVar1;
  uint uVar2;
  uint __size;
  uchar *buf;
  uint uVar3;
  pthread_mutex_t *__mutex;
  
  iVar1 = DAT_000162d4;
  uVar2 = (uint)which_chain;
  printf("--- %s\n",DAT_000162d8);
  __mutex = (pthread_mutex_t *)(iVar1 + uVar2 * 0x18);
  pthread_mutex_lock(__mutex);
  __size = check_how_many_uart_data_in_fpga(which_chain);
  if (__size != 0) {
    buf = (uchar *)malloc(__size);
    if (buf == (uchar *)0x0) {
      printf("%s: uart%d malloc buffer error\n",DAT_000162d8,uVar2);
      usleep(500000);
      pthread_mutex_unlock(__mutex);
    }
    else {
      uVar3 = read_uart_data_in_fpga(which_chain,buf,__size);
      if (__size != uVar3) {
        printf("%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n",DAT_000162d8,uVar2,__size,
               uVar3);
      }
      free(buf);
      usleep(10000);
      pthread_mutex_unlock(__mutex);
    }
    return 1;
  }
  pthread_mutex_unlock(__mutex);
  return 0;
}

