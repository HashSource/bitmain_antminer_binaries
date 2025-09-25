
ASIdentifierChoice * d2i_ASIdentifierChoice(ASIdentifierChoice **a,uchar **in,long len)

{
  ASIdentifierChoice *pAVar1;
  
  pAVar1 = (ASIdentifierChoice *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASIdentifierChoice_it);
  return pAVar1;
}

