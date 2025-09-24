
bool ASYNC_WAIT_CTX_set_wait_fd
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x1c,"crypto/async/async_wait.c",0x32);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x33,0x6a,0x41,"crypto/async/async_wait.c",0x33);
  }
  else {
    iVar2 = param_1[1];
    iVar3 = *param_1;
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[3] = param_5;
    puVar1[4] = 1;
    puVar1[6] = iVar3;
    param_1[1] = iVar2 + 1;
    *param_1 = (int)puVar1;
  }
  return puVar1 != (undefined4 *)0x0;
}

