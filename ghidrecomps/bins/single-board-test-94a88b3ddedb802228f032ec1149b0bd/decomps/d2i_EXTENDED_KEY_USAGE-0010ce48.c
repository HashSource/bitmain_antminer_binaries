
EXTENDED_KEY_USAGE * d2i_EXTENDED_KEY_USAGE(EXTENDED_KEY_USAGE **a,uchar **in,long len)

{
  EXTENDED_KEY_USAGE *pEVar1;
  
  pEVar1 = (EXTENDED_KEY_USAGE *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&EXTENDED_KEY_USAGE_it);
  return pEVar1;
}

