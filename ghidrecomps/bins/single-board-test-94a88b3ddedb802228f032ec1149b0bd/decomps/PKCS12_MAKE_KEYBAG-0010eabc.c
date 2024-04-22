
PKCS12_SAFEBAG * PKCS12_MAKE_KEYBAG(PKCS8_PRIV_KEY_INFO *p8)

{
  PKCS12_SAFEBAG *pPVar1;
  ASN1_OBJECT *pAVar2;
  
  pPVar1 = PKCS12_SAFEBAG_new();
  if (pPVar1 == (PKCS12_SAFEBAG *)0x0) {
    ERR_put_error(0x23,0x70,0x41,DAT_0010eaec,0x5f);
  }
  else {
    pAVar2 = OBJ_nid2obj(0x96);
    pPVar1->type = pAVar2;
    (pPVar1->value).bag = (pkcs12_bag_st *)p8;
  }
  return pPVar1;
}

