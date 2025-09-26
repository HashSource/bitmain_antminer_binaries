
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_SIG * X509_SIG_new(void)

{
  X509_SIG *pXVar1;
  
  pXVar1 = (X509_SIG *)ASN1_item_new((ASN1_ITEM *)&X509_SIG_it);
  return pXVar1;
}

