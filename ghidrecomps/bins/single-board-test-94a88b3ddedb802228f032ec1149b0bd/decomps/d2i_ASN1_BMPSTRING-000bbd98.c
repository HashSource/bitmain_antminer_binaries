
ASN1_BMPSTRING * d2i_ASN1_BMPSTRING(ASN1_BMPSTRING **a,uchar **in,long len)

{
  ASN1_BMPSTRING *pAVar1;
  
  pAVar1 = (ASN1_BMPSTRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000bbda0);
  return pAVar1;
}

