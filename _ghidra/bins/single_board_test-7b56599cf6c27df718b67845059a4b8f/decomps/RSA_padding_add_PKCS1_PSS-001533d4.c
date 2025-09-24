
int RSA_padding_add_PKCS1_PSS(RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,int sLen)

{
  int iVar1;
  
  iVar1 = RSA_padding_add_PKCS1_PSS_mgf1(rsa,EM,mHash,Hash,(EVP_MD *)0x0,sLen);
  return iVar1;
}

