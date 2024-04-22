
int PEM_write_bio_DSAparams(BIO *bp,DSA *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(i2d_DSAparams + 1,"DSA PARAMETERS",bp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,
                             0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

