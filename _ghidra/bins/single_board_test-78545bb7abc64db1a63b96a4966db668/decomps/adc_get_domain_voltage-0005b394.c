
float adc_get_domain_voltage
                (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,int domain)

{
  uint32_t uVar1;
  int domain_local;
  uint32_t which_asic_address_local;
  uint8_t mode_local;
  uint8_t which_chain_local;
  uint32_t Adc_inpiut_sel [5];
  uint32_t dv0_avg;
  float vol;
  
  Adc_inpiut_sel[0] = 1;
  Adc_inpiut_sel[1] = 2;
  Adc_inpiut_sel[2] = 3;
  Adc_inpiut_sel[3] = 4;
  Adc_inpiut_sel[4] = 5;
  uVar1 = adc_get_domain_vol_dv_out(which_chain,mode,which_asic_address,Adc_inpiut_sel[domain]);
  return (float)(((double)uVar1 / 2048.0) / 8.0 - 1.0);
}

