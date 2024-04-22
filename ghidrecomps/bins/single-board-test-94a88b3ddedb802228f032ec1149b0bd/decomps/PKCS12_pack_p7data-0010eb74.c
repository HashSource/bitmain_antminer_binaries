
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  PKCS7 *pPVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  
  pPVar1 = PKCS7_new();
  if (pPVar1 == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x72,0x41,DAT_0010ebe8,0x8d);
  }
  else {
    pAVar2 = OBJ_nid2obj(0x15);
    pPVar1->type = pAVar2;
    pAVar3 = ASN1_STRING_type_new(4);
    (pPVar1->d).data = pAVar3;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x23,0x72,0x41,DAT_0010ebe8,0x92);
      pPVar1 = (PKCS7 *)0x0;
    }
    else {
      pAVar3 = ASN1_item_pack(sk,DAT_0010ebe4,&(pPVar1->d).data);
      if (pAVar3 == (ASN1_STRING *)0x0) {
        ERR_put_error(0x23,0x72,100,DAT_0010ebe8,0x97);
        pPVar1 = (PKCS7 *)0x0;
      }
    }
  }
  return pPVar1;
}

