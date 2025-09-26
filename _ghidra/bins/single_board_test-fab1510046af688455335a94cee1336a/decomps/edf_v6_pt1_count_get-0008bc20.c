
int edf_v6_pt1_count_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return (uint)*(byte *)((int)ctx->priv + 0x60);
}

