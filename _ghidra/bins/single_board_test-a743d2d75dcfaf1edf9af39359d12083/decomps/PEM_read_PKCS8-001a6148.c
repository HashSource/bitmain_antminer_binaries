
X509_SIG * PEM_read_PKCS8(FILE *fp,X509_SIG **x,undefined1 *cb,void *u)

{
  X509_SIG *pXVar1;
  
  pXVar1 = (X509_SIG *)PEM_ASN1_read((undefined1 *)0x156e99,"ENCRYPTED PRIVATE KEY",fp,x,cb,u);
  return pXVar1;
}

