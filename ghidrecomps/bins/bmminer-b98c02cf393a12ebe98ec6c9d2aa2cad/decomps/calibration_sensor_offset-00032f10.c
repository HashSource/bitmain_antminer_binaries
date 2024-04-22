
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 calibration_sensor_offset(undefined4 param_1,uint param_2)

{
  undefined uVar1;
  char cVar2;
  FILE *pFVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char **ppcVar10;
  uint uVar11;
  uint uVar12;
  char **ppcVar13;
  char *pcVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  char **local_58;
  undefined4 local_4c;
  char *local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined2 local_2c;
  char *pcStack_2a;
  
  local_38 = 0;
  local_3c = (char *)0x0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  pthread_mutex_lock(DAT_0003325c);
  AT24C02_read_bytes_part_7(0x98,&local_3c,param_2 & 0xff,8);
  pthread_mutex_unlock(DAT_0003325c);
  if (3 < log_level) {
    pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: Chain[J%d] PIC temp offset: ","driver-btm-c5.c",0x19d6,DAT_000336dc,
              param_2 + 1);
    }
    fclose(pFVar3);
  }
  ppcVar13 = &pcStack_2a;
  uVar12 = log_level;
  ppcVar10 = &local_3c;
  do {
    while (3 < uVar12) {
      pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%d,",(int)*(char *)ppcVar10);
      }
      ppcVar10 = (char **)((int)ppcVar10 + 1);
      fclose(pFVar3);
      uVar12 = log_level;
      if (ppcVar10 == ppcVar13) goto LAB_00032fb4;
    }
    ppcVar10 = (char **)((int)ppcVar10 + 1);
  } while (ppcVar10 != ppcVar13);
LAB_00032fb4:
  if (uVar12 < 4) {
    uVar11 = local_38 >> 0x10 & 0x1f;
    if (uVar11 == 7) {
      DEVICEADDR[param_2] = 0x9c;
LAB_00033246:
      local_4c = 0x9c;
      chip_hasNoMiddle = 1;
      goto LAB_0003301a;
    }
LAB_00032fcc:
    if ((uVar11 == 9) || (uVar11 == 6)) {
      if (3 < uVar12) {
        ppcVar13 = (char **)0x5a4;
      }
      local_4c = 0x9a;
      if (3 < uVar12) {
        ppcVar13 = (char **)((uint)ppcVar13 & 0xffff | 0x80000);
      }
      DEVICEADDR[param_2] = 0x9a;
    }
    else {
      if (3 < uVar12) {
        ppcVar13 = (char **)0x5a4;
      }
      local_4c = 0x98;
      if (3 < uVar12) {
        ppcVar13 = (char **)((uint)ppcVar13 & 0xffff | 0x80000);
      }
      DEVICEADDR[param_2] = 0x98;
    }
    if (3 < uVar12) goto LAB_000332fe;
  }
  else {
    ppcVar13 = &log_file;
    pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fputc(10,pFVar3);
    }
    fclose(pFVar3);
    uVar12 = log_level;
    uVar11 = local_38 >> 0x10 & 0x1f;
    if (uVar11 != 7) goto LAB_00032fcc;
    DEVICEADDR[param_2] = 0x9c;
    if (uVar12 < 4) goto LAB_00033246;
    local_4c = 0x9c;
LAB_000332fe:
    pFVar3 = fopen(*ppcVar13,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: chain[%d] temp chip I2C addr=0x%02x\n","driver-btm-c5.c",0x19f8,
              DAT_000336dc,param_2 + 1,local_4c);
    }
    fclose(pFVar3);
  }
  if ((1 < uVar11 - 1) && (chip_hasNoMiddle = 1, 3 < log_level)) {
    pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: chain[%d] has no middle temp, use special fix mode.\n",
              "driver-btm-c5.c",0x1a00,DAT_000336dc,param_2 + 1);
    }
    fclose(pFVar3);
  }
