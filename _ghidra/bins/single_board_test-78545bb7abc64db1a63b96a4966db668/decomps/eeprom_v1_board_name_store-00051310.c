
int eeprom_v1_board_name_store(eeprom_v1 *eeprom)

{
  int32_t iVar1;
  int iVar2;
  eeprom_v1 *eeprom_local;
  
  iVar1 = eeprom_write((uint)(eeprom->private).board_id,'\x01',(uint8_t *)(eeprom->data).board_name,
                       0xf);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

