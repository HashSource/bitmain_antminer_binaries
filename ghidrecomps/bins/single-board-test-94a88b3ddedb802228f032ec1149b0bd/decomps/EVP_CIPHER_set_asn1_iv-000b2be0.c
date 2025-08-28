
int EVP_CIPHER_set_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  uint len;
  
  if (type != (ASN1_TYPE *)0x0) {
    len = c->cipher->iv_len;
    if (0x10 < len) {
      OpenSSLDie("evp_lib.c",0x7c,"j <= sizeof(c->iv)");
    }
    iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
    return iVar1;
  }
  return 0;
}

