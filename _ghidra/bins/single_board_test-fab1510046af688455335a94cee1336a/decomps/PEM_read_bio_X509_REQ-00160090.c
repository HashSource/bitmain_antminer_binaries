
X509_REQ * PEM_read_bio_X509_REQ(BIO *bp,X509_REQ **x,undefined1 *cb,void *u)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)PEM_ASN1_read_bio((undefined1 *)0x1a41b9,"CERTIFICATE REQUEST",bp,x,cb,u);
  return pXVar1;
}

