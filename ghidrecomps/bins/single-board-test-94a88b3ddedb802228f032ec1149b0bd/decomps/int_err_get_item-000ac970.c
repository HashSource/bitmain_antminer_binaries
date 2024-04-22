
_LHASH * int_err_get_item(void *param_1)

{
  int iVar1;
  _LHASH *lh;
  code **ppcVar2;
  
  iVar1 = DAT_000ac9e0;
  ppcVar2 = *(code ***)(DAT_000ac9e0 + 0x2f4);
  if (ppcVar2 == (code **)0x0) {
    CRYPTO_lock(9,1,DAT_000ac9e4,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ac9e8;
    }
    CRYPTO_lock(10,1,DAT_000ac9e4,0x12a);
    ppcVar2 = *(code ***)(iVar1 + 0x2f4);
  }
  lh = (_LHASH *)(**ppcVar2)(0);
  if (lh != (_LHASH *)0x0) {
    CRYPTO_lock(5,1,DAT_000ac9e4,0x189);
    lh = (_LHASH *)lh_retrieve(lh,param_1);
    CRYPTO_lock(6,1,DAT_000ac9e4,0x18b);
  }
  return lh;
}

