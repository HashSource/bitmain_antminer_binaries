
int gf_hibit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_60 [20];
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  gf_add(local_60,param_1,param_1);
  gf_strong_reduce(local_60);
  return (local_60[0] << 0x1f) >> 0x1f;
}

