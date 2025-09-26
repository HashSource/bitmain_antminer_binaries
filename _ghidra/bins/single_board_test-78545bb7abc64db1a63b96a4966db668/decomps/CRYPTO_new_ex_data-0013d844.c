
int CRYPTO_new_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined1 *ptr;
  int iVar9;
  int iVar10;
  undefined1 *local_58;
  undefined1 local_50 [44];
  
  if (0xf < (uint)class_index) {
    ERR_put_error(0xf,0x71,7,"crypto/ex_data.c",0x37);
    return 0;
  }
  iVar1 = CRYPTO_THREAD_run_once(&ex_data_init,0x13d52d);
  if ((iVar1 == 0) || (do_ex_data_init_ossl_ret_ == 0)) {
    ERR_put_error(0xf,0x71,0x41,"crypto/ex_data.c",0x3c);
    return 0;
  }
  if (ex_data_lock == 0) {
    return 0;
  }
  iVar6 = class_index * 4;
  ptr = (undefined1 *)0x0;
  CRYPTO_THREAD_write_lock();
  ad->sk = (stack_st_void *)0x0;
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(ex_data + iVar6));
  if (iVar1 < 1) {
    CRYPTO_THREAD_unlock(ex_data_lock);
    goto LAB_0013d9a2;
  }
  if (iVar1 < 10) {
    puVar4 = local_50;
    if (8 < iVar1) goto LAB_0013d8b8;
  }
  else {
    puVar4 = (undefined1 *)CRYPTO_malloc(iVar1 * 4,"crypto/ex_data.c",0xe2);
    if (puVar4 == (undefined1 *)0x0) {
      CRYPTO_THREAD_unlock(ex_data_lock);
      ERR_put_error(0xf,0x70,0x41,"crypto/ex_data.c",0xea);
      return 0;
    }
LAB_0013d8b8:
    ptr = (undefined1 *)0x0;
    puVar7 = puVar4 + 0x28;
    iVar9 = 1;
    do {
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr);
      *(undefined4 *)(puVar7 + -0x28) = uVar2;
      iVar10 = iVar9 + 8;
      HintPreloadData(puVar7);
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),iVar9);
      *(undefined4 *)(puVar7 + -0x24) = uVar2;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr + 2);
      *(undefined4 *)(puVar7 + -0x20) = uVar2;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr + 3);
      *(undefined4 *)(puVar7 + -0x1c) = uVar2;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr + 4);
      *(undefined4 *)(puVar7 + -0x18) = uVar2;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr + 5);
      *(undefined4 *)(puVar7 + -0x14) = uVar2;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr + 6);
      puVar5 = ptr + 7;
      *(undefined4 *)(puVar7 + -0x10) = uVar2;
      ptr = ptr + 8;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),puVar5);
      *(undefined4 *)(puVar7 + -0xc) = uVar2;
      puVar7 = puVar7 + 0x20;
      iVar9 = iVar10;
    } while (iVar10 < iVar1 + -7);
  }
  local_58 = local_50;
  puVar8 = (undefined4 *)(puVar4 + (int)ptr * 4);
  do {
    puVar7 = ptr + 1;
    uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar6),ptr);
    *puVar8 = uVar2;
    ptr = puVar7;
    puVar8 = puVar8 + 1;
  } while ((int)puVar7 < iVar1);
  iVar6 = 0;
  CRYPTO_THREAD_unlock(ex_data_lock);
  do {
    if ((*(int *)(puVar4 + iVar6 * 4) != 0) && (*(int *)(*(int *)(puVar4 + iVar6 * 4) + 8) != 0)) {
      pvVar3 = CRYPTO_get_ex_data(ad,iVar6);
      puVar8 = *(undefined4 **)(puVar4 + iVar6 * 4);
      (*(code *)puVar8[2])(obj,pvVar3,ad,iVar6,*puVar8,puVar8[1]);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < iVar1);
  ptr = puVar4;
  if (puVar4 == local_58) {
    return 1;
  }
LAB_0013d9a2:
  CRYPTO_free(ptr);
  return 1;
}

