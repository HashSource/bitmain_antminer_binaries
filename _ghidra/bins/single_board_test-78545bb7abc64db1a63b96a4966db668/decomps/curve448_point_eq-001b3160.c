
void curve448_point_eq(int param_1,int param_2)

{
  undefined1 auStack_a0 [64];
  undefined1 auStack_60 [72];
  
  gf_mul(auStack_60,param_1 + 0x40,param_2);
  gf_mul(auStack_a0,param_2 + 0x40,param_1);
  gf_eq(auStack_60,auStack_a0);
  return;
}

