
int ISL_set_clear_faults(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t clear;
  
  clear = '\x01';
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x03',&clear,1);
  return 0;
}

