
int eeprom_v1_sweep_retrieve(eeprom_v1 *eeprom)

{
  int iVar1;
  int32_t iVar2;
  byte bVar3;
  size_t in_stack_fffffee0;
  eeprom_v1 *eeprom_local;
  uint16_t len;
  uint16_t start_pos;
  uint8_t crc8;
  uint8_t buf [256];
  
  memset(buf,0,0x100);
  crc8 = '\0';
  start_pos = 0;
  len = 0;
  iVar1 = sweep_crc(eeprom,&start_pos,&len,&crc8);
  if (iVar1 == 0) {
    iVar2 = eeprom_read((uint)(eeprom->private).board_id,(char)start_pos + '\x10',buf,(uint)len);
    if (iVar2 == 0) {
      iVar1 = decrypt((EVP_PKEY_CTX *)eeprom,buf,(size_t *)(uint)len,
                      (uchar *)((eeprom->data).board_name + start_pos + 0xf),in_stack_fffffee0);
      if (iVar1 == 0) {
        iVar1 = sweep_crc(eeprom,&start_pos,&len,&crc8);
        if (iVar1 == 0) {
          if ((eeprom->data).board_name[(uint)len + (uint)start_pos + 0xe] == crc8) {
            bVar3 = 4;
          }
          else {
            bVar3 = 0;
          }
          (eeprom->private).status = bVar3 | (eeprom->private).status;
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
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

