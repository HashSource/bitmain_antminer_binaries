
void i2c_send(byte param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5)

{
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  
  local_f = 0;
  local_c = param_5;
  local_10 = param_2;
  local_e = param_3;
  local_d = param_4;
  midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x28),8,&local_10);
  return;
}

