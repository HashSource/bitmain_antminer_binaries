
ASN1_STRING * ASN1_item_pack(void *obj,ASN1_ITEM *it,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar2 = ASN1_STRING_new();
    if (pAVar2 == (ASN1_STRING *)0x0) {
LAB_0010a7d4:
      ERR_put_error(0xd,0xc6,0x41,DAT_0010a7e8,0xac);
      return (ASN1_STRING *)0x0;
    }
  }
  else {
    pAVar2 = *oct;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      pAVar2 = ASN1_STRING_new();
      if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_0010a7d4;
      *oct = pAVar2;
    }
  }
  if (pAVar2->data != (uchar *)0x0) {
    CRYPTO_free(pAVar2->data);
    pAVar2->data = (uchar *)0x0;
  }
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)obj,&pAVar2->data,it);
  pAVar2->length = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xc6,0x70,DAT_0010a7e8,0xba);
    pAVar2 = (ASN1_STRING *)0x0;
  }
  else if (pAVar2->data == (uchar *)0x0) {
    ERR_put_error(0xd,0xc6,0x41,DAT_0010a7e8,0xbe);
    pAVar2 = (ASN1_STRING *)0x0;
  }
  return pAVar2;
}

