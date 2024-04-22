
ASN1_OCTET_STRING *
PKCS12_item_i2d_encrypt(X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,void *obj,int zbuf)

{
  ASN1_STRING *a;
  size_t len;
  uchar *puVar1;
  uchar *local_24 [2];
  
  local_24[0] = (uchar *)0x0;
  a = ASN1_STRING_type_new(4);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x23,0x6c,0x41,DAT_0010f110,0xb2);
  }
  else {
    len = ASN1_item_i2d((ASN1_VALUE *)obj,local_24,it);
    if (local_24[0] == (uchar *)0x0) {
      ERR_put_error(0x23,0x6c,0x66,DAT_0010f110,0xb7);
    }
    else {
      puVar1 = PKCS12_pbe_crypt(algor,pass,passlen,local_24[0],len,&a->data,&a->length,1);
      if (puVar1 != (uchar *)0x0) {
        if (zbuf != 0) {
          OPENSSL_cleanse(local_24[0],len);
        }
        CRYPTO_free(local_24[0]);
        return a;
      }
      ERR_put_error(0x23,0x6c,0x67,DAT_0010f110,0xbc);
      CRYPTO_free(local_24[0]);
    }
    ASN1_OCTET_STRING_free(a);
  }
  return (ASN1_OCTET_STRING *)0x0;
}

