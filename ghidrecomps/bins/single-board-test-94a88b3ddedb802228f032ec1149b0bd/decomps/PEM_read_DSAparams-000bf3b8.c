
DSA * PEM_read_DSAparams(FILE *fp,DSA **x,undefined1 *cb,void *u)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)PEM_ASN1_read(d2i_DSAparams + 1,"DSA PARAMETERS",fp,x,cb,u);
  return pDVar1;
}

