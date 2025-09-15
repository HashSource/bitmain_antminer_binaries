
_Bool _eeprom_get_pcb_version(uint8_t chain,uint8_t *pcb_version)

{
  uint8_t uVar1;
  uint8_t *pcb_version_local;
  uint8_t chain_local;
  
  uVar1 = array_read_one_byte(0xfc,chain);
  *pcb_version = uVar1;
  return true;
}

