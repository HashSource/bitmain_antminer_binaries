
int OBJ_NAME_new_index(hash_func *hash_func,cmp_func *cmp_func,free_func *free_func)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (name_funcs_stack == (_STACK *)0x0) {
    CRYPTO_mem_ctrl(3);
    name_funcs_stack = sk_new_null();
    CRYPTO_mem_ctrl(2);
    if (name_funcs_stack == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar1 = names_type_num;
  names_type_num = names_type_num + 1;
  iVar2 = sk_num(name_funcs_stack);
  if (iVar2 < names_type_num) {
    do {
      iVar2 = iVar2 + 1;
      CRYPTO_mem_ctrl(3);
      puVar3 = (undefined4 *)CRYPTO_malloc(0xc,"o_names.c",0x57);
      CRYPTO_mem_ctrl(2);
      if (puVar3 == (undefined4 *)0x0) {
        ERR_put_error(8,0x6a,0x41,"o_names.c",0x5a);
        return 0;
      }
      puVar3[2] = 0;
      *puVar3 = 0x14f3d5;
      puVar3[1] = strcmp;
      CRYPTO_mem_ctrl(3);
      sk_push(name_funcs_stack,puVar3);
      CRYPTO_mem_ctrl(2);
    } while (iVar2 < names_type_num);
  }
  puVar3 = (undefined4 *)sk_value(name_funcs_stack,iVar1);
  if (hash_func != (hash_func *)0x0) {
    *puVar3 = hash_func;
  }
  if (cmp_func != (cmp_func *)0x0) {
    puVar3[1] = cmp_func;
  }
  if (free_func != (free_func *)0x0) {
    puVar3[2] = free_func;
  }
  return iVar1;
}

