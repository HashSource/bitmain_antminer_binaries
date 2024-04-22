
int i2d_RSA_PUBKEY_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp(i2d_RSA_PUBKEY + 1,fp,rsa);
  return iVar1;
}

