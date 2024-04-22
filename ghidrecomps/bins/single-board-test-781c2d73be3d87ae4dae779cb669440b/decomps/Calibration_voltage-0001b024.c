
/* WARNING: Unknown calling convention */

int Calibration_voltage(uchar which_chain,uchar which_iic)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  byte bVar6;
  uint which_chain_00;
  uint voltage;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  double dVar11;
  undefined4 uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint uVar16;
  uint *puVar17;
  uint vol0;
  uint vol1;
  uint vol2;
  uint vol3;
  
  which_chain_00 = (uint)which_chain;
  vol0 = 0;
  vol1 = 0;
  vol2 = 0;
  iVar9 = 0x100;
  vol3 = 0;
  voltage = get_target_voltage();
  fVar14 = DAT_0001b310;
  bVar6 = power_calculate_voltage(voltage);
  dVar1 = DAT_0001b2e0;
  uVar10 = (uint)bVar6;
  power_set_voltage(bVar6);
  dVar2 = DAT_0001b2e8;
  printf("\n--- %s: target_V0 = %d, N = %d\n",DAT_0001b314,voltage,uVar10);
  write(power_control_fd,&DAT_0002cbd8,1);
  dVar4 = DAT_0001b2f8;
  dVar3 = DAT_0001b2f0;
  usleep(500000);
  dVar5 = DAT_0001b300;
  enable_dsPIC33EP16GS202_dc_dc(which_chain_00,which_iic,'\x01');
  usleep(500000);
  do {
    while( true ) {
      puVar17 = &vol3;
      iVar7 = dsPIC33EP16GS202_read_out_4_voltage(which_iic,which_chain,&vol0,&vol1,&vol2,&vol3);
      if (iVar7 != 1) break;
      if (gHashBoard_BHB91601P == false) {
        if (gHashBoard_BHB91601S == false) {
          printf("\n!!! %s Please check Hashboard type!\n\n",DAT_0001b314);
        }
        else {
          fVar14 = (float)((((double)(ulonglong)vol0 * dVar1 * dVar2 * dVar3) / 10.0) * dVar4);
        }
      }
      else if (BHB91601_ASIC_NUMBER == 0x3c) {
        fVar14 = (float)((((double)(ulonglong)vol0 * dVar1 * dVar2 * dVar5) / 10.0) * dVar4);
      }
      else if (BHB91601_ASIC_NUMBER == 0x54) {
        fVar14 = (float)((((double)(ulonglong)vol0 * dVar1 * dVar2 * DAT_0001b308) / 10.0) * dVar4);
      }
      fVar13 = (float)(ulonglong)voltage;
      fVar15 = fVar14 - fVar13;
      uVar8 = (undefined4)((ulonglong)(double)fVar14 >> 0x20);
      uVar12 = SUB84((double)fVar14,0);
      dVar11 = (double)fVar15;
      uVar16 = voltage;
      printf("\n--- %s: voltage_V0 = %f, target_V0 = %d, error_value = %f\n\n",DAT_0001b314,uVar12,
             uVar8,voltage,puVar17,dVar11);
      if ((int)((uint)(fVar15 < 0.0) << 0x1f) < 0) {
        fVar15 = -fVar15;
      }
      if ((int)((uint)(fVar15 < (float)(ulonglong)Conf.Voltage_accuracy) << 0x1f) < 0) {
        printf("\n--- %s: Calibration voltage done. voltage_V0 = %f, N = %d, Voltage_accuracy = %d\n"
               ,DAT_0001b314,uVar12,uVar8,uVar10,Conf.Voltage_accuracy,dVar11);
        return 0;
      }
      if (fVar14 == fVar13 || fVar14 < fVar13 != (NAN(fVar14) || NAN(fVar13))) {
        if (uVar10 == 0) {
          printf("\n!!! %s: N = %d, fail\n",DAT_0001b314,0,Conf.Voltage_accuracy,uVar16,puVar17,
                 dVar11);
          enable_dsPIC33EP16GS202_dc_dc(which_chain_00,which_iic,'\0');
          write(power_control_fd,&DAT_0002cbdc,1);
          return -3;
        }
        bVar6 = (char)uVar10 - 1;
      }
      else {
        if (uVar10 == 0xff) {
          printf("\n!!! %s: N = %d, fail\n",DAT_0001b314,0xff,Conf.Voltage_accuracy,uVar16,puVar17,
                 dVar11);
          enable_dsPIC33EP16GS202_dc_dc(which_chain_00,which_iic,'\0');
          write(power_control_fd,&DAT_0002cbdc,1);
          return -2;
        }
        bVar6 = (char)uVar10 + 1;
      }
      uVar10 = (uint)bVar6;
      printf("\n--- %s: N = %d\n",DAT_0001b314,uVar10,Conf.Voltage_accuracy,uVar16,puVar17,dVar11);
      power_set_voltage(bVar6);
      usleep(1000000);
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) goto LAB_0001b1ba;
    }
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
LAB_0001b1ba:
  printf("\n!!! %s: calibration_counter = %d, fail\n",DAT_0001b314,0x100);
  return -1;
}

