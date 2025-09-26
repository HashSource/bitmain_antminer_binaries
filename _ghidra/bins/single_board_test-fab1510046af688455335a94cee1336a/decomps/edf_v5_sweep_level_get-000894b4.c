
int edf_v5_sweep_level_get(edf_ctx_p ctx,uint8_t *array,size_t *len)

{
  size_t __n;
  size_t *len_local;
  uint8_t *array_local;
  edf_ctx_p ctx_local;
  size_t tmp;
  
  __n = *len;
  if (0x7f < __n) {
    __n = 0x80;
  }
  memcpy(array,(void *)((int)ctx->priv + 0x77),__n);
  *len = __n;
  return 0;
}

