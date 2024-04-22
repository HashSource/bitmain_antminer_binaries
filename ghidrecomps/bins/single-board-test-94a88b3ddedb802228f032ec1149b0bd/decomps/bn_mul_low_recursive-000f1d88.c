
void bn_mul_low_recursive(int param_1,int param_2,int param_3,int param_4,ulong *param_5)

{
  int num;
  int iVar1;
  ulong *rp;
  ulong *puVar2;
  
  num = param_4 / 2;
  puVar2 = param_5;
  bn_mul_recursive_constprop_0();
  if (num < 0x20) {
    iVar1 = num * 4;
    rp = (ulong *)(param_1 + iVar1);
    bn_mul_low_normal(param_5,param_2,param_3 + iVar1,num,puVar2);
    bn_mul_low_normal(param_5 + num,param_2 + iVar1,param_3,num);
    bn_add_words(rp,rp,param_5,num);
    bn_add_words(rp,rp,param_5 + num,num);
    return;
  }
  iVar1 = num * 4;
  puVar2 = (ulong *)(param_1 + iVar1);
  bn_mul_low_recursive(param_5,param_2,param_3 + iVar1,num,param_5 + param_4);
  bn_add_words(puVar2,puVar2,param_5,num);
  bn_mul_low_recursive(param_5,param_2 + iVar1,param_3,num,param_5 + param_4);
  bn_add_words(puVar2,puVar2,param_5,num);
  return;
}

