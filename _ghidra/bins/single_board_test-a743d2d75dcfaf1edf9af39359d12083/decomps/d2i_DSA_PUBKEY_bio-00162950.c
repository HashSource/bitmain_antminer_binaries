
DSA * d2i_DSA_PUBKEY_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio((xnew *)0x196af9,(undefined1 *)0x156cb1,bp,dsa);
  return pDVar1;
}

