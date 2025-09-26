
int lookup_certs_sk(int param_1,X509_NAME *param_2)

{
  int iVar1;
  X509 *a;
  X509_NAME *b;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0;
  while( true ) {
    do {
      iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x14));
      iVar3 = iVar2 + 1;
      if (iVar1 <= iVar2) {
        return iVar4;
      }
      a = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x14),iVar2);
      b = X509_get_subject_name(a);
      iVar1 = X509_NAME_cmp(param_2,b);
      iVar2 = iVar3;
    } while (iVar1 != 0);
    iVar1 = X509_up_ref(a);
    if (iVar1 == 0) break;
    if (((iVar4 == 0) && (iVar4 = OPENSSL_sk_new_null(), iVar4 == 0)) ||
       (iVar1 = OPENSSL_sk_push(iVar4,a), iVar1 == 0)) {
      X509_free(a);
      OPENSSL_sk_pop_free(iVar4,(undefined *)0x178169);
      ERR_put_error(0xb,0x98,0x41,"crypto/x509/x509_vfy.c",0x186);
      *(undefined4 *)(param_1 + 0x60) = 0x11;
      return 0;
    }
  }
  OPENSSL_sk_pop_free(iVar4,(undefined *)0x178169);
  ERR_put_error(0xb,0x98,0x44,"crypto/x509/x509_vfy.c",0x17d);
  *(undefined4 *)(param_1 + 0x60) = 1;
  return 0;
}

