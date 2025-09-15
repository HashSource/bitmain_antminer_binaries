
RSA_PSS_PARAMS * d2i_RSA_PSS_PARAMS(RSA_PSS_PARAMS **a,uchar **in,long len)

{
  RSA_PSS_PARAMS *pRVar1;
  
  pRVar1 = (RSA_PSS_PARAMS *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&RSA_PSS_PARAMS_it);
  return pRVar1;
}

