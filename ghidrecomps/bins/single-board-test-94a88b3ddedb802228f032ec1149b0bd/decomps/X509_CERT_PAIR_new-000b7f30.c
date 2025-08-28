
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_CERT_PAIR * X509_CERT_PAIR_new(void)

{
  X509_CERT_PAIR *pXVar1;
  
  pXVar1 = (X509_CERT_PAIR *)ASN1_item_new((ASN1_ITEM *)X509_CERT_PAIR_it);
  return pXVar1;
}

