
DSA * PEM_read_DSA_PUBKEY(FILE *fp,DSA **x,undefined1 *cb,void *u)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)PEM_ASN1_read((undefined1 *)0x156cb1,"PUBLIC KEY",fp,x,cb,u);
  return pDVar1;
}

