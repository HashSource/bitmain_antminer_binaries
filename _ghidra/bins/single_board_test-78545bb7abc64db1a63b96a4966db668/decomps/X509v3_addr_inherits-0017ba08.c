
undefined4 X509v3_addr_inherits(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = 0;
  do {
    iVar1 = OPENSSL_sk_num(param_1);
    if (iVar1 <= iVar2) {
      return 0;
    }
    iVar1 = OPENSSL_sk_value(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (**(int **)(iVar1 + 4) != 0);
  return 1;
}

