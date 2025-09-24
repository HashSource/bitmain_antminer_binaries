
int i2d_EC_PUBKEY_fp(FILE *fp,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp((undefined1 *)0x16e221,fp,eckey);
  return iVar1;
}

