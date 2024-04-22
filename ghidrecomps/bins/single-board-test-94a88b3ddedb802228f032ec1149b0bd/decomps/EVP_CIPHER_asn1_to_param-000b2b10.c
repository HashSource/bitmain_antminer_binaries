
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  ASN1_TYPE *__n;
  ASN1_TYPE *pAVar1;
  EVP_CIPHER *pEVar2;
  
  pEVar2 = c->cipher;
  if (pEVar2->get_asn1_parameters == (_func_1235 *)0x0) {
    if (-1 < (int)(pEVar2->flags << 0x13)) {
      return -1;
    }
    if ((pEVar2->flags & 0xf0007) == 0x10002) {
      __n = (ASN1_TYPE *)0x1;
    }
    else {
      __n = type;
      if (type != (ASN1_TYPE *)0x0) {
        __n = (ASN1_TYPE *)pEVar2->iv_len;
        if ((ASN1_TYPE *)0x10 < __n) {
          OpenSSLDie(DAT_000b2b84,0x6b,DAT_000b2b88);
        }
        pAVar1 = (ASN1_TYPE *)ASN1_TYPE_get_octetstring(type,c->oiv,(int)__n);
        if (__n != pAVar1) {
          return -1;
        }
        if (0 < (int)__n) {
          memcpy(c->iv,c->oiv,(size_t)__n);
        }
      }
    }
  }
  else {
    __n = (ASN1_TYPE *)(*pEVar2->get_asn1_parameters)(c,type);
  }
  return (int)__n;
}

