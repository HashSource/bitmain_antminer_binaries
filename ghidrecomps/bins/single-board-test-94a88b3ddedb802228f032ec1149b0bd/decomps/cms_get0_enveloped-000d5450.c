
ASN1_OBJECT * cms_get0_enveloped(ASN1_OBJECT **param_1)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  
  iVar1 = OBJ_obj2nid(*param_1);
  if (iVar1 == 0x17) {
    pAVar2 = param_1[1];
  }
  else {
    ERR_put_error(0x2e,0x83,0x6b,DAT_000d547c,0x4f);
    pAVar2 = (ASN1_OBJECT *)0x0;
  }
  return pAVar2;
}

