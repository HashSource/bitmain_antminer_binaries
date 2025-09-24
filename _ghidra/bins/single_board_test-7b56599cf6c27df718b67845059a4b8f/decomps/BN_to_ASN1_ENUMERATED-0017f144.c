
ASN1_ENUMERATED * BN_to_ASN1_ENUMERATED(BIGNUM *bn,ASN1_ENUMERATED *ai)

{
  int iVar1;
  int iVar2;
  ASN1_ENUMERATED *str;
  
  if (ai == (ASN1_ENUMERATED *)0x0) {
    str = ASN1_STRING_type_new(10);
    if (str == (ASN1_STRING *)0x0) {
      ERR_put_error(0xd,0xe5,0x3a,"crypto/asn1/a_int.c",0x1cf);
      return (ASN1_ENUMERATED *)0x0;
    }
  }
  else {
    ai->type = 10;
    str = ai;
  }
  iVar1 = BN_is_negative(bn);
  if ((iVar1 != 0) && (iVar1 = BN_is_zero(bn), iVar1 == 0)) {
    str->type = str->type | 0x102;
  }
  iVar2 = BN_num_bits(bn);
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  iVar1 = iVar1 >> 3;
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  iVar2 = ASN1_STRING_set(str,(void *)0x0,iVar1);
  if (iVar2 != 0) {
    iVar2 = BN_is_zero(bn);
    if (iVar2 == 0) {
      iVar1 = BN_bn2bin(bn,str->data);
    }
    else {
      *str->data = '\0';
    }
    str->length = iVar1;
    return str;
  }
  ERR_put_error(0xd,0xe5,0x41,"crypto/asn1/a_int.c",0x1dc);
  if (ai != str) {
    ASN1_INTEGER_free(str);
  }
  return (ASN1_ENUMERATED *)0x0;
}

