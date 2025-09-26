
void CRYPTO_free_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined1 *ptr;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  undefined1 *local_58;
  undefined1 local_50 [44];
  
  if (0xf < (uint)class_index) {
    ERR_put_error(0xf,0x71,7,"crypto/ex_data.c",0x37);
    goto LAB_0013de22;
  }
  iVar1 = CRYPTO_THREAD_run_once(&ex_data_init,0x13d52d);
  if ((iVar1 == 0) || (do_ex_data_init_ossl_ret_ == 0)) {
    ERR_put_error(0xf,0x71,0x41,"crypto/ex_data.c",0x3c);
    goto LAB_0013de22;
  }
  if (ex_data_lock == 0) goto LAB_0013de22;
  iVar5 = class_index * 4;
  CRYPTO_THREAD_write_lock();
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(ex_data + iVar5));
  if (iVar1 < 1) {
    ptr = (undefined1 *)0x0;
    CRYPTO_THREAD_unlock(ex_data_lock);
  }
  else if (iVar1 < 10) {
    ptr = local_50;
    if (iVar1 < 9) {
      iVar6 = 0;
    }
    else {
LAB_0013dd2c:
      iVar6 = 0;
      puVar7 = ptr + 0x28;
      iVar4 = 1;
      do {
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6);
        *(undefined4 *)(puVar7 + -0x28) = uVar2;
        iVar10 = iVar4 + 8;
        HintPreloadData(puVar7);
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar4);
        *(undefined4 *)(puVar7 + -0x24) = uVar2;
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6 + 2);
        *(undefined4 *)(puVar7 + -0x20) = uVar2;
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6 + 3);
        *(undefined4 *)(puVar7 + -0x1c) = uVar2;
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6 + 4);
        *(undefined4 *)(puVar7 + -0x18) = uVar2;
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6 + 5);
        *(undefined4 *)(puVar7 + -0x14) = uVar2;
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6 + 6);
        iVar4 = iVar6 + 7;
        *(undefined4 *)(puVar7 + -0x10) = uVar2;
        iVar6 = iVar6 + 8;
        uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar4);
        *(undefined4 *)(puVar7 + -0xc) = uVar2;
        puVar7 = puVar7 + 0x20;
        iVar4 = iVar10;
      } while (iVar10 < iVar1 + -7);
    }
    local_58 = local_50;
    puVar8 = (undefined4 *)(ptr + iVar6 * 4);
    do {
      iVar4 = iVar6 + 1;
      uVar2 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6);
      *puVar8 = uVar2;
      iVar6 = iVar4;
      puVar8 = puVar8 + 1;
    } while (iVar4 < iVar1);
    piVar9 = (int *)(ptr + -4);
    iVar5 = 0;
    CRYPTO_THREAD_unlock(ex_data_lock);
    do {
      piVar9 = piVar9 + 1;
      puVar8 = (undefined4 *)*piVar9;
      if ((puVar8 != (undefined4 *)0x0) && (puVar8[3] != 0)) {
        pvVar3 = CRYPTO_get_ex_data(ad,iVar5);
        (*(code *)puVar8[3])(obj,pvVar3,ad,iVar5,*puVar8,puVar8[1]);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != iVar1);
    if (ptr == local_58) goto LAB_0013de22;
  }
  else {
    ptr = (undefined1 *)CRYPTO_malloc(iVar1 * 4,"crypto/ex_data.c",0x151);
    if (ptr != (undefined1 *)0x0) goto LAB_0013dd2c;
    CRYPTO_THREAD_unlock(ex_data_lock);
    iVar6 = 0;
    do {
      CRYPTO_THREAD_write_lock(ex_data_lock);
      puVar8 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar6);
      CRYPTO_THREAD_unlock(ex_data_lock);
      if ((puVar8 != (undefined4 *)0x0) && (puVar8[3] != 0)) {
        pvVar3 = CRYPTO_get_ex_data(ad,iVar6);
        (*(code *)puVar8[3])(obj,pvVar3,ad,iVar6,*puVar8,puVar8[1]);
      }
      iVar6 = iVar6 + 1;
    } while (iVar1 != iVar6);
  }
  CRYPTO_free(ptr);
LAB_0013de22:
  OPENSSL_sk_free(ad->sk);
  ad->sk = (stack_st_void *)0x0;
  return;
}

