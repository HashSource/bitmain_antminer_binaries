
int PEM_write_bio_PrivateKey
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char acStack_68 [80];
  
  pEVar2 = x->ameth;
  if ((pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar2 + 0x28) != 0)) {
    iVar1 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
  }
  else {
    BIO_snprintf(acStack_68,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar2 + 0xc));
    iVar1 = PEM_ASN1_write_bio((undefined1 *)0x107fe5,acStack_68,bp,x,enc,kstr,klen,cb,u);
  }
  return iVar1;
}

