
int PEM_write_bio_Parameters(BIO *bp,EVP_PKEY *x)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char acStack_60 [80];
  
  pEVar2 = x->ameth;
  if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(pEVar2 + 0x3c);
    if (iVar1 != 0) {
      BIO_snprintf(acStack_60,0x50,DAT_000bfcc8,*(undefined4 *)(pEVar2 + 0xc));
      iVar1 = PEM_ASN1_write_bio(*(undefined1 **)(x->ameth + 0x3c),acStack_60,bp,x,(EVP_CIPHER *)0x0
                                 ,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
  }
  return iVar1;
}

