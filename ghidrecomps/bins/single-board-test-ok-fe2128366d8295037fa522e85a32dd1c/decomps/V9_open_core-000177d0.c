
void V9_open_core(byte param_1)

{
  undefined local_5c [52];
  undefined local_28;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_14 = 0;
  local_18 = 0;
  local_10 = 0;
  local_1c = 0;
  memset(local_5c,0,0x40);
  local_5c[0] = 0xff;
  printf("\n--- %s: Chain : %d\n","V9_open_core",(uint)param_1);
  gIsOpenCoreEnd = 0;
  gIsOpeningCore = 1;
  memset(local_5c,0,0x40);
  BM1385_set_gateblk(param_1,0,1);
  for (local_c = 0; local_c < 0x32; local_c = local_c + 1) {
    uart_send(param_1,local_5c,0x40);
    usleep(Conf._192_4_);
  }
  memset(local_5c,0,0x40);
  for (local_10 = 0; local_10 < 0x34; local_10 = local_10 + 1) {
    local_5c[local_10] = (char)local_10;
  }
  local_28 = 0xff;
  BM1385_set_gateblk(param_1,0,1);
  for (local_c = 0; local_c < 0x3c; local_c = local_c + 1) {
    uart_send(param_1,local_5c,0x40);
    usleep(Conf._192_4_);
  }
  clear_uart_rx_fifo(param_1);
  gIsOpeningCore = 0;
  gIsOpenCoreEnd = 1;
  return;
}

