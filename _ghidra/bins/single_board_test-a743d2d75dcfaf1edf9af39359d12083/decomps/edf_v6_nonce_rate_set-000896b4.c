
int edf_v6_nonce_rate_set(edf_ctx_p ctx,uint16_t val)

{
  uint16_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint16_t *)((int)ctx->priv + 0x66) = val;
  return 0;
}

