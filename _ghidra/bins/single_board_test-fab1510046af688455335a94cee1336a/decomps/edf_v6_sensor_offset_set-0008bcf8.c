
int edf_v6_sensor_offset_set(edf_ctx_p ctx,uint8_t *array,size_t *len)

{
  size_t __n;
  size_t *len_local;
  uint8_t *array_local;
  edf_ctx_p ctx_local;
  size_t tmp;
  
  __n = *len;
  if (5 < __n) {
    __n = 6;
  }
  memcpy((void *)((int)ctx->priv + 0x35),array,__n);
  *len = __n;
  return 0;
}

