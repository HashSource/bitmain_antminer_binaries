
uint32_t adc_get_domain_vol_dv_out
                   (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,
                   uint32_t Adc_inpiut_sel)

{
  uint32_t uVar1;
  uint32_t Adc_inpiut_sel_local;
  uint32_t which_asic_address_local;
  uint8_t mode_local;
  uint8_t which_chain_local;
  uint32_t vol;
  uint32_t adc_voltage;
  uint32_t end_loop;
  uint32_t max_loop;
  uint32_t loop_num;
  uint32_t loop;
  uint32_t vol_sum;
  uint32_t phase0_avg;
  
  phase0_avg = 0;
  vol_sum = 0;
  send_set_config_command
            (which_chain,mode,which_asic_address,0xb8,Adc_inpiut_sel << 0xd | 0x230c030d);
  send_set_config_command(which_chain,mode,which_asic_address,0xb9,0x3f014381);
  send_set_config_command(which_chain,mode,which_asic_address,0xba,0x40010);
  send_set_config_command(which_chain,mode,which_asic_address,0xbb,0x3340e80);
  loop = 0;
  loop_num = 0;
  do {
    send_set_config_command
              (which_chain,mode,which_asic_address,0xb8,Adc_inpiut_sel << 0xd | 0x232c030d);
    usleep(60000);
    uVar1 = get_register_info(which_asic_address,0xf,false,"1370");
    if ((int)uVar1 < 0) {
      if (loop != 0) {
        vol_sum = (uVar1 & 0x7fff) + vol_sum;
      }
      loop = loop + 1;
    }
    loop_num = loop_num + 1;
  } while ((loop != 9) && (loop_num < 0x15));
  if (1 < loop) {
    phase0_avg = __aeabi_uidiv(vol_sum,loop - 1);
  }
  return phase0_avg;
}

