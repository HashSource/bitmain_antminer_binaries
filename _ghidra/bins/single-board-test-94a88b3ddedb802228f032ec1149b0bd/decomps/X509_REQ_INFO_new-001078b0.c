
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_REQ_INFO * X509_REQ_INFO_new(void)

{
  X509_REQ_INFO *pXVar1;
  
  pXVar1 = (X509_REQ_INFO *)ASN1_item_new((ASN1_ITEM *)&X509_REQ_INFO_it);
  return pXVar1;
}

