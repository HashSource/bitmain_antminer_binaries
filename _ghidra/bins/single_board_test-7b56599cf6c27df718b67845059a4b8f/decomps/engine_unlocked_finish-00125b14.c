
int engine_unlocked_finish(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x54) + -1;
  *(int *)(param_1 + 0x54) = iVar2;
  if ((iVar2 == 0) && (*(code **)(param_1 + 0x34) != (code *)0x0)) {
    if (param_2 == 0) {
      iVar2 = (**(code **)(param_1 + 0x34))();
    }
    else {
      CRYPTO_THREAD_unlock(global_engine_lock);
      iVar2 = (**(code **)(param_1 + 0x34))(param_1);
      CRYPTO_THREAD_write_lock(global_engine_lock);
    }
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = engine_free_util(param_1,0);
  }
  else {
    iVar1 = engine_free_util(param_1,0);
    iVar2 = 1;
  }
  if (iVar1 != 0) {
    return iVar2;
  }
  ERR_put_error(0x26,0xbf,0x6a,"crypto/engine/eng_init.c",0x46);
  return 0;
}

