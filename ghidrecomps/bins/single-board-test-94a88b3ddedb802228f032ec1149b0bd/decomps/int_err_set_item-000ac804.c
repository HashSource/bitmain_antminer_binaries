
_LHASH * int_err_set_item(void *param_1)

{
  int iVar1;
  _LHASH *lh;
  code **ppcVar2;
  
  iVar1 = DAT_000ac874;
  ppcVar2 = *(code ***)(DAT_000ac874 + 0x2f4);
  if (ppcVar2 == (code **)0x0) {
    CRYPTO_lock(9,1,DAT_000ac878,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ac87c;
    }
    CRYPTO_lock(10,1,DAT_000ac878,0x12a);
    ppcVar2 = *(code ***)(iVar1 + 0x2f4);
  }
  lh = (_LHASH *)(**ppcVar2)(1);
  if (lh != (_LHASH *)0x0) {
    CRYPTO_lock(9,1,DAT_000ac878,0x19a);
    lh = (_LHASH *)lh_insert(lh,param_1);
    CRYPTO_lock(10,1,DAT_000ac878,0x19c);
  }
  return lh;
}

