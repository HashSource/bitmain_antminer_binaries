
void calc_nonce_stats_super(pattern_test_stats *stats,asic_status *asic_stats)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  asic_status *asic_stats_local;
  pattern_test_stats *stats_local;
  int avg;
  uint32_t core_domain;
  uint32_t domain;
  float spow;
  int sum;
  uint32_t core;
  uint32_t asic;
  
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    iVar2 = __aeabi_uidiv(asic,(g_rt.config)->asics_in_domain);
    for (core = 0; core < (uint)(g_rt.config)->asic_small_cores; core = core + 1) {
      iVar3 = (g_rt.config)->asic_domain_num;
      iVar1 = __aeabi_uidiv(core * (g_rt.config)->asic_domain_num,(g_rt.config)->asic_small_cores);
      iVar1 = iVar1 + iVar2 * iVar3;
      stats->nonce_num_domain[iVar1] =
           (uint)asic_stats->every_asic_reg_ntick_nonce_num[asic] + stats->nonce_num_domain[iVar1];
      stats->nonce_num_domain_big[iVar2] =
           (uint)asic_stats->every_asic_reg_ntick_nonce_num[asic] +
           stats->nonce_num_domain_big[iVar2];
    }
  }
  sum = 0;
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    sum = sum + stats->nonce_num_asic[asic];
  }
  iVar2 = __aeabi_idiv(sum,(g_rt.config)->asics);
  spow = 0.0;
  for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
    spow = spow + (float)((stats->nonce_num_asic[asic] - iVar2) *
                         (stats->nonce_num_asic[asic] - iVar2));
  }
  dVar4 = sqrt((double)(spow / (float)(longlong)(g_rt.config)->asics));
  stats->nonce_stdev = (float)dVar4;
  return;
}

