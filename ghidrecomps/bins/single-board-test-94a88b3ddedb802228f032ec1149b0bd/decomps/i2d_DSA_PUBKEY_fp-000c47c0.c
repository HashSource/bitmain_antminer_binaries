
int i2d_DSA_PUBKEY_fp(FILE *fp,DSA *dsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp(i2d_DSA_PUBKEY + 1,fp,dsa);
  return iVar1;
}

