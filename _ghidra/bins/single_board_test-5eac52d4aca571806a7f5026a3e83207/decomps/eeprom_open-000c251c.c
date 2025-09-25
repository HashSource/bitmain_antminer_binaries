
/* WARNING: Unknown calling convention */

int32_t eeprom_open(uint32_t which_chain)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"%s: Bad eeprom param, input chain is %d\n","eeprom_open",which_chain);
  _applog(0,tmp42,false);
  return -0x7ffffeff;
}

