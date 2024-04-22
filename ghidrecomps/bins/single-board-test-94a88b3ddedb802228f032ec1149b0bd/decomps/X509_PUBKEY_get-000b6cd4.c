
EVP_PKEY * X509_PUBKEY_get(X509_PUBKEY *key)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  if (key != (X509_PUBKEY *)0x0) {
    if (key->pkey != (EVP_PKEY *)0x0) {
      CRYPTO_add_lock(&key->pkey->references,1,10,DAT_000b6dc0,0x87);
      return key->pkey;
    }
    if (key->public_key != (ASN1_BIT_STRING *)0x0) {
      pkey = EVP_PKEY_new();
      if (pkey != (EVP_PKEY *)0x0) {
        iVar1 = OBJ_obj2nid(key->algor->algorithm);
        iVar1 = EVP_PKEY_set_type(pkey,iVar1);
        if (iVar1 == 0) {
          ERR_put_error(0xb,0x77,0x6f,DAT_000b6dc0,0x94);
        }
        else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
          ERR_put_error(0xb,0x77,0x7c,DAT_000b6dc0,0x9e);
        }
        else {
          iVar1 = (**(code **)(pkey->ameth + 0x14))(pkey,key);
          if (iVar1 != 0) {
            CRYPTO_lock(9,10,DAT_000b6dc0,0xa3);
            if (key->pkey == (EVP_PKEY *)0x0) {
              key->pkey = pkey;
              CRYPTO_lock(10,10,DAT_000b6dc0,0xaa);
            }
            else {
              CRYPTO_lock(10,10,DAT_000b6dc0,0xa5);
              EVP_PKEY_free(pkey);
              pkey = key->pkey;
            }
            CRYPTO_add_lock(&pkey->references,1,10,DAT_000b6dc0,0xac);
            return pkey;
          }
          ERR_put_error(0xb,0x77,0x7d,DAT_000b6dc0,0x9a);
        }
        EVP_PKEY_free(pkey);
        return (EVP_PKEY *)0x0;
      }
      ERR_put_error(0xb,0x77,0x41,DAT_000b6dc0,0x8f);
    }
  }
  return (EVP_PKEY *)0x0;
}

