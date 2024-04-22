
bool if_hashrate_ok(void)

{
  int iVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (total_mhashes_done / DAT_00034fd8) / total_secs;
  iVar1 = ideal_total_hash_rate;
  if (opt_economic_mode != '\0') {
    iVar1 = GetTotalRate_part_12();
  }
  dVar2 = (double)(longlong)iVar1 * DAT_00034fe0;
  return dVar3 != dVar2 && dVar3 < dVar2 == (NAN(dVar3) || NAN(dVar2));
}

