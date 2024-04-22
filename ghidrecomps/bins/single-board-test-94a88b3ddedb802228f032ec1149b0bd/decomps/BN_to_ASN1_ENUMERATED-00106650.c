
ASN1_ENUMERATED * BN_to_ASN1_ENUMERATED(BIGNUM *bn,ASN1_ENUMERATED *ai)

{
  uchar *to;
  ASN1_ENUMERATED *a;
  int iVar1;
  int iVar2;
  
  a = ai;
  if ((ai == (ASN1_ENUMERATED *)0x0) && (a = ASN1_STRING_type_new(10), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8a,0x3a,DAT_00106700,0x92);
    return (ASN1_ENUMERATED *)0x0;
  }
  if (bn->neg == 0) {
    iVar2 = 10;
  }
  else {
    iVar2 = 0x10a;
  }
  a->type = iVar2;
  iVar2 = BN_num_bits(bn);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (3 < a->length) goto LAB_001066ba;
  }
  else {
    iVar1 = iVar2 + 7;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    iVar2 = (iVar1 >> 3) + 1;
    if ((iVar1 >> 3) + 4 < a->length) {
LAB_001066ba:
      to = a->data;
      goto LAB_00106696;
    }
  }
  to = (uchar *)CRYPTO_realloc(a->data,iVar2 + 4,DAT_00106700,0x9c);
  if (to == (uchar *)0x0) {
    ERR_put_error(0xd,0x8a,0x41,DAT_00106700,0x9e);
    if (ai == a) {
      return (ASN1_ENUMERATED *)0x0;
    }
    ASN1_STRING_free(a);
    return (ASN1_ENUMERATED *)0x0;
  }
  a->data = to;
LAB_00106696:
  iVar2 = BN_bn2bin(bn,to);
  a->length = iVar2;
  return a;
}

