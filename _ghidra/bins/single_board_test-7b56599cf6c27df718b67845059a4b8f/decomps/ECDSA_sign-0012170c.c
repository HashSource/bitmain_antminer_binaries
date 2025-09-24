
int ECDSA_sign(int type,uchar *dgst,int dgstlen,uchar *sig,uint *siglen,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ECDSA_sign_ex(type,dgst,dgstlen,sig,siglen,(BIGNUM *)0x0,(BIGNUM *)0x0,eckey);
  return iVar1;
}

