
void EVP_PKEY_meth_set_paramgen
               (EVP_PKEY_METHOD *pmeth,paramgen_init *paramgen_init,paramgen *paramgen)

{
  *(paramgen_init **)(pmeth + 0x14) = paramgen_init;
  *(paramgen **)(pmeth + 0x18) = paramgen;
  return;
}

