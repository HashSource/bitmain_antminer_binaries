
int edf_v5_sweep_freq_step_set(edf_ctx_p ctx,uint8_t val)

{
  uint8_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint8_t *)((int)ctx->priv + 0x76) = val;
  return 0;
}

