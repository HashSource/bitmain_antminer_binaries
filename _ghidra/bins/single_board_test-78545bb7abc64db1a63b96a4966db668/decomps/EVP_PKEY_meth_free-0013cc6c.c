
void EVP_PKEY_meth_free(EVP_PKEY_METHOD *pmeth)

{
  if ((pmeth != (EVP_PKEY_METHOD *)0x0) && (*(int *)(pmeth + 4) << 0x1f < 0)) {
    CRYPTO_free(pmeth);
    return;
  }
  return;
}

