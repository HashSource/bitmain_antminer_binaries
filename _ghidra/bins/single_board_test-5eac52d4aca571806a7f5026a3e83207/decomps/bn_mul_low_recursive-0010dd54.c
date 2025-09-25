
void bn_mul_low_recursive(int param_1,int param_2,int param_3,int param_4,ulong *param_5)

{
  int num;
  ulong *puVar1;
  ulong *rp;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  num = param_4 / 2;
  uVar4 = 0;
  uVar3 = 0;
  puVar1 = param_5;
  bn_mul_recursive();
  if (num < 0x20) {
    iVar2 = num * 4;
    puVar1 = (ulong *)(param_1 + iVar2);
    bn_mul_low_normal(param_5,param_2,param_3 + iVar2,num,uVar3);
    bn_mul_low_normal(param_5 + num,param_2 + iVar2,param_3,num);
    bn_add_words(puVar1,puVar1,param_5,num);
    bn_add_words(puVar1,puVar1,param_5 + num,num);
    return;
  }
  iVar2 = num * 4;
  rp = (ulong *)(param_1 + iVar2);
  bn_mul_low_recursive(param_5,param_2,param_3 + iVar2,num,param_5 + param_4,uVar4,puVar1);
  bn_add_words(rp,rp,param_5,num);
  bn_mul_low_recursive(param_5,param_2 + iVar2,param_3,num,param_5 + param_4);
  bn_add_words(rp,rp,param_5,num);
  return;
}

