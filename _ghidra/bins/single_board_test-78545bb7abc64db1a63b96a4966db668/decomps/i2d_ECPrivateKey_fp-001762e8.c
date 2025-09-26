
int i2d_ECPrivateKey_fp(FILE *fp,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp((undefined1 *)0x125f5d,fp,eckey);
  return iVar1;
}

