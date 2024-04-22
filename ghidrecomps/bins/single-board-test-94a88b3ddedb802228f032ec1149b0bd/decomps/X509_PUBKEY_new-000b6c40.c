
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_PUBKEY * X509_PUBKEY_new(void)

{
  X509_PUBKEY *pXVar1;
  
  pXVar1 = (X509_PUBKEY *)ASN1_item_new((ASN1_ITEM *)&X509_PUBKEY_it);
  return pXVar1;
}

