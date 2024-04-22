
/* WARNING: Unknown calling convention */

int8_t do_calibration_sensor_offset(uchar device,uchar chip_addr,int chain,int temp_chip_index)

{
  uchar data;
  int8_t middle;
  uint uVar1;
  undefined uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  double dVar6;
  char logstr [256];
  
  uVar2 = 0;
  uVar1 = check_reg_temp(device,0xfe,'\0','\0',chip_addr,chain);
  bVar5 = (uVar1 & 0xff) == 0x1a;
  if (bVar5) {
    uVar2 = 1;
  }
  iVar3 = *DAT_00032ae0 + chain * 8;
  iVar4 = iVar3;
  if (bVar5) {
    iVar4 = DAT_00032ae4;
  }
  *(char *)(temp_chip_index + iVar3 + 0x468) = (char)uVar1;
  if (bVar5) {
    *(undefined *)(iVar4 + 0xe18) = uVar2;
  }
  check_reg_temp(device,9,'\x04','\x01',chip_addr,chain);
  check_reg_temp(device,0x11,'\0','\x01',chip_addr,chain);
  uVar1 = check_reg_temp(device,0,'\0','\0',chip_addr,chain);
  iVar3 = (int)(char)((char)uVar1 + -0x40);
  uVar1 = check_reg_temp(device,1,'\0','\0',chip_addr,chain);
  dVar6 = (double)(longlong)iVar3;
  iVar4 = (int)(char)((byte)uVar1 & 0xbf);
  data = (uchar)(int)(DAT_00032ae8 -
                     (float)(((double)(longlong)iVar4 - (dVar6 + DAT_00032ad0) * DAT_00032ad8) -
                            dVar6));
  check_reg_temp(device,0x11,data,'\x01',chip_addr,chain);
  sprintf(logstr,DAT_00032aec,chain,(uint)chip_addr,iVar3,iVar4,(int)(char)data);
  writeInitLogFile(logstr);
  return data;
}

