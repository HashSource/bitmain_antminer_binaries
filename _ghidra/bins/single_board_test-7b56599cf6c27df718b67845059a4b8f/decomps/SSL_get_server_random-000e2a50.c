
size_t SSL_get_server_random(int param_1,void *param_2,size_t param_3)

{
  if (param_3 == 0) {
    return 0x20;
  }
  if (0x1f < param_3) {
    param_3 = 0x20;
  }
  memcpy(param_2,(void *)(*(int *)(param_1 + 0x7c) + 0x8c),param_3);
  return param_3;
}

