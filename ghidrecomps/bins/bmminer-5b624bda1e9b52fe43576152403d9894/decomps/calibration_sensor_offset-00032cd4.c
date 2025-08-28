
/* WARNING: Unknown calling convention */

int8_t calibration_sensor_offset(uchar device,int chain)

{
  uchar uVar1;
  int8_t iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  all_parameters *paVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char temp_offset [8];
  char logstr [256];
  
  iVar7 = chain + 1;
  iVar9 = chain * 8;
  get_temperature_offset_value((uchar)chain,(uchar *)temp_offset);
  iVar8 = (int)temp_offset[1];
  uVar4 = (uint)temp_offset[2];
  pcVar10 = temp_offset;
  sprintf(logstr,"Chain[J%d] PIC temp offset=%d,%d,%d,%d,%d,%d,%d,%d\n",iVar7,(int)temp_offset[0],
          iVar8,uVar4,(int)temp_offset[3],(int)temp_offset[4],(int)temp_offset[5],
          (int)temp_offset[6],(int)temp_offset[7]);
  writeInitLogFile(logstr);
  paVar6 = dev;
  cVar5 = '\0';
  iVar11 = 0;
  iVar12 = (int)dev->chain_exist + chain + -8;
  *(undefined1 *)(iVar12 + 0x458) = 0;
  do {
    if ('\0' < *pcVar10) {
      paVar6->TempChipAddr[chain][cVar5] = (*pcVar10 + -1) * '\x04';
      *(char *)((int)&h + dev->chain_asic_temp_num[chain] + iVar9 + 0x50) = pcVar10[1];
      set_baud_with_addr(paVar6->baud,0,paVar6->TempChipAddr[chain][*(char *)(iVar12 + 0x458)],chain
                         ,1,0,1);
      check_asic_reg_with_addr
                (0x1c,(uint)dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain,1);
      uVar3 = check_reg_temp(device,0xfe,'\0','\0',
                             dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain);
      paVar6 = dev;
      uVar4 = uVar3 & 0xff;
      iVar12 = (int)dev->chain_asic_temp_num[chain];
      dev->TempChipType[chain][iVar12] = (uchar)uVar3;
      iVar8 = (int)*(char *)((int)&h + iVar12 + iVar9 + 0x50);
      sprintf(logstr,"Chain[J%d] chip[%d] use PIC middle temp offset=%d typeID=%02x\n",iVar7,
              (uint)paVar6->TempChipAddr[chain][iVar12],iVar8,uVar4);
      writeInitLogFile(logstr);
      paVar6 = dev;
      iVar12 = (int)dev->chain_asic_temp_num[chain];
      uVar1 = dev->TempChipType[chain][iVar12];
      if (uVar1 != 'U' && uVar1 != '\x1a') {
        dev->chain_asic_temp_num[chain] = '\0';
        goto LAB_00032ed2;
      }
      if (uVar1 == '\x1a') {
        is218_Temp = true;
      }
      iVar2 = do_calibration_sensor_offset(device,dev->TempChipAddr[chain][iVar12],chain,iVar12);
      paVar6 = dev;
      *(int8_t *)((int)&h + iVar12 + iVar9 + 0x50) = iVar2;
      iVar8 = (int)*(char *)((int)&h + paVar6->chain_asic_temp_num[chain] + iVar9 + 0x50);
      uVar4 = (uint)paVar6->TempChipType[chain][paVar6->chain_asic_temp_num[chain]];
      sprintf(logstr,"Chain[J%d] chip[%d] get middle temp offset=%d typeID=%02x\n",iVar7,
              (uint)paVar6->TempChipAddr[chain][iVar11],iVar8,uVar4);
      writeInitLogFile(logstr);
      paVar6 = dev;
      iVar12 = (int)dev->chain_exist + chain + -8;
      cVar5 = *(char *)(iVar12 + 0x458) + '\x01';
      *(char *)(iVar12 + 0x458) = cVar5;
    }
    iVar11 = iVar11 + 1;
    pcVar10 = pcVar10 + 2;
  } while (iVar11 != 4);
  paVar6 = (all_parameters *)(int)cVar5;
  if ((int)paVar6 < 1) {
    iVar9 = chain << 3;
LAB_00032ed2:
    sprintf(logstr,"Warning: Chain[J%d] has no temp offset in PIC! will fix it\n",iVar7,paVar6,iVar8
            ,uVar4);
    writeInitLogFile(logstr);
    paVar6 = dev;
    iVar12 = 0;
    dev->TempChipAddr[chain][0] = '\0';
    paVar6->chain_asic_temp_num[chain] = '\x02';
    paVar6->TempChipAddr[0][iVar9 + 1] = ' ';
    do {
      set_baud_with_addr(paVar6->baud,0,paVar6->TempChipAddr[0][iVar12 + iVar9],chain,1,0,1);
      check_asic_reg_with_addr(0x1c,(uint)dev->TempChipAddr[0][iVar12 + iVar9],chain,1);
      iVar2 = do_calibration_sensor_offset(device,dev->TempChipAddr[0][iVar12 + iVar9],chain,iVar12)
      ;
      paVar6 = dev;
      middle_Offset[0][iVar12 + iVar9] = iVar2;
      iVar8 = iVar12 + iVar9;
      iVar12 = iVar12 + 1;
      sprintf(logstr,"Chain[J%d] chip[%d] get middle temp offset=%d typeID=%02x\n",iVar7,
              (uint)paVar6->TempChipAddr[0][iVar8],(int)iVar2,(uint)paVar6->TempChipType[0][iVar8]);
      writeInitLogFile(logstr);
      paVar6 = dev;
    } while (iVar12 < dev->chain_asic_temp_num[chain]);
  }
  return '\0';
}

