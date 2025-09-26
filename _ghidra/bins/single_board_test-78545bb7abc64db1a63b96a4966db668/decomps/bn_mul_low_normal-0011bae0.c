
void bn_mul_low_normal(ulong *param_1,ulong *param_2,ulong *param_3,uint param_4)

{
  ulong *puVar1;
  int num;
  uint num_00;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  num_00 = param_4 - 1;
  bn_mul_words(param_1,param_2,param_4,*param_3);
  if (0 < (int)num_00) {
    param_3 = param_3 + 0xd;
    uVar3 = num_00 - (param_4 + 1 & 0xfffffffc);
    uVar2 = num_00 - (param_4 & 0xfffffffc);
    uVar4 = num_00 & 3;
    do {
      HintPreloadData(param_3);
      bn_mul_add_words(param_1 + 1,param_2,num_00,param_3[-0xc]);
      if (num_00 == uVar3) {
        return;
      }
      bn_mul_add_words(param_1 + 2,param_2,num_00 - 1,param_3[-0xb]);
      puVar1 = param_1 + 3;
      param_1 = param_1 + 4;
      if (num_00 == uVar2) {
        return;
      }
      bn_mul_add_words(puVar1,param_2,num_00 - 2,param_3[-10]);
      bVar5 = num_00 == uVar4;
      num = num_00 - 3;
      num_00 = num_00 - 4;
      if (bVar5) {
        return;
      }
      puVar1 = param_3 + -9;
      param_3 = param_3 + 4;
      bn_mul_add_words(param_1,param_2,num,*puVar1);
    } while (0 < (int)num_00);
  }
  return;
}

