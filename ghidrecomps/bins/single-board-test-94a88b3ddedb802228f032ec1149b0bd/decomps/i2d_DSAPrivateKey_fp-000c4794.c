
int i2d_DSAPrivateKey_fp(FILE *fp,DSA *dsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp(i2d_DSAPrivateKey + 1,fp,dsa);
  return iVar1;
}

