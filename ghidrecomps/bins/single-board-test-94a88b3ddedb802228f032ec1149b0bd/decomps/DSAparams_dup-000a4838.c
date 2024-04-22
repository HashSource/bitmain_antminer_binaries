
DSA * DSAparams_dup(DSA *x)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_dup(DAT_000a4840,x);
  return pDVar1;
}

