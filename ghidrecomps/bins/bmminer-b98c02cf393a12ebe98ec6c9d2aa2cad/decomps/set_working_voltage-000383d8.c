
void set_working_voltage(void)

{
  FILE *__stream;
  
  if (log_level < 4) {
    set_iic_power_to_working_voltage();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: setting to working voltage...\n","driver-btm-c5.c",0x2f51,
            DAT_00038434);
  }
  fclose(__stream);
  set_iic_power_to_working_voltage();
  return;
}

