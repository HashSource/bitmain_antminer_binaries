
CMS_CertificateChoices * CMS_add0_CertificateChoices(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *val;
  _STACK *p_Var2;
  _STACK **pp_Var3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var3 = (_STACK **)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,DAT_0010faf8,0x1a4);
      return (CMS_CertificateChoices *)0x0;
    }
    pp_Var3 = *(_STACK ***)(*(int *)(cms + 4) + 4);
  }
  if (pp_Var3 != (_STACK **)0x0) {
    if (*pp_Var3 == (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      *pp_Var3 = p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        return (CMS_CertificateChoices *)0x0;
      }
    }
    val = ASN1_item_new(DAT_0010fafc);
    if (val != (ASN1_VALUE *)0x0) {
      iVar1 = sk_push(*pp_Var3,val);
      if (iVar1 == 0) {
        ASN1_item_free(val,DAT_0010fafc);
        return (CMS_CertificateChoices *)0x0;
      }
      return (CMS_CertificateChoices *)val;
    }
  }
  return (CMS_CertificateChoices *)0x0;
}

