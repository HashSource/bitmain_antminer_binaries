
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void oid_module_finish(void)

{
  int *piVar1;
  _LHASH *lh;
  
  piVar1 = DAT_0008c214;
  if (*DAT_0008c214 == 0) {
    lh = (_LHASH *)DAT_0008c214[1];
    if (lh != (_LHASH *)0x0) {
      lh->down_load = 0;
      lh_doall(lh,DAT_0008c218);
      lh_doall((_LHASH *)piVar1[1],DAT_0008c21c);
      lh_doall((_LHASH *)piVar1[1],DAT_0008c220);
      lh_free((_LHASH *)piVar1[1]);
      piVar1[1] = 0;
    }
    return;
  }
  *DAT_0008c214 = 2;
  return;
}

