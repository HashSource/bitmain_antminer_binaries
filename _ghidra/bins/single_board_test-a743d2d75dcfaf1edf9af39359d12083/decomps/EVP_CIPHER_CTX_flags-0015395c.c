
ulong EVP_CIPHER_CTX_flags(EVP_CIPHER_CTX *ctx)

{
  return ctx->cipher->flags;
}

