
DSA * d2i_DSAPrivateKey_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio(DSA_new + 1,d2i_DSAPrivateKey + 1,bp,dsa);
  return pDVar1;
}

