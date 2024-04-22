
ASN1_INTEGER * s2i_ASN1_INTEGER(X509V3_EXT_METHOD *meth,char *value)

{
  char cVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  bool bVar4;
  BIGNUM *local_14 [2];
  
  local_14[0] = (BIGNUM *)0x0;
  if (value == (char *)0x0) {
    ERR_put_error(0x22,0x6c,0x6d,DAT_000c7b60,0xb6);
  }
  else {
    local_14[0] = BN_new();
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
      iVar2 = BN_hex2bn(local_14,value);
    }
    else {
      iVar2 = BN_dec2bn(local_14,value);
    }
    if ((iVar2 == 0) || (value[iVar2] != '\0')) {
      BN_free(local_14[0]);
      ERR_put_error(0x22,0x6c,100,DAT_000c7b60,0xcd);
    }
    else {
      if (bVar4 == 0) {
        pAVar3 = BN_to_ASN1_INTEGER(local_14[0],(ASN1_INTEGER *)0x0);
        BN_free(local_14[0]);
        if (pAVar3 != (ASN1_INTEGER *)0x0) {
          return pAVar3;
        }
      }
      else {
        iVar2 = local_14[0]->top;
        pAVar3 = BN_to_ASN1_INTEGER(local_14[0],(ASN1_INTEGER *)0x0);
        BN_free(local_14[0]);
        if (pAVar3 != (ASN1_INTEGER *)0x0) {
          if (iVar2 == 0) {
            return pAVar3;
          }
          pAVar3->type = pAVar3->type | 0x100;
          return pAVar3;
        }
      }
      ERR_put_error(0x22,0x6c,0x65,DAT_000c7b60,0xd8);
    }
  }
  return (ASN1_INTEGER *)0x0;
}

