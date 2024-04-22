
int PEM_write_SSL_SESSION(FILE *fp,SSL_SESSION *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_SSL_SESSION + 1,"SSL SESSION PARAMETERS",fp,x,(EVP_CIPHER *)0x0,
                         (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

