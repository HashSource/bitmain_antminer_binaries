
void BN_MONT_CTX_init(BN_MONT_CTX *ctx)

{
  ctx->ri = 0;
  BN_init(&ctx->RR);
  BN_init(&ctx->N);
  BN_init(&ctx->Ni);
  ctx->n0[1] = 0;
  ctx->n0[0] = 0;
  ctx->flags = 0;
  return;
}

