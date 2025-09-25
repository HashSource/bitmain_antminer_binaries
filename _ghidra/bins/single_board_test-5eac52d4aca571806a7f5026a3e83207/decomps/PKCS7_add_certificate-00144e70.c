
int PKCS7_add_certificate(PKCS7 *p7,X509 *x509)

{
  int iVar1;
  uchar *puVar2;
  uchar **ppuVar3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 != 0x18)) {
    ERR_put_error(0x21,100,0x71,"crypto/pkcs7/pk7_lib.c",0xfc);
    return 0;
  }
  ppuVar3 = &((p7->d).data)->data;
  if (((p7->d).data)->data == (uchar *)0x0) {
    puVar2 = (uchar *)OPENSSL_sk_new_null();
    *ppuVar3 = puVar2;
  }
  if (*ppuVar3 == (uchar *)0x0) {
    ERR_put_error(0x21,100,0x41,"crypto/pkcs7/pk7_lib.c",0x103);
    iVar1 = 0;
  }
  else {
    X509_up_ref(x509);
    iVar1 = OPENSSL_sk_push(*ppuVar3,x509);
    if (iVar1 == 0) {
      X509_free(x509);
      return 0;
    }
    iVar1 = 1;
  }
  return iVar1;
}

