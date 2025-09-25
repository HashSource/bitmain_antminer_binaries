
int SSL_SESSION_set1_ticket_appdata(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  CRYPTO_free(*(void **)(param_1 + 500));
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  if (param_3 == 0 || param_2 == 0) {
    *(undefined4 *)(param_1 + 500) = 0;
    return 1;
  }
  iVar1 = CRYPTO_memdup(param_2,param_3,"ssl/ssl_sess.c",0x4df,param_4);
  *(int *)(param_1 + 500) = iVar1;
  if (iVar1 != 0) {
    iVar1 = 1;
    *(int *)(param_1 + 0x1f8) = param_3;
  }
  return iVar1;
}

