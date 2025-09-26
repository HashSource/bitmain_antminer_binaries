
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_asic_nonce_state(void)

{
  int j;
  int i;
  
  for (i = 0; i < (g_rt.config)->domains; i = i + 1) {
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      if ((g_rt.config)->is_super == false) {
        g_rt.last_succ_asic_nonce_num[i * (g_rt.config)->asics_in_domain + j] =
             g_rt.asic_stats.every_asic_got_nonce_num[j + i * (g_rt.config)->asics_in_domain];
      }
      else {
        g_rt.last_succ_asic_nonce_num[i * (g_rt.config)->asics_in_domain + j] =
             g_rt.asic_stats.every_asic_reg_ntick_nonce_num[j + i * (g_rt.config)->asics_in_domain];
      }
    }
  }
  return;
}

