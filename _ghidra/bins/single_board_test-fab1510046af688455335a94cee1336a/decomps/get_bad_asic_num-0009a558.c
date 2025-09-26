
/* WARNING: Unknown calling convention */

int get_bad_asic_num(void)

{
  int i;
  int bad_asic_num;
  
  bad_asic_num = 0;
  clear_bad_asic_ids();
  for (i = 0; i < (g_rt.config)->asics; i = i + 1) {
    if ((int)(uint)g_rt.asic_stats.every_asic_reg_last_nonce_num[i] <
        ((((g_rt.config)->standard).asic_nonce_rate + -0x708) *
        (g_rt.config)->patter_num * (g_rt.config)->asic_small_cores) / 10000) {
      add_bad_asic_ids(i);
      printf("bad asic index %d  num %d \n",i,(uint)g_rt.asic_stats.every_asic_reg_last_nonce_num[i]
            );
      bad_asic_num = bad_asic_num + 1;
    }
  }
  return bad_asic_num;
}

