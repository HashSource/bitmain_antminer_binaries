
int X509_EXTENSION_set_critical(X509_EXTENSION *ex,int crit)

{
  ASN1_BOOLEAN AVar1;
  
  if (ex == (X509_EXTENSION *)0x0) {
    return 0;
  }
  if (crit == 0) {
    AVar1 = -1;
  }
  else {
    AVar1 = 0xff;
  }
  ex->critical = AVar1;
  return 1;
}

