
int OBJ_NAME_remove(char *name,int type)

{
  int iVar1;
  int *ptr;
  int *piVar2;
  uint local_20 [2];
  char *local_18;
  
  iVar1 = OBJ_NAME_init();
  if (iVar1 == 0) {
    return 0;
  }
  CRYPTO_THREAD_write_lock(obj_lock);
  local_20[0] = type & 0xffff7fff;
  local_18 = name;
  ptr = (int *)OPENSSL_LH_delete(names_lh,local_20);
  piVar2 = ptr;
  if (ptr != (int *)0x0) {
    if (name_funcs_stack != 0) {
      iVar1 = OPENSSL_sk_num();
      if (*ptr < iVar1) {
        iVar1 = OPENSSL_sk_value(name_funcs_stack);
        (**(code **)(iVar1 + 8))(ptr[2],*ptr,ptr[3]);
      }
    }
    piVar2 = (int *)0x1;
    CRYPTO_free(ptr);
  }
  CRYPTO_THREAD_unlock(obj_lock);
  return (int)piVar2;
}

