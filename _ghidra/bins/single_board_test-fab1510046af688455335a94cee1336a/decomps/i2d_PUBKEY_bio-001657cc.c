
int i2d_PUBKEY_bio(BIO *bp,EVP_PKEY *pkey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0x1596f9,bp,(uchar *)pkey);
  return iVar1;
}

