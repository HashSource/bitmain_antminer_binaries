
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_ALGOR * X509_ALGOR_new(void)

{
  X509_ALGOR *pXVar1;
  
  pXVar1 = (X509_ALGOR *)ASN1_item_new((ASN1_ITEM *)&X509_ALGOR_it);
  return pXVar1;
}

