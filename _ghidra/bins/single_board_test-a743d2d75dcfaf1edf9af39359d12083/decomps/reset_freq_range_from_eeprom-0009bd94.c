
_Bool reset_freq_range_from_eeprom(eeprom_data_format_t *efd,sweep_ctx *sweep,int asics)

{
  int32_t iVar1;
  uint32_t uVar2;
  int asics_local;
  sweep_ctx *sweep_local;
  eeprom_data_format_t *efd_local;
  char tmp42 [256];
  int freq;
  
  if (efd != (eeprom_data_format_t *)0x0) {
    iVar1 = get_chain_freq_minmax(false,efd,asics);
    sweep->range_freq[0] = (float)(longlong)iVar1;
    sweep->range_freq[1] = (float)(longlong)iVar1 * (sweep->bias + 1.0);
    uVar2 = (*efd->voltage_get)(efd);
    sweep->voltage = uVar2;
    snprintf(tmp42,0x100,
             "from eeprom:reset freq range [%f,%f] eeprom_min_freq:%d, voltage:%d asics:%d",iVar1,
             (double)sweep->range_freq[0],(double)sweep->range_freq[1],iVar1,sweep->voltage,asics);
    puts(tmp42);
  }
  return efd != (eeprom_data_format_t *)0x0;
}

