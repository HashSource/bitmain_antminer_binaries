
X509_CRL * PEM_read_X509_CRL(FILE *fp,X509_CRL **x,undefined1 *cb,void *u)

{
  X509_CRL *pXVar1;
  
  pXVar1 = (X509_CRL *)PEM_ASN1_read(d2i_X509_CRL + 1,"X509 CRL",fp,x,cb,u);
  return pXVar1;
}

