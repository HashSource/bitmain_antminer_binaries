
DSA * d2i_DSA_PUBKEY_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio((xnew *)0x122555,(undefined1 *)0x177d21,bp,dsa);
  return pDVar1;
}

