
undefined4 set_iic_power_to_higher_voltage(void)

{
  double dVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  double dVar5;
  
  dVar5 = DAT_0080b6d8;
  iVar2 = is7007_Board();
  dVar1 = DAT_0080b6e0;
  if (iVar2 == 0) {
    dVar5 = dVar5 + DAT_00042c48;
    if (dVar5 != DAT_0080b6e0 && dVar5 < DAT_0080b6e0 == (NAN(dVar5) || NAN(DAT_0080b6e0))) {
LAB_00042b76:
      iVar2 = is7007_Board();
      if (iVar2 != 0) {
        if (log_level < 4) {
          return 1;
        }
        pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: setting to higer voltage %f...do nothing, current iic data:%d\n"
                  ,"power.c",0x2ca,DAT_00042c60);
        }
        fclose(pFVar3);
        return 1;
      }
      uVar4 = 0;
      dVar5 = dVar1;
      goto joined_r0x00042be2;
    }
  }
  else {
    dVar5 = DAT_0080b6d8 + DAT_00042c50;
    if (dVar5 != DAT_0080b6e0 && dVar5 < DAT_0080b6e0 == (NAN(dVar5) || NAN(DAT_0080b6e0)))
    goto LAB_00042b76;
  }
  uVar4 = 1;
joined_r0x00042be2:
  if (3 < log_level) {
    pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: setting to voltage %f...\n","power.c",0x2be,DAT_00042c60);
    }
    fclose(pFVar3);
  }
  iVar2 = set_iic_power_voltage(SUB84(dVar5,0),&power_info,uVar4);
  if ((iVar2 == 0) &&
     (dVar5 = (double)get_avg_voltage(), (int)((uint)(dVar5 < DAT_00042c58) << 0x1f) < 0)) {
    stop_mining("power voltage too low\n");
  }
  return 1;
}

