
SSL_SESSION * PEM_read_bio_SSL_SESSION(BIO *bp,SSL_SESSION **x,undefined1 *cb,void *u)

{
  SSL_SESSION *pSVar1;
  
  pSVar1 = (SSL_SESSION *)
           PEM_ASN1_read_bio((undefined1 *)0x10b1cd,"SSL SESSION PARAMETERS",bp,x,cb,u);
  return pSVar1;
}

