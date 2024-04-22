
stack_st_X509_ALGOR * PKCS7_get_smimecap(PKCS7_SIGNER_INFO *si)

{
  ASN1_TYPE *pAVar1;
  uchar *local_c;
  
  pAVar1 = PKCS7_get_signed_attribute(si,0xa7);
  if (pAVar1 != (ASN1_TYPE *)0x0) {
    if (pAVar1->type == 0x10) {
      local_c = ((pAVar1->value).asn1_string)->data;
      pAVar1 = (ASN1_TYPE *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,&local_c,((pAVar1->value).asn1_string)->length,
                             DAT_000d1140);
    }
    else {
      pAVar1 = (ASN1_TYPE *)0x0;
    }
  }
  return (stack_st_X509_ALGOR *)pAVar1;
}

