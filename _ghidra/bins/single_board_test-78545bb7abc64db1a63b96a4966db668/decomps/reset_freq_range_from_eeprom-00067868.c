
_Bool reset_freq_range_from_eeprom(eeprom_v1 *efd,sweep_ctx *sweep,int asics)

{
  int32_t iVar1;
  int asics_local;
  sweep_ctx *sweep_local;
  eeprom_v1 *efd_local;
  char time_stamp [48];
  char tmp1 [256];
  int freq;
  
  if (efd != (eeprom_v1 *)0x0) {
    iVar1 = get_chain_freq_minmax(false,efd,asics);
    sweep->range_freq[0] = (float)(longlong)iVar1;
    sweep->range_freq[1] = (float)(longlong)iVar1 * (sweep->bias + 1.0);
    sweep->voltage = (uint)(efd->data).field_2.format_v1.pt2.voltage;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : from eeprom:reset freq range [%f,%f] eeprom_min_freq:%d, voltage:%d asics:%d\n",
           "reset_freq_range_from_eeprom",SUB84((double)sweep->range_freq[0],0),
           (int)((ulonglong)(double)sweep->range_freq[0] >> 0x20),(double)sweep->range_freq[1],iVar1
           ,sweep->voltage,asics);
    snprintf(tmp1,0x100,
             "from eeprom:reset freq range [%f,%f] eeprom_min_freq:%d, voltage:%d asics:%d",iVar1,
             (double)sweep->range_freq[0],(double)sweep->range_freq[1],iVar1,sweep->voltage,asics);
    log_to_file(tmp1,time_stamp);
  }
  return efd != (eeprom_v1 *)0x0;
}

