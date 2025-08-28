
void names_lh_free_LHASH_DOALL(uint *param_1)

{
  int *ptr;
  int iVar1;
  void *pvVar2;
  uint local_20 [2];
  uint local_18;
  
  if (param_1 != (uint *)0x0) {
    if (((int)free_type < 0) || (free_type == *param_1)) {
      local_18 = param_1[2];
      if (names_lh != (_LHASH *)0x0) {
        local_20[0] = *param_1 & 0xffff7fff;
        ptr = (int *)lh_delete(names_lh,local_20);
        if (ptr != (int *)0x0) {
          if (name_funcs_stack != (_STACK *)0x0) {
            iVar1 = sk_num(name_funcs_stack);
            if (*ptr < iVar1) {
              pvVar2 = sk_value(name_funcs_stack,*ptr);
              (**(code **)((int)pvVar2 + 8))(ptr[2],*ptr,ptr[3]);
            }
          }
          CRYPTO_free(ptr);
        }
      }
    }
  }
  return;
}

