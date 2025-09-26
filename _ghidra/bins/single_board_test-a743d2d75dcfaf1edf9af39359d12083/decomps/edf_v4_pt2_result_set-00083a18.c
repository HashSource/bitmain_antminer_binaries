
int edf_v4_pt2_result_set(edf_ctx_p ctx,uint8_t val)

{
  uint8_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint8_t *)((int)ctx->priv + 0x6c) = val;
  return 0;
}

