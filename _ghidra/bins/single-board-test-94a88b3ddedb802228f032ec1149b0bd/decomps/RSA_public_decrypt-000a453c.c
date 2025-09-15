
int RSA_public_decrypt(int flen,uchar *from,uchar *to,RSA *rsa,int padding)

{
  int iVar1;
  
  iVar1 = (*rsa->meth->rsa_pub_dec)(flen,from,to,rsa,padding);
  return iVar1;
}

