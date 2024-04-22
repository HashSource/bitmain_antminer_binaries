
undefined cnx_needed(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 100) != 1) {
    return 0;
  }
  if ((((1 < pool_strategy - 3U) &&
       (((*(char *)(param_1 + 0x280) == '\0' || (*(char *)(param_1 + 0x61) == '\0')) &&
        (iVar1 = current_pool(), param_1 != iVar1)))) && (*(int *)(param_1 + 0x2dc) == 0)) &&
     ((pool_strategy != 0 || (iVar2 = *(int *)(param_1 + 4), iVar1 = cp_prio(), iVar1 <= iVar2)))) {
    return no_work;
  }
  return 1;
}

