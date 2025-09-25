
void EVP_PKEY_meth_set_decrypt(EVP_PKEY_METHOD *pmeth,decrypt_init *decrypt_init,decrypt *decrypt)

{
  *(decrypt_init **)(pmeth + 0x54) = decrypt_init;
  *(decrypt **)(pmeth + 0x58) = decrypt;
  return;
}

