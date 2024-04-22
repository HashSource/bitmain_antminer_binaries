
void get_benchfile_work(int param_1)

{
  undefined4 *puVar1;
  
  benchfile_get_work();
  puVar1 = pools;
  *(undefined *)(param_1 + 0x11a) = 1;
  *(undefined4 *)(param_1 + 0x104) = *puVar1;
  cgtime(param_1 + 400);
  copy_time(param_1 + 0x198,param_1 + 400);
  *(undefined *)(param_1 + 0x1b8) = 0x42;
  calc_diff((int)DAT_0001e3c0,param_1);
  return;
}

