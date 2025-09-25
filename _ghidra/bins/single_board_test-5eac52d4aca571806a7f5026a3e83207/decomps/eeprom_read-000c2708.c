
/* WARNING: Unknown calling convention */

int32_t eeprom_read(uint32_t which_chain,uint8_t addr,uint8_t *buf,uint32_t len)

{
  int32_t iVar1;
  uint8_t *data;
  uint8_t *puVar2;
  uint8_t tmp_addr;
  char tmp42 [2048];
  
  if (which_chain < 0x10) {
    if ((_g_eeprom_state[which_chain].chain_has_opened != 0) ||
       (iVar1 = eeprom_open(which_chain), -1 < iVar1)) {
      if (len != 0) {
        data = buf;
        do {
          puVar2 = data + 1;
          tmp_addr = addr;
          iVar1 = iic_read_reg(_g_eeprom_state[which_chain].eeprom_fd,&tmp_addr,1,data,1,true);
          addr = addr + '\x01';
          if (iVar1 != 1) {
            snprintf(tmp42,0x800,"fail to read eeprom by iic, chain: %d, addr: %d\n",which_chain,
                     (uint)tmp_addr);
            _applog(0,tmp42,false);
            return -0x7fffff00;
          }
          data = puVar2;
        } while (puVar2 != buf + len);
      }
      usleep(500000);
      return 0;
    }
    snprintf(tmp42,0x800,"%s: auto exec eeprom_open, but chain %d open eeprom failed\n",
             "eeprom_read",which_chain);
    _applog(0,tmp42,false);
  }
  else {
    snprintf(tmp42,0x800,"%s: Bad eeprom param, input chain is %d\n","eeprom_read",which_chain);
    _applog(0,tmp42,false);
    iVar1 = -0x7ffffeff;
  }
  return iVar1;
}

