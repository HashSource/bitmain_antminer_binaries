
int OBJ_NAME_new_index(hash_func *hash_func,cmp_func *cmp_func,free_func *free_func)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = OBJ_NAME_init();
  if (iVar1 == 0) {
    return 0;
  }
  CRYPTO_THREAD_write_lock(obj_lock);
  if (name_funcs_stack == 0) {
    CRYPTO_mem_ctrl(3);
    name_funcs_stack = OPENSSL_sk_new_null();
    CRYPTO_mem_ctrl(2);
    iVar1 = name_funcs_stack;
    if (name_funcs_stack == 0) goto LAB_0013df2a;
  }
  iVar1 = names_type_num;
  names_type_num = names_type_num + 1;
  iVar2 = OPENSSL_sk_num();
  if (iVar2 < names_type_num) {
    do {
      iVar2 = iVar2 + 1;
      CRYPTO_mem_ctrl(3);
      puVar4 = (undefined4 *)CRYPTO_zalloc(0xc,"crypto/objects/o_names.c",0x70);
      CRYPTO_mem_ctrl(2);
      if (puVar4 == (undefined4 *)0x0) {
        ERR_put_error(8,0x6a,0x41,"crypto/objects/o_names.c",0x73);
        iVar1 = 0;
        goto LAB_0013df2a;
      }
      *puVar4 = 0x1337bd;
      puVar4[1] = strcasecmp;
      CRYPTO_mem_ctrl(3);
      iVar3 = OPENSSL_sk_push(name_funcs_stack,puVar4);
      CRYPTO_mem_ctrl(2);
      if (iVar3 == 0) {
        ERR_put_error(8,0x6a,0x41,"crypto/objects/o_names.c",0x7f);
        CRYPTO_free(puVar4);
        iVar1 = 0;
        goto LAB_0013df2a;
      }
    } while (iVar2 < names_type_num);
  }
  puVar4 = (undefined4 *)OPENSSL_sk_value(name_funcs_stack,iVar1);
  if (hash_func != (hash_func *)0x0) {
    *puVar4 = hash_func;
  }
  if (cmp_func != (cmp_func *)0x0) {
    puVar4[1] = cmp_func;
  }
  if (free_func != (free_func *)0x0) {
    puVar4[2] = free_func;
  }
LAB_0013df2a:
  CRYPTO_THREAD_unlock(obj_lock);
  return iVar1;
}

