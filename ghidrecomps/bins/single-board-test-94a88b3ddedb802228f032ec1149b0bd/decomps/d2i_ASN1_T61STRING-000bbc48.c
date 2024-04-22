
ASN1_T61STRING * d2i_ASN1_T61STRING(ASN1_T61STRING **a,uchar **in,long len)

{
  ASN1_T61STRING *pAVar1;
  
  pAVar1 = (ASN1_T61STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000bbc50);
  return pAVar1;
}

