
/* WARNING: Unknown calling convention */

uint uart_receive(uchar which_uart,uchar *buf,uint buf_length)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  pthread_mutex_t *__mutex;
  
  __mutex = (pthread_mutex_t *)(DAT_000160e4 + (uint)which_uart * 0x18);
  pthread_mutex_lock(__mutex);
  if (Conf.AsicType == 0x569) {
    uVar2 = check_how_many_uart_data_in_fpga(which_uart);
    uVar1 = 5;
    if (buf_length < uVar2) goto LAB_000160aa;
  }
  else {
    uVar1 = check_how_many_uart_data_in_fpga(which_uart);
    if (uVar1 <= buf_length) {
      uVar1 = 0;
      goto LAB_00016092;
    }
    uVar1 = 0;
LAB_000160aa:
    printf("%s: nbytes > buf_length\n",DAT_000160e8);
    uVar2 = buf_length;
  }
  if (uVar2 < uVar1) {
    pthread_mutex_unlock(__mutex);
    return 0;
  }
  iVar3 = __udivsi3(uVar2,uVar1);
  uVar1 = uVar1 * iVar3;
LAB_00016092:
  uVar1 = read_uart_data_in_fpga(which_uart,buf,uVar1);
  pthread_mutex_unlock(__mutex);
  return uVar1;
}

