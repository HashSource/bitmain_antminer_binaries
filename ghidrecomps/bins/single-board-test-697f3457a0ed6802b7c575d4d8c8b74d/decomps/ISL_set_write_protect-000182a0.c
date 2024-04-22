
int ISL_set_write_protect(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t mode)

{
  uint8_t mode_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  
  mode_local = mode;
  i2c_dev_addr_local = i2c_dev_addr;
  which_i2c_local = which_i2c;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x10',&mode_local,1);
  return 0;
}

