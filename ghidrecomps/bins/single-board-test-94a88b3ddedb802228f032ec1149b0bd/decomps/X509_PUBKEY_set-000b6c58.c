
int X509_PUBKEY_set(X509_PUBKEY **x,EVP_PKEY *pkey)

{
  X509_PUBKEY *val;
  int iVar1;
  code *pcVar2;
  
  if ((x != (X509_PUBKEY **)0x0) &&
     (val = (X509_PUBKEY *)ASN1_item_new(DAT_000b6ccc), val != (X509_PUBKEY *)0x0)) {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,DAT_000b6cd0,0x6f);
    }
    else {
      pcVar2 = *(code **)(pkey->ameth + 0x18);
      if (pcVar2 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,DAT_000b6cd0,0x6b);
      }
      else {
        iVar1 = (*pcVar2)(val,pkey);
        if (iVar1 != 0) {
          if (*x != (X509_PUBKEY *)0x0) {
            ASN1_item_free((ASN1_VALUE *)*x,DAT_000b6ccc);
          }
          *x = val;
          return 1;
        }
        ERR_put_error(0xb,0x78,0x7e,DAT_000b6cd0,0x67);
      }
    }
    ASN1_item_free((ASN1_VALUE *)val,DAT_000b6ccc);
  }
  return 0;
}

