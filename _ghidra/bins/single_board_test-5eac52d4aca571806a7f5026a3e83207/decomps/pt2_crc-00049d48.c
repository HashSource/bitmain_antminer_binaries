
int pt2_crc(eeprom_v1 *eeprom,uint16_t *start_pos,uint16_t *len,uint8_t *crc8)

{
  uint8_t uVar1;
  uint8_t *crc8_local;
  uint16_t *len_local;
  uint16_t *start_pos_local;
  eeprom_v1 *eeprom_local;
  
  uVar1 = (eeprom->data).version;
  if (uVar1 == '\x01') {
    *start_pos = 0x50;
    *len = 0x10;
  }
  else {
    if (uVar1 != '\x02') {
      return -1;
    }
    *start_pos = 1;
    *len = 1;
  }
  uVar1 = cal_crc8((uint8_t *)((eeprom->data).board_name + *start_pos + 0xf),*len - 1);
  *crc8 = uVar1;
  return 0;
}

