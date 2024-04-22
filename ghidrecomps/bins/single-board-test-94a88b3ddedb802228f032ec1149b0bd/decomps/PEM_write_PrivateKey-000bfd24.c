
int PEM_write_PrivateKey
              (FILE *fp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *bp;
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char acStack_68 [84];
  
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x8b,7,DAT_000bfda8,0xee);
    iVar1 = 0;
  }
  else {
    pEVar2 = x->ameth;
    if ((pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar2 + 0x28) != 0)) {
      iVar1 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
    }
    else {
      BIO_snprintf(acStack_68,0x50,DAT_000bfdac,*(undefined4 *)(pEVar2 + 0xc));
      iVar1 = PEM_ASN1_write_bio(DAT_000bfdb0,acStack_68,bp,x,enc,kstr,klen,cb,u);
    }
    BIO_free(bp);
  }
  return iVar1;
}

