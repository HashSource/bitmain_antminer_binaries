
NETSCAPE_CERT_SEQUENCE *
PEM_read_bio_NETSCAPE_CERT_SEQUENCE(BIO *bp,NETSCAPE_CERT_SEQUENCE **x,undefined1 *cb,void *u)

{
  NETSCAPE_CERT_SEQUENCE *pNVar1;
  
  pNVar1 = (NETSCAPE_CERT_SEQUENCE *)
           PEM_ASN1_read_bio((undefined1 *)0x1a48a5,"CERTIFICATE",bp,x,cb,u);
  return pNVar1;
}

