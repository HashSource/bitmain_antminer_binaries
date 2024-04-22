
undefined4 set_iic_power_to_highest_voltage(void)

{
  int iVar1;
  FILE *__stream;
  
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: setting to highest voltage...\n","power.c",0x2a0,DAT_00042af8);
    }
    fclose(__stream);
  }
  iVar1 = set_iic_power_voltage((int)DAT_0080b6e0,&power_info,0);
  if (iVar1 == 0) {
    set_iic_power_to_working_voltage_part_2();
  }
  return 1;
}

