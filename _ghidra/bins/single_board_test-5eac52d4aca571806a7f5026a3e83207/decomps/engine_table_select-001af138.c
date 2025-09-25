
int engine_table_select(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28 [4];
  
  if (*param_1 == 0) {
    iVar2 = 0;
  }
  else {
    ERR_set_mark();
    CRYPTO_THREAD_write_lock(global_engine_lock);
    if ((*param_1 == 0) ||
       (local_28[0] = param_2, iVar1 = OPENSSL_LH_retrieve(*param_1,local_28), iVar1 == 0)) {
      iVar2 = 0;
    }
    else if (((*(int *)(iVar1 + 8) == 0) || (iVar2 = engine_unlocked_init(), iVar2 == 0)) &&
            (*(int *)(iVar1 + 0xc) == 0)) {
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 1;
        iVar2 = OPENSSL_sk_value(*(undefined4 *)(iVar1 + 4),iVar3);
        if (iVar2 == 0) goto LAB_001af1d4;
        iVar3 = iVar4;
      } while (((*(int *)(iVar2 + 0x54) < 1) && (table_flags << 0x1f < 0)) ||
              (iVar4 = engine_unlocked_init(), iVar4 == 0));
      if ((iVar2 != *(int *)(iVar1 + 8)) && (iVar3 = engine_unlocked_init(iVar2), iVar3 != 0)) {
        if (*(int *)(iVar1 + 8) != 0) {
          engine_unlocked_finish(*(int *)(iVar1 + 8),0);
        }
        *(int *)(iVar1 + 8) = iVar2;
      }
LAB_001af1d4:
      *(undefined4 *)(iVar1 + 0xc) = 1;
    }
    else {
      iVar2 = *(int *)(iVar1 + 8);
      *(undefined4 *)(iVar1 + 0xc) = 1;
    }
    CRYPTO_THREAD_unlock(global_engine_lock);
    ERR_pop_to_mark();
  }
  return iVar2;
}

