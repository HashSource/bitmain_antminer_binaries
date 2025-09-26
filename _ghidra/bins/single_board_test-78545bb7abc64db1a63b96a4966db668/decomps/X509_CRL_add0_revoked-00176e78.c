
int X509_CRL_add0_revoked(X509_CRL *crl,X509_REVOKED *rev)

{
  ISSUING_DIST_POINT *pIVar1;
  int iVar2;
  
  pIVar1 = crl->idp;
  if (pIVar1 == (ISSUING_DIST_POINT *)0x0) {
    pIVar1 = (ISSUING_DIST_POINT *)OPENSSL_sk_new(0x17684d);
    crl->idp = pIVar1;
    if (pIVar1 == (ISSUING_DIST_POINT *)0x0) goto LAB_00176ea4;
  }
  iVar2 = OPENSSL_sk_push(pIVar1,rev);
  if (iVar2 != 0) {
    crl->base_crl_number = (ASN1_INTEGER *)0x1;
    return 1;
  }
LAB_00176ea4:
  ERR_put_error(0xd,0xa9,0x41,"crypto/x509/x_crl.c",0x15a);
  return 0;
}

