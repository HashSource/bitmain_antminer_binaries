
int SSL_CTX_set_ssl_version(SSL_CTX *ctx,SSL_METHOD *meth)

{
  int iVar1;
  
  ctx->method = meth;
  iVar1 = SSL_CTX_set_ciphersuites
                    (ctx,
                     "TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_GCM_SHA256");
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xaa,0xe6,"ssl/ssl_lib.c",0x297);
    return 0;
  }
  iVar1 = ssl_create_cipher_list
                    (ctx->method,ctx->cert_store,&ctx->cipher_list,&ctx->cipher_list_by_id,
                     "ALL:!COMPLEMENTOFDEFAULT:!eNULL",ctx->verify_mode);
  if ((iVar1 != 0) && (iVar1 = OPENSSL_sk_num(), 0 < iVar1)) {
    return 1;
  }
  ERR_put_error(0x14,0xaa,0xe6,"ssl/ssl_lib.c",0x2a0);
  return 0;
}

