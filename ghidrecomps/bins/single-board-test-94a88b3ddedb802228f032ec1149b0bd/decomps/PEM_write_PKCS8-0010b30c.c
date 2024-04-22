
int PEM_write_PKCS8(FILE *fp,X509_SIG *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_X509_SIG + 1,"ENCRYPTED PRIVATE KEY",fp,x,(EVP_CIPHER *)0x0,
                         (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

