
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VERIFY_PARAM * X509_VERIFY_PARAM_new(void)

{
  X509_VERIFY_PARAM *pXVar1;
  
  pXVar1 = (X509_VERIFY_PARAM *)CRYPTO_zalloc(0x40,"crypto/x509/x509_vpm.c",0x56);
  if (pXVar1 == (X509_VERIFY_PARAM *)0x0) {
    ERR_put_error(0xb,0x9f,0x41,"crypto/x509/x509_vpm.c",0x58);
  }
  else {
    pXVar1->trust = 0;
    pXVar1->depth = -1;
    pXVar1->policies = (stack_st_ASN1_OBJECT *)0xffffffff;
  }
  return pXVar1;
}

