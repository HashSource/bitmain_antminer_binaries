
int PKCS7_add_attrib_smimecap(PKCS7_SIGNER_INFO *si,stack_st_X509_ALGOR *cap)

{
  ASN1_STRING *data;
  int iVar1;
  
  data = ASN1_STRING_new();
  if (data != (ASN1_STRING *)0x0) {
    iVar1 = ASN1_item_i2d((ASN1_VALUE *)cap,&data->data,DAT_000d1108);
    data->length = iVar1;
    iVar1 = PKCS7_add_signed_attribute(si,0xa7,0x10,data);
    return iVar1;
  }
  ERR_put_error(0x21,0x76,0x41,DAT_000d110c,0x4b);
  return 0;
}

