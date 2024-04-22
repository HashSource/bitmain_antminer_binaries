
/* WARNING: Type propagation algorithm not settling */

void int_thread_del_item(void *param_1)

{
  int iVar1;
  void *ptr;
  void *pvVar2;
  ulong uVar3;
  int iVar4;
  _LHASH *local_1c [2];
  
  iVar1 = DAT_000acd54;
  iVar4 = *(int *)(DAT_000acd54 + 0x2f4);
  if (iVar4 == 0) {
    CRYPTO_lock(9,1,DAT_000ace20,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ace24;
    }
    CRYPTO_lock(10,1,DAT_000ace20,0x12a);
    iVar4 = *(int *)(iVar1 + 0x2f4);
  }
  local_1c[0] = (_LHASH *)(**(code **)(iVar4 + 0x14))(0);
  iVar4 = DAT_000acd58;
  if (local_1c[0] != (_LHASH *)0x0) {
    CRYPTO_lock(9,1,DAT_000acd5c,0x217);
    ptr = lh_delete(local_1c[0],param_1);
    if (((*(int *)(iVar4 + 4) == 1) && (*(_LHASH **)(iVar4 + 8) != (_LHASH *)0x0)) &&
       (uVar3 = lh_num_items(*(_LHASH **)(iVar4 + 8)), uVar3 == 0)) {
      lh_free(*(_LHASH **)(iVar4 + 8));
      *(undefined4 *)(iVar4 + 8) = 0;
    }
    CRYPTO_lock(10,1,DAT_000acd5c,0x21f);
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0x18))(local_1c);
    if (ptr != (void *)0x0) {
      if ((*(void **)((int)ptr + 0x88) == (void *)0x0) || (-1 < *(int *)((int)ptr + 200) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0x8c);
        *(undefined4 *)((int)ptr + 200) = 0;
      }
      else {
        CRYPTO_free(*(void **)((int)ptr + 0x88));
        pvVar2 = *(void **)((int)ptr + 0x8c);
        *(undefined4 *)((int)ptr + 0x88) = 0;
        *(undefined4 *)((int)ptr + 200) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xcc) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0x90);
        *(undefined4 *)((int)ptr + 0xcc) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0x90);
        *(undefined4 *)((int)ptr + 0x8c) = 0;
        *(undefined4 *)((int)ptr + 0xcc) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xd0) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0x94);
        *(undefined4 *)((int)ptr + 0xd0) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0x94);
        *(undefined4 *)((int)ptr + 0x90) = 0;
        *(undefined4 *)((int)ptr + 0xd0) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xd4) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0x98);
        *(undefined4 *)((int)ptr + 0xd4) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0x98);
        *(undefined4 *)((int)ptr + 0x94) = 0;
        *(undefined4 *)((int)ptr + 0xd4) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xd8) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0x9c);
        *(undefined4 *)((int)ptr + 0xd8) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0x9c);
        *(undefined4 *)((int)ptr + 0x98) = 0;
        *(undefined4 *)((int)ptr + 0xd8) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xdc) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xa0);
        *(undefined4 *)((int)ptr + 0xdc) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xa0);
        *(undefined4 *)((int)ptr + 0x9c) = 0;
        *(undefined4 *)((int)ptr + 0xdc) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xe0) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xa4);
        *(undefined4 *)((int)ptr + 0xe0) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xa4);
        *(undefined4 *)((int)ptr + 0xa0) = 0;
        *(undefined4 *)((int)ptr + 0xe0) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xe4) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xa8);
        *(undefined4 *)((int)ptr + 0xe4) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xa8);
        *(undefined4 *)((int)ptr + 0xa4) = 0;
        *(undefined4 *)((int)ptr + 0xe4) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xe8) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xac);
        *(undefined4 *)((int)ptr + 0xe8) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xac);
        *(undefined4 *)((int)ptr + 0xa8) = 0;
        *(undefined4 *)((int)ptr + 0xe8) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xec) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xb0);
        *(undefined4 *)((int)ptr + 0xec) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xb0);
        *(undefined4 *)((int)ptr + 0xac) = 0;
        *(undefined4 *)((int)ptr + 0xec) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xf0) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xb4);
        *(undefined4 *)((int)ptr + 0xf0) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xb4);
        *(undefined4 *)((int)ptr + 0xb0) = 0;
        *(undefined4 *)((int)ptr + 0xf0) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xf4) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xb8);
        *(undefined4 *)((int)ptr + 0xf4) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xb8);
        *(undefined4 *)((int)ptr + 0xb4) = 0;
        *(undefined4 *)((int)ptr + 0xf4) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xf8) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xbc);
        *(undefined4 *)((int)ptr + 0xf8) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xbc);
        *(undefined4 *)((int)ptr + 0xb8) = 0;
        *(undefined4 *)((int)ptr + 0xf8) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0xfc) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xc0);
        *(undefined4 *)((int)ptr + 0xfc) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xc0);
        *(undefined4 *)((int)ptr + 0xbc) = 0;
        *(undefined4 *)((int)ptr + 0xfc) = 0;
      }
      if ((pvVar2 == (void *)0x0) || (-1 < *(int *)((int)ptr + 0x100) << 0x1f)) {
        pvVar2 = *(void **)((int)ptr + 0xc4);
        *(undefined4 *)((int)ptr + 0x100) = 0;
      }
      else {
        CRYPTO_free(pvVar2);
        pvVar2 = *(void **)((int)ptr + 0xc4);
        *(undefined4 *)((int)ptr + 0xc0) = 0;
        *(undefined4 *)((int)ptr + 0x100) = 0;
      }
      if ((pvVar2 != (void *)0x0) && (*(int *)((int)ptr + 0x104) << 0x1f < 0)) {
        CRYPTO_free(pvVar2);
        *(undefined4 *)((int)ptr + 0xc4) = 0;
      }
      *(undefined4 *)((int)ptr + 0x104) = 0;
      CRYPTO_free(ptr);
      return;
    }
    return;
  }
  return;
}

