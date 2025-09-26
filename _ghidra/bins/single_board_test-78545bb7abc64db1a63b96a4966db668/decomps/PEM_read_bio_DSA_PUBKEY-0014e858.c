
DSA * PEM_read_bio_DSA_PUBKEY(BIO *bp,DSA **x,undefined1 *cb,void *u)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)PEM_ASN1_read_bio((undefined1 *)0x177d21,"PUBLIC KEY",bp,x,cb,u);
  return pDVar1;
}

