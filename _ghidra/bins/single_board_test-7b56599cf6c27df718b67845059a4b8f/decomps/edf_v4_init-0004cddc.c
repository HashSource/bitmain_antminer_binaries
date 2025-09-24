
/* WARNING: Unknown calling convention */

eeprom_data_format_t * edf_v4_init(void)

{
  eeprom_data_format_t *__dest;
  undefined1 *__s;
  edf_v4_priv *priv;
  eeprom_data_format_t *ctx;
  
  __dest = (eeprom_data_format_t *)malloc(0x128);
  if (__dest == (eeprom_data_format_t *)0x0) {
    __dest = (eeprom_data_format_t *)0x0;
  }
  else {
    __s = (undefined1 *)malloc(0x72);
    if (__dest == (eeprom_data_format_t *)0x0) {
      free((void *)0x0);
      __dest = (eeprom_data_format_t *)0x0;
    }
    else {
      memset(__s,0,0x72);
      *__s = 4;
      __s[1] = 0x11;
      memcpy(__dest,&edf_v4_ops,0x128);
      __dest->priv = __s;
    }
  }
  return __dest;
}

