
int edf_v5_test_standard_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return (uint)*(byte *)((int)ctx->priv + 0x6b);
}

