
int PEM_write_bio_PUBKEY(BIO *bp,EVP_PKEY *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(i2d_PUBKEY + 1,"PUBLIC KEY",bp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,0,
                             (undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

