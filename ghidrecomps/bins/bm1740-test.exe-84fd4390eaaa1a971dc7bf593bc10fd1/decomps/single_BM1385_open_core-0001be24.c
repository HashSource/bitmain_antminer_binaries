
void single_BM1385_open_core(byte param_1)

{
  undefined local_74 [52];
  undefined local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  memset(local_74,0,0x40);
  local_74[0] = 0xff;
  local_10 = Conf._204_4_;
  local_14 = Conf._208_4_;
  local_30 = Conf._212_4_;
  local_34 = Conf._216_4_;
  printf("\n--- %s: Chain : %d\n","single_BM1385_open_core",(uint)param_1);
  gIsOpenCoreEnd = 0;
  memset(local_74,0,0x40);
  BM1385_set_gateblk(param_1,0,1);
  for (local_c = 0; local_c < 0x32; local_c = local_c + 1) {
    uart_send(param_1,local_74,0x40);
    usleep(Conf._192_4_);
  }
  memset(local_74,0,0x40);
  BM1385_set_gateblk(param_1,0,1);
  for (local_c = 0; local_c < 0x32; local_c = local_c + 1) {
    if (local_c < 0x20) {
      if ((local_10 & 1) != 0) {
        local_40 = 0xff;
      }
      local_10 = local_10 >> 1;
    }
    else if ((local_c < 0x40) && (0x1f < local_c)) {
      if ((local_14 & 1) != 0) {
        local_40 = 0xff;
      }
      local_14 = local_14 >> 1;
    }
    else {
      printf("%s: which_core = %d, error!!!\n","single_BM1385_open_core",local_c);
    }
    uart_send(param_1,local_74,0x40);
    usleep(Conf._192_4_);
  }
  gIsOpenCoreEnd = 1;
  return;
}

