
int edf_v4_enc_algorithm_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return (uint)(*(byte *)((int)ctx->priv + 1) >> 4);
}

