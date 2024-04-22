
ASN1_INTEGER * BN_to_ASN1_INTEGER(BIGNUM *bn,ASN1_INTEGER *ai)

{
  ASN1_INTEGER *a;
  int iVar1;
  int iVar2;
  uchar *to;
  
  a = ai;
  if ((ai == (ASN1_INTEGER *)0x0) && (a = ASN1_STRING_type_new(2), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8b,0x3a,DAT_000b59ec,0x1a5);
  }
  else {
    if (bn->neg == 0) {
      iVar2 = 2;
    }
    else if (bn->top == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 0x102;
    }
    a->type = iVar2;
    iVar2 = BN_num_bits(bn);
    if (iVar2 == 0) {
      iVar1 = 3;
      iVar2 = 0;
    }
    else {
      iVar1 = iVar2 + 7;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      iVar2 = (iVar1 >> 3) + 1;
      iVar1 = (iVar1 >> 3) + 4;
    }
    if (iVar1 < a->length) {
      to = a->data;
    }
    else {
      to = (uchar *)CRYPTO_realloc(a->data,iVar2 + 4,DAT_000b59ec,0x1af);
      if (to == (uchar *)0x0) {
        ERR_put_error(0xd,0x8b,0x41,DAT_000b59ec,0x1b1);
        if (ai == a) {
          return (ASN1_INTEGER *)0x0;
        }
        ASN1_STRING_free(a);
        return (ASN1_INTEGER *)0x0;
      }
      a->data = to;
    }
    iVar2 = BN_bn2bin(bn,to);
    a->length = iVar2;
    if (iVar2 == 0) {
      *a->data = '\0';
      a->length = 1;
    }
  }
  return a;
}

