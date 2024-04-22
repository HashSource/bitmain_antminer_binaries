
ASN1_STRING * ASN1_STRING_type_new(int type)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)CRYPTO_malloc(0x10,DAT_000bd004,0x19c);
  if (pAVar1 == (ASN1_STRING *)0x0) {
    ERR_put_error(0xd,0x82,0x41,DAT_000bd004,0x19e);
  }
  else {
    pAVar1->length = 0;
    pAVar1->type = type;
    pAVar1->data = (uchar *)0x0;
    pAVar1->flags = 0;
  }
  return pAVar1;
}

