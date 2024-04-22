
/* WARNING: Unknown calling convention */

_Bool if_hashrate_ok(void)

{
  undefined uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
  dVar4 = (total_mhashes_done / DAT_00034da0) / total_secs;
  iVar2 = GetTotalRate();
  dVar3 = (double)(longlong)iVar2 * DAT_00034da8;
  if (dVar4 == dVar3 || dVar4 < dVar3 != (NAN(dVar4) || NAN(dVar3))) {
    iVar2 = 0;
  }
  uVar1 = (undefined)iVar2;
  if (dVar4 != dVar3 && dVar4 < dVar3 == (NAN(dVar4) || NAN(dVar3))) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

