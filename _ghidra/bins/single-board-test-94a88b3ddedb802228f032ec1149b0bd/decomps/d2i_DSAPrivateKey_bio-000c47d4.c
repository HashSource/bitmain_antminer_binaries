
DSA * d2i_DSAPrivateKey_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio((xnew *)0xfe399,(undefined1 *)0xa47f1,bp,dsa);
  return pDVar1;
}

