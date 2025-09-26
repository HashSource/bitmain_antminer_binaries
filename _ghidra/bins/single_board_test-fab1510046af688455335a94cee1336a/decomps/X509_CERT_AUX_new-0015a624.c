
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_CERT_AUX * X509_CERT_AUX_new(void)

{
  X509_CERT_AUX *pXVar1;
  
  pXVar1 = (X509_CERT_AUX *)ASN1_item_new((ASN1_ITEM *)&X509_CERT_AUX_it);
  return pXVar1;
}

