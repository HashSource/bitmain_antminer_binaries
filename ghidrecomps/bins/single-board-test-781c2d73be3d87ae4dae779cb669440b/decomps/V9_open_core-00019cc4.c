
/* WARNING: Unknown calling convention */

void V9_open_core(uchar which_chain)

{
  uchar *puVar1;
  uchar *puVar2;
  int iVar3;
  uchar data [64];
  
  memset(data,0,0x40);
  data[0] = 0xff;
  printf("\n--- %s: Chain : %d\n",DAT_00019d98,(uint)which_chain);
  gIsOpenCoreEnd = false;
  gIsOpeningCore = true;
  memset(data,0,0x40);
  iVar3 = 0x32;
  BM1385_set_gateblk(which_chain,'\0',true);
  do {
    uart_send(which_chain,data,0x40);
    usleep(Conf.OpenCoreGap);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  memset(data,0,0x40);
  puVar1 = data;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = (char)puVar1 - (char)data;
    puVar1 = puVar2;
  } while (puVar2 != data + 0x34);
  iVar3 = 0x3c;
  data[52] = 0xff;
  BM1385_set_gateblk(which_chain,'\0',true);
  do {
    uart_send(which_chain,data,0x40);
    usleep(Conf.OpenCoreGap);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  clear_uart_rx_fifo(which_chain);
  gIsOpeningCore = false;
  gIsOpenCoreEnd = true;
  return;
}

