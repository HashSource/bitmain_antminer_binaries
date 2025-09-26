
undefined4
ASYNC_start_job(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,void *param_5
               ,size_t param_6)

{
  int iVar1;
  void *ptr;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  
  iVar1 = OPENSSL_init_crypto(0x100,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  ptr = (void *)async_get_ctx();
  if (ptr == (void *)0x0) {
    iVar1 = ossl_init_thread_start(1,0);
    if (iVar1 == 0) {
      return 0;
    }
    ptr = CRYPTO_malloc(0xc,"crypto/async/async.c",0x28);
    if (ptr == (void *)0x0) {
      ERR_put_error(0x33,100,0x41,"crypto/async/async.c",0x2a);
LAB_00114bea:
      CRYPTO_free(ptr);
      return 0;
    }
    *(undefined4 *)((int)ptr + 4) = 0;
    *(undefined4 *)((int)ptr + 8) = 0;
    iVar1 = CRYPTO_THREAD_set_local(&ctxkey,ptr);
    if (iVar1 == 0) goto LAB_00114bea;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar1 = *(int *)((int)ptr + 4);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)CRYPTO_THREAD_get_local(&poolkey);
      if (puVar2 == (undefined4 *)0x0) {
        iVar1 = ASYNC_init_thread(0,0);
        if (iVar1 == 0) goto LAB_00114c36;
        puVar2 = (undefined4 *)CRYPTO_THREAD_get_local(&poolkey);
      }
      iVar1 = OPENSSL_sk_pop(*puVar2);
      if (iVar1 == 0) {
        if ((puVar2[2] == 0) || ((uint)puVar2[1] < (uint)puVar2[2])) {
          pvVar4 = (void *)CRYPTO_zalloc(0x18,"crypto/async/async.c",0x52);
          if (pvVar4 == (void *)0x0) {
            ERR_put_error(0x33,0x66,0x41,"crypto/async/async.c",0x54);
          }
          else {
            *(undefined4 *)((int)pvVar4 + 0x10) = 0;
            CRYPTO_free(*(void **)((int)pvVar4 + 8));
            CRYPTO_free(pvVar4);
          }
        }
LAB_00114c36:
        *(undefined4 *)((int)ptr + 4) = 0;
        return 1;
      }
      *(int *)((int)ptr + 4) = iVar1;
      if (param_5 == (void *)0x0) {
        *(undefined4 *)(iVar1 + 8) = 0;
      }
      else {
        pvVar4 = CRYPTO_malloc(param_6,"crypto/async/async.c",0xe3);
        iVar5 = *(int *)((int)ptr + 4);
        *(void **)(iVar1 + 8) = pvVar4;
        pvVar4 = *(void **)(iVar5 + 8);
        if (pvVar4 == (void *)0x0) {
          ERR_put_error(0x33,0x69,0x41,"crypto/async/async.c",0xe5);
          iVar1 = *(int *)((int)ptr + 4);
          puVar2 = (undefined4 *)CRYPTO_THREAD_get_local(&poolkey);
          CRYPTO_free(*(void **)(iVar1 + 8));
          *(undefined4 *)(iVar1 + 8) = 0;
          OPENSSL_sk_push(*puVar2,iVar1);
          *(undefined4 *)((int)ptr + 4) = 0;
          return 0;
        }
        memcpy(pvVar4,param_5,param_6);
        iVar1 = *(int *)((int)ptr + 4);
      }
      *(undefined4 *)(iVar1 + 4) = param_4;
      *(undefined4 *)(iVar1 + 0x14) = param_2;
      ERR_put_error(0x33,0x69,0x66,"crypto/async/async.c",0xf3);
      goto LAB_00114b7c;
    }
  }
  else {
    *(int *)((int)ptr + 4) = iVar1;
  }
  iVar5 = *(int *)(iVar1 + 0x10);
  if (iVar5 == 3) {
    *param_3 = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0x14) = 0;
    puVar2 = (undefined4 *)CRYPTO_THREAD_get_local(&poolkey);
    CRYPTO_free(*(void **)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 8) = 0;
    OPENSSL_sk_push(*puVar2,iVar1);
    *(undefined4 *)((int)ptr + 4) = 0;
    *param_1 = 0;
    return 3;
  }
  if (iVar5 == 1) {
    *param_1 = iVar1;
    *(undefined4 *)(*(int *)((int)ptr + 4) + 0x10) = 2;
    *(undefined4 *)((int)ptr + 4) = 0;
    return 2;
  }
  if (iVar5 != 2) {
    ERR_put_error(0x33,0x69,0x44,"crypto/async/async.c",0xd7);
    iVar1 = *(int *)((int)ptr + 4);
    puVar2 = (undefined4 *)CRYPTO_THREAD_get_local(&poolkey);
    CRYPTO_free(*(void **)(iVar1 + 8));
    uVar3 = *puVar2;
    *(undefined4 *)(iVar1 + 8) = 0;
    OPENSSL_sk_push(uVar3,iVar1);
    *(undefined4 *)((int)ptr + 4) = 0;
    *param_1 = 0;
    return 0;
  }
  *(int *)((int)ptr + 4) = *param_1;
  ERR_put_error(0x33,0x69,0x66,"crypto/async/async.c",0xd0);
LAB_00114b7c:
  iVar1 = *(int *)((int)ptr + 4);
  puVar2 = (undefined4 *)CRYPTO_THREAD_get_local(&poolkey);
  CRYPTO_free(*(void **)(iVar1 + 8));
  uVar3 = *puVar2;
  *(undefined4 *)(iVar1 + 8) = 0;
  OPENSSL_sk_push(uVar3,iVar1);
  *(undefined4 *)((int)ptr + 4) = 0;
  *param_1 = 0;
  return 0;
}

