
undefined4 cms_set1_ias(undefined4 *param_1,X509 *param_2)

{
  ASN1_VALUE *val;
  X509_NAME *name;
  int iVar1;
  ASN1_INTEGER *str;
  ASN1_STRING *dst;
  
  val = ASN1_item_new((ASN1_ITEM *)CMS_IssuerAndSerialNumber_it);
  if (val != (ASN1_VALUE *)0x0) {
    name = X509_get_issuer_name(param_2);
    iVar1 = X509_NAME_set((X509_NAME **)val,name);
    if (iVar1 != 0) {
      dst = *(ASN1_STRING **)(val + 4);
      str = X509_get_serialNumber(param_2);
      iVar1 = ASN1_STRING_copy(dst,str);
      if (iVar1 != 0) {
        ASN1_item_free((ASN1_VALUE *)*param_1,(ASN1_ITEM *)CMS_IssuerAndSerialNumber_it);
        *param_1 = val;
        return 1;
      }
    }
  }
  ASN1_item_free(val,(ASN1_ITEM *)CMS_IssuerAndSerialNumber_it);
  ERR_put_error(0x2e,0xb0,0x41,"crypto/cms/cms_lib.c",0x237);
  return 0;
}

