
void print_chain_asic_domain_avg_voltage(uint8_t which_chain)

{
  int iVar1;
  uint8_t which_chain_local;
  char time_stamp [48];
  float asic_vol [256];
  int temp_j;
  int j_1;
  int i_2;
  int j;
  int i_1;
  int i;
  
  memset(asic_vol,0,0x400);
  memset(g_asic_vol_domain,0,0x4000);
  for (i = 0; i < 4; i = i + 1) {
    adc_get_chain_domain_vol_dv_out(which_chain,i);
  }
  for (i_1 = 0; i_1 < (g_rt.config)->domains; i_1 = i_1 + 1) {
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      asic_vol[i_1 * (g_rt.config)->asics_in_domain + j] =
           asic_vol[j + i_1 * (g_rt.config)->asics_in_domain] +
           g_asic_vol_domain[which_chain][i_1 * (g_rt.config)->asics_in_domain + j][0];
      asic_vol[i_1 * (g_rt.config)->asics_in_domain + j] =
           asic_vol[j + i_1 * (g_rt.config)->asics_in_domain] +
           g_asic_vol_domain[which_chain][i_1 * (g_rt.config)->asics_in_domain + j][1];
      asic_vol[i_1 * (g_rt.config)->asics_in_domain + j] =
           asic_vol[j + i_1 * (g_rt.config)->asics_in_domain] +
           g_asic_vol_domain[which_chain][i_1 * (g_rt.config)->asics_in_domain + j][2];
      asic_vol[i_1 * (g_rt.config)->asics_in_domain + j] =
           asic_vol[j + i_1 * (g_rt.config)->asics_in_domain] +
           g_asic_vol_domain[which_chain][i_1 * (g_rt.config)->asics_in_domain + j][3];
    }
  }
  for (i_2 = 0; i_2 < (g_rt.config)->domains; i_2 = i_2 + 1) {
    for (j_1 = 0; j_1 < (g_rt.config)->asics_in_domain; j_1 = j_1 + 1) {
      iVar1 = j_1;
      if ((i_2 & 1U) != 0) {
        iVar1 = ((g_rt.config)->asics_in_domain - j_1) + -1;
      }
      printf("%0.4f ");
      snprintf(print_chain_asic_domain_avg_voltage::lexical_block_4::lexical_block_4_1::
               lexical_block_4_1_1::lexical_block_4_1_1_1::tmp1,0x100,"%0.4f ",
               asic_vol + iVar1 + i_2 * (g_rt.config)->asics_in_domain,
               (double)asic_vol[iVar1 + i_2 * (g_rt.config)->asics_in_domain]);
      log_to_filex(print_chain_asic_domain_avg_voltage::lexical_block_4::lexical_block_4_1::
                   lexical_block_4_1_1::lexical_block_4_1_1_1::tmp1,time_stamp);
    }
    putchar(10);
    print_chain_asic_domain_avg_voltage::lexical_block_4::lexical_block_4_2::tmp1_1[0] = '\n';
    print_chain_asic_domain_avg_voltage::lexical_block_4::lexical_block_4_2::tmp1_1[1] = '\0';
    log_to_filex(print_chain_asic_domain_avg_voltage::lexical_block_4::lexical_block_4_2::tmp1_1,
                 time_stamp);
  }
  return;
}

