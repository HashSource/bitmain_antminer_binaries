
CMS_RevocationInfoChoice * CMS_add0_RevocationInfoChoice(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *val;
  int *piVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    piVar2 = (int *)(*(int *)(cms + 4) + 0x10);
    if (piVar2 == (int *)0x0) {
      return (CMS_RevocationInfoChoice *)0x0;
    }
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x84,0x98,"crypto/cms/cms_lib.c",0x1b0);
      return (CMS_RevocationInfoChoice *)0x0;
    }
    if (*(int *)(*(int *)(cms + 4) + 4) == 0) {
      return (CMS_RevocationInfoChoice *)0x0;
    }
    piVar2 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (*piVar2 == 0) {
    iVar1 = OPENSSL_sk_new_null();
    *piVar2 = iVar1;
    if (iVar1 == 0) {
      return (CMS_RevocationInfoChoice *)0x0;
    }
  }
  val = ASN1_item_new((ASN1_ITEM *)CMS_RevocationInfoChoice_it);
  if (val == (ASN1_VALUE *)0x0) {
    return (CMS_RevocationInfoChoice *)0x0;
  }
  iVar1 = OPENSSL_sk_push(*piVar2,val);
  if (iVar1 == 0) {
    ASN1_item_free(val,(ASN1_ITEM *)CMS_RevocationInfoChoice_it);
    return (CMS_RevocationInfoChoice *)0x0;
  }
  return (CMS_RevocationInfoChoice *)val;
}

