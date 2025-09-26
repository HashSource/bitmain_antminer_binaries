
void EVP_PKEY_meth_set_sign(EVP_PKEY_METHOD *pmeth,sign_init *sign_init,sign *sign)

{
  *(sign_init **)(pmeth + 0x24) = sign_init;
  *(sign **)(pmeth + 0x28) = sign;
  return;
}

