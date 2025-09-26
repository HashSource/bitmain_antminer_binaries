
int edf_v5_board_name_get(edf_ctx_p ctx,char *array,size_t *len)

{
  size_t __n;
  size_t *len_local;
  char *array_local;
  edf_ctx_p ctx_local;
  size_t tmp;
  
  __n = *len;
  if (8 < __n) {
    __n = 9;
  }
  memcpy(array,(void *)((int)ctx->priv + 0x3e),__n);
  *len = __n;
  return 0;
}

