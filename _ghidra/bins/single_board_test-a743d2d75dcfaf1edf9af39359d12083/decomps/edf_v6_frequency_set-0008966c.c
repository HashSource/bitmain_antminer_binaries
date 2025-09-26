
int edf_v6_frequency_set(edf_ctx_p ctx,uint16_t val)

{
  uint16_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint16_t *)((int)ctx->priv + 100) = val;
  return 0;
}

