
int ISL_set_vout_command
              (uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint16_t voltage)

{
  uint16_t voltage_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t cmd [2];
  
  which_chain_local = which_chain;
  cmd = (uint8_t  [2])voltage;
  printf("uint16 = 0x%04x[%u], cmd0=%02x cmd1=%02x\n",(uint)voltage,(uint)voltage,
         (uint)(byte)voltage,(uint)(byte)(voltage >> 8));
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'!',cmd,2);
  return 0;
}

