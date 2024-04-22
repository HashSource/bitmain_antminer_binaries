
EVP_PKEY * EVP_PKEY_CTX_get0_peerkey(EVP_PKEY_CTX *ctx)

{
  return *(EVP_PKEY **)(ctx + 0xc);
}

