
void EVP_PKEY_meth_set_init(EVP_PKEY_METHOD *pmeth,init *init)

{
  *(init **)(pmeth + 8) = init;
  return;
}

