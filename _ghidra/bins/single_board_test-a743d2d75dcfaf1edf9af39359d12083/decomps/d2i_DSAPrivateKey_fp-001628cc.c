
DSA * d2i_DSAPrivateKey_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_fp((xnew *)0x196af9,(undefined1 *)0x147731,fp,dsa);
  return pDVar1;
}

