
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_CINF * X509_CINF_new(void)

{
  X509_CINF *pXVar1;
  
  pXVar1 = (X509_CINF *)ASN1_item_new((ASN1_ITEM *)&X509_CINF_it);
  return pXVar1;
}

