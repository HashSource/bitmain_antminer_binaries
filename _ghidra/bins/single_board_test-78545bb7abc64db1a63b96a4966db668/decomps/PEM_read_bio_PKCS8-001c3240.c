
X509_SIG * PEM_read_bio_PKCS8(BIO *bp,X509_SIG **x,undefined1 *cb,void *u)

{
  X509_SIG *pXVar1;
  
  pXVar1 = (X509_SIG *)PEM_ASN1_read_bio((undefined1 *)0x1908e9,"ENCRYPTED PRIVATE KEY",bp,x,cb,u);
  return pXVar1;
}

