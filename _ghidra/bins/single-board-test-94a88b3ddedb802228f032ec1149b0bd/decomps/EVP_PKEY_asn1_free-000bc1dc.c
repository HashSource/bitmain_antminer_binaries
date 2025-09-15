
void EVP_PKEY_asn1_free(EVP_PKEY_ASN1_METHOD *ameth)

{
  if ((ameth != (EVP_PKEY_ASN1_METHOD *)0x0) && (*(int *)(ameth + 8) << 0x1e < 0)) {
    if (*(void **)(ameth + 0xc) != (void *)0x0) {
      CRYPTO_free(*(void **)(ameth + 0xc));
    }
    if (*(void **)(ameth + 0x10) != (void *)0x0) {
      CRYPTO_free(*(void **)(ameth + 0x10));
    }
    CRYPTO_free(ameth);
    return;
  }
  return;
}

