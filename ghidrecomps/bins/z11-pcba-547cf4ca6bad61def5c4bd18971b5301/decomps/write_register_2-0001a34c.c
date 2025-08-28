
void write_register_2(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                     undefined4 param_5)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined4 local_c;
  
  local_c = param_5;
  local_10 = param_3;
  local_f = param_2;
  local_e = param_4;
  midd_ioctl(*(undefined4 *)(g_chain + param_1 * 0x20),1,&local_10);
  return;
}

