
int X509_PUBKEY_set(X509_PUBKEY **x,EVP_PKEY *pkey)

{
  X509_PUBKEY *a;
  int iVar1;
  code *pcVar2;
  
  if (x == (X509_PUBKEY **)0x0) {
    return 0;
  }
  a = X509_PUBKEY_new();
  if (a != (X509_PUBKEY *)0x0) {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,"crypto/x509/x_pubkey.c",0x52);
    }
    else {
      pcVar2 = *(code **)(pkey->ameth + 0x18);
      if (pcVar2 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,"crypto/x509/x_pubkey.c",0x4e);
      }
      else {
        iVar1 = (*pcVar2)(a,pkey);
        if (iVar1 != 0) {
          X509_PUBKEY_free(*x);
          *x = a;
          a->pkey = pkey;
          EVP_PKEY_up_ref(pkey);
          return 1;
        }
        ERR_put_error(0xb,0x78,0x7e,"crypto/x509/x_pubkey.c",0x4a);
      }
    }
  }
  X509_PUBKEY_free(a);
  return 0;
}

