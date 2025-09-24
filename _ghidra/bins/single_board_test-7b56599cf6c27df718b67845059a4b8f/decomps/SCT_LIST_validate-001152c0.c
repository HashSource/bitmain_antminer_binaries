
uint SCT_LIST_validate(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = OPENSSL_sk_num();
  if (0 < iVar1) {
    uVar5 = 1;
    iVar2 = 0;
    do {
      iVar4 = iVar2 + 1;
      iVar2 = OPENSSL_sk_value(param_1,iVar2);
      if (iVar2 != 0) {
        uVar3 = SCT_validate(iVar2,param_2);
        uVar5 = uVar5 & uVar3;
        if ((int)uVar3 < 0) {
          return uVar3;
        }
      }
      iVar2 = iVar4;
    } while (iVar4 != iVar1);
    return uVar5;
  }
  return 1;
}

