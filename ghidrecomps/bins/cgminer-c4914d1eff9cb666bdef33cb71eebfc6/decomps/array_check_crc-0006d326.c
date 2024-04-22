
_Bool array_check_crc(uint8_t chain)

{
  uint8_t chain_local;
  uint16_t _crc_;
  FILE *pFile_1;
  FILE *pFile;
  uint16_t crc;
  uint8_t *buf;
  
  buf = eeprom_info[chain];
  crc = 0;
  _crc_ = 0;
  crc = CRC16(buf,0xfe);
  array_read_bytes(0xfe,(uint8_t *)&_crc_,chain,2);
  if ((((crc & 0xff) * 0x100 == (_crc_ & 0xff00)) && ((_crc_ & 0xff) * 0x100 == (crc & 0xff00))) &&
     (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s:%d:%s: CAUTION: seems high/low bytes reversed\n","eeprom.c",0x11f,
              "array_check_crc");
    }
    fclose((FILE *)pFile);
  }
  if ((crc != _crc_) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFile_1 = (FILE *)fopen(log_file,"a+");
    if (pFile_1 != (FILE *)0x0) {
      fprintf((FILE *)pFile_1,"%s:%d:%s: chain [%d] CRC error: 0x%x != 0x%x\n","eeprom.c",0x124,
              "array_check_crc",(uint)chain,(uint)crc,(uint)_crc_);
    }
    fclose((FILE *)pFile_1);
  }
  return crc == _crc_;
}

