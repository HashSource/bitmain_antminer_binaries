
DSA * d2i_DSA_PUBKEY_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_fp(DSA_new + 1,d2i_DSA_PUBKEY + 1,fp,dsa);
  return pDVar1;
}

