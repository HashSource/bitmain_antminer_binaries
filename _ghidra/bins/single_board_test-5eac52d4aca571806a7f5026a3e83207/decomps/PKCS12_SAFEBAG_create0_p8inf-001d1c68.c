
PKCS12_SAFEBAG * PKCS12_SAFEBAG_create0_p8inf(_union_984 param_1)

{
  PKCS12_SAFEBAG *pPVar1;
  ASN1_OBJECT *pAVar2;
  
  pPVar1 = PKCS12_SAFEBAG_new();
  if (pPVar1 == (PKCS12_SAFEBAG *)0x0) {
    ERR_put_error(0x23,0x70,0x41,"crypto/pkcs12/p12_sbag.c",0x71);
  }
  else {
    pAVar2 = OBJ_nid2obj(0x96);
    pPVar1->type = pAVar2;
    pPVar1->value = param_1;
  }
  return pPVar1;
}

