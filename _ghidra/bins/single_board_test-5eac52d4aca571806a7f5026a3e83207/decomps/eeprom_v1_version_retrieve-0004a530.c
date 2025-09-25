
int eeprom_v1_version_retrieve(eeprom_v1 *eeprom)

{
  int32_t iVar1;
  int iVar2;
  eeprom_v1 *eeprom_local;
  uint8_t version;
  
  version = '\0';
  iVar1 = eeprom_read((uint)(eeprom->private).board_id,'\0',&version,1);
  if (iVar1 == 0) {
    (eeprom->data).version = version;
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

