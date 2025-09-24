
DSA * d2i_DSA_PUBKEY_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_fp((xnew *)0x11897d,(undefined1 *)0x16e149,fp,dsa);
  return pDVar1;
}

