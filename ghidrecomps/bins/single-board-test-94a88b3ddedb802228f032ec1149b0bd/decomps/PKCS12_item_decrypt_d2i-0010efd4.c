
void * PKCS12_item_decrypt_d2i
                 (X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,ASN1_OCTET_STRING *oct,
                 int zbuf)

{
  uchar *puVar1;
  ASN1_VALUE *pAVar2;
  uchar *local_24;
  uchar *local_20;
  size_t local_1c;
  
  puVar1 = PKCS12_pbe_crypt(algor,pass,passlen,oct->data,oct->length,&local_24,(int *)&local_1c,0);
  if (puVar1 == (uchar *)0x0) {
    ERR_put_error(0x23,0x6a,0x75,DAT_0010f058,0x8b);
    pAVar2 = (ASN1_VALUE *)0x0;
  }
  else {
    local_20 = local_24;
    pAVar2 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_20,local_1c,it);
    if (zbuf != 0) {
      OPENSSL_cleanse(local_24,local_1c);
    }
    if (pAVar2 == (ASN1_VALUE *)0x0) {
      ERR_put_error(0x23,0x6a,0x65,DAT_0010f058,0x9f);
    }
    CRYPTO_free(local_24);
  }
  return pAVar2;
}

