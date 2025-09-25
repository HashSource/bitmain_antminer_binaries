
int OBJ_NAME_add(char *name,int type,char *data)

{
  int iVar1;
  uint *ptr;
  int *ptr_00;
  
  iVar1 = OBJ_NAME_init();
  if (iVar1 != 0) {
    ptr = (uint *)CRYPTO_malloc(0x10,"crypto/objects/o_names.c",0xe1);
    if (ptr != (uint *)0x0) {
      *ptr = type & 0xffff7fff;
      ptr[1] = type & 0x8000;
      ptr[2] = (uint)name;
      ptr[3] = (uint)data;
      CRYPTO_THREAD_write_lock(obj_lock);
      ptr_00 = (int *)OPENSSL_LH_insert(names_lh,ptr);
      if (ptr_00 == (int *)0x0) {
        iVar1 = OPENSSL_LH_error(names_lh);
        if (iVar1 == 0) {
          iVar1 = 1;
        }
        else {
          CRYPTO_free(ptr);
          iVar1 = 0;
        }
      }
      else {
        if (name_funcs_stack != 0) {
          iVar1 = OPENSSL_sk_num();
          if (*ptr_00 < iVar1) {
            iVar1 = OPENSSL_sk_value(name_funcs_stack);
            (**(code **)(iVar1 + 8))(ptr_00[2],*ptr_00,ptr_00[3]);
          }
        }
        iVar1 = 1;
        CRYPTO_free(ptr_00);
      }
      CRYPTO_THREAD_unlock(obj_lock);
      return iVar1;
    }
  }
  return 0;
}

