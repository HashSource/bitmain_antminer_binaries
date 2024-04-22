
undefined4 power_check_reply(byte *param_1,byte *param_2,uint param_3)

{
  FILE *pFVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[3] == param_2[3])) &&
     (uVar2 = (uint)param_2[2], uVar2 + 2 == param_3)) {
    if (uVar2 < 3) {
      uVar4 = 0;
    }
    else {
      uVar3 = 2;
      uVar4 = 0;
      do {
        pbVar5 = param_2 + uVar3;
        uVar3 = uVar3 + 1 & 0xffff;
        uVar4 = *pbVar5 + uVar4 & 0xffff;
      } while (uVar3 < uVar2);
    }
    uVar2 = (uint)param_2[param_3 - 2] + (uint)param_2[param_3 - 1] * 0x100 & 0xffff;
    if (uVar2 == uVar4) {
      return 1;
    }
    if (log_level < 4) {
      if ((param_3 & 0xffff) == 0) {
        return 0;
      }
    }
    else {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: power reply crc error, crc %04x != crc_reply %04x:\n","power.c",
                0x37c,DAT_000423f4,uVar4,uVar2);
      }
      fclose(pFVar1);
      uVar2 = log_level;
      if ((param_3 & 0xffff) == 0) goto LAB_00042278;
    }
    uVar2 = log_level;
    pbVar5 = param_2;
    do {
      if (3 < uVar2) {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%02x ",(uint)*pbVar5);
        }
        fclose(pFVar1);
        uVar2 = log_level;
      }
      pbVar5 = pbVar5 + 1;
    } while (((int)pbVar5 - (int)param_2 & 0xffffU) < (param_3 & 0xffff));
  }
  else {
    if (log_level < 4) {
      if ((param_3 & 0xffff) == 0) {
        return 0;
      }
    }
    else {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: power reply data error:\n","power.c",0x36c,DAT_000423f4);
      }
      fclose(pFVar1);
      uVar2 = log_level;
      if ((param_3 & 0xffff) == 0) goto LAB_00042278;
    }
    uVar2 = log_level;
    pbVar5 = param_2;
    do {
      while (3 < uVar2) {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%02x ",(uint)*pbVar5);
        }
        pbVar5 = pbVar5 + 1;
        fclose(pFVar1);
        uVar2 = log_level;
        if ((param_3 & 0xffff) <= ((int)pbVar5 - (int)param_2 & 0xffffU)) goto LAB_00042278;
      }
      pbVar5 = pbVar5 + 1;
    } while (((int)pbVar5 - (int)param_2 & 0xffffU) < (param_3 & 0xffff));
  }
LAB_00042278:
  if (3 < uVar2) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return 0;
}

