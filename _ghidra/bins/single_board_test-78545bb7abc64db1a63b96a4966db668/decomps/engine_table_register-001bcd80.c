
undefined4
engine_table_register
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
          int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *ptr;
  undefined4 uVar3;
  undefined4 local_38 [5];
  
  CRYPTO_THREAD_write_lock(global_engine_lock);
  if (*param_1 == 0) {
    iVar2 = OPENSSL_LH_new(0x1bcced,0x1bccf1);
    if (iVar2 == 0) {
LAB_001bce80:
      uVar3 = 0;
      goto LAB_001bce82;
    }
    *param_1 = iVar2;
    engine_cleanup_add_first(param_2);
  }
  if (param_5 != 0) {
    do {
      while( true ) {
        local_38[0] = *param_4;
        puVar1 = (undefined4 *)OPENSSL_LH_retrieve(*param_1,local_38);
        if (puVar1 == (undefined4 *)0x0) {
          ptr = (undefined4 *)CRYPTO_malloc(0x10,"crypto/engine/eng_table.c",100);
          if (ptr == (undefined4 *)0x0) goto LAB_001bce80;
          ptr[3] = 1;
          *ptr = *param_4;
          iVar2 = OPENSSL_sk_new_null();
          ptr[1] = iVar2;
          if (iVar2 == 0) {
            CRYPTO_free(ptr);
            uVar3 = 0;
            goto LAB_001bce82;
          }
          ptr[2] = 0;
          OPENSSL_LH_insert(*param_1,ptr);
          puVar1 = (undefined4 *)OPENSSL_LH_retrieve(*param_1,local_38);
          if (ptr != puVar1) {
            uVar3 = 0;
            OPENSSL_sk_free(ptr[1]);
            CRYPTO_free(ptr);
            goto LAB_001bce82;
          }
        }
        OPENSSL_sk_delete_ptr(puVar1[1],param_3);
        iVar2 = OPENSSL_sk_push(puVar1[1],param_3);
        if (iVar2 == 0) goto LAB_001bce80;
        puVar1[3] = 0;
        if (param_6 == 0) break;
        iVar2 = engine_unlocked_init(param_3);
        if (iVar2 == 0) {
          ERR_put_error(0x26,0xb8,0x6d,"crypto/engine/eng_table.c",0x82);
          uVar3 = 0;
          goto LAB_001bce82;
        }
        if (puVar1[2] != 0) {
          engine_unlocked_finish(puVar1[2],0);
        }
        param_5 = param_5 + -1;
        puVar1[2] = param_3;
        param_4 = param_4 + 1;
        puVar1[3] = 1;
        if (param_5 == 0) goto LAB_001bce28;
      }
      param_5 = param_5 + -1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
  }
LAB_001bce28:
  uVar3 = 1;
LAB_001bce82:
  CRYPTO_THREAD_unlock(global_engine_lock);
  return uVar3;
}

