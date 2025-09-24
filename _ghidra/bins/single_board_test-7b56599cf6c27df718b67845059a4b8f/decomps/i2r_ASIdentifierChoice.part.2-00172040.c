
undefined4 i2r_ASIdentifierChoice_part_2(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_2 + 4));
  if (0 < iVar1) {
    do {
      piVar2 = (int *)OPENSSL_sk_value(*(undefined4 *)(param_2 + 4),iVar4);
      if (*piVar2 == 0) {
        pcVar3 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(ASN1_INTEGER *)piVar2[1]);
        if (pcVar3 == (char *)0x0) {
          return 0;
        }
        BIO_printf(param_1,"%*s%s\n",param_3 + 2,"",pcVar3);
        CRYPTO_free(pcVar3);
      }
      else {
        if ((*piVar2 != 1) ||
           (pcVar3 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*(ASN1_INTEGER **)piVar2[1]),
           pcVar3 == (char *)0x0)) {
          return 0;
        }
        BIO_printf(param_1,"%*s%s-",param_3 + 2,"",pcVar3);
        CRYPTO_free(pcVar3);
        pcVar3 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*(ASN1_INTEGER **)(piVar2[1] + 4));
        if (pcVar3 == (char *)0x0) {
          return 0;
        }
        BIO_printf(param_1,"%s\n",pcVar3);
        CRYPTO_free(pcVar3);
      }
      iVar4 = iVar4 + 1;
      iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_2 + 4));
    } while (iVar4 < iVar1);
  }
  return 1;
}

