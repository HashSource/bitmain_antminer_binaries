
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_CRL_INFO * X509_CRL_INFO_new(void)

{
  X509_CRL_INFO *pXVar1;
  
  pXVar1 = (X509_CRL_INFO *)ASN1_item_new((ASN1_ITEM *)&X509_CRL_INFO_it);
  return pXVar1;
}

