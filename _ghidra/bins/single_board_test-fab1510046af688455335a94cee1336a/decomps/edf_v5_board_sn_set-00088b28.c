
int edf_v5_board_sn_set(edf_ctx_p ctx,char *array,size_t *len)

{
  size_t __n;
  size_t *len_local;
  char *array_local;
  edf_ctx_p ctx_local;
  size_t tmp;
  
  __n = *len;
  if (0x11 < __n) {
    __n = 0x12;
  }
  memcpy((void *)((int)ctx->priv + 2),array,__n);
  *len = __n;
  return 0;
}

