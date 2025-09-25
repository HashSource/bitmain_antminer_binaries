
int X509_set_serialNumber(X509 *x,ASN1_INTEGER *serial)

{
  int iVar1;
  
  if (x != (X509 *)0x0) {
    if ((ASN1_INTEGER *)&x->sig_alg != serial) {
      iVar1 = ASN1_STRING_copy((ASN1_STRING *)&x->sig_alg,serial);
      return iVar1;
    }
    x = (X509 *)0x1;
  }
  return (int)x;
}

