
int edf_v4_enc_algorithm_set(edf_ctx_p ctx,uint8_t val)

{
  uint8_t val_local;
  edf_ctx_p ctx_local;
  
  *(byte *)((int)ctx->priv + 1) = *(byte *)((int)ctx->priv + 1) & 0xf;
  *(byte *)((int)ctx->priv + 1) = val << 4 | *(byte *)((int)ctx->priv + 1);
  return 0;
}

