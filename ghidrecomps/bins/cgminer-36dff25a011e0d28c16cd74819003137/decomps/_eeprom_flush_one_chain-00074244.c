
int _eeprom_flush_one_chain(int chain,eeprom_layout_t *eeprom_buf)

{
  uint16_t uVar1;
  int iVar2;
  FILE *__stream;
  eeprom_layout_t *eeprom_buf_local;
  int chain_local;
  eeprom_layout_t eeprom_buf_tmp;
  FILE *pFile;
  int flush_len;
  int crc_len;
  int start;
  uint8_t *p_buf_tmp;
  uint8_t *p_buf;
  
  *(undefined *)&eeprom_buf->cgminer_header = 0x97;
  *(undefined *)((int)&eeprom_buf->cgminer_header + 1) = 0x13;
  uVar1 = CRC16((uint8_t *)&eeprom_buf->cgminer_header,0xa4);
  eeprom_buf->crc_cgminer = uVar1;
  iVar2 = _eeprom_write_iic_bytes((uint8_t)chain,0x28,0xa6,(uint8_t *)&eeprom_buf->cgminer_header);
  if (iVar2 == 0) {
    memset(&eeprom_buf_tmp,0xff,0x100);
    iVar2 = _eeprom_read_iic_bytes
                      ((uint8_t)chain,0x28,0xa6,(uint8_t *)&eeprom_buf_tmp.cgminer_header);
    if (iVar2 == 0) {
      iVar2 = memcmp(&eeprom_buf->cgminer_header,&eeprom_buf_tmp.cgminer_header,0xa6);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          __stream = fopen(log_file,"a+");
          if (__stream != (FILE *)0x0) {
            fprintf(__stream,"%s:%d:%s: Read data is different of write data.\n","eeprom.c",0x142,
                    "_eeprom_flush_one_chain");
          }
          fclose(__stream);
        }
        iVar2 = -1;
      }
    }
    else {
      iVar2 = -1;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

