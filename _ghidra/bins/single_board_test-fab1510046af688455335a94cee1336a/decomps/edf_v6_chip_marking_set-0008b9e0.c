
int edf_v6_chip_marking_set(edf_ctx_p ctx,char *array,size_t *len)

{
  size_t __n;
  size_t *len_local;
  char *array_local;
  edf_ctx_p ctx_local;
  size_t tmp;
  
  __n = *len;
  if (0xd < __n) {
    __n = 0xe;
  }
  memcpy((void *)((int)ctx->priv + 0x17),array,__n);
  *len = __n;
  return 0;
}

