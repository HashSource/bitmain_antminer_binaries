
int CRYPTO_dup_ex_data(int class_index,CRYPTO_EX_DATA *to,CRYPTO_EX_DATA *from)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *val;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 *local_64;
  undefined1 *local_5c;
  void *local_54;
  undefined1 local_50 [44];
  
  if (from->sk == (stack_st_void *)0x0) {
    return 1;
  }
  if (0xf < (uint)class_index) {
    ERR_put_error(0xf,0x71,7,"crypto/ex_data.c",0x37);
    return 0;
  }
  iVar1 = CRYPTO_THREAD_run_once(&ex_data_init,0x12f705);
  if ((iVar1 == 0) || (do_ex_data_init_ossl_ret_ == 0)) {
    ERR_put_error(0xf,0x71,0x41,"crypto/ex_data.c",0x3c);
    return 0;
  }
  if (ex_data_lock == 0) {
    return 0;
  }
  iVar5 = class_index * 4;
  CRYPTO_THREAD_write_lock();
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(ex_data + iVar5));
  iVar2 = OPENSSL_sk_num(from->sk);
  if (iVar2 <= iVar1) {
    iVar1 = iVar2;
  }
  if (iVar1 < 1) {
    CRYPTO_THREAD_unlock(ex_data_lock);
    if (iVar1 == 0) {
      return 1;
    }
LAB_0012fe50:
    ERR_put_error(0xf,0x6e,0x41,"crypto/ex_data.c",0x11f);
    return 0;
  }
  if (iVar1 < 10) {
    local_64 = local_50;
    if (iVar1 < 9) {
      iVar2 = 0;
      goto LAB_0012fd30;
    }
  }
  else {
    local_64 = (undefined1 *)CRYPTO_malloc(iVar1 << 2,"crypto/ex_data.c",0x115);
    if (local_64 == (undefined1 *)0x0) {
      CRYPTO_THREAD_unlock(ex_data_lock);
      goto LAB_0012fe50;
    }
  }
  iVar2 = 0;
  puVar6 = local_64 + 0x28;
  iVar4 = 1;
  do {
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2);
    *(undefined4 *)(puVar6 + -0x28) = uVar3;
    iVar8 = iVar4 + 8;
    HintPreloadData(puVar6);
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar4);
    *(undefined4 *)(puVar6 + -0x24) = uVar3;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2 + 2);
    *(undefined4 *)(puVar6 + -0x20) = uVar3;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2 + 3);
    *(undefined4 *)(puVar6 + -0x1c) = uVar3;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2 + 4);
    *(undefined4 *)(puVar6 + -0x18) = uVar3;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2 + 5);
    *(undefined4 *)(puVar6 + -0x14) = uVar3;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2 + 6);
    iVar4 = iVar2 + 7;
    *(undefined4 *)(puVar6 + -0x10) = uVar3;
    iVar2 = iVar2 + 8;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar4);
    *(undefined4 *)(puVar6 + -0xc) = uVar3;
    puVar6 = puVar6 + 0x20;
    iVar4 = iVar8;
  } while (iVar8 < iVar1 + -7);
LAB_0012fd30:
  local_5c = local_50;
  puVar7 = (undefined4 *)(local_64 + iVar2 * 4);
  do {
    iVar4 = iVar2 + 1;
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ex_data + iVar5),iVar2);
    *puVar7 = uVar3;
    iVar2 = iVar4;
    puVar7 = puVar7 + 1;
  } while (iVar4 < iVar1);
  CRYPTO_THREAD_unlock(ex_data_lock);
  val = CRYPTO_get_ex_data(to,iVar1 + -1);
  iVar2 = CRYPTO_set_ex_data(to,iVar1 + -1,val);
  if (iVar2 == 0) {
LAB_0012fdc8:
    iVar1 = 0;
  }
  else {
    puVar7 = (undefined4 *)(local_64 + -4);
    iVar2 = 0;
    do {
      local_54 = CRYPTO_get_ex_data(from,iVar2);
      puVar7 = puVar7 + 1;
      puVar9 = (undefined4 *)*puVar7;
      if (((puVar9 != (undefined4 *)0x0) && ((code *)puVar9[4] != (code *)0x0)) &&
         (iVar5 = (*(code *)puVar9[4])(to,from,&local_54,iVar2,*puVar9,puVar9[1]), iVar5 == 0))
      goto LAB_0012fdc8;
      iVar5 = iVar2 + 1;
      CRYPTO_set_ex_data(to,iVar2,local_54);
      iVar2 = iVar5;
    } while (iVar5 != iVar1);
    iVar1 = 1;
  }
  if (local_64 != local_5c) {
    CRYPTO_free(local_64);
  }
  return iVar1;
}

