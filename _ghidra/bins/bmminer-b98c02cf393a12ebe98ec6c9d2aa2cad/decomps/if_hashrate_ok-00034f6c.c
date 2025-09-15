
bool if_hashrate_ok(void)

{
  int iVar1;
  double dVar2;
  
  dVar2 = (total_mhashes_done / 1000.0) / total_secs;
  iVar1 = ideal_total_hash_rate;
  if (opt_economic_mode != '\0') {
    iVar1 = GetTotalRate_part_12();
  }
  return (double)(longlong)iVar1 * 0.98 < dVar2;
}

