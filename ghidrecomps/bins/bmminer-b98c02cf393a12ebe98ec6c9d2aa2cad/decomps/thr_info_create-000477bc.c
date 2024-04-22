
void thr_info_create(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _cgsem_init(param_1 + 0x10,"util.c",DAT_000477f0,0x4a7);
  (*(code *)PTR_pthread_create_0007cf18)(param_1 + 0xc,param_2,param_3,param_4);
  return;
}

