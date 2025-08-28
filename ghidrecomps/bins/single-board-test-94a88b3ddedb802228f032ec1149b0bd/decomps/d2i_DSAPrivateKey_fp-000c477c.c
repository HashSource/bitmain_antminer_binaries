
DSA * d2i_DSAPrivateKey_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_fp((xnew *)0xfe399,(undefined1 *)0xa47f1,fp,dsa);
  return pDVar1;
}

