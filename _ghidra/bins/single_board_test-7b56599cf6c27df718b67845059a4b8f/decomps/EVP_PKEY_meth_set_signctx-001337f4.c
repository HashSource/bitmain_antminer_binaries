
void EVP_PKEY_meth_set_signctx(EVP_PKEY_METHOD *pmeth,signctx_init *signctx_init,signctx *signctx)

{
  *(signctx_init **)(pmeth + 0x3c) = signctx_init;
  *(signctx **)(pmeth + 0x40) = signctx;
  return;
}

