
CMS_CertificateChoices * CMS_add0_CertificateChoices(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *val;
  _STACK *p_Var2;
  int *piVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    piVar3 = (int *)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,"cms_lib.c",0x1a4);
      return (CMS_CertificateChoices *)0x0;
    }
    piVar3 = *(int **)(*(int *)(cms + 4) + 4);
  }
  if (piVar3 != (int *)0x0) {
    if (*piVar3 == 0) {
      p_Var2 = sk_new_null();
      *piVar3 = (int)p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        return (CMS_CertificateChoices *)0x0;
      }
    }
    val = ASN1_item_new((ASN1_ITEM *)CMS_CertificateChoices_it);
    if (val != (ASN1_VALUE *)0x0) {
      iVar1 = sk_push((_STACK *)*piVar3,val);
      if (iVar1 == 0) {
        ASN1_item_free(val,(ASN1_ITEM *)CMS_CertificateChoices_it);
        return (CMS_CertificateChoices *)0x0;
      }
      return (CMS_CertificateChoices *)val;
    }
  }
  return (CMS_CertificateChoices *)0x0;
}

