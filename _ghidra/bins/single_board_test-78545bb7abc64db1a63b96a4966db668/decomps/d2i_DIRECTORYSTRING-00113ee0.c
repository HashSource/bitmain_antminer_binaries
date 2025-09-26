
ASN1_STRING * d2i_DIRECTORYSTRING(ASN1_STRING **a,uchar **in,long len)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)DIRECTORYSTRING_it);
  return pAVar1;
}

