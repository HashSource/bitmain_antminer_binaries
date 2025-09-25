
void bn_to_mont_fixed_top(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  bn_mul_mont_fixed_top(param_1,param_2,param_3 + 4,param_3,param_4);
  return;
}

