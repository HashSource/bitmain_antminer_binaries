
X509_CRL * X509_CRL_diff(X509_CRL *param_1,X509_CRL *param_2,EVP_PKEY *param_3,EVP_MD *param_4)

{
  int iVar1;
  X509_CRL *x;
  int iVar2;
  X509_EXTENSION *ex;
  ASN1_INTEGER **ppAVar3;
  int iVar4;
  _STACK *p_Var5;
  X509_REVOKED *local_24;
  
  if ((param_1->base_crl_number != (ASN1_INTEGER *)0x0) ||
     (param_2->base_crl_number != (ASN1_INTEGER *)0x0)) {
    ERR_put_error(0xb,0x69,0x7f,DAT_000c23e4,0x7be);
    return (X509_CRL *)0x0;
  }
  if ((param_1->crl_number == (ASN1_INTEGER *)0x0) || (param_2->crl_number == (ASN1_INTEGER *)0x0))
  {
    ERR_put_error(0xb,0x69,0x82,DAT_000c23e4,0x7c3);
    return (X509_CRL *)0x0;
  }
  iVar1 = X509_NAME_cmp(param_1->crl->issuer,param_2->crl->issuer);
  if (iVar1 != 0) {
    ERR_put_error(0xb,0x69,0x81,DAT_000c23e4,0x7c8);
    return (X509_CRL *)0x0;
  }
  iVar1 = crl_extension_match(param_1,param_2,0x5a);
  if (iVar1 == 0) {
    ERR_put_error(0xb,0x69,0x6e,DAT_000c23e4,0x7cd);
    return (X509_CRL *)0x0;
  }
  iVar1 = crl_extension_match(param_1,param_2,0x302);
  if (iVar1 == 0) {
    ERR_put_error(0xb,0x69,0x80,DAT_000c23e4,0x7d1);
    return (X509_CRL *)0x0;
  }
  iVar1 = ASN1_INTEGER_cmp(param_2->crl_number,param_1->crl_number);
  if (iVar1 < 1) {
    ERR_put_error(0xb,0x69,0x84,DAT_000c23e4,0x7d6);
    return (X509_CRL *)0x0;
  }
  if ((param_3 != (EVP_PKEY *)0x0) &&
     ((iVar1 = X509_CRL_verify(param_1,param_3), iVar1 < 1 ||
      (iVar1 = X509_CRL_verify(param_2,param_3), iVar1 < 1)))) {
    ERR_put_error(0xb,0x69,0x83,DAT_000c23e4,0x7dc);
    return (X509_CRL *)0x0;
  }
  x = X509_CRL_new();
  if (x == (X509_CRL *)0x0) {
    ERR_put_error(0xb,0x69,0x41,DAT_000c23e4,0x81a);
    return (X509_CRL *)0x0;
  }
  iVar1 = X509_CRL_set_version(x,1);
  if ((((iVar1 != 0) && (iVar1 = X509_CRL_set_issuer_name(x,param_2->crl->issuer), iVar1 != 0)) &&
      (iVar1 = X509_CRL_set_lastUpdate(x,param_2->crl->lastUpdate), iVar1 != 0)) &&
     (iVar1 = X509_CRL_set_nextUpdate(x,param_2->crl->nextUpdate), iVar1 != 0)) {
    iVar2 = X509_CRL_add1_ext_i2d(x,0x8c,param_1->crl_number,1,0);
    iVar1 = 0;
    while (iVar2 != 0) {
      iVar2 = X509_CRL_get_ext_count(param_2);
      if (iVar2 <= iVar1) {
        p_Var5 = &param_2->crl->revoked->stack;
        iVar1 = 0;
        goto LAB_000c22e8;
      }
      ex = X509_CRL_get_ext(param_2,iVar1);
      iVar2 = X509_CRL_add_ext(x,ex,-1);
      iVar1 = iVar1 + 1;
    }
  }
  goto LAB_000c223e;
  while( true ) {
    local_24 = (X509_REVOKED *)X509_REVOKED_dup(ppAVar3);
    if (local_24 == (X509_REVOKED *)0x0) goto LAB_000c223e;
    iVar2 = X509_CRL_add0_revoked(x,local_24);
    if (iVar2 == 0) break;
LAB_000c22e8:
    do {
      iVar2 = sk_num(p_Var5);
      iVar4 = iVar1 + 1;
      if (iVar2 <= iVar1) {
        if (param_4 == (EVP_MD *)0x0) {
          return x;
        }
        if (param_3 == (EVP_PKEY *)0x0) {
          return x;
        }
        iVar1 = X509_CRL_sign(x,param_3,param_4);
        if (iVar1 != 0) {
          return x;
        }
        goto LAB_000c223e;
      }
      ppAVar3 = (ASN1_INTEGER **)sk_value(p_Var5,iVar1);
      iVar2 = X509_CRL_get0_by_serial(param_1,&local_24,*ppAVar3);
      iVar1 = iVar4;
    } while (iVar2 != 0);
  }
  X509_REVOKED_free(local_24);
LAB_000c223e:
  ERR_put_error(0xb,0x69,0x41,DAT_000c23e4,0x81a);
  X509_CRL_free(x);
  return (X509_CRL *)0x0;
}

