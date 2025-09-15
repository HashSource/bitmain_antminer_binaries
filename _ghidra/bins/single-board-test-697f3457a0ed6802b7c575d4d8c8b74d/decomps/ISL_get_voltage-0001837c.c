
int ISL_get_voltage(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint16_t *voltage)

{
  uint16_t *voltage_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t vol [2];
  
  which_chain_local = which_chain;
  memset(vol,0,2);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'!',vol,2);
  *voltage = (uint16_t)vol;
  return 0;
}

