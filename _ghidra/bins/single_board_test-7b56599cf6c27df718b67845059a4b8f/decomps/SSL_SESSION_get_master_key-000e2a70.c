
size_t SSL_SESSION_get_master_key(int param_1,void *param_2,uint param_3)

{
  uint __n;
  
  if (param_3 != 0) {
    __n = *(uint *)(param_1 + 4);
    if (param_3 <= *(uint *)(param_1 + 4)) {
      __n = param_3;
    }
    memcpy(param_2,(void *)(param_1 + 0x48),__n);
    return __n;
  }
  return *(size_t *)(param_1 + 4);
}

