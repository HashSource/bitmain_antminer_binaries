
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  X509_PUBKEY *key;
  EVP_PKEY *pEVar1;
  
  key = (X509_PUBKEY *)ASN1_item_d2i((ASN1_VALUE **)0x0,pp,length,(ASN1_ITEM *)&X509_PUBKEY_it);
  if (key != (X509_PUBKEY *)0x0) {
    pEVar1 = X509_PUBKEY_get(key);
    ASN1_item_free((ASN1_VALUE *)key,(ASN1_ITEM *)&X509_PUBKEY_it);
    if (pEVar1 != (EVP_PKEY *)0x0) {
      if (a == (EVP_PKEY **)0x0) {
        return pEVar1;
      }
      EVP_PKEY_free(*a);
      *a = pEVar1;
      return pEVar1;
    }
  }
  return (EVP_PKEY *)0x0;
}

