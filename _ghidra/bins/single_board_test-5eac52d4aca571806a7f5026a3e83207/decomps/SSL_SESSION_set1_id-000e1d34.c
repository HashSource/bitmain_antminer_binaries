
undefined4 SSL_SESSION_set1_id(int param_1,void *param_2,size_t param_3)

{
  if (param_3 < 0x21) {
    *(size_t *)(param_1 + 0x148) = param_3;
    if ((void *)(param_1 + 0x14c) != param_2) {
      memcpy((void *)(param_1 + 0x14c),param_2,param_3);
    }
    return 1;
  }
  ERR_put_error(0x14,0x1a7,0x198,"ssl/ssl_sess.c",0x32f);
  return 0;
}

