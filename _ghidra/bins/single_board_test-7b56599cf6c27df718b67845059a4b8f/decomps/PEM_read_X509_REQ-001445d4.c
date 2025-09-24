
X509_REQ * PEM_read_X509_REQ(FILE *fp,X509_REQ **x,undefined1 *cb,void *u)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)PEM_ASN1_read((undefined1 *)0x16e355,"CERTIFICATE REQUEST",fp,x,cb,u);
  return pXVar1;
}

