
void get_benchmark_work(int param_1)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0x40400000;
  _cg_memcpy(param_1 + 0xa0,bench_target,0x20,"cgminer.c","get_benchmark_work",0x105c);
  puVar1 = pools;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined1 *)(param_1 + 0x11a) = 1;
  *(undefined4 *)(param_1 + 0x104) = *puVar1;
  cgtime(param_1 + 400);
  copy_time(param_1 + 0x198,param_1 + 400);
  *(undefined1 *)(param_1 + 0x1b8) = 0x42;
  return;
}

