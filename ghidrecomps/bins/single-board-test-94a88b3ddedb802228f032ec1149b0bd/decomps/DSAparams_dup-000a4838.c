
DSA * DSAparams_dup(DSA *x)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_dup((ASN1_ITEM *)DSAparams_it,x);
  return pDVar1;
}

