
void set_succ_asic_nonce_state(uint8_t *state)

{
  uint8_t *state_local;
  int j;
  int i;
  
  for (i = 0; i < (g_rt.config)->domains; i = i + 1) {
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      if ((state[j + i * (g_rt.config)->asics_in_domain] != '\0') &&
         (g_rt.asic_stats.every_asic_got_nonce_num[j + i * (g_rt.config)->asics_in_domain] != 0)) {
        g_rt.last_succ_asic_nonce_num[i * (g_rt.config)->asics_in_domain + j] =
             g_rt.asic_stats.every_asic_got_nonce_num[j + i * (g_rt.config)->asics_in_domain];
        if ((g_rt.config)->is_super == false) {
          g_rt.last_succ_asic_nonce_num[i * (g_rt.config)->asics_in_domain + j] =
               g_rt.asic_stats.every_asic_got_nonce_num[j + i * (g_rt.config)->asics_in_domain];
        }
        else {
          g_rt.last_succ_asic_nonce_num[i * (g_rt.config)->asics_in_domain + j] =
               g_rt.asic_stats.every_asic_reg_ntick_nonce_num
               [j + i * (g_rt.config)->asics_in_domain];
        }
      }
    }
  }
  return;
}

