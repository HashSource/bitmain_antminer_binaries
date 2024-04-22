
int _eeprom_load_one_chain(int chain,eeprom_layout_t *eeprom_buf)

{
  _Bool _Var1;
  int iVar2;
  eeprom_layout_t *eeprom_buf_local;
  int chain_local;
  eeprom_layout_t eeprom_buf_tmp;
  
  memset(&eeprom_buf_tmp,0,0x100);
  iVar2 = _eeprom_read_iic_bytes((uint8_t)chain,0,0x100,(uint8_t *)&eeprom_buf_tmp);
  if (iVar2 == 0) {
    _Var1 = _eeprom_is_fixture_crc_pass(&eeprom_buf_tmp);
    if ((_Var1) && (_Var1 = _eeprom_is_fixture_header_pass(&eeprom_buf_tmp), _Var1)) {
      _Var1 = _eeprom_is_cgminer_crc_pass(&eeprom_buf_tmp);
      if ((!_Var1) || (_Var1 = _eeprom_is_cgminer_header_pass(&eeprom_buf_tmp), _Var1)) {
        memcpy(eeprom_buf,&eeprom_buf_tmp,0x100);
        iVar2 = 0;
      }
      else {
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

