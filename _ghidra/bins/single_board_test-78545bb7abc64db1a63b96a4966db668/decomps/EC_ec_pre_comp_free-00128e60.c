
void EC_ec_pre_comp_free(void *param_1)

{
  bool bVar1;
  EC_POINT *point;
  int *piVar2;
  int iVar3;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  piVar2 = (int *)((int)param_1 + 0x18);
  do {
    ExclusiveAccess(piVar2);
    iVar3 = *piVar2;
    bVar1 = (bool)hasExclusiveAccess(piVar2);
  } while (!bVar1);
  *piVar2 = iVar3 + -1;
  if (iVar3 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar3 + -1) {
    return;
  }
  piVar2 = *(int **)((int)param_1 + 0x10);
  if (piVar2 != (int *)0x0) {
    point = (EC_POINT *)*piVar2;
    if (point != (EC_POINT *)0x0) {
      do {
        EC_POINT_free(point);
        piVar2 = piVar2 + 1;
        point = (EC_POINT *)*piVar2;
      } while (point != (EC_POINT *)0x0);
      piVar2 = *(int **)((int)param_1 + 0x10);
    }
    CRYPTO_free(piVar2);
  }
  CRYPTO_THREAD_lock_free(*(undefined4 *)((int)param_1 + 0x1c));
  CRYPTO_free(param_1);
  return;
}

