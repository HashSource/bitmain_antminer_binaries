
undefined4 update_cipher_list(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = OPENSSL_sk_dup(*param_1);
  if (iVar1 != 0) {
    while ((iVar2 = OPENSSL_sk_num(iVar1), 0 < iVar2 &&
           (iVar2 = OPENSSL_sk_value(iVar1), *(int *)(iVar2 + 0x20) == 0x304))) {
      OPENSSL_sk_delete(iVar1,0);
    }
    for (iVar2 = 0; iVar4 = OPENSSL_sk_num(param_3), iVar2 < iVar4; iVar2 = iVar2 + 1) {
      uVar3 = OPENSSL_sk_value(param_3,iVar2);
      OPENSSL_sk_insert(iVar1,uVar3,iVar2);
    }
    iVar2 = OPENSSL_sk_dup(iVar1);
    if (iVar2 != 0) {
      OPENSSL_sk_free(*param_2);
      *param_2 = iVar2;
      OPENSSL_sk_set_cmp_func(iVar2,0xdd4cd);
      OPENSSL_sk_sort(*param_2);
      OPENSSL_sk_free(*param_1);
      *param_1 = iVar1;
      return 1;
    }
  }
  return 0;
}

