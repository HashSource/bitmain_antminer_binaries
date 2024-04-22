
int RSA_verify_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  size_t len;
  uchar *to;
  int iVar1;
  ASN1_OCTET_STRING *a;
  int iVar2;
  uchar *local_24;
  
  len = RSA_size(rsa);
  if (len != siglen) {
    ERR_put_error(4,0x78,0x77,DAT_00124fc8,0x74);
    return 0;
  }
  to = (uchar *)CRYPTO_malloc(len,DAT_00124fc8,0x78);
  if (to != (uchar *)0x0) {
    iVar2 = 1;
    iVar1 = RSA_public_decrypt(len,sigbuf,to,rsa,1);
    if ((iVar1 < 1) ||
       (local_24 = to, a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_24,iVar1),
       a == (ASN1_OCTET_STRING *)0x0)) {
      iVar2 = 0;
    }
    else {
      if ((a->length != m_length) || (iVar1 = memcmp(m,a->data,a->length), iVar1 != 0)) {
        iVar2 = 0;
        ERR_put_error(4,0x78,0x68,DAT_00124fc8,0x89);
      }
      ASN1_STRING_free(a);
    }
    OPENSSL_cleanse(to,len);
    CRYPTO_free(to);
    return iVar2;
  }
  ERR_put_error(4,0x78,0x41,DAT_00124fc8,0x7a);
  return 0;
}

