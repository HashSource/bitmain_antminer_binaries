
AUTHORITY_KEYID * d2i_AUTHORITY_KEYID(AUTHORITY_KEYID **a,uchar **in,long len)

{
  AUTHORITY_KEYID *pAVar1;
  
  pAVar1 = (AUTHORITY_KEYID *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&AUTHORITY_KEYID_it);
  return pAVar1;
}

