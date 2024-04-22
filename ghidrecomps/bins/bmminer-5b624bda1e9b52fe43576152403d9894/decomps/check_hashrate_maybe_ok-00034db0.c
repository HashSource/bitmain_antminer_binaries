
_Bool check_hashrate_maybe_ok(double level)

{
  undefined uVar1;
  int iVar2;
  double in_d0;
  double dVar3;
  double dVar4;
  
  dVar3 = (total_mhashes_done / DAT_00034e08) / total_secs;
  iVar2 = GetTotalRate();
  dVar4 = (double)(longlong)iVar2 * in_d0;
  if (dVar3 == dVar4 || dVar3 < dVar4 != (NAN(dVar3) || NAN(dVar4))) {
    iVar2 = 0;
  }
  uVar1 = (undefined)iVar2;
  if (dVar3 != dVar4 && dVar3 < dVar4 == (NAN(dVar3) || NAN(dVar4))) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

