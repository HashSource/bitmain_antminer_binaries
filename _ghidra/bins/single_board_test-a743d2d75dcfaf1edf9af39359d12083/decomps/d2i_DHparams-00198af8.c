
DH * d2i_DHparams(DH **a,uchar **pp,long length)

{
  DH *pDVar1;
  
  pDVar1 = (DH *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)&DHparams_it);
  return pDVar1;
}

