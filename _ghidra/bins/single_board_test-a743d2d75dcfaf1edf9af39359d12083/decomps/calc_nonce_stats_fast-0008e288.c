
void calc_nonce_stats_fast(pattern_test_stats *stats,asic_status *asic_stats)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  asic_status *asic_stats_local;
  pattern_test_stats *stats_local;
  int avg;
  uint32_t core_domain;
  uint32_t domain;
  float spow;
  int sum;
  uint32_t core_nonce_count;
  uint32_t core;
  uint32_t asic;
  
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    iVar3 = __aeabi_uidiv(asic,(g_rt.config)->asics_in_domain);
    for (core = 0; core < (uint)(g_rt.config)->asic_small_cores; core = core + 1) {
      iVar4 = (g_rt.config)->asic_domain_num;
      iVar2 = __aeabi_uidiv(core * (g_rt.config)->asic_domain_num,(g_rt.config)->asic_small_cores);
      iVar2 = iVar2 + iVar3 * iVar4;
      stats->nonce_num_domain[iVar2] =
           (uint)asic_stats->asic_core_nonce_num[asic][core] + stats->nonce_num_domain[iVar2];
      stats->nonce_num_domain_big[iVar3] =
           (uint)asic_stats->asic_core_nonce_num[asic][core] + stats->nonce_num_domain_big[iVar3];
      bVar1 = asic_stats->asic_core_nonce_num[asic][core];
      stats->nonce_stats[asic][bVar1] = stats->nonce_stats[asic][bVar1] + 1;
    }
  }
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    for (core_nonce_count = 1; core_nonce_count < 9; core_nonce_count = core_nonce_count + 1) {
      stats->nonce_stats[asic][core_nonce_count] =
           stats->nonce_stats[asic][core_nonce_count] +
           stats->nonce_stats[asic - 1][core_nonce_count + 8];
    }
  }
  sum = 0;
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    sum = sum + stats->nonce_num_asic[asic];
  }
  iVar3 = __aeabi_idiv(sum,(g_rt.config)->asics);
  spow = 0.0;
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    spow = spow + (float)((stats->nonce_num_asic[asic] - iVar3) *
                         (stats->nonce_num_asic[asic] - iVar3));
  }
  dVar5 = sqrt((double)(spow / (float)(longlong)(g_rt.config)->asics));
  stats->nonce_stdev = (float)dVar5;
  return;
}

