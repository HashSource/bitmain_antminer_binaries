
int do_calibration_sensor_offset(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  FILE *pFVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_2c;
  
  iVar5 = param_3 * 8;
  cVar2 = *(char *)(dev + iVar5 + param_4 + 0x468);
  if (cVar2 != 'A' && (cVar2 != '\x1a' && cVar2 != 'U')) {
    DEVICEADDR[param_3] = 0x98;
    cVar2 = check_reg_temp(0x98,0xfe,0,0,param_2,param_3);
    uVar1 = log_level;
    *(char *)(dev + iVar5 + param_4 + 0x468) = cVar2;
    if (3 < uVar1) {
      pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: Chain[J%d] try read temp chip[%d] ID=%02x (I2C addr=0x98)\n",
                "driver-btm-c5.c",0x18c4,DAT_00032d6c,param_3 + 1,param_2,
                (uint)*(byte *)(dev + iVar5 + param_4 + 0x468));
      }
      fclose(pFVar3);
      cVar2 = *(char *)(dev + iVar5 + param_4 + 0x468);
    }
    if (cVar2 == 'A' || (cVar2 == 'U' || cVar2 == '\x1a')) {
      param_1 = 0x98;
    }
    else {
      DEVICEADDR[param_3] = 0x9a;
      cVar2 = check_reg_temp(0x9a,0xfe,0,0,param_2,param_3);
      uVar1 = log_level;
      *(char *)(dev + iVar5 + param_4 + 0x468) = cVar2;
      if (3 < uVar1) {
        pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: Chain[J%d] try read temp chip[%d] ID=%02x (I2C addr=0x9A)\n",
                  "driver-btm-c5.c",0x18d0,DAT_00032d6c,param_3 + 1,param_2,
                  (uint)*(byte *)(dev + iVar5 + param_4 + 0x468));
        }
        fclose(pFVar3);
        cVar2 = *(char *)(dev + iVar5 + param_4 + 0x468);
      }
      if (cVar2 == 'A' || (cVar2 == 'U' || cVar2 == '\x1a')) {
        param_1 = 0x9a;
      }
      else {
        DEVICEADDR[param_3] = 0x9c;
        cVar2 = check_reg_temp(0x9c,0xfe,0,0,param_2,param_3);
        uVar1 = log_level;
        *(char *)(dev + iVar5 + param_4 + 0x468) = cVar2;
        if (3 < uVar1) {
          pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d:%s: Chain[J%d] try read temp chip[%d] ID=%02x (I2C addr=0x9C)\n",
                    "driver-btm-c5.c",0x18dc,DAT_00032d6c,param_3 + 1,param_2,
                    (uint)*(byte *)(dev + iVar5 + param_4 + 0x468));
          }
          fclose(pFVar3);
          cVar2 = *(char *)(param_4 + iVar5 + dev + 0x468);
        }
        param_1 = 0x9c;
      }
    }
  }
  if (cVar2 != 'U') {
    is218_Temp = 1;
  }
  check_reg_temp(param_1,9,4,1,param_2,param_3);
  check_reg_temp(param_1,0x11,0,1,param_2,param_3);
  cVar2 = check_reg_temp(param_1,0,0,0,param_2,param_3);
  iVar4 = (int)(char)(cVar2 + -0x40);
  cVar2 = check_reg_temp(param_1,1,0,0,param_2,param_3);
  iVar6 = (int)(char)(cVar2 + -0x40);
  local_2c = (char)(int)(DAT_00032d68 -
                        (float)(((double)(longlong)iVar6 -
                                ((double)(longlong)iVar4 + DAT_00032d58) * DAT_00032d60) -
                               (double)(longlong)iVar4));
  iVar5 = (int)local_2c;
  if (iVar5 < 1) {
    if (log_level < 4) {
      iVar5 = 0x1b;
    }
    else {
      pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,
                "%s:%d:%s: Warning: Chain[%d] chip[%d] local:%hhd remote:%hhd offset:%hhd, will fixed offset=27\n"
                ,"driver-btm-c5.c",0x18fe,DAT_00032d6c,param_3,param_2,iVar4,iVar6,iVar5);
      }
      fclose(pFVar3);
      iVar5 = 0x1b;
    }
  }
  check_reg_temp(param_1,0x11);
  if (3 < log_level) {
    pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: New offset Chain[%d] chip[%d] local:%hhd remote:%hhd offset:%hhd \n"
              ,"driver-btm-c5.c",0x1905,DAT_00032d6c,param_3 + 1,param_2,iVar4,iVar6,iVar5);
    }
    fclose(pFVar3);
    return iVar5;
  }
  return iVar5;
}

