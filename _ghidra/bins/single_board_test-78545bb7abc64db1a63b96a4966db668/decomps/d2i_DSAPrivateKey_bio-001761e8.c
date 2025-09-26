
DSA * d2i_DSAPrivateKey_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio((xnew *)0x122555,(undefined1 *)0x122265,bp,dsa);
  return pDVar1;
}

