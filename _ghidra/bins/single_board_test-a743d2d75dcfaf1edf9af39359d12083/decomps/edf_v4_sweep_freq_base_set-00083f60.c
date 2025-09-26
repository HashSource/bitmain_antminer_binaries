
int edf_v4_sweep_freq_base_set(edf_ctx_p ctx,uint16_t val)

{
  uint16_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint16_t *)((int)ctx->priv + 0x74) = val;
  return 0;
}

