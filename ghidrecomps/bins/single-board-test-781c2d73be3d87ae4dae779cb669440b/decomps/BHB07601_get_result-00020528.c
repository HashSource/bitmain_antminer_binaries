
/* WARNING: Unknown calling convention */

uint BHB07601_get_result(uchar which_chain)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  byte bVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint local_34;
  
  uVar2 = (uint)which_chain;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  uVar8 = 0;
  printf("every ASIC require nonce number: %u\n",Conf.pattern_number * 0x2a0);
  local_34 = 0xf;
  uVar11 = 0;
  while (uVar11 < BHB07601_ASIC_NUMBER) {
    uVar3 = calculate_how_many_nonce_per_asic_get(which_chain,(uchar)uVar11,0x2a0);
    uVar10 = uVar11 + 1;
    if ((uVar3 < Conf.pattern_number * 0x2a0) && (uVar8 = uVar8 + 1, Conf.Invalid_Asic_Num < uVar8))
    {
      local_34 = 0xe;
    }
    printf("IC[%02d]=%-10d",uVar11,uVar3);
    uVar11 = uVar10;
    if ((uVar10 & 3) == 0) {
      putchar(10);
    }
  }
  if (BHB07601_ASIC_NUMBER != 0) {
    uVar11 = 0;
    puVar9 = (uint *)(DAT_00020698 + uVar2 * 0x80000);
    do {
      uVar8 = calculate_how_many_nonce_per_asic_get(which_chain,(uchar)uVar11,0x2a0);
      if (uVar8 < Conf.pattern_number * 0x2a0) {
        puVar7 = puVar9 + -0x2a0;
        uVar3 = 0;
        do {
          puVar7 = puVar7 + 1;
          if ((*puVar7 < Conf.pattern_number) && (*puVar7 < Conf.Least_nonce_per_core)) {
            uVar3 = uVar3 + 1;
          }
        } while (puVar9 != puVar7);
        if (Conf.Invalid_Core_Num < uVar3) {
          local_34 = 0xe;
          printf("\nerror asic is %d\n",uVar11);
        }
        if (Conf.Dump_Lost_Nonce != 0) {
          printf("asic[%02d] = %d\n",uVar11,uVar8);
          dump_core_lost_nonce(which_chain,(uchar)uVar11);
          puts("\n");
        }
      }
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 0x400;
    } while (uVar11 < BHB07601_ASIC_NUMBER);
  }
  printf("\nevery Domain require nonce number: %u\n",
         (BHB07601_ASIC_NUMBER / 0xc) * Conf.pattern_number * 0xa8,
         BHB07601_ASIC_NUMBER * -0x55555555);
  uVar11 = calculate_how_many_nonce_per_domain_get(which_chain,'\0');
  printf("D[%02d]:%-10d ",0,uVar11);
  uVar8 = 1;
  do {
    while( true ) {
      uVar10 = uVar8 + 1;
      uVar3 = calculate_how_many_nonce_per_domain_get(which_chain,(uchar)uVar8);
      uVar11 = uVar11 + uVar3;
      printf("D[%02d]:%-10d ",uVar8,uVar3);
      if ((uVar10 & 3) != 0) break;
      printf("D_BIG[%02d]:%-10d\n",uVar8 >> 2,uVar11);
      uVar11 = 0;
      uVar8 = uVar10;
      if (uVar10 == 0x30) goto LAB_000206dc;
    }
    uVar8 = uVar10;
  } while (uVar10 != 0x30);
