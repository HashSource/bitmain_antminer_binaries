
X509 * PEM_read_X509(FILE *fp,X509 **x,undefined1 *cb,void *u)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)PEM_ASN1_read((undefined1 *)0x178125,"CERTIFICATE",fp,x,cb,u);
  return pXVar1;
}

