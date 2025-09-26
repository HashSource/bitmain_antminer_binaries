
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_NAME_ENTRY * X509_NAME_ENTRY_new(void)

{
  X509_NAME_ENTRY *pXVar1;
  
  pXVar1 = (X509_NAME_ENTRY *)ASN1_item_new((ASN1_ITEM *)&X509_NAME_ENTRY_it);
  return pXVar1;
}

