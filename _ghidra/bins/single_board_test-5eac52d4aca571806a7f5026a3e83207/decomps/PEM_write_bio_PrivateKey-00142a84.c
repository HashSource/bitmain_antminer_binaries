
int PEM_write_bio_PrivateKey
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  if ((x->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) && (*(int *)(x->ameth + 0x28) == 0)) {
    iVar1 = PEM_write_bio_PrivateKey_traditional();
    return iVar1;
  }
  iVar1 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
  return iVar1;
}

