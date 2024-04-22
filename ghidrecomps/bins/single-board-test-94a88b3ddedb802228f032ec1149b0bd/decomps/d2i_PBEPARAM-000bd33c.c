
PBEPARAM * d2i_PBEPARAM(PBEPARAM **a,uchar **in,long len)

{
  PBEPARAM *pPVar1;
  
  pPVar1 = (PBEPARAM *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&PBEPARAM_it);
  return pPVar1;
}

