
int ISL_set_on_off_config(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t config)

{
  uint8_t config_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  
  config_local = config;
  i2c_dev_addr_local = i2c_dev_addr;
  which_i2c_local = which_i2c;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x02',&config_local,1);
  return 0;
}

