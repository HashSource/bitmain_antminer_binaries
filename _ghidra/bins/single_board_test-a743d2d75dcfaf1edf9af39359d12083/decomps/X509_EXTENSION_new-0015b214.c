
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_EXTENSION * X509_EXTENSION_new(void)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = (X509_EXTENSION *)ASN1_item_new((ASN1_ITEM *)&X509_EXTENSION_it);
  return pXVar1;
}

