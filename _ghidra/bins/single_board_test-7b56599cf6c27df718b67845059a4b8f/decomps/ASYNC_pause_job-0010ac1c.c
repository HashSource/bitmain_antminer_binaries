
undefined4 ASYNC_pause_job(void)

{
  int iVar1;
  
  iVar1 = async_get_ctx();
  if (((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) && (*(int *)(iVar1 + 8) == 0)) {
    *(undefined4 *)(*(int *)(iVar1 + 4) + 0x10) = 1;
    ERR_put_error(0x33,0x67,0x66,"crypto/async/async.c",0x113);
    return 0;
  }
  return 1;
}

