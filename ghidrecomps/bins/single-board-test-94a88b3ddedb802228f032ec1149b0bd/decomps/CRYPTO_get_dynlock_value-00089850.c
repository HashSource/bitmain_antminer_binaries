
CRYPTO_dynlock_value * CRYPTO_get_dynlock_value(int i)

{
  int iVar1;
  int iVar2;
  _STACK *p_Var3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  
  iVar1 = DAT_000898ac;
  if (i != 0) {
    i = ~i;
  }
  if (*(code **)(DAT_000898ac + 0x10) != (code *)0x0) {
    (**(code **)(DAT_000898ac + 0x10))(9,0x1d,DAT_000898b0,0x156);
  }
  iVar2 = DAT_000898ac;
  p_Var3 = *(_STACK **)(iVar1 + 0x20);
  if ((p_Var3 == (_STACK *)0x0) || (iVar4 = sk_num(p_Var3), iVar4 <= i)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)sk_value(*(_STACK **)(iVar2 + 0x20),i);
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
  }
  pcVar6 = *(code **)(iVar1 + 0x10);
  if (pcVar6 != (code *)0x0) {
    (*pcVar6)(10,0x1d,DAT_000898b0,0x15d);
  }
  if (piVar5 != (int *)0x0) {
    return (CRYPTO_dynlock_value *)piVar5[1];
  }
  return (CRYPTO_dynlock_value *)0x0;
}

