
int X509_chain_up_ref(void)

{
  int iVar1;
  int iVar2;
  X509 *a;
  int iVar3;
  
  iVar1 = OPENSSL_sk_dup();
  if (iVar1 != 0) {
    for (iVar3 = 0; iVar2 = OPENSSL_sk_num(iVar1), iVar3 < iVar2; iVar3 = iVar3 + 1) {
      OPENSSL_sk_value(iVar1,iVar3);
      iVar2 = X509_up_ref();
      if (iVar2 == 0) {
        iVar2 = iVar3 + -1;
        if (0 < iVar3) {
          do {
            a = (X509 *)OPENSSL_sk_value(iVar1,iVar2);
            iVar2 = iVar2 + -1;
            X509_free(a);
          } while (iVar2 != -1);
        }
        OPENSSL_sk_free(iVar1);
        return 0;
      }
    }
  }
  return iVar1;
}

