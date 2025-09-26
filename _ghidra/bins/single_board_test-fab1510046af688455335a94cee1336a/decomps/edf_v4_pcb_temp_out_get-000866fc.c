
int edf_v4_pcb_temp_out_get(edf_ctx_p ctx)

{
  edf_ctx_p ctx_local;
  
  return (int)*(char *)((int)ctx->priv + 0x69);
}

