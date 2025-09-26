
int edf_v6_pt1_count_set(edf_ctx_p ctx,uint8_t val)

{
  uint8_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint8_t *)((int)ctx->priv + 0x60) = val;
  return 0;
}

