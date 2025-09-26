
eeprom_data_format_t * edf_create_ctx(int version)

{
  eeprom_data_format_t *peVar1;
  int iVar2;
  int version_local;
  eeprom_data_format_t *ctx;
  int i;
  
  i = 0;
  while( true ) {
    if (2 < i) {
      return (eeprom_data_format_t *)0x0;
    }
    peVar1 = (*submodule_init[i])();
    iVar2 = (*peVar1->version_get)(peVar1);
    if (iVar2 == version) break;
    (*peVar1->destroy)(peVar1);
    i = i + 1;
  }
  return peVar1;
}

