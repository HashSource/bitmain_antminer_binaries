
ASN1_ENUMERATED * d2i_ASN1_ENUMERATED(ASN1_ENUMERATED **a,uchar **in,long len)

{
  ASN1_ENUMERATED *pAVar1;
  
  pAVar1 = (ASN1_ENUMERATED *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000bbb30);
  return pAVar1;
}

