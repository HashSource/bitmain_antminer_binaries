
bool check_hashrate_maybe_ok(void)

{
  int iVar1;
  double in_d0;
  double dVar2;
  double dVar3;
  
  dVar3 = (total_mhashes_done / DAT_000351e0) / total_secs;
  iVar1 = ideal_total_hash_rate;
  if (opt_economic_mode != '\0') {
    iVar1 = GetTotalRate_part_12();
  }
  dVar2 = (double)(longlong)iVar1 * in_d0;
  return dVar3 != dVar2 && dVar3 < dVar2 == (NAN(dVar3) || NAN(dVar2));
}

