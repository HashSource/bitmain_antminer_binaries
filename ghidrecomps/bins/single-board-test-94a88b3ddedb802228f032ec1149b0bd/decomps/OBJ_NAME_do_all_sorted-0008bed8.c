
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int local_30;
  size_t local_2c;
  void *local_28;
  int local_24;
  undefined4 local_20;
  int *local_1c;
  
  iVar3 = DAT_0008bf50;
  local_30 = type;
  uVar2 = lh_num_items(*(_LHASH **)(DAT_0008bf50 + 8));
  local_28 = CRYPTO_malloc(uVar2 << 2,DAT_0008bf54,0x13a);
  if (local_28 != (void *)0x0) {
    local_20 = DAT_0008bf58;
    local_2c = 0;
    local_24 = type;
    local_1c = &local_30;
    lh_doall_arg(*(_LHASH **)(iVar3 + 8),DAT_0008bf5c,&local_24);
    qsort(local_28,local_2c,4,DAT_0008bf60);
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

