
void set_fixed_voltage(void)

{
  FILE *__stream;
  undefined8 in_d0;
  
  DAT_0080b6d8 = in_d0;
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: s9_84_fixed_voltage = %f\n","power.c",0xee,DAT_00041870);
    }
    (*(code *)PTR_fclose_0007cfe8)(__stream);
    return;
  }
  return;
}

