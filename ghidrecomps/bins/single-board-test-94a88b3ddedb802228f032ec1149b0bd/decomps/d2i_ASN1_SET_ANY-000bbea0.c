
ASN1_SEQUENCE_ANY * d2i_ASN1_SET_ANY(ASN1_SEQUENCE_ANY **a,uchar **in,long len)

{
  ASN1_SEQUENCE_ANY *pAVar1;
  
  pAVar1 = (ASN1_SEQUENCE_ANY *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000bbea8);
  return pAVar1;
}

