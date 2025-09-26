
DSA * d2i_DSA_PUBKEY_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_fp((xnew *)0x199639,(undefined1 *)0x1597f1,fp,dsa);
  return pDVar1;
}

