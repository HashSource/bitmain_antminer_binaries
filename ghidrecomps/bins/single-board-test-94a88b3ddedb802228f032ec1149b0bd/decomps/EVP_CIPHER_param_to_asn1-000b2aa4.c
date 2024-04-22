
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  uint len;
  
  pEVar2 = c->cipher;
  if (pEVar2->set_asn1_parameters != (_func_1234 *)0x0) {
    iVar1 = (*pEVar2->set_asn1_parameters)(c,type);
    return iVar1;
  }
  if (-1 < (int)(pEVar2->flags << 0x13)) {
    return -1;
  }
  if ((pEVar2->flags & 0xf0007) == 0x10002) {
    ASN1_TYPE_set(type,5,(void *)0x0);
    return 1;
  }
  if (type != (ASN1_TYPE *)0x0) {
    len = pEVar2->iv_len;
    if (0x10 < len) {
      OpenSSLDie(DAT_000b2b08,0x7c,DAT_000b2b0c);
    }
    iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
    return iVar1;
  }
  return 0;
}

