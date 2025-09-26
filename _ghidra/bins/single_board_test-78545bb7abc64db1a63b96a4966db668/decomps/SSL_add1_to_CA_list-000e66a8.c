
undefined4 SSL_add1_to_CA_list(int param_1,X509 *param_2)

{
  X509_NAME *pXVar1;
  int iVar2;
  
  if (param_2 != (X509 *)0x0) {
    if (*(int *)(param_1 + 0x4e0) == 0) {
      iVar2 = OPENSSL_sk_new_null();
      *(int *)(param_1 + 0x4e0) = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
    pXVar1 = X509_get_subject_name(param_2);
    pXVar1 = X509_NAME_dup(pXVar1);
    if (pXVar1 != (X509_NAME *)0x0) {
      iVar2 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x4e0),pXVar1);
      if (iVar2 == 0) {
        X509_NAME_free(pXVar1);
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

