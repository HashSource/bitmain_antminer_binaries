
void write_register_2(int param_1,undefined param_2,undefined param_3,undefined param_4,
                     undefined4 param_5)

{
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined4 local_c;
  
  local_c = param_5;
  local_10 = param_3;
  local_f = param_2;
  local_e = param_4;
  midd_ioctl(*(undefined4 *)(g_chain + param_1 * 0x20),1,&local_10);
  return;
}

