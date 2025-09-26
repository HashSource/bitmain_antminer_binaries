
int i2d_RSAPrivateKey_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)RSAPrivateKey_it,fp,rsa);
  return iVar1;
}

