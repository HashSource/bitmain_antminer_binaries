
undefined4 set_iic_power_to_working_voltage(void)

{
  int iVar1;
  FILE *__stream;
  
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: setting to working voltage...\n","power.c",0x28e,DAT_00042a84);
    }
    fclose(__stream);
  }
  iVar1 = set_iic_power_voltage((int)DAT_0080b6d8,&power_info,1);
  if (iVar1 == 0) {
    set_iic_power_to_working_voltage_part_2();
  }
  return 1;
}

