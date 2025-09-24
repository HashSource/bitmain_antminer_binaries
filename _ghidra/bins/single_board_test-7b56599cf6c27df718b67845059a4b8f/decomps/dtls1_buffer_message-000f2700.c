
undefined4 dtls1_buffer_message(int *param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined1 extraout_var;
  undefined1 *ptr;
  pitem *item;
  int iVar4;
  int iVar5;
  int iVar6;
  void *__dest;
  uchar local_20 [8];
  
  if (param_1[0x1e] != 0) {
    return 0;
  }
  __dest = (void *)param_1[0x1d];
  ptr = (undefined1 *)CRYPTO_malloc(0x34,"ssl/statem/statem_dtls.c",0x3e);
  if (ptr == (undefined1 *)0x0) {
    ERR_put_error(0x14,0x26f,0x41,"ssl/statem/statem_dtls.c",0x3f);
  }
  else if ((__dest == (void *)0x0) ||
          (__dest = CRYPTO_malloc((int)__dest,"ssl/statem/statem_dtls.c",0x44),
          __dest != (void *)0x0)) {
    iVar6 = param_1[0x1b];
    *(undefined4 *)(ptr + 0x30) = 0;
    *(void **)(ptr + 0x2c) = __dest;
    memcpy(__dest,*(void **)(iVar6 + 4),param_1[0x1d]);
    iVar6 = param_1[0x20];
    if (param_2 == 0) {
      iVar5 = *(int *)(iVar6 + 0x124);
      if (iVar5 + 0xc != param_1[0x1d]) {
        return 0;
      }
    }
    else {
      iVar5 = *(int *)(iVar6 + 0x124);
      if (*param_1 == 0x100) {
        iVar4 = 3;
      }
      else {
        iVar4 = 1;
      }
      if (iVar4 + iVar5 != param_1[0x1d]) {
        return 0;
      }
    }
    uVar2 = *(undefined2 *)(iVar6 + 0x128);
    *(int *)(ptr + 4) = iVar5;
    *(undefined2 *)(ptr + 8) = uVar2;
    uVar3 = *(undefined1 *)(iVar6 + 0x120);
    *(undefined4 *)(ptr + 0xc) = 0;
    *ptr = uVar3;
    uVar1 = *(undefined2 *)(param_1[0x3ce] + 2);
    iVar6 = param_1[0xfb];
    *(undefined4 *)(ptr + 0x10) = *(undefined4 *)(param_1[0x20] + 0x124);
    iVar5 = param_1[0x100];
    *(int *)(ptr + 0x18) = iVar6;
    iVar6 = param_1[0xf9];
    *(int *)(ptr + 0x1c) = iVar5;
    iVar5 = param_1[0x11d];
    *(int *)(ptr + 0x14) = param_2;
    *(int *)(ptr + 0x20) = iVar6;
    *(int *)(ptr + 0x24) = iVar5;
    *(undefined2 *)(ptr + 0x28) = uVar1;
    local_20[0] = '\0';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    local_20[4] = '\0';
    local_20[5] = '\0';
    local_20[6] = '\0';
    local_20[7] = '\0';
    dtls1_get_queue_priority(uVar2,param_2);
    local_20[6] = extraout_var;
    uVar3 = dtls1_get_queue_priority(*(undefined2 *)(ptr + 8),*(undefined4 *)(ptr + 0x14));
    local_20[7] = uVar3;
    item = pitem_new(local_20,ptr);
    if (item != (pitem *)0x0) {
      pqueue_insert(*(pqueue *)(param_1[0x20] + 0x114),item);
      return 1;
    }
    dtls1_hm_fragment_free(ptr);
  }
  else {
    ERR_put_error(0x14,0x26f,0x41,"ssl/statem/statem_dtls.c",0x45);
    CRYPTO_free(ptr);
  }
  return 0;
}

