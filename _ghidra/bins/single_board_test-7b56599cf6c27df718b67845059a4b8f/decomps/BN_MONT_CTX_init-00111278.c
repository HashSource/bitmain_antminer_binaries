
void BN_MONT_CTX_init(BN_MONT_CTX *ctx)

{
  ctx->ri = 0;
  bn_init(&ctx->RR);
  bn_init(&ctx->N);
  bn_init(&ctx->Ni);
  ctx->n0[1] = 0;
  ctx->n0[0] = 0;
  ctx->flags = 0;
  return;
}

