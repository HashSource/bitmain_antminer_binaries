
void get_benchmark_work(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = DAT_0001bc04;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0x40400000;
  _cg_memcpy(param_1 + 0xa0,DAT_0001bc08,0x20,"cgminer.c",uVar1,0x105c);
  puVar2 = pools;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined *)(param_1 + 0x11a) = 1;
  *(undefined4 *)(param_1 + 0x104) = *puVar2;
  cgtime(param_1 + 400);
  copy_time(param_1 + 0x198,param_1 + 400);
  *(undefined *)(param_1 + 0x1b8) = 0x42;
  return;
}

