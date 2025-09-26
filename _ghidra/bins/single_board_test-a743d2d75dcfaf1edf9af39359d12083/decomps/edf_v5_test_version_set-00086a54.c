
int edf_v5_test_version_set(edf_ctx_p ctx,uint8_t val)

{
  uint8_t val_local;
  edf_ctx_p ctx_local;
  
  *(uint8_t *)((int)ctx->priv + 0x6a) = val;
  return 0;
}

