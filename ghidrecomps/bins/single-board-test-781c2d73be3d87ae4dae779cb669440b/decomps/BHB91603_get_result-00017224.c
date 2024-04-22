
/* WARNING: Unknown calling convention */

uint BHB91603_get_result(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  work *pwVar7;
  work *works;
  uint *puVar8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint *local_30;
  
  uVar4 = (uint)which_chain;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  printf("every ASIC require nonce number: %u\n",Conf.pattern_number << 8);
  if (BHB91603_ASIC_NUMBER != 0) {
    uVar2 = 0;
    do {
      if (uVar2 == (uVar2 / 10) * 10) {
        putchar(10);
      }
      uVar1 = calculate_how_many_nonce_per_asic_get(which_chain,(uchar)uVar2,0x100);
      uVar5 = uVar2 + 1;
      printf("asic[%02d]=%d\t",uVar2,uVar1);
      uVar2 = uVar5;
    } while (uVar5 < BHB91603_ASIC_NUMBER);
  }
  puts("\n");
  if (BHB91603_ASIC_NUMBER == 0) {
    local_38 = 7;
  }
  else {
    local_38 = 7;
    local_3c = 0;
    local_30 = (uint *)(DAT_000175e4 + uVar4 * 0x80000);
    do {
      uVar2 = calculate_how_many_nonce_per_asic_get(which_chain,(uchar)local_3c,0x100);
      if (uVar2 < Conf.pattern_number << 8) {
        printf("asic[%02d] = %d\n",local_3c,uVar2);
        iVar6 = 0;
        pwVar7 = cgpu.works[local_3c];
        local_40 = 0;
        puVar8 = local_30;
        do {
          puVar8 = puVar8 + 1;
          if (*puVar8 < Conf.pattern_number) {
            uVar2 = 0;
            if (*puVar8 < Conf.Least_nonce_per_core) {
              local_40 = local_40 + 1;
            }
            printf("core[%03d] = %d,      lost these nonce : ",iVar6);
            if (Conf.pattern_number != 0) {
              do {
                while (pwVar7[Conf.pattern_number * iVar6 + uVar2].is_nonce_return_back[uVar4][0] !=
                       0) {
                  uVar2 = uVar2 + 1;
                  if (Conf.pattern_number <= uVar2) goto LAB_000173ac;
                }
                printf("%d  ",uVar2);
                uVar2 = uVar2 + 1;
              } while (uVar2 < Conf.pattern_number);
            }
LAB_000173ac:
            putchar(10);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 0x100);
        if (Conf.Invalid_Core_Num < local_40) {
          local_38 = 6;
          printf("\n error asic is %d\n",local_3c);
        }
        puts("\n");
      }
      local_30 = local_30 + 0x400;
      local_3c = local_3c + 1;
    } while (local_3c < BHB91603_ASIC_NUMBER);
  }
  printf("HW number = %d, Conf.Most_HW_Num = %d\n\n",gHw_Nonce_Num[uVar4],Conf.Most_HW_Num);
  if (Conf.Most_HW_Num < gHw_Nonce_Num[uVar4]) {
    local_38 = 6;
  }
  puts(
      "\n------------------------------------------------------------------------------------------------------\n"
      );
  if ((Conf.TempSensor1 != 0) && (gSensor_read_ok_counter[uVar4][0] < 5)) {
    local_38 = local_38 & 0xfffffffd;
    puts("\nSensor 1 check error");
  }
  if ((Conf.TempSensor2 != 0) && (gSensor_read_ok_counter[uVar4][1] < 5)) {
    local_38 = local_38 & 0xfffffffd;
    puts("\nSensor 2 check error");
  }
  if ((Conf.TempSensor3 != 0) && (gSensor_read_ok_counter[uVar4][2] < 5)) {
    local_38 = local_38 & 0xfffffffd;
    puts("\nSensor 3 check error");
  }
  if ((Conf.TempSensor4 != 0) && (gSensor_read_ok_counter[uVar4][3] < 5)) {
    local_38 = local_38 & 0xfffffffd;
    puts("\nSensor 4 check error");
  }
  if (Conf.TargetTemp < gGlobalHighestTemp) {
    local_38 = local_38 & 0xfffffffb;
  }
  printf("Chain%d total valid nonce number: %d, lost %d nonce\n\n",uVar4,gValid_Nonce_Num[uVar4],
         BHB91603_ASIC_NUMBER * Conf.pattern_number * 0x100 - gValid_Nonce_Num[uVar4]);
  printf("Nonce rate = %f \n\n");
  if ((int)(local_38 << 0x1f) < 0) {
    pcVar3 = "Pattern OK\n";
  }
  else {
    pcVar3 = "Pattern NG\n";
  }
  puts(pcVar3);
  if ((int)(local_38 << 0x1e) < 0) {
    pcVar3 = "Sensor OK\n";
  }
  else {
    pcVar3 = "Sensor NG\n";
  }
  puts(pcVar3);
  if ((int)(local_38 << 0x1d) < 0) {
    pcVar3 = "Temperature OK\n";
  }
  else {
    pcVar3 = "Temperature NG\n";
  }
  puts(pcVar3);
  printf("HW number = %d\n\n",gHw_Nonce_Num[uVar4]);
  uVar4 = read_axi_fpga(0x3e);
  printf("CRC error number = %d\n\n",uVar4);
  return local_38;
}

