
void EVP_PKEY_asn1_free(EVP_PKEY_ASN1_METHOD *ameth)

{
  if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return;
  }
  if (-1 < *(int *)(ameth + 8) << 0x1e) {
    return;
  }
  CRYPTO_free(*(void **)(ameth + 0xc));
  CRYPTO_free(*(void **)(ameth + 0x10));
  CRYPTO_free(ameth);
  return;
}

