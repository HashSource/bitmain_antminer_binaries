
/* WARNING: Unknown calling convention */

int8_t do_calibration_sensor_offset(uchar device,uchar chip_addr,int chain,int temp_chip_index)

{
  uchar data;
  uint uVar1;
  undefined1 extraout_r2;
  undefined1 uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  double dVar7;
  char logstr [256];
  
  uVar1 = check_reg_temp(device,0xfe,'\0','\0',chip_addr,chain);
  bVar6 = (uVar1 & 0xff) == 0x1a;
  uVar2 = extraout_r2;
  if (bVar6) {
    uVar2 = 1;
  }
  puVar3 = dev->chain_exist + chain * 2 + -2;
  if (bVar6) {
    puVar3 = (uint *)0x6f47d8;
  }
  *(char *)((int)(dev->chain_exist + chain * 2 + -2) + temp_chip_index + 0x468) = (char)uVar1;
  if (bVar6) {
    *(undefined1 *)(puVar3 + 0x386) = uVar2;
  }
  check_reg_temp(device,9,'\x04','\x01',chip_addr,chain);
  check_reg_temp(device,0x11,'\0','\x01',chip_addr,chain);
  uVar1 = check_reg_temp(device,0,'\0','\0',chip_addr,chain);
  iVar5 = (int)(char)((char)uVar1 + -0x40);
  uVar1 = check_reg_temp(device,1,'\0','\0',chip_addr,chain);
  dVar7 = (double)(longlong)iVar5;
  iVar4 = (int)(char)((byte)uVar1 & 0xbf);
  data = (uchar)(int)(0.0 - (float)(((double)(longlong)iVar4 -
                                    (dVar7 + 273.15) * 0.10119047619047628) - dVar7));
  check_reg_temp(device,0x11,data,'\x01',chip_addr,chain);
  sprintf(logstr,"New offset Chain[%d] chip[%d] local:%hhd remote:%hhd offset:%hhd \n",chain,
          (uint)chip_addr,iVar5,iVar4,(int)(char)data);
  writeInitLogFile(logstr);
  return data;
}

