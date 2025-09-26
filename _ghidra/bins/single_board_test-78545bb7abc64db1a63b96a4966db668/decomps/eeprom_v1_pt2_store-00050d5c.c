
int eeprom_v1_pt2_store(eeprom_v1 *eeprom)

{
  int iVar1;
  int extraout_r0;
  int32_t iVar2;
  eeprom_v1 *eeprom_local;
  uint16_t len;
  uint16_t start_pos;
  uint8_t crc8;
  uint8_t buf [256];
  
  memset(buf,0,0x100);
  crc8 = '\0';
  start_pos = 0;
  len = 0;
  iVar1 = pt2_crc(eeprom,&start_pos,&len,&crc8);
  if (iVar1 == 0) {
    (eeprom->data).board_name[(uint)len + (uint)start_pos + 0xe] = crc8;
    encrypt((char *)eeprom,(int)((eeprom->data).board_name + start_pos + 0xf));
    if (extraout_r0 == 0) {
      iVar2 = eeprom_write((uint)(eeprom->private).board_id,(char)start_pos + '\x10',buf,(uint)len);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

