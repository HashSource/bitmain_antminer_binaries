
ASN1_OCTET_STRING *
PKCS12_item_i2d_encrypt(X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,void *obj,int zbuf)

{
  ASN1_OCTET_STRING *a;
  size_t len;
  uchar *puVar1;
  uchar *local_1c;
  
  local_1c = (uchar *)0x0;
  a = ASN1_OCTET_STRING_new();
  if (a == (ASN1_OCTET_STRING *)0x0) {
    ERR_put_error(0x23,0x6c,0x41,"crypto/pkcs12/p12_decr.c",0x86);
  }
  else {
    len = ASN1_item_i2d((ASN1_VALUE *)obj,&local_1c,it);
    if (local_1c == (uchar *)0x0) {
      ERR_put_error(0x23,0x6c,0x66,"crypto/pkcs12/p12_decr.c",0x8b);
    }
    else {
      puVar1 = PKCS12_pbe_crypt(algor,pass,passlen,local_1c,len,&a->data,&a->length,1);
      if (puVar1 != (uchar *)0x0) {
        if (zbuf != 0) {
          OPENSSL_cleanse(local_1c,len);
        }
        CRYPTO_free(local_1c);
        return a;
      }
      ERR_put_error(0x23,0x6c,0x67,"crypto/pkcs12/p12_decr.c",0x90);
      CRYPTO_free(local_1c);
    }
  }
  ASN1_OCTET_STRING_free(a);
  return (ASN1_OCTET_STRING *)0x0;
}

