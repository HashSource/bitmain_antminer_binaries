
int i2d_RSA_PUBKEY_fp(FILE *fp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp((undefined1 *)0x169ead,fp,rsa);
  return iVar1;
}

