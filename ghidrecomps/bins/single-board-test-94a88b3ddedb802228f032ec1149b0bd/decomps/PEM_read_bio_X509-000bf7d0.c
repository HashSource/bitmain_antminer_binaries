
X509 * PEM_read_bio_X509(BIO *bp,X509 **x,undefined1 *cb,void *u)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)PEM_ASN1_read_bio(d2i_X509 + 1,"CERTIFICATE",bp,x,cb,u);
  return pXVar1;
}

