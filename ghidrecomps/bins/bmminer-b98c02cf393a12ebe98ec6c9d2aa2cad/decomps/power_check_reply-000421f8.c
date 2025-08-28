
undefined4 power_check_reply(byte *param_1,byte *param_2,uint param_3)

{
  ushort uVar1;
  FILE *pFVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[3] == param_2[3])) &&
     (uVar3 = (uint)param_2[2], uVar3 + 2 == param_3)) {
    if (uVar3 < 3) {
      uVar5 = 0;
    }
    else {
      uVar4 = 2;
      uVar5 = 0;
      do {
        pbVar6 = param_2 + uVar4;
        uVar4 = uVar4 + 1 & 0xffff;
        uVar5 = *pbVar6 + uVar5 & 0xffff;
      } while (uVar4 < uVar3);
    }
    uVar1 = *(ushort *)(param_2 + (param_3 - 2));
    if (uVar1 == uVar5) {
      return 1;
    }
    if (log_level < 4) {
      if ((param_3 & 0xffff) == 0) {
        return 0;
      }
    }
    else {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power reply crc error, crc %04x != crc_reply %04x:\n","power.c",
                0x37c,"power_check_reply",uVar5,(uint)uVar1);
      }
      fclose(pFVar2);
      uVar3 = log_level;
      if ((param_3 & 0xffff) == 0) goto LAB_00042278;
    }
    uVar3 = log_level;
    pbVar6 = param_2;
    do {
      if (3 < uVar3) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%02x ",(uint)*pbVar6);
        }
        fclose(pFVar2);
        uVar3 = log_level;
      }
      pbVar6 = pbVar6 + 1;
    } while (((int)pbVar6 - (int)param_2 & 0xffffU) < (param_3 & 0xffff));
  }
  else {
    if (log_level < 4) {
      if ((param_3 & 0xffff) == 0) {
        return 0;
      }
    }
    else {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power reply data error:\n","power.c",0x36c,"power_check_reply");
      }
      fclose(pFVar2);
      uVar3 = log_level;
      if ((param_3 & 0xffff) == 0) goto LAB_00042278;
    }
    uVar3 = log_level;
    pbVar6 = param_2;
    do {
      while (3 < uVar3) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%02x ",(uint)*pbVar6);
        }
        pbVar6 = pbVar6 + 1;
        fclose(pFVar2);
        uVar3 = log_level;
        if ((param_3 & 0xffff) <= ((int)pbVar6 - (int)param_2 & 0xffffU)) goto LAB_00042278;
      }
      pbVar6 = pbVar6 + 1;
    } while (((int)pbVar6 - (int)param_2 & 0xffffU) < (param_3 & 0xffff));
  }
LAB_00042278:
  if (3 < uVar3) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    fclose(pFVar2);
  }
  return 0;
}

