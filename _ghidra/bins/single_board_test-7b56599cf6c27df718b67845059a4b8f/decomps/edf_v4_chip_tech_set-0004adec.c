
int edf_v4_chip_tech_set(edf_ctx_p ctx,char *array,size_t *len)

{
  size_t __n;
  size_t *len_local;
  char *array_local;
  edf_ctx_p ctx_local;
  size_t tmp;
  
  __n = *len;
  if (2 < __n) {
    __n = 3;
  }
  memcpy((void *)((int)ctx->priv + 0x3b),array,__n);
  *len = __n;
  return 0;
}

