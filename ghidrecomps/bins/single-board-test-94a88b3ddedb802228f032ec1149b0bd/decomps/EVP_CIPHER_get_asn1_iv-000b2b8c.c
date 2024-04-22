
int EVP_CIPHER_get_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  ASN1_TYPE *__n;
  
  if (type != (ASN1_TYPE *)0x0) {
    __n = (ASN1_TYPE *)c->cipher->iv_len;
    if ((ASN1_TYPE *)0x10 < __n) {
      OpenSSLDie(DAT_000b2bd8,0x6b,DAT_000b2bdc);
    }
    type = (ASN1_TYPE *)ASN1_TYPE_get_octetstring(type,c->oiv,(int)__n);
    if (type == __n) {
      if (0 < (int)__n) {
        memcpy(c->iv,c->oiv,(size_t)__n);
      }
    }
    else {
      type = (ASN1_TYPE *)0xffffffff;
    }
  }
  return (int)type;
}

