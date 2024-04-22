
int PEM_write_DSAparams(FILE *fp,DSA *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_DSAparams + 1,"DSA PARAMETERS",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,0,
                         (undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

