
void * ASN1_item_unpack(ASN1_STRING *oct,ASN1_ITEM *it)

{
  ASN1_VALUE *pAVar1;
  uchar *local_14 [2];
  
  local_14[0] = oct->data;
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)0x0,local_14,oct->length,it);
  if (pAVar1 != (ASN1_VALUE *)0x0) {
    return pAVar1;
  }
  ERR_put_error(0xd,199,0x6e,"crypto/asn1/asn_pack.c",0x3c);
  return (void *)0x0;
}

