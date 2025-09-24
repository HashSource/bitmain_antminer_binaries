
void engine_remove_dynamic_id(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
    if ((param_2 != 0) && (iVar2 = CRYPTO_THREAD_write_lock(global_engine_lock), iVar2 == 0)) {
      return;
    }
    iVar2 = *(int *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x6c) = 0;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 100) = *(undefined4 *)(param_1 + 100);
    }
    iVar1 = *(int *)(param_1 + 100);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x68) = iVar2;
    }
    if (param_1 == engine_dyn_list_head) {
      engine_dyn_list_head = *(int *)(param_1 + 0x68);
    }
    if (param_1 == engine_dyn_list_tail) {
      engine_dyn_list_tail = iVar1;
    }
    if (param_2 != 0) {
      CRYPTO_THREAD_unlock(global_engine_lock);
      return;
    }
  }
  return;
}

