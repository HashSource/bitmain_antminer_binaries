
int PKCS7_add_crl(PKCS7 *p7,X509_CRL *x509)

{
  int iVar1;
  int iVar2;
  _STACK *p_Var3;
  stack_st_X509_CRL **ppsVar4;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 == 0x16) || (iVar1 == 0x18)) {
    ppsVar4 = &((p7->d).sign)->crl;
    if (*ppsVar4 == (stack_st_X509_CRL *)0x0) {
      p_Var3 = sk_new_null();
      *ppsVar4 = (stack_st_X509_CRL *)p_Var3;
      if (p_Var3 == (_STACK *)0x0) {
        ERR_put_error(0x21,0x65,0x41,DAT_000cf5d8,0x157);
        return 0;
      }
    }
    CRYPTO_add_lock(&x509->references,1,6,DAT_000cf5d8,0x15b);
    iVar2 = sk_push(&(*ppsVar4)->stack,x509);
    iVar1 = 1;
    if (iVar2 == 0) {
      X509_CRL_free(x509);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(0x21,0x65,0x71,DAT_000cf5d8,0x150);
    iVar1 = 0;
  }
  return iVar1;
}

