
int ISL_on(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t oper;
  
  oper = 0x80;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x01',&oper,1);
  return 0;
}

