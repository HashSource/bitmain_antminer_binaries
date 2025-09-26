
PBKDF2PARAM * d2i_PBKDF2PARAM(PBKDF2PARAM **a,uchar **in,long len)

{
  PBKDF2PARAM *pPVar1;
  
  pPVar1 = (PBKDF2PARAM *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PBKDF2PARAM_it);
  return pPVar1;
}

