
ASN1_OCTET_STRING * d2i_ASN1_OCTET_STRING(ASN1_OCTET_STRING **a,uchar **in,long len)

{
  ASN1_OCTET_STRING *pAVar1;
  
  pAVar1 = (ASN1_OCTET_STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000bbb90);
  return pAVar1;
}

