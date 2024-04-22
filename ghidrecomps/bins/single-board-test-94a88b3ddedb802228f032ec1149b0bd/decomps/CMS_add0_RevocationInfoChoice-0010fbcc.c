
CMS_RevocationInfoChoice * CMS_add0_RevocationInfoChoice(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *val;
  _STACK *p_Var2;
  _STACK **pp_Var3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var3 = (_STACK **)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x84,0x98,DAT_0010fc40,0x1ef);
      return (CMS_RevocationInfoChoice *)0x0;
    }
    pp_Var3 = (_STACK **)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (pp_Var3 != (_STACK **)0x0) {
    if (*pp_Var3 == (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      *pp_Var3 = p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        return (CMS_RevocationInfoChoice *)0x0;
      }
    }
    val = ASN1_item_new(DAT_0010fc44);
    if (val != (ASN1_VALUE *)0x0) {
      iVar1 = sk_push(*pp_Var3,val);
      if (iVar1 == 0) {
        ASN1_item_free(val,DAT_0010fc44);
        return (CMS_RevocationInfoChoice *)0x0;
      }
      return (CMS_RevocationInfoChoice *)val;
    }
  }
  return (CMS_RevocationInfoChoice *)0x0;
}

