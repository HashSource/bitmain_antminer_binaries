
void EVP_PKEY_meth_set_copy(EVP_PKEY_METHOD *pmeth,copy *copy)

{
  *(copy **)(pmeth + 0xc) = copy;
  return;
}

