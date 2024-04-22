
undefined4
i2c_recv(byte param_1,undefined param_2,char param_3,undefined param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint local_28;
  byte local_24;
  undefined local_23;
  undefined local_22;
  undefined4 local_20;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  uint local_14;
  
  iVar1 = i2c_status(param_1,param_2);
  if (iVar1 == 0) {
    local_28._0_2_ = CONCAT11(param_4,(char)g_general_i2c_command);
    local_28 = CONCAT22(CONCAT11((char)((uint)g_general_i2c_command >> 0x18),param_3 << 1),
                        (undefined2)local_28) | 0x1000000;
    local_17 = 0;
    local_16 = 0x20;
    local_14 = local_28;
    local_18 = param_2;
    midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x20),1,&local_18);
    usleep(200000);
    iVar1 = i2c_status(param_1,param_2);
    if (iVar1 == 0) {
      local_17 = 0;
      local_16 = 0x20;
      local_18 = param_2;
      midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x20),0,&local_18);
      local_22 = 0x20;
      local_24 = param_1;
      local_23 = param_2;
      iVar1 = read_reg_item(&local_24,500);
      if (iVar1 < 1) {
        uVar2 = 0xffffffff;
      }
      else {
        *param_5 = local_20;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