LAB_000206dc:
  printf("\nHW number = %d, Conf.Most_HW_Num = %d\n\n",gHw_Nonce_Num[uVar2],Conf.Most_HW_Num);
  if (Conf.Most_HW_Num < gHw_Nonce_Num[uVar2]) {
    local_34 = 0xe;
  }
  puts(
      "\n------------------------------------------------------------------------------------------------------\n"
      );
  if ((gSensor_OK[uVar2][2] & gSensor_OK[uVar2][1] & gSensor_OK[uVar2][0] & gSensor_OK[uVar2][3]) ==
      0) {
    local_34 = local_34 & 0xfffffffd;
  }
  bVar6 = gHigherThanAlarmTemp;
  if (Conf.TargetTemp < gGlobalHighestTemp) {
    bVar6 = gHigherThanAlarmTemp | 1;
  }
  if (bVar6 != 0) {
    local_34 = local_34 & 0xfffffffb;
  }
  gBad_Chip.idx[0] = 0;
  gBad_Chip.nonce_num[0] = Conf.pattern_number * 0x2a0;
  gBad_Chip.idx[1] = 0;
  gBad_Chip.idx[2] = 0;
  gBad_Chip.idx[3] = 0;
  gBad_Chip.nonce_num[1] = gBad_Chip.nonce_num[0];
  gBad_Chip.nonce_num[2] = gBad_Chip.nonce_num[0];
  gBad_Chip.nonce_num[3] = gBad_Chip.nonce_num[0];
  if (BHB07601_ASIC_NUMBER == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = 0;
    uVar8 = 1;
    do {
      uVar4 = calculate_how_many_nonce_per_asic_get(which_chain,(char)uVar8 + 0xff,0x2a0);
      uVar10 = gBad_Chip.nonce_num[2];
      uVar3 = gBad_Chip.idx[2];
      if ((uVar4 < (Conf.pattern_number * Conf.bad_chip_nonce_rate * 0x2a0) / 100) &&
         (uVar11 = uVar11 + 1, uVar4 <= gBad_Chip.nonce_num[0])) {
        gBad_Chip.idx[2] = gBad_Chip.idx[1];
        gBad_Chip.idx[3] = uVar3;
        gBad_Chip.nonce_num[2] = gBad_Chip.nonce_num[1];
        gBad_Chip.nonce_num[1] = gBad_Chip.nonce_num[0];
        gBad_Chip.nonce_num[3] = uVar10;
        gBad_Chip.idx[1] = gBad_Chip.idx[0];
        gBad_Chip.idx[0] = uVar8;
        gBad_Chip.nonce_num[0] = uVar4;
      }
      bVar1 = uVar8 < BHB07601_ASIC_NUMBER;
      uVar8 = uVar8 + 1;
    } while (bVar1);
  }
  if (Conf.bad_chip_num <= uVar11) {
    local_34 = local_34 & 0xfffffff7;
  }
  gBad_Chip.total_badchip = uVar11;
  printf("Chain%d total bad number: %d\n\n",uVar2,uVar11);
  printf("Chain%d total valid nonce number: %d, lost %d nonce\n\n",uVar2,gValid_Nonce_Num[uVar2],
         BHB07601_ASIC_NUMBER * Conf.pattern_number * 0x2a0 - gValid_Nonce_Num[uVar2]);
  printf("Nonce rate = %f%% \n\n");
  if ((int)(local_34 << 0x1f) < 0) {
    pcVar5 = "Pattern OK\n";
  }
  else {
    pcVar5 = "Pattern NG\n";
  }
  puts(pcVar5);
  if ((int)(local_34 << 0x1e) < 0) {
    pcVar5 = "Sensor OK\n";
  }
  else {
    pcVar5 = "Sensor NG\n";
  }
  puts(pcVar5);
  if ((int)(local_34 << 0x1d) < 0) {
    pcVar5 = "Temperature OK\n";
  }
  else {
    pcVar5 = "Temperature NG\n";
  }
  puts(pcVar5);
  if ((int)(local_34 << 0x1c) < 0) {
    pcVar5 = "Bad Chip Check OK\n";
  }
  else {
    pcVar5 = "Bad Chip Check NG\n";
  }
  puts(pcVar5);
  printf("HW number = %d\n\n",gHw_Nonce_Num[uVar2]);
  uVar11 = read_axi_fpga(0x3e);
  printf("CRC error number = %d\n\n",uVar11);
  return local_34;
}

