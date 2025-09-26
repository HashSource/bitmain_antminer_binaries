
undefined4
engine_table_register
          (int *param_1,undefined4 param_2,void *param_3,undefined4 *param_4,int param_5,int param_6
          )

{
  undefined4 *ptr;
  int iVar1;
  _STACK *p_Var2;
  _LHASH *p_Var3;
  undefined4 uVar4;
  undefined4 local_38 [5];
  
  CRYPTO_lock(9,0x1e,"eng_table.c",0x8a);
  if (*param_1 == 0) {
    p_Var3 = lh_new((LHASH_HASH_FN_TYPE)0x19dad9,(LHASH_COMP_FN_TYPE)0x19dadd);
    if (p_Var3 == (_LHASH *)0x0) {
LAB_0019dc1c:
      uVar4 = 0;
      goto LAB_0019dc1e;
    }
    *param_1 = (int)p_Var3;
    engine_cleanup_add_first(param_2);
  }
  if (param_5 != 0) {
    do {
      while( true ) {
        local_38[0] = *param_4;
        ptr = (undefined4 *)lh_retrieve((_LHASH *)*param_1,local_38);
        if (ptr == (undefined4 *)0x0) {
          ptr = (undefined4 *)CRYPTO_malloc(0x10,"eng_table.c",0x96);
          if (ptr == (undefined4 *)0x0) goto LAB_0019dc1c;
          ptr[3] = 1;
          *ptr = *param_4;
          p_Var2 = sk_new_null();
          ptr[1] = p_Var2;
          if (p_Var2 == (_STACK *)0x0) {
            CRYPTO_free(ptr);
            uVar4 = 0;
            goto LAB_0019dc1e;
          }
          ptr[2] = 0;
          lh_insert((_LHASH *)*param_1,ptr);
        }
        sk_delete_ptr((_STACK *)ptr[1],param_3);
        iVar1 = sk_push((_STACK *)ptr[1],param_3);
        if (iVar1 == 0) goto LAB_0019dc1c;
        ptr[3] = 0;
        if (param_6 == 0) break;
        iVar1 = engine_unlocked_init(param_3);
        if (iVar1 == 0) {
          ERR_put_error(0x26,0xb8,0x6d,"eng_table.c",0xaf);
          uVar4 = 0;
          goto LAB_0019dc1e;
        }
        if (ptr[2] != 0) {
          engine_unlocked_finish(ptr[2],0);
        }
        param_5 = param_5 + -1;
        ptr[2] = param_3;
        ptr[3] = 1;
        param_4 = param_4 + 1;
        if (param_5 == 0) goto LAB_0019dbe4;
      }
      param_5 = param_5 + -1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
  }
LAB_0019dbe4:
  uVar4 = 1;
LAB_0019dc1e:
  CRYPTO_lock(10,0x1e,"eng_table.c",0xbb);
  return uVar4;
}

