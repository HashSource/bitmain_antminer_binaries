
int PEM_write_RSAPublicKey(FILE *fp,RSA *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_RSAPublicKey + 1,"RSA PUBLIC KEY",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,0
                         ,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

