
undefined4 SSL_SESSION_set1_master_key(int param_1,void *param_2,size_t param_3)

{
  if (0x100 < param_3) {
    return 0;
  }
  memcpy((void *)(param_1 + 0x48),param_2,param_3);
  *(size_t *)(param_1 + 4) = param_3;
  return 1;
}

