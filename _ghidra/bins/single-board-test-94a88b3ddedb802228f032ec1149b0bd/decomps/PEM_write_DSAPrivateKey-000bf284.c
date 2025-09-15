
int PEM_write_DSAPrivateKey
              (FILE *fp,DSA *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write((undefined1 *)0xa47fd,"DSA PRIVATE KEY",fp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

