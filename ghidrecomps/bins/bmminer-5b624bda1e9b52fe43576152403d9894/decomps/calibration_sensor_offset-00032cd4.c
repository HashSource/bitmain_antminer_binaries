
/* WARNING: Unknown calling convention */

int8_t calibration_sensor_offset(uchar device,int chain)

{
  int *piVar1;
  char *__format;
  int8_t iVar2;
  int iVar3;
  uint uVar4;
  uint ret;
  uint uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  int i;
  int iVar13;
  char temp_offset [8];
  char logstr [256];
  
  iVar8 = chain + 1;
  iVar10 = chain * 8;
  get_temperature_offset_value((uchar)chain,(uchar *)temp_offset);
  piVar1 = DAT_00032f9c;
  iVar9 = (int)temp_offset[1];
  uVar5 = (uint)temp_offset[2];
  pcVar11 = temp_offset;
  sprintf(logstr,DAT_00032fa0,iVar8,(int)temp_offset[0],iVar9,uVar5,(int)temp_offset[3],
          (int)temp_offset[4],(int)temp_offset[5],(int)temp_offset[6],(int)temp_offset[7]);
  writeInitLogFile(logstr);
  iVar3 = *piVar1;
  cVar7 = '\0';
  iVar12 = 0;
  iVar13 = DAT_00032fa4 + iVar10;
  iVar6 = iVar3 + chain;
  *(undefined *)(iVar6 + 0x458) = 0;
  do {
    if ('\0' < *pcVar11) {
      *(char *)((int)cVar7 + iVar3 + iVar10 + 0x4e8) = (*pcVar11 + -1) * '\x04';
      *(char *)(*(char *)(*piVar1 + chain + 0x458) + iVar13 + 0x50) = pcVar11[1];
      set_baud_with_addr(*(uchar *)(iVar3 + 0x2fea),0,
                         *(uchar *)(iVar3 + iVar10 + (int)*(char *)(iVar6 + 0x458) + 0x4e8),chain,1,
                         0,1);
      check_asic_reg_with_addr
                (0x1c,(uint)*(byte *)(*piVar1 + iVar10 + (int)*(char *)(*piVar1 + chain + 0x458) +
                                     0x4e8),chain,1);
      uVar4 = check_reg_temp(device,0xfe,'\0','\0',
                             *(uchar *)((int)*(char *)(*piVar1 + chain + 0x458) + *piVar1 + iVar10 +
                                       0x4e8),chain);
      __format = DAT_00032fa8;
      uVar5 = uVar4 & 0xff;
      iVar6 = (int)*(char *)(*piVar1 + chain + 0x458);
      iVar3 = *piVar1 + iVar10 + iVar6;
      *(char *)(iVar3 + 0x468) = (char)uVar4;
      iVar9 = (int)*(char *)(iVar6 + iVar13 + 0x50);
      sprintf(logstr,__format,iVar8,(uint)*(byte *)(iVar3 + 0x4e8),iVar9,uVar5);
      writeInitLogFile(logstr);
      iVar3 = *piVar1;
      iVar6 = (int)*(char *)(iVar3 + chain + 0x458);
      cVar7 = *(char *)(iVar3 + iVar10 + iVar6 + 0x468);
      if (cVar7 != 'U' && cVar7 != '\x1a') {
        *(undefined *)(iVar3 + chain + 0x458) = 0;
        goto LAB_00032ed2;
      }
      if (cVar7 == '\x1a') {
        is218_Temp = true;
      }
      iVar2 = do_calibration_sensor_offset
                        (device,*(uchar *)(iVar3 + iVar10 + iVar6 + 0x4e8),chain,iVar6);
      iVar3 = *piVar1;
      *(int8_t *)(iVar6 + iVar13 + 0x50) = iVar2;
      iVar6 = iVar3 + iVar10;
      iVar3 = (int)*(char *)(iVar3 + chain + 0x458);
      iVar9 = (int)*(char *)(iVar13 + iVar3 + 0x50);
      uVar5 = (uint)*(byte *)(iVar3 + iVar6 + 0x468);
      sprintf(logstr,DAT_00032fac,iVar8,(uint)*(byte *)(iVar6 + iVar12 + 0x4e8),iVar9,uVar5);
      writeInitLogFile(logstr);
      iVar3 = *piVar1;
      iVar6 = iVar3 + chain;
      cVar7 = *(char *)(iVar6 + 0x458) + '\x01';
      *(char *)(iVar6 + 0x458) = cVar7;
    }
    iVar12 = iVar12 + 1;
    pcVar11 = pcVar11 + 2;
  } while (iVar12 != 4);
  iVar3 = (int)cVar7;
  if (iVar3 < 1) {
LAB_00032ed2:
    iVar10 = chain * 8;
    sprintf(logstr,DAT_00032fb0,iVar8,iVar3,iVar9,uVar5);
    writeInitLogFile(logstr);
    iVar3 = DAT_00032fb4;
    iVar6 = *piVar1;
    iVar9 = 0;
    *(undefined *)(iVar6 + (chain + 0x9d) * 8) = 0;
    *(undefined *)(iVar6 + chain + 0x458) = 2;
    *(undefined *)(iVar6 + iVar10 + 0x4e9) = 0x20;
    do {
      set_baud_with_addr(*(uchar *)(iVar6 + 0x2fea),0,*(uchar *)(iVar6 + iVar10 + iVar9 + 0x4e8),
                         chain,1,0,1);
      check_asic_reg_with_addr(0x1c,(uint)*(byte *)(*piVar1 + iVar10 + iVar9 + 0x4e8),chain,1);
      iVar2 = do_calibration_sensor_offset
                        (device,*(uchar *)(*piVar1 + iVar10 + iVar9 + 0x4e8),chain,iVar9);
      iVar6 = *piVar1;
      *(int8_t *)(iVar3 + iVar10 + iVar9) = iVar2;
      iVar6 = iVar6 + iVar10 + iVar9;
      iVar9 = iVar9 + 1;
      sprintf(logstr,DAT_00032fac,iVar8,(uint)*(byte *)(iVar6 + 0x4e8),(int)iVar2,
              (uint)*(byte *)(iVar6 + 0x468));
      writeInitLogFile(logstr);
      iVar6 = *piVar1;
    } while (iVar9 < *(char *)(iVar6 + chain + 0x458));
  }
  return '\0';
}

