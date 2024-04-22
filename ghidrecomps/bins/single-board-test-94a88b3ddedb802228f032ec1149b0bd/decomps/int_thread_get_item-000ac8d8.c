
void * int_thread_get_item(void *param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  _LHASH *local_14;
  
  iVar1 = DAT_000ac964;
  iVar3 = *(int *)(DAT_000ac964 + 0x2f4);
  if (iVar3 == 0) {
    CRYPTO_lock(9,1,DAT_000ac968,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ac96c;
    }
    CRYPTO_lock(10,1,DAT_000ac968,0x12a);
    iVar3 = *(int *)(iVar1 + 0x2f4);
  }
  local_14 = (_LHASH *)(**(code **)(iVar3 + 0x14))(0);
  if (local_14 == (_LHASH *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    CRYPTO_lock(5,1,DAT_000ac968,499);
    pvVar2 = lh_retrieve(local_14,param_1);
    CRYPTO_lock(6,1,DAT_000ac968,0x1f5);
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0x18))(&local_14);
  }
  return pvVar2;
}

