
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int local_30;
  size_t local_2c;
  void *local_28;
  int local_24 [2];
  undefined1 *local_1c;
  
  local_30 = type;
  uVar2 = lh_num_items(names_lh);
  local_28 = CRYPTO_malloc(uVar2 << 2,"o_names.c",0x13a);
  if (local_28 != (void *)0x0) {
    local_24[1] = 0x8bad1;
    local_2c = 0;
    local_24[0] = type;
    local_1c = (undefined1 *)&local_30;
    lh_doall_arg(names_lh,(LHASH_DOALL_ARG_FN_TYPE)0x8babd,local_24);
    qsort(local_28,local_2c,4,(__compar_fn_t)0x8ba3d);
    if (0 < (int)local_2c) {
      iVar3 = 0;
      do {
        iVar1 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        (*fn)(*(OBJ_NAME **)((int)local_28 + iVar1),arg);
      } while (iVar3 < (int)local_2c);
    }
    CRYPTO_free(local_28);
  }
  return;
}

