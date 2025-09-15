
int ISL_read_reg_default(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t value [2];
  
  value[0] = '\0';
  value[1] = '\0';
  which_chain_local = which_chain;
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\0',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x01',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x02',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x03',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x10',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'!',value,2);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\"',value,1);
  return 0;
}

