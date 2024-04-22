
X509_CERT_PAIR * PEM_read_bio_X509_CERT_PAIR(BIO *bp,X509_CERT_PAIR **x,undefined1 *cb,void *u)

{
  X509_CERT_PAIR *pXVar1;
  
  pXVar1 = (X509_CERT_PAIR *)PEM_ASN1_read_bio(d2i_X509_CERT_PAIR + 1,"CERTIFICATE PAIR",bp,x,cb,u);
  return pXVar1;
}

