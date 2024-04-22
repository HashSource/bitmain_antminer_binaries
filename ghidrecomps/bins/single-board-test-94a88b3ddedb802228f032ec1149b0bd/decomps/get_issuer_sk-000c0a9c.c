
void * get_issuer_sk(void **param_1,int param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  _STACK *p_Var4;
  
  p_Var4 = *(_STACK **)(param_2 + 0x18);
  iVar3 = 0;
  do {
    iVar2 = sk_num(p_Var4);
    if (iVar2 <= iVar3) {
      *param_1 = (void *)0x0;
      return (void *)0x0;
    }
    pvVar1 = sk_value(p_Var4,iVar3);
    iVar2 = (**(code **)(param_2 + 0x28))(param_2,param_3,pvVar1);
    iVar3 = iVar3 + 1;
  } while (iVar2 == 0);
  *param_1 = pvVar1;
  if (pvVar1 != (void *)0x0) {
    CRYPTO_add_lock((int *)((int)pvVar1 + 0x10),1,3,DAT_000c0b04,0x220);
    pvVar1 = (void *)0x1;
  }
  return pvVar1;
}

