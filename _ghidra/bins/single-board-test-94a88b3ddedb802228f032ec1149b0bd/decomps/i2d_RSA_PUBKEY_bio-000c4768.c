
int i2d_RSA_PUBKEY_bio(BIO *bp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0xb6e8d,bp,(uchar *)rsa);
  return iVar1;
}

