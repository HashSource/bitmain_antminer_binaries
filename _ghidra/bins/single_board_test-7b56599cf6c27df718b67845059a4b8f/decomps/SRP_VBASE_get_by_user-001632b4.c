
undefined4 * SRP_VBASE_get_by_user(undefined4 *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == (undefined4 *)0x0) {
LAB_001632e2:
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar2 = 0;
    do {
      iVar1 = OPENSSL_sk_num(*param_1);
      if (iVar1 <= iVar2) goto LAB_001632e2;
      puVar3 = (undefined4 *)OPENSSL_sk_value(*param_1,iVar2);
      iVar1 = strcmp((char *)*puVar3,param_2);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
  }
  return puVar3;
}

