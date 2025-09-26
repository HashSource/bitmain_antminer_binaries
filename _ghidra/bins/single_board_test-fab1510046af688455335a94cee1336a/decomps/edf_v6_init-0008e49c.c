
/* WARNING: Unknown calling convention */

eeprom_data_format_t * edf_v6_init(void)

{
  eeprom_data_format_t *__dest;
  undefined1 *__s;
  edf_v6_priv *priv;
  eeprom_data_format_t *ctx;
  
  __dest = (eeprom_data_format_t *)malloc(0x130);
  if (__dest == (eeprom_data_format_t *)0x0) {
    __dest = (eeprom_data_format_t *)0x0;
  }
  else {
    __s = (undefined1 *)malloc(0xfa);
    if (__dest == (eeprom_data_format_t *)0x0) {
      free((void *)0x0);
      __dest = (eeprom_data_format_t *)0x0;
    }
    else {
      memset(__s,0,0xfa);
      *__s = 6;
      __s[1] = 0x11;
      memcpy(__dest,&edf_v6_ops,0x130);
      __dest->priv = __s;
    }
  }
  return __dest;
}

