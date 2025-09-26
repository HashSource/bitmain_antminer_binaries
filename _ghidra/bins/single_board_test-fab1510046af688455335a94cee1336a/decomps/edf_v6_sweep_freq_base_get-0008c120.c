
int edf_v6_sweep_freq_base_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return (uint)*(ushort *)((int)ctx->priv + 0x74);
}

