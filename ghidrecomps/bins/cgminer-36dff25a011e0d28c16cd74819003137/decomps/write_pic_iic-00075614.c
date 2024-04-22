
uint8_t write_pic_iic(uint8_t chain,uint8_t data)

{
  uint8_t uVar1;
  uint8_t data_local;
  uint8_t chain_local;
  uint8_t reg_addr;
  _Bool reg_addr_valid;
  uint8_t which_iic;
  uint8_t dev_addr;
  
  uVar1 = znyq_set_iic(chain & 7 | 0x20,'\0',false,false,'\0',data);
  return uVar1;
}

