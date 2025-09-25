
_Bool eeprom_v1_is_board_name_available(eeprom_v1 *eeprom)

{
  eeprom_v1 *eeprom_local;
  
  return (eeprom->data).board_name[0] != '\0';
}

