
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  cert_st *pcVar1;
  int iVar2;
  undefined4 uVar3;
  _func_3296 *p_Var4;
  undefined4 uVar5;
  undefined4 uVar6;
  cert_st *pcVar7;
  
  pcVar7 = ssl->cert;
  if ((SSL_CTX *)ssl->psk_server_callback != ctx) {
    if (ctx == (SSL_CTX *)0x0) {
      ctx = (SSL_CTX *)ssl->tls_session_secret_cb_arg;
    }
    pcVar1 = (cert_st *)ssl_cert_dup(ctx->cert);
    ssl->cert = pcVar1;
    if (pcVar7 != (cert_st *)0x0) {
      if (ssl->server != 0) {
        uVar6 = *(undefined4 *)(pcVar7 + 0x124);
        uVar3 = *(undefined4 *)(pcVar7 + 0x154);
        *(undefined4 *)(pcVar1 + 0x128) = *(undefined4 *)(pcVar7 + 0x128);
        uVar5 = *(undefined4 *)(pcVar7 + 0x158);
        *(undefined4 *)(pcVar1 + 0x124) = uVar6;
        *(undefined4 *)(pcVar1 + 0x154) = uVar3;
        *(undefined4 *)(pcVar1 + 0x158) = uVar5;
        *(undefined4 *)(pcVar7 + 0x124) = 0;
        *(undefined4 *)(pcVar7 + 0x154) = 0;
      }
      ssl_cert_free(pcVar7);
    }
    if (0x20 < ssl->sid_ctx_length) {
      OpenSSLDie(DAT_0007c630,0xc67,DAT_0007c634);
    }
    p_Var4 = ssl->psk_server_callback;
    if (((p_Var4 != (_func_3296 *)0x0) && (ssl->sid_ctx_length == *(size_t *)(p_Var4 + 0xc4))) &&
       (iVar2 = memcmp(ssl->sid_ctx,p_Var4 + 200,ssl->sid_ctx_length), iVar2 == 0)) {
      ssl->sid_ctx_length = ctx->sid_ctx_length;
      uVar3 = *(undefined4 *)(ctx->sid_ctx + 4);
      uVar5 = *(undefined4 *)(ctx->sid_ctx + 8);
      uVar6 = *(undefined4 *)(ctx->sid_ctx + 0xc);
      *(undefined4 *)ssl->sid_ctx = *(undefined4 *)ctx->sid_ctx;
      *(undefined4 *)(ssl->sid_ctx + 4) = uVar3;
      *(undefined4 *)(ssl->sid_ctx + 8) = uVar5;
      *(undefined4 *)(ssl->sid_ctx + 0xc) = uVar6;
      uVar3 = *(undefined4 *)(ctx->sid_ctx + 0x14);
      uVar5 = *(undefined4 *)(ctx->sid_ctx + 0x18);
      uVar6 = *(undefined4 *)(ctx->sid_ctx + 0x1c);
      *(undefined4 *)(ssl->sid_ctx + 0x10) = *(undefined4 *)(ctx->sid_ctx + 0x10);
      *(undefined4 *)(ssl->sid_ctx + 0x14) = uVar3;
      *(undefined4 *)(ssl->sid_ctx + 0x18) = uVar5;
      *(undefined4 *)(ssl->sid_ctx + 0x1c) = uVar6;
    }
    CRYPTO_add_lock(&ctx->references,1,0xc,DAT_0007c630,0xc76);
    p_Var4 = ssl->psk_server_callback;
    if (p_Var4 != (_func_3296 *)0x0) {
      iVar2 = CRYPTO_add_lock((int *)(p_Var4 + 0x60),-1,0xc,DAT_0007c630,0x82a);
      if (iVar2 < 1) {
        SSL_CTX_free_part_5(p_Var4);
      }
    }
    ssl->psk_server_callback = (_func_3296 *)ctx;
  }
  return ctx;
}

