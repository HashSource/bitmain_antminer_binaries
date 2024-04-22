
undefined4 set_iic_power_to_highest_voltage(void)

{
  char cVar1;
  FILE *__stream;
  double dVar2;
  
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: setting to highest voltage...\n","power.c",0x2a0);
    }
    fclose(__stream);
  }
  cVar1 = set_iic_power_voltage((int)DAT_003b0f58,&power_info,0);
  if (cVar1 != '\x01') {
    dVar2 = (double)get_avg_voltage();
    if ((int)((uint)(dVar2 < DAT_00035358) << 0x1f) < 0) {
      stop_mining("power voltage too low\n");
    }
  }
  return 1;
}

