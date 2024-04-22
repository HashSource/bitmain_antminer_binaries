
int quickly_set_to_highest_voltage(void)

{
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  
  if ((DAT_0080b6f0 < DAT_0080b6e8) || (iVar1 = is7007_Board(), iVar1 == 0)) {
    if (log_level < 4) {
      if (DAT_0080b6f0 == 0) {
LAB_00042f66:
        iVar1 = set_iic_power_to_highest_voltage();
        return iVar1;
      }
    }
    else {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: setting to highest voltage...\n","power.c",0x2f2,DAT_00042fbc);
      }
      fclose(pFVar2);
      if (DAT_0080b6f0 == 0) goto LAB_00042f66;
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: iic data set to %d\n","power.c",0x2f8,DAT_00042fbc,DAT_0080b6f0)
          ;
        }
        fclose(pFVar2);
      }
    }
    write_iic_of_S9_plus_power(DAT_0080b6f0 & 0xff,&power_info);
    iVar1 = 1;
  }
  else {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: setting to highest voltage... current iic data:%d\n","power.c",
                0x2e5,DAT_00042fbc,DAT_0080b6e8);
      }
      fclose(pFVar2);
    }
    if (minus_n_number != 0) {
      DAT_0080b6f0 = DAT_0080b6e8;
      minus_n_number = minus_n_number + -1;
    }
    uVar3 = DAT_0080b6f0 & 0xff;
    if (minus_n_number < 2 && 1 < uVar3) {
      uVar3 = uVar3 - 1 & 0xff;
    }
    iVar1 = write_iic_of_S9_plus_power(uVar3,&power_info);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: iic data set to %d\n","power.c",0x2ef,DAT_00042fbc,uVar3);
      }
      iVar1 = fclose(pFVar2);
    }
  }
  return iVar1;
}

