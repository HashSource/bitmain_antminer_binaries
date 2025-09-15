
int i2d_EC_PUBKEY(EC_KEY *a,uchar **pp)

{
  EVP_PKEY *pkey;
  X509_PUBKEY *local_14;
  
  if (a != (EC_KEY *)0x0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0xb5,0x41,"x_pubkey.c",0x14a);
      a = (EC_KEY *)0x0;
    }
    else {
      EVP_PKEY_set1_EC_KEY(pkey,a);
      local_14 = (X509_PUBKEY *)0x0;
      a = (EC_KEY *)X509_PUBKEY_set(&local_14,pkey);
      if (a != (EC_KEY *)0x0) {
        a = (EC_KEY *)ASN1_item_i2d((ASN1_VALUE *)local_14,pp,(ASN1_ITEM *)&X509_PUBKEY_it);
        ASN1_item_free((ASN1_VALUE *)local_14,(ASN1_ITEM *)&X509_PUBKEY_it);
      }
      EVP_PKEY_free(pkey);
    }
  }
  return (int)a;
}

