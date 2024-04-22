
/* WARNING: Unknown calling convention */

uint V9_get_result(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  work *pwVar9;
  work *works;
  uint local_3c;
  int local_34;
  uint *local_2c;
  
  uVar1 = (uint)which_chain;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  uVar6 = 0;
  uVar4 = 0;
  uVar7 = 7;
  printf("every ASIC require nonce number: %u\n",Conf.pattern_number * 0x32);
  do {
    if (uVar4 == (uVar4 / 9) * 9) {
      putchar(10);
    }
    uVar2 = calculate_how_many_nonce_per_asic_get(which_chain,(uchar)uVar4,0x32);
    printf("asic[%02d]=%d\t",uVar4,uVar2);
    uVar4 = uVar4 + 1;
    if ((uVar2 < Conf.pattern_number * 0x32) && (uVar6 = uVar6 + 1, Conf.Invalid_Asic_Num < uVar6))
    {
      uVar7 = 6;
    }
  } while (uVar4 != 0x2d);
  local_34 = 0;
  puts("\n");
  local_2c = (uint *)(DAT_0001a020 + uVar1 * 0x80000);
  do {
    uVar4 = calculate_how_many_nonce_per_asic_get(which_chain,(uchar)local_34,0x32);
    if (uVar4 < Conf.pattern_number * 0x32) {
      printf("asic[%02d] = %d\n",local_34,uVar4);
      pwVar9 = cgpu.works[local_34];
      iVar5 = 0;
      local_3c = 0;
      puVar8 = local_2c;
      do {
        puVar8 = puVar8 + 1;
        uVar4 = *puVar8;
        if (uVar4 < Conf.pattern_number) {
          uVar6 = 0;
          local_3c = local_3c + 1;
          if (Conf.Invalid_Core_Num < local_3c) {
            uVar7 = 6;
          }
          if (uVar4 < Conf.Least_nonce_per_core) {
            uVar7 = 6;
          }
          printf("core[%02d] = %d,      lost these nonce : ",iVar5,uVar4);
          if (Conf.pattern_number != 0) {
            do {
              while (pwVar9[iVar5 * Conf.pattern_number + uVar6].is_nonce_return_back[uVar1][0] == 0
                    ) {
                printf("%d  ",uVar6);
                uVar6 = uVar6 + 1;
                if (Conf.pattern_number <= uVar6) goto LAB_00019f2c;
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < Conf.pattern_number);
          }
LAB_00019f2c:
          putchar(10);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x32);
      puts("\n");
    }
    local_34 = local_34 + 1;
    local_2c = local_2c + 0x400;
    if (local_34 == 0x2d) {
      if (Conf.Most_HW_Num < gHw_Nonce_Num[uVar1]) {
        uVar7 = 6;
        printf("ret = %d\n",6);
      }
      puts(
          "\n------------------------------------------------------------------------------------------------------\n"
          );
      if (gSensor_OK[uVar1][0] == false) {
        uVar7 = uVar7 & 0xfffffffd;
      }
      if (gHigherThanAlarmTemp != false) {
        uVar7 = uVar7 & 0xfffffffb;
      }
      printf("Chain%d total valid nonce number: %d\n\n",uVar1,gValid_Nonce_Num[uVar1]);
      if ((uVar7 & 1) == 0) {
        pcVar3 = "Pattern NG\n";
      }
      else {
        pcVar3 = "Pattern OK\n";
      }
      puts(pcVar3);
      if ((uVar7 & 2) == 0) {
        pcVar3 = "Sensor NG\n";
      }
      else {
        pcVar3 = "Sensor OK\n";
      }
      puts(pcVar3);
      if ((uVar7 & 4) == 0) {
        pcVar3 = "Temperature NG\n";
      }
      else {
        pcVar3 = "Temperature OK\n";
      }
      puts(pcVar3);
      printf("HW number = %d\n\n",gHw_Nonce_Num[uVar1]);
      return uVar7;
    }
  } while( true );
}