LAB_0003301a:
  iVar9 = dev;
  iVar7 = 0;
  iVar6 = 1;
  *(undefined *)(dev + param_2 + 0x458) = 0;
  uVar12 = 0;
  do {
    if (iVar7 != 3) {
      if (*(char *)((int)&local_3c + iVar7 * 2) != '\0') {
        uVar12 = uVar12 + 1 & 0xff;
      }
      if (iVar6 == 9) break;
    }
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 1;
  } while( true );
  if (uVar12 != 0) {
    iVar6 = param_2 * 8;
    iVar8 = 0;
    iVar7 = iVar6 + 0x708e90;
    uVar11 = 0;
    local_58 = &local_3c;
    do {
      cVar2 = *(char *)((int)&local_3c + uVar11 * 2);
      if ((byte)(cVar2 - 1U) < 0x53) {
        cVar2 = (cVar2 + -1) * '\x03';
        *(char *)(iVar9 + iVar6 + iVar8 + 0x4e8) = cVar2;
        uVar1 = *(undefined *)(iVar9 + 0x542f);
        *(char *)(iVar7 + iVar8 + 0x488) = *(char *)((int)local_58 + 1);
        set_baud_with_addr(uVar1,0,cVar2,param_2,1,0,1);
        check_asic_reg_with_addr
                  (0x1c,*(undefined *)(dev + iVar6 + (int)*(char *)(dev + param_2 + 0x458) + 0x4e8),
                   param_2,1);
        uVar17 = (uint)*(byte *)(dev + iVar6 + (int)*(char *)(dev + param_2 + 0x458) + 0x4e8);
        uVar16 = param_2;
        uVar1 = check_reg_temp(local_4c,0xfe,0,0,uVar17,param_2);
        iVar9 = dev;
        uVar5 = log_level;
        iVar8 = dev + param_2;
        *(undefined *)((int)*(char *)(iVar8 + 0x458) + dev + iVar6 + 0x468) = uVar1;
        if (3 < uVar5) {
          pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar3 != (FILE *)0x0) {
            uVar16 = param_2 + 1;
            iVar9 = (int)*(char *)(dev + param_2 + 0x458);
            iVar8 = dev + iVar6 + iVar9;
            uVar17 = DAT_000336dc;
            fprintf(pFVar3,
                    "%s:%d:%s: Chain[J%d] chip[%d] use PIC middle temp offset=%d typeID=%02x\n",
                    "driver-btm-c5.c",0x1a19,DAT_000336dc,uVar16,(uint)*(byte *)(iVar8 + 0x4e8),
                    (int)*(char *)(iVar9 + iVar7 + 0x488),(uint)*(byte *)(iVar8 + 0x468));
          }
          fclose(pFVar3);
          iVar8 = dev + param_2;
          iVar9 = dev;
        }
        iVar15 = (int)*(char *)(iVar8 + 0x458);
        iVar8 = iVar9 + iVar6 + iVar15;
        uVar18 = (uint)*(byte *)(iVar8 + 0x468);
        uVar5 = uVar18 - 0x55;
        if (uVar5 != 0) {
          uVar5 = 1;
        }
        if (uVar18 == 0x1a) {
          uVar4 = 0;
        }
        else {
          uVar4 = uVar5 & 1;
        }
        if (uVar18 == 0x41) {
          uVar4 = 0;
        }
        if (uVar4 != 0) {
          uVar17 = (uint)*(byte *)(iVar8 + 0x4e8);
          uVar5 = 0;
          local_4c = 0x98;
          chip_hasNoMiddle = 1;
          DEVICEADDR[param_2] = 0x98;
          uVar16 = param_2;
          cVar2 = check_reg_temp(0x98,0xfe,0,0,uVar17,param_2);
          iVar9 = dev;
          iVar8 = dev + param_2;
          if (cVar2 == 'U' || cVar2 == '\x1a') {
            uVar5 = 1;
          }
          if (cVar2 != 'U' && cVar2 != '\x1a') {
            uVar5 = 0;
          }
          if (cVar2 == 'A') {
            uVar5 = uVar5 | 1;
          }
          iVar15 = (int)*(char *)(iVar8 + 0x458) + dev + iVar6;
          *(char *)(iVar15 + 0x468) = cVar2;
          if (uVar5 == 0) {
            local_4c = 0x9a;
            uVar17 = (uint)*(byte *)(iVar15 + 0x4e8);
            DEVICEADDR[param_2] = 0x9a;
            uVar16 = param_2;
            cVar2 = check_reg_temp(0x9a,0xfe,0);
            iVar9 = dev;
            iVar8 = dev + param_2;
            if (cVar2 == 'U' || cVar2 == '\x1a') {
              uVar5 = 1;
            }
            if (cVar2 != 'U' && cVar2 != '\x1a') {
              uVar5 = 0;
            }
            if (cVar2 == 'A') {
              uVar5 = uVar5 | 1;
            }
            iVar15 = (int)*(char *)(iVar8 + 0x458) + dev + iVar6;
            *(char *)(iVar15 + 0x468) = cVar2;
            if (uVar5 == 0) {
              uVar17 = (uint)*(byte *)(iVar15 + 0x4e8);
              local_4c = 0x9c;
              DEVICEADDR[param_2] = 0x9c;
              uVar16 = param_2;
              uVar1 = check_reg_temp(0x9c,0xfe,0);
              iVar9 = dev;
              iVar8 = dev + param_2;
              *(undefined *)((int)*(char *)(iVar8 + 0x458) + dev + iVar6 + 0x468) = uVar1;
            }
          }
          iVar15 = (int)*(char *)(iVar8 + 0x458);
          uVar18 = (uint)*(byte *)(iVar9 + iVar6 + iVar15 + 0x468);
          uVar5 = uVar18 - 0x55;
          if (uVar5 != 0) {
            uVar5 = 1;
          }
          if (uVar18 == 0x1a) {
            uVar4 = 0;
          }
          else {
            uVar4 = uVar5 & 1;
          }
          if (uVar18 == 0x41) {
            uVar4 = 0;
          }
          if (uVar4 != 0) {
            *(undefined *)(iVar8 + 0x458) = 0;
            goto joined_r0x00033694;
          }
        }
        if (uVar5 != 0) {
          is218_Temp = 1;
        }
        uVar1 = do_calibration_sensor_offset
                          (local_4c,*(undefined *)(iVar9 + iVar6 + iVar15 + 0x4e8),param_2,iVar15,
                           uVar17,uVar16);
        uVar5 = log_level;
        *(undefined *)(iVar15 + iVar7 + 0x488) = uVar1;
        if (3 < uVar5) {
          pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar3 != (FILE *)0x0) {
            iVar9 = (int)*(char *)(dev + param_2 + 0x458);
            fprintf(pFVar3,"%s:%d:%s: Chain[J%d] chip[%d] get middle temp offset=%d typeID=%02x\n",
                    "driver-btm-c5.c",0x1a76,DAT_000336dc,param_2 + 1,
                    (uint)*(byte *)(dev + iVar6 + uVar11 + 0x4e8),
                    (int)*(char *)(iVar9 + iVar7 + 0x488),
                    (uint)*(byte *)(dev + iVar6 + iVar9 + 0x468));
          }
          fclose(pFVar3);
        }
        iVar9 = dev;
        cVar2 = *(char *)(dev + param_2 + 0x458) + '\x01';
        iVar8 = (int)cVar2;
        *(char *)(dev + param_2 + 0x458) = cVar2;
      }
      uVar11 = uVar11 + 1;
      local_58 = (char **)((int)local_58 + 2);
    } while (uVar11 != uVar12);
    if (0 < iVar8) {
      return 0;
    }
  }
  iVar6 = param_2 << 3;
