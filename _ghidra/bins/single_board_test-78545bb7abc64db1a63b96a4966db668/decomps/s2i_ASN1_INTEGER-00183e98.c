
ASN1_INTEGER * s2i_ASN1_INTEGER(X509V3_EXT_METHOD *meth,char *value)

{
  char cVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  bool bVar4;
  BIGNUM *local_14;
  
  local_14 = (BIGNUM *)0x0;
  if (value == (char *)0x0) {
    ERR_put_error(0x22,0x6c,0x6d,"crypto/x509v3/v3_utl.c",0xca);
  }
  else {
    local_14 = BN_new();
    if (local_14 == (BIGNUM *)0x0) {
      ERR_put_error(0x22,0x6c,0x41,"crypto/x509v3/v3_utl.c",0xcf);
    }
    else {
      cVar1 = *value;
      bVar4 = cVar1 == '-';
      if (bVar4) {
        cVar1 = value[1];
      }
      if (bVar4) {
        value = value + bVar4;
      }
      if ((cVar1 == '0') && ((value[1] & 0xdfU) == 0x58)) {
        value = value + 2;
        iVar2 = BN_hex2bn(&local_14,value);
      }
      else {
        iVar2 = BN_dec2bn(&local_14,value);
      }
      if ((iVar2 == 0) || (value[iVar2] != '\0')) {
        BN_free(local_14);
        ERR_put_error(0x22,0x6c,100,"crypto/x509v3/v3_utl.c",0xe5);
        return (ASN1_INTEGER *)0x0;
      }
      if ((bVar4 == 0) || (iVar2 = BN_is_zero(local_14), iVar2 != 0)) {
        pAVar3 = BN_to_ASN1_INTEGER(local_14,(ASN1_INTEGER *)0x0);
        BN_free(local_14);
        if (pAVar3 != (ASN1_INTEGER *)0x0) {
          return pAVar3;
        }
      }
      else {
        pAVar3 = BN_to_ASN1_INTEGER(local_14,(ASN1_INTEGER *)0x0);
        BN_free(local_14);
        if (pAVar3 != (ASN1_INTEGER *)0x0) {
          pAVar3->type = pAVar3->type | 0x100;
          return pAVar3;
        }
      }
      ERR_put_error(0x22,0x6c,0x65,"crypto/x509v3/v3_utl.c",0xf0);
    }
  }
  return (ASN1_INTEGER *)0x0;
}

