
undefined4 set_iic_power_to_higher_voltage(void)

{
  double dVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  undefined4 extraout_s1;
  double dVar5;
  
  dVar5 = DAT_0080b6d8;
  iVar2 = is7007_Board();
  dVar1 = DAT_0080b6e0;
  if (iVar2 == 0) {
    dVar5 = dVar5 + 0.3;
  }
  else {
    dVar5 = DAT_0080b6d8 + 0.35;
  }
  if (DAT_0080b6e0 < dVar5) {
    iVar2 = is7007_Board();
    if (iVar2 != 0) {
      if (3 < log_level) {
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: setting to higer voltage %f...do nothing, current iic data:%d\n"
                  ,"power.c",0x2ca,"set_iic_power_to_higher_voltage");
        }
        fclose(pFVar3);
        return 1;
      }
      return 1;
    }
    uVar4 = 0;
    dVar5 = dVar1;
  }
  else {
    uVar4 = 1;
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: setting to voltage %f...\n","power.c",0x2be,
              "set_iic_power_to_higher_voltage");
    }
    fclose(pFVar3);
  }
  iVar2 = set_iic_power_voltage(SUB84(dVar5,0),&power_info,uVar4);
  if ((iVar2 == 0) &&
     (uVar4 = get_avg_voltage(),
     (int)((uint)((double)CONCAT44(extraout_s1,uVar4) < 9.7) << 0x1f) < 0)) {
    stop_mining("power voltage too low\n");
  }
  return 1;
}

