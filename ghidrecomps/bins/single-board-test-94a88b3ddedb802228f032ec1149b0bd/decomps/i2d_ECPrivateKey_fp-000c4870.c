
int i2d_ECPrivateKey_fp(FILE *fp,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp(i2d_ECPrivateKey + 1,fp,eckey);
  return iVar1;
}

