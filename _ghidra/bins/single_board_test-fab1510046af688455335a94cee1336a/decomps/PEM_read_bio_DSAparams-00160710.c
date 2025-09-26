
DSA * PEM_read_bio_DSAparams(BIO *bp,DSA **x,undefined1 *cb,void *u)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)PEM_ASN1_read_bio((undefined1 *)0x14a289,"DSA PARAMETERS",bp,x,cb,u);
  return pDVar1;
}

