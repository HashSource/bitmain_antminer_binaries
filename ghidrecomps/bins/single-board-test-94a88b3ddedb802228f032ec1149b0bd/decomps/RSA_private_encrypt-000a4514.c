
int RSA_private_encrypt(int flen,uchar *from,uchar *to,RSA *rsa,int padding)

{
  int iVar1;
  
  iVar1 = (*rsa->meth->rsa_priv_enc)(flen,from,to,rsa,padding);
  return iVar1;
}