joined_r0x00033694:
  if (3 < log_level) {
    pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: Warning: Chain[J%d] has no temp offset in PIC! will fix it\n",
              "driver-btm-c5.c",0x1a82,DAT_000336dc,param_2 + 1);
    }
    fclose(pFVar3);
  }
  iVar7 = dev;
  iVar9 = DAT_000336e0;
  *(undefined *)(dev + param_2 + 0x458) = 2;
  *(undefined *)(iVar7 + (param_2 + 0x9d) * 8) = 0x45;
  iVar8 = 0;
  *(undefined *)(iVar7 + iVar6 + 0x4e9) = 0x84;
  pcVar14 = (char *)(iVar9 + iVar6);
  do {
    set_baud_with_addr(*(undefined *)(iVar7 + 0x542f),0,
                       *(undefined *)(iVar7 + iVar6 + iVar8 + 0x4e8),param_2,1,0,1);
    check_asic_reg_with_addr(0x1c,*(undefined *)(dev + iVar6 + iVar8 + 0x4e8),param_2,1);
    if (3 < log_level) {
      pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: Chain[J%d] use default temp chip[%d] \n","driver-btm-c5.c",0x1afe,
                DAT_000336dc,param_2 + 1,(uint)*(byte *)(dev + iVar6 + iVar8 + 0x4e8));
      }
      fclose(pFVar3);
    }
    cVar2 = do_calibration_sensor_offset
                      (local_4c,*(undefined *)(dev + iVar6 + iVar8 + 0x4e8),param_2,iVar8);
    uVar12 = log_level;
    *pcVar14 = cVar2;
    if (3 < uVar12) {
      pFVar3 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar3 != (FILE *)0x0) {
        iVar9 = dev + iVar6 + iVar8;
        fprintf(pFVar3,"%s:%d:%s: Chain[J%d] chip[%d] get middle temp offset=%d typeID=%02x\n",
                "driver-btm-c5.c",0x1b03,DAT_000336dc,param_2 + 1,(uint)*(byte *)(iVar9 + 0x4e8),
                (int)*pcVar14,(uint)*(byte *)(iVar9 + 0x468));
      }
      fclose(pFVar3);
    }
    iVar8 = iVar8 + 1;
    pcVar14 = pcVar14 + 1;
    iVar7 = dev;
  } while (iVar8 < *(char *)(dev + param_2 + 0x458));
  return 0;
}

