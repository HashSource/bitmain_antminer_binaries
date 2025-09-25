
int PKCS7_add_crl(PKCS7 *p7,X509_CRL *x509)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 != 0x18)) {
    ERR_put_error(0x21,0x65,0x71,"crypto/pkcs7/pk7_lib.c",0x11c);
    return 0;
  }
  plVar3 = &((p7->d).data)->flags;
  if (((p7->d).data)->flags == 0) {
    lVar2 = OPENSSL_sk_new_null();
    *plVar3 = lVar2;
  }
  if (*plVar3 == 0) {
    ERR_put_error(0x21,0x65,0x41,"crypto/pkcs7/pk7_lib.c",0x123);
    iVar1 = 0;
  }
  else {
    X509_CRL_up_ref(x509);
    iVar1 = OPENSSL_sk_push(*plVar3,x509);
    if (iVar1 == 0) {
      X509_CRL_free(x509);
      return 0;
    }
    iVar1 = 1;
  }
  return iVar1;
}

