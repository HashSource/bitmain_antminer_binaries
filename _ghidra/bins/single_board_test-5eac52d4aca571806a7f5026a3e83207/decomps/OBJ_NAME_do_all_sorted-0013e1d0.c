
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  int iVar1;
  int iVar2;
  int local_1c;
  size_t local_18;
  void *local_14;
  
  local_1c = type;
  iVar2 = OPENSSL_LH_num_items(names_lh);
  local_14 = CRYPTO_malloc(iVar2 << 2,"crypto/objects/o_names.c",0x166);
  if (local_14 != (void *)0x0) {
    iVar2 = 0;
    local_18 = 0;
    OBJ_NAME_do_all(type,(fn *)0x13dded,&local_1c);
    qsort(local_14,local_18,4,(__compar_fn_t)0x13ddd1);
    if (0 < (int)local_18) {
      do {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        (*fn)(*(OBJ_NAME **)((int)local_14 + iVar1),arg);
      } while (iVar2 < (int)local_18);
    }
    CRYPTO_free(local_14);
  }
  return;
}

