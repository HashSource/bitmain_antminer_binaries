
void i2c_send(byte param_1,undefined1 param_2,char param_3,undefined1 param_4,undefined1 param_5)

{
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  uint local_18;
  undefined4 local_14;
  
  local_14._3_1_ = (undefined1)((uint)g_general_i2c_command >> 0x18);
  local_14 = CONCAT31(CONCAT21(CONCAT11(local_14._3_1_,param_3 << 1),param_4),param_5) | 0x10000;
  local_1b = 0;
  local_1a = 0x20;
  local_18 = local_14;
  local_1c = param_2;
  midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x20),1,&local_1c);
  return;
}

