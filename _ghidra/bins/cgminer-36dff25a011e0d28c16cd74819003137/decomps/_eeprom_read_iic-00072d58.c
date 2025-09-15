
uint8_t _eeprom_read_iic(uint8_t chain,uint8_t reg_addr)

{
  uint8_t uVar1;
  uint8_t reg_addr_local;
  uint8_t chain_local;
  _Bool reg_addr_valid;
  uchar which_iic;
  uchar dev_addr;
  
  uVar1 = znyq_set_iic(chain & 7 | 0x50,'\0',true,true,reg_addr,'\0');
  return uVar1;
}

