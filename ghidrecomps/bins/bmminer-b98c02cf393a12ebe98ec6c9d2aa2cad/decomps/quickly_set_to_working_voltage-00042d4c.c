
undefined4 quickly_set_to_working_voltage(void)

{
  FILE *pFVar1;
  undefined4 uVar2;
  
  if (log_level < 4) {
    if (DAT_0080b6ec == 0) {
LAB_00042e0a:
      uVar2 = set_iic_power_to_working_voltage();
      return uVar2;
    }
  }
  else {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: setting to working voltage...\n","power.c",0x2d5,DAT_00042e14);
    }
    fclose(pFVar1);
    if (DAT_0080b6ec == 0) goto LAB_00042e0a;
    if (3 < log_level) {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: iic data set to %d\n","power.c",0x2db,DAT_00042e14,DAT_0080b6ec);
      }
      fclose(pFVar1);
    }
  }
  write_iic_of_S9_plus_power(DAT_0080b6ec & 0xff,&power_info);
  return 1;
}

