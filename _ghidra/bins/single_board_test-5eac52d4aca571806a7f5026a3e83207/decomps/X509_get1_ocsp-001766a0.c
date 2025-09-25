
stack_st_OPENSSL_STRING * X509_get1_ocsp(X509 *x)

{
  AUTHORITY_INFO_ACCESS *a;
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  size_t __n;
  int iVar4;
  size_t *psVar5;
  stack_st_OPENSSL_STRING *sk;
  void *pvVar6;
  
  a = (AUTHORITY_INFO_ACCESS *)X509_get_ext_d2i(x,0xb1,(int *)0x0,(int *)0x0);
  if (a == (AUTHORITY_INFO_ACCESS *)0x0) {
    return (stack_st_OPENSSL_STRING *)0x0;
  }
  sk = (stack_st_OPENSSL_STRING *)0x0;
  iVar4 = 0;
  do {
    iVar1 = OPENSSL_sk_num(a);
    if (iVar1 <= iVar4) {
LAB_00176762:
      AUTHORITY_INFO_ACCESS_free(a);
      return sk;
    }
    puVar2 = (undefined4 *)OPENSSL_sk_value(a,iVar4);
    iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar2);
    if ((((iVar1 != 0xb2) || (*(int *)puVar2[1] != 6)) ||
        (psVar5 = (size_t *)((int *)puVar2[1])[1], psVar5[1] != 0x16)) ||
       (((pvVar6 = (void *)psVar5[2], pvVar6 == (void *)0x0 || (__n = *psVar5, __n == 0)) ||
        (pvVar3 = memchr(pvVar6,0,__n), pvVar3 != (void *)0x0)))) goto LAB_001766c6;
    if (sk == (stack_st_OPENSSL_STRING *)0x0) {
      sk = (stack_st_OPENSSL_STRING *)OPENSSL_sk_new(0x1752f5);
      if (sk != (stack_st_OPENSSL_STRING *)0x0) {
        pvVar6 = (void *)psVar5[2];
        __n = *psVar5;
        goto LAB_00176718;
      }
LAB_00176760:
      sk = (stack_st_OPENSSL_STRING *)0x0;
      goto LAB_00176762;
    }
LAB_00176718:
    pvVar6 = (void *)CRYPTO_strndup(pvVar6,__n,"crypto/x509v3/v3_utl.c",0x21c);
    if (pvVar6 == (void *)0x0) {
LAB_0017675a:
      X509_email_free(sk);
      goto LAB_00176760;
    }
    iVar1 = OPENSSL_sk_find(sk,pvVar6);
    if (iVar1 == -1) {
      iVar1 = OPENSSL_sk_push(sk,pvVar6);
      if (iVar1 == 0) {
        CRYPTO_free(pvVar6);
        goto LAB_0017675a;
      }
    }
    else {
      CRYPTO_free(pvVar6);
    }
LAB_001766c6:
    iVar4 = iVar4 + 1;
  } while( true );
}

