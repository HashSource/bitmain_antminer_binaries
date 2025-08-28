
/* WARNING: Unknown calling convention */

_Bool if_hashrate_ok(void)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  double dVar4;
  
  dVar4 = (total_mhashes_done / 1000.0) / total_secs;
  iVar3 = GetTotalRate();
  lVar1 = (longlong)iVar3;
  if (dVar4 <= (double)lVar1 * 0.98) {
    iVar3 = 0;
  }
  uVar2 = (undefined1)iVar3;
  if ((double)lVar1 * 0.98 < dVar4) {
    uVar2 = 1;
  }
  return (_Bool)uVar2;
}

