
void EVP_PKEY_CTX_set_cb(EVP_PKEY_CTX *ctx,undefined1 *cb)

{
  *(undefined1 **)(ctx + 0x1c) = cb;
  return;
}

