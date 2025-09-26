
int edf_v4_pcb_temp_in_set(edf_ctx_p ctx,int8_t val)

{
  int8_t val_local;
  edf_ctx_p ctx_local;
  
  *(int8_t *)((int)ctx->priv + 0x68) = val;
  return 0;
}

