
undefined4 check_in_list(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  
  if ((param_3 == 0) || (param_4 == 0)) {
    return 0;
  }
  if (param_5 == 0) {
    puVar3 = (ushort *)(param_3 + -2);
    iVar2 = 0;
    do {
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + 1;
      if (*puVar3 == param_2) {
        return 1;
      }
    } while (param_4 != iVar2);
  }
  else {
    puVar3 = (ushort *)(param_3 + -2);
    iVar2 = 0;
    do {
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + 1;
      if ((*puVar3 == param_2) && (iVar1 = tls_curve_allowed(param_1,param_2,0x20006), iVar1 != 0))
      {
        return 1;
      }
    } while (param_4 != iVar2);
  }
  return 0;
}

