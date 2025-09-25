
undefined4 engine_add_dynamic_id(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x6c) == 0 && param_2 == 0)) ||
     ((param_3 != 0 && (iVar1 = CRYPTO_THREAD_write_lock(global_engine_lock), iVar1 == 0)))) {
    return 0;
  }
  iVar1 = engine_dyn_list_head;
  if (param_2 == 0) {
LAB_00121e38:
    if (iVar1 == 0) {
      if (engine_dyn_list_tail == 0) {
        engine_dyn_list_head = param_1;
        *(undefined4 *)(param_1 + 100) = 0;
        goto LAB_00121e4e;
      }
    }
    else if ((engine_dyn_list_tail != 0) && (*(int *)(engine_dyn_list_tail + 0x68) == 0)) {
      *(int *)(engine_dyn_list_tail + 0x68) = param_1;
      *(int *)(param_1 + 100) = engine_dyn_list_tail;
LAB_00121e4e:
      uVar4 = 1;
      *(undefined4 *)(param_1 + 0x68) = 0;
      engine_dyn_list_tail = param_1;
      goto joined_r0x00121e5c;
    }
  }
  else if (engine_dyn_list_head == 0) {
LAB_00121e00:
    if (*(int *)(param_1 + 0x6c) == 0) {
      *(int *)(param_1 + 0x6c) = param_2;
      goto LAB_00121e38;
    }
  }
  else {
    iVar2 = *(int *)(engine_dyn_list_head + 0x6c);
    iVar3 = engine_dyn_list_head;
    while (param_2 != iVar2) {
      iVar3 = *(int *)(iVar3 + 0x60);
      if (iVar3 == 0) goto LAB_00121e00;
      iVar2 = *(int *)(iVar3 + 0x6c);
    }
  }
  uVar4 = 0;
joined_r0x00121e5c:
  if (param_3 == 0) {
    return uVar4;
  }
  CRYPTO_THREAD_unlock(global_engine_lock);
  return uVar4;
}

