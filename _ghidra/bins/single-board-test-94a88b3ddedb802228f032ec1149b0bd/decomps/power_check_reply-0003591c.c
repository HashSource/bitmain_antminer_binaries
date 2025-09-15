
undefined4 power_check_reply(char *param_1,char *param_2,byte param_3)

{
  ushort uVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  ushort local_c;
  ushort local_a;
  
  local_a = 0;
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[3] == param_2[3])) &&
     ((byte)param_2[2] + 2 == (uint)param_3)) {
    for (local_c = 2; (int)(uint)local_c < (int)(param_3 - 2); local_c = local_c + 1) {
      local_a = local_a + (byte)param_2[local_c];
    }
    uVar1 = (ushort)(byte)param_2[param_3 - 2] + (ushort)(byte)param_2[param_3 - 1] * 0x100;
    if (local_a == uVar1) {
      uVar3 = 1;
    }
    else {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: power reply crc error, crc %04x != crc_reply %04x:\n","power.c",
                  0x367,(uint)local_a,(uint)uVar1);
        }
        fclose(pFVar2);
      }
      for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%02x ",(uint)(byte)param_2[local_c]);
          }
          fclose(pFVar2);
        }
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fputc(10,pFVar2);
        }
        fclose(pFVar2);
      }
      uVar3 = 0;
    }
  }
  else {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: power reply data error:\n","power.c",0x357);
      }
      fclose(pFVar2);
    }
    for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%02x ",(uint)(byte)param_2[local_c]);
        }
        fclose(pFVar2);
      }
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fputc(10,pFVar2);
      }
      fclose(pFVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}

