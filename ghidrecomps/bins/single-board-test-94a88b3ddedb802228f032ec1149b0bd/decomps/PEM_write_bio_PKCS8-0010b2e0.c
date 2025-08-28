
int PEM_write_bio_PKCS8(BIO *bp,X509_SIG *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio((undefined1 *)0xb70e9,"ENCRYPTED PRIVATE KEY",bp,x,(EVP_CIPHER *)0x0,
                             (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

