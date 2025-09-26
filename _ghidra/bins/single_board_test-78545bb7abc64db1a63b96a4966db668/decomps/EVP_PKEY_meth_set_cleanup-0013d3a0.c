
void EVP_PKEY_meth_set_cleanup(EVP_PKEY_METHOD *pmeth,cleanup *cleanup)

{
  *(cleanup **)(pmeth + 0x10) = cleanup;
  return;
}

