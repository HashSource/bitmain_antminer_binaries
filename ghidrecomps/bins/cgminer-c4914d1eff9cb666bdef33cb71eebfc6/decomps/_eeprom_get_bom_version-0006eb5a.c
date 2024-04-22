
_Bool _eeprom_get_bom_version(uint8_t chain,uint8_t *bom_version)

{
  uint8_t uVar1;
  uint8_t *bom_version_local;
  uint8_t chain_local;
  
  uVar1 = array_read_one_byte(0xfd,chain);
  *bom_version = uVar1;
  return true;
}

