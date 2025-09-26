
int PEM_write_RSAPrivateKey
              (FILE *fp,RSA *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write((undefined1 *)0x149f29,"RSA PRIVATE KEY",fp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

