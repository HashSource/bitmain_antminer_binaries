
uint32_t adc_get_chain_domain_vol_dv_out(uint8_t which_chain,uint32_t which_domiam)

{
  uint uVar1;
  float fVar2;
  uint32_t which_domiam_local;
  uint8_t which_chain_local;
  uint32_t Adc_inpiut_sel [4];
  int asic_num;
  int asic_id;
  uint32_t phase0_avg;
  uint32_t end_loop;
  int asic_id_1;
  int count;
  uint32_t loop_num;
  
  loop_num = 0;
  Adc_inpiut_sel[0] = 1;
  Adc_inpiut_sel[1] = 2;
  Adc_inpiut_sel[2] = 4;
  Adc_inpiut_sel[3] = 5;
  memset(g_chain_vol_data,0,0x3420);
  send_set_config_command
            (which_chain,'\x01',0,0xb8,Adc_inpiut_sel[which_domiam] << 0xd | 0x230c030d);
  send_set_config_command(which_chain,'\x01',0,0xb9,0x3f014381);
  send_set_config_command(which_chain,'\x01',0,0xba,0x40010);
  send_set_config_command(which_chain,'\x01',0,0xbb,0x3340e80);
  do {
    send_set_config_command
              (which_chain,'\x01',0,0xb8,Adc_inpiut_sel[which_domiam] << 0xd | 0x232c030d);
    usleep(60000);
    get_register_info(0,0xf,true,"1370");
    count = 0;
    while ((count < 0x1e &&
           (g_chain_vol_data[which_chain].got_vol_asics_everytime != (g_rt.config)->asics))) {
      usleep(500000);
      count = count + 1;
    }
    loop_num = loop_num + 1;
    g_chain_vol_data[which_chain].got_vol_asics_everytime = 0;
    memset(g_chain_vol_data[which_chain].got_vol_flag_everytime,0,0x100);
  } while ((loop_num < 0x15) &&
          (g_chain_vol_data[which_chain].finish_read_vol_asics != (g_rt.config)->asics));
  for (asic_id_1 = 0; asic_id_1 < (g_rt.config)->asics; asic_id_1 = asic_id_1 + 1) {
    uVar1 = __aeabi_idiv(g_chain_vol_data[which_chain].asic_vol_data_info[asic_id_1].
                         asic_returned_vol_data,
                         g_chain_vol_data[which_chain].asic_vol_data_info[asic_id_1].
                         asic_returned_vol_count + -1);
    g_asic_vol_domain[which_chain][asic_id_1][which_domiam] =
         (float)(((double)uVar1 / 2048.0) / 8.0 - 1.0);
    if (1 < which_domiam) {
      fVar2 = g_asic_vol_domain[which_chain][asic_id_1][which_domiam];
      g_asic_vol_domain[which_chain][asic_id_1][which_domiam] = fVar2 + fVar2;
    }
  }
  return 0;
}

