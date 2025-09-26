
/* WARNING: Unknown calling convention */

int32_t set_chain_reg_connect_left_diode_to_temp(uint8_t which_chain)

{
  adc_ctrl1_t adc_ctrl1_value;
  analog_mux_control_t analog_mux_control;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0xb9,&adc_ctrl1_value.v);
  adc_ctrl1_value.v = adc_ctrl1_value.v & 0xffffdfff;
  send_set_config_command(which_chain,'\x01',0,0xb9,adc_ctrl1_value.v);
  usleep(20000);
  get_register_cache_value(hashboard_cache_level,which_chain,0,0x54,&analog_mux_control.v);
  analog_mux_control.v = analog_mux_control.v & 0xfffffff0 | 2;
  send_set_config_command(which_chain,'\x01',0,0x54,analog_mux_control.v);
  usleep(100000);
  get_register_cache_value(hashboard_cache_level,which_chain,0,0xb9,&adc_ctrl1_value.v);
  adc_ctrl1_value.v = adc_ctrl1_value.v | 0x4000;
  send_set_config_command(which_chain,'\x01',0,0xb9,adc_ctrl1_value.v);
  usleep(20000);
  return 0;
}

