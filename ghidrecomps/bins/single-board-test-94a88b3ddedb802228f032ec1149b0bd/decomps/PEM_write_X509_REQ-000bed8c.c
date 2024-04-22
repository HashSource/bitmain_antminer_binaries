
int PEM_write_X509_REQ(FILE *fp,X509_REQ *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_X509_REQ + 1,"CERTIFICATE REQUEST",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,
                         0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

