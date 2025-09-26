
int edf_v5_test_standard_set(edf_ctx_p ctx,uint8_t val)

{
  uint8_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint8_t *)((int)ctx->priv + 0x6b) = val;
  return 0;
}

