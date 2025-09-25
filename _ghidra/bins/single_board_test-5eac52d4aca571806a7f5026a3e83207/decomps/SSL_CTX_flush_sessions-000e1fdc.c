
void SSL_CTX_flush_sessions(SSL_CTX *ctx,long tm)

{
  undefined4 uVar1;
  SSL_CTX *local_1c;
  long local_18;
  ulong local_14;
  
  local_14 = ctx->session_cache_size;
  if (local_14 != 0) {
    local_1c = ctx;
    local_18 = tm;
    CRYPTO_THREAD_write_lock(ctx[1].client_CA);
    uVar1 = OPENSSL_LH_get_down_load(ctx->session_cache_size);
    OPENSSL_LH_set_down_load(ctx->session_cache_size,0);
    OPENSSL_LH_doall_arg(local_14,0xe1655,&local_1c);
    OPENSSL_LH_set_down_load(ctx->session_cache_size,uVar1);
    CRYPTO_THREAD_unlock(ctx[1].client_CA);
  }
  return;
}

