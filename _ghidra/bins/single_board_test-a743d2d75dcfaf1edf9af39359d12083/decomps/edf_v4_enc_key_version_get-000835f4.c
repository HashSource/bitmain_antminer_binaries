
int edf_v4_enc_key_version_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return *(byte *)((int)ctx->priv + 1) & 0xf;
}

