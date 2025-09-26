
int edf_v4_nonce_rate_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return (uint)*(ushort *)((int)ctx->priv + 0x66);
}

