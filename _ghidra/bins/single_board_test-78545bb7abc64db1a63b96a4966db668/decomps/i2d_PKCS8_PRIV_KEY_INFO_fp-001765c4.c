
int i2d_PKCS8_PRIV_KEY_INFO_fp(FILE *fp,PKCS8_PRIV_KEY_INFO *p8inf)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp((undefined1 *)0x10ffd5,fp,p8inf);
  return iVar1;
}

