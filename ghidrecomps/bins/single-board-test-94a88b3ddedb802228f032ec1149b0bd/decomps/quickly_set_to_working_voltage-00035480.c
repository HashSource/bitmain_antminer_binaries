
undefined4 quickly_set_to_working_voltage(void)

{
  FILE *pFVar1;
  undefined4 uVar2;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: setting to working voltage...\n","power.c",0x2cf);
    }
    fclose(pFVar1);
  }
  if (DAT_003b0f64 == 0) {
    uVar2 = set_iic_power_to_working_voltage();
  }
  else {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: iic data set to %d\n","power.c",0x2d5,DAT_003b0f64);
      }
      fclose(pFVar1);
    }
    write_iic_of_S9_plus_power(DAT_003b0f64 & 0xff,&power_info);
    uVar2 = 1;
  }
  return uVar2;
}

