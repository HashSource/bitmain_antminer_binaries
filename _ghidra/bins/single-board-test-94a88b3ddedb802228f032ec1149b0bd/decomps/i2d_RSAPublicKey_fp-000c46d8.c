
int i2d_RSAPublicKey_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)RSAPublicKey_it,fp,rsa);
  return iVar1;
}

