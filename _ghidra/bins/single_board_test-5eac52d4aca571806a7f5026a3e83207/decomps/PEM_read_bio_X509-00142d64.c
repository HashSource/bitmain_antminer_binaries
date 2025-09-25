
X509 * PEM_read_bio_X509(BIO *bp,X509 **x,undefined1 *cb,void *u)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)PEM_ASN1_read_bio((undefined1 *)0x16a2fd,"CERTIFICATE",bp,x,cb,u);
  return pXVar1;
}

