
CMS_CertificateChoices * CMS_add0_CertificateChoices(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *val;
  int *piVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    piVar2 = (int *)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,"crypto/cms/cms_lib.c",0x163);
      return (CMS_CertificateChoices *)0x0;
    }
    piVar2 = *(int **)(*(int *)(cms + 4) + 4);
  }
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == 0) {
      iVar1 = OPENSSL_sk_new_null();
      *piVar2 = iVar1;
      if (iVar1 == 0) {
        return (CMS_CertificateChoices *)0x0;
      }
    }
    val = ASN1_item_new((ASN1_ITEM *)CMS_CertificateChoices_it);
    if (val != (ASN1_VALUE *)0x0) {
      iVar1 = OPENSSL_sk_push(*piVar2,val);
      if (iVar1 == 0) {
        ASN1_item_free(val,(ASN1_ITEM *)CMS_CertificateChoices_it);
        return (CMS_CertificateChoices *)0x0;
      }
      return (CMS_CertificateChoices *)val;
    }
  }
  return (CMS_CertificateChoices *)0x0;
}

