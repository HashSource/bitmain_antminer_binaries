
_Bool eeprom_v1_is_pt1_available(eeprom_v1 *eeprom)

{
  eeprom_v1 *eeprom_local;
  
  return ((eeprom->private).status & 1) != 0;
}

