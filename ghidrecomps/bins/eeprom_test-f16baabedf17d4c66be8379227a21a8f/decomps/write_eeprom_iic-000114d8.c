
uint8_t write_eeprom_iic(uint8_t chain,uint8_t reg_addr,uint8_t data)

{
  uint8_t uVar1;
  uint8_t data_local;
  uint8_t reg_addr_local;
  uint8_t chain_local;
  _Bool reg_addr_valid;
  uchar which_iic;
  uchar dev_addr;
  
  uVar1 = znyq_set_iic(chain & 7 | 0x50,'\0',false,true,reg_addr,data);
  return uVar1;
}

