
undefined4 SSL_SESSION_set1_alpn_selected(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  CRYPTO_free(*(void **)(param_1 + 0x1e4));
  if (param_3 == 0 || param_2 == 0) {
    *(undefined4 *)(param_1 + 0x1e4) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    return 1;
  }
  iVar1 = CRYPTO_memdup(param_2,param_3,"ssl/ssl_sess.c",0x3ac,param_4);
  *(int *)(param_1 + 0x1e4) = iVar1;
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x1e8) = param_3;
    return 1;
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  return 0;
}

