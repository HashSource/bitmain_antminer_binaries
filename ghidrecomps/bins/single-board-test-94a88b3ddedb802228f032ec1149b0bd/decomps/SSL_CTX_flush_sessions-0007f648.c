
void SSL_CTX_flush_sessions(SSL_CTX *ctx,long tm)

{
  char *file;
  LHASH_DOALL_ARG_FN_TYPE func;
  ulong uVar1;
  SSL_CTX *local_1c;
  long local_18;
  _LHASH *local_14;
  
  local_14 = (_LHASH *)ctx->sessions;
  if (local_14 != (_LHASH *)0x0) {
    local_1c = ctx;
    local_18 = tm;
    CRYPTO_lock(9,0xc,DAT_0007f690,0x45b);
    func = DAT_0007f694;
    uVar1 = local_14->down_load;
    local_14->down_load = 0;
    lh_doall_arg(local_14,func,&local_1c);
    file = DAT_0007f690;
    local_14->down_load = uVar1;
    CRYPTO_lock(10,0xc,file,0x461);
  }
  return;
}

