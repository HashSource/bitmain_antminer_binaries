
void set_fixed_voltage(void)

{
  FILE *__stream;
  undefined8 in_d0;
  
  DAT_0080b6d8 = in_d0;
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: s9_84_fixed_voltage = %f\n","power.c",0xee,"set_fixed_voltage");
    }
    fclose(__stream);
    return;
  }
  return;
}

