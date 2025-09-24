
stack_st_OPENSSL_STRING * get_email(X509_NAME *param_1,undefined4 param_2)

{
  X509_NAME_ENTRY *ne;
  ASN1_STRING *pAVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  size_t sVar6;
  int iVar7;
  size_t *psVar8;
  stack_st_OPENSSL_STRING *sk;
  uchar *__s;
  
  sk = (stack_st_OPENSSL_STRING *)0x0;
  iVar7 = -1;
  do {
    while( true ) {
      do {
        iVar7 = X509_NAME_get_index_by_NID(param_1,0x30,iVar7);
        if (iVar7 < 0) {
          iVar7 = 0;
          goto LAB_0017aa82;
        }
        ne = X509_NAME_get_entry(param_1,iVar7);
        pAVar1 = X509_NAME_ENTRY_get_data(ne);
      } while (((pAVar1->type != 0x16) || (__s = pAVar1->data, __s == (uchar *)0x0)) ||
              ((sVar6 = pAVar1->length, sVar6 == 0 ||
               (pvVar2 = memchr(__s,0,sVar6), pvVar2 != (void *)0x0))));
      if (sk == (stack_st_OPENSSL_STRING *)0x0) {
        sk = (stack_st_OPENSSL_STRING *)OPENSSL_sk_new(0x179545);
        if (sk == (stack_st_OPENSSL_STRING *)0x0) {
          return (stack_st_OPENSSL_STRING *)0x0;
        }
        __s = pAVar1->data;
        sVar6 = pAVar1->length;
      }
      pvVar2 = (void *)CRYPTO_strndup(__s,sVar6,"crypto/x509v3/v3_utl.c",0x21c);
      if (pvVar2 == (void *)0x0) goto LAB_0017ab14;
      iVar3 = OPENSSL_sk_find(sk,pvVar2);
      if (iVar3 == -1) break;
      CRYPTO_free(pvVar2);
    }
    iVar3 = OPENSSL_sk_push(sk,pvVar2);
  } while (iVar3 != 0);
LAB_0017ab0a:
  CRYPTO_free(pvVar2);
LAB_0017ab14:
  X509_email_free(sk);
  return (stack_st_OPENSSL_STRING *)0x0;
LAB_0017aa82:
  iVar3 = OPENSSL_sk_num(param_2);
  if (iVar3 <= iVar7) {
    return sk;
  }
  piVar4 = (int *)OPENSSL_sk_value(param_2,iVar7);
  if ((((*piVar4 == 1) && (psVar8 = (size_t *)piVar4[1], psVar8[1] == 0x16)) &&
      (pvVar2 = (void *)psVar8[2], pvVar2 != (void *)0x0)) &&
     ((sVar6 = *psVar8, sVar6 != 0 && (pvVar5 = memchr(pvVar2,0,sVar6), pvVar5 == (void *)0x0)))) {
    if (sk == (stack_st_OPENSSL_STRING *)0x0) {
      sk = (stack_st_OPENSSL_STRING *)OPENSSL_sk_new(0x179545);
      if (sk == (stack_st_OPENSSL_STRING *)0x0) {
        return (stack_st_OPENSSL_STRING *)0x0;
      }
      pvVar2 = (void *)psVar8[2];
      sVar6 = *psVar8;
    }
    pvVar2 = (void *)CRYPTO_strndup(pvVar2,sVar6,"crypto/x509v3/v3_utl.c",0x21c);
    if (pvVar2 == (void *)0x0) goto LAB_0017ab14;
    iVar3 = OPENSSL_sk_find(sk,pvVar2);
    if (iVar3 == -1) {
      iVar3 = OPENSSL_sk_push(sk,pvVar2);
      if (iVar3 == 0) goto LAB_0017ab0a;
    }
    else {
      CRYPTO_free(pvVar2);
    }
  }
  iVar7 = iVar7 + 1;
  goto LAB_0017aa82;
}

