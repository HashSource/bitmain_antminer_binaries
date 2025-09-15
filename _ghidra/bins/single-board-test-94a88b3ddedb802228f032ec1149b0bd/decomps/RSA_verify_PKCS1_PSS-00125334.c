
int RSA_verify_PKCS1_PSS(RSA *rsa,uchar *mHash,EVP_MD *Hash,uchar *EM,int sLen)

{
  int iVar1;
  
  iVar1 = RSA_verify_PKCS1_PSS_mgf1(rsa,mHash,Hash,(EVP_MD *)0x0,EM,sLen);
  return iVar1;
}

