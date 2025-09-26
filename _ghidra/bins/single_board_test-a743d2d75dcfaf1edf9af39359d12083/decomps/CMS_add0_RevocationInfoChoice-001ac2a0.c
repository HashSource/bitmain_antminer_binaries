
CMS_RevocationInfoChoice * CMS_add0_RevocationInfoChoice(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *val;
  _STACK *p_Var2;
  int *piVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    piVar3 = (int *)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x84,0x98,"cms_lib.c",0x1ef);
      return (CMS_RevocationInfoChoice *)0x0;
    }
    piVar3 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (piVar3 != (int *)0x0) {
    if (*piVar3 == 0) {
      p_Var2 = sk_new_null();
      *piVar3 = (int)p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        return (CMS_RevocationInfoChoice *)0x0;
      }
    }
    val = ASN1_item_new((ASN1_ITEM *)CMS_RevocationInfoChoice_it);
    if (val != (ASN1_VALUE *)0x0) {
      iVar1 = sk_push((_STACK *)*piVar3,val);
      if (iVar1 == 0) {
        ASN1_item_free(val,(ASN1_ITEM *)CMS_RevocationInfoChoice_it);
        return (CMS_RevocationInfoChoice *)0x0;
      }
      return (CMS_RevocationInfoChoice *)val;
    }
  }
  return (CMS_RevocationInfoChoice *)0x0;
}

