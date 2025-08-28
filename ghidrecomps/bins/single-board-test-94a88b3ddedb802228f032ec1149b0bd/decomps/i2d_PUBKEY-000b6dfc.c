
int i2d_PUBKEY(EVP_PKEY *a,uchar **pp)

{
  int iVar1;
  X509_PUBKEY *local_c;
  
  local_c = (X509_PUBKEY *)0x0;
  if ((a == (EVP_PKEY *)0x0) || (iVar1 = X509_PUBKEY_set(&local_c,a), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = ASN1_item_i2d((ASN1_VALUE *)local_c,pp,(ASN1_ITEM *)&X509_PUBKEY_it);
    ASN1_item_free((ASN1_VALUE *)local_c,(ASN1_ITEM *)&X509_PUBKEY_it);
  }
  return iVar1;
}

