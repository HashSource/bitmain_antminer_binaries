
int X509_PUBKEY_set(X509_PUBKEY **x,EVP_PKEY *pkey)

{
  X509_PUBKEY *val;
  int iVar1;
  code *pcVar2;
  
  if ((x != (X509_PUBKEY **)0x0) &&
     (val = (X509_PUBKEY *)ASN1_item_new((ASN1_ITEM *)&X509_PUBKEY_it), val != (X509_PUBKEY *)0x0))
  {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,"x_pubkey.c",0x6f);
    }
    else {
      pcVar2 = *(code **)(pkey->ameth + 0x18);
      if (pcVar2 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,"x_pubkey.c",0x6b);
      }
      else {
        iVar1 = (*pcVar2)(val,pkey);
        if (iVar1 != 0) {
          if (*x != (X509_PUBKEY *)0x0) {
            ASN1_item_free((ASN1_VALUE *)*x,(ASN1_ITEM *)&X509_PUBKEY_it);
          }
          *x = val;
          return 1;
        }
        ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x67);
      }
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_PUBKEY_it);
  }
  return 0;
}

