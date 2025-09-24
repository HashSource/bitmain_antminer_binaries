
/* WARNING: Unknown calling convention */

uint32_t get_result(void)

{
  int iVar1;
  int extraout_r1;
  uint uVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  work_new *pwVar7;
  bool bVar8;
  double dVar9;
  char time_stamp [48];
  char tmp1 [256];
  work_new *work;
  work_new *works;
  uint32_t asic_num_per_voltage_domain;
  uint32_t voltage_domain;
  uint32_t pattern_num;
  uint32_t core_num;
  uint32_t asic_num;
  uint32_t statistics_core_num;
  _Bool temp;
  uint32_t how_many_core_not_receive_all_nonce_per_asic;
  uint32_t voltage_domain_received_nonce_number;
  uint32_t how_many_asic_not_receive_all_nonce;
  uint32_t which_voltage_domain;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  uint32_t j;
  uint32_t i;
  uint32_t result;
  
  uVar2 = (Local_Config_Information->Hash_Board).Asic_Num;
  uVar3 = (Local_Config_Information->Hash_Board).Small_Core_Num;
  uVar4 = (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
  uVar5 = (Local_Config_Information->Hash_Board).Voltage_Domain;
  uVar6 = (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain;
  j = 0;
  how_many_core_not_receive_all_nonce_per_asic = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic :%d,core:%d\n","get_result",uVar2,uVar3);
  snprintf(tmp1,0x100,"asic :%d,core:%d",uVar2,uVar3);
  log_to_file(tmp1,time_stamp);
  iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1398");
  statistics_core_num = uVar3;
  if ((((iVar1 != 0) &&
       (iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1360"), iVar1 != 0)) &&
      (iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1366"), iVar1 != 0)) &&
     (iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1368"), iVar1 != 0)) {
    iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1399");
    if (iVar1 == 0) {
      statistics_core_num = uVar3 + 1;
    }
    else {
      iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1362");
      if (iVar1 != 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Don\'t support this type ASIC: %s\n\n","get_result",
               (Local_Config_Information->Hash_Board).Asic_Type);
        snprintf(tmp1,0x100,"Don\'t support this type ASIC: %s\n",
                 (Local_Config_Information->Hash_Board).Asic_Type);
        log_to_file(tmp1,time_stamp);
        return 0;
      }
      statistics_core_num = uVar3 + 3;
    }
  }
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  if (uVar2 != 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Hashboard require nonce number:                %d\n\n","get_result",
           uVar2 * uVar3 * uVar4);
    snprintf(tmp1,0x100,"Hashboard require nonce number:                %d\n",uVar2 * uVar3 * uVar4)
    ;
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every voltage domain require nonce number:     %d\n\n","get_result",
         uVar6 * uVar3 * uVar4);
  snprintf(tmp1,0x100,"every voltage domain require nonce number:     %d\n",uVar6 * uVar3 * uVar4);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every ASIC require nonce number:               %d\n\n","get_result",uVar3 * uVar4);
  snprintf(tmp1,0x100,"every ASIC require nonce number:               %d\n",uVar3 * uVar4);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every CORE require nonce number:               %d\n\n","get_result",uVar4);
  snprintf(tmp1,0x100,"every CORE require nonce number:               %d\n",uVar4);
  log_to_file(tmp1,time_stamp);
  puts(
      "------------------------------------------------------------------------------------------------------\n"
      );
  if ((Local_Config_Information->Test_Info).Display.Display_result_Voltage_Domain != false) {
    gHistory_Result[gPattern_test_counter].asic_ok = true;
    for (which_voltage_domain = 0; which_voltage_domain < uVar5;
        which_voltage_domain = which_voltage_domain + 1) {
      voltage_domain_received_nonce_number = 0;
      for (which_asic = 0; which_asic < uVar6; which_asic = which_asic + 1) {
        voltage_domain_received_nonce_number =
             voltage_domain_received_nonce_number +
             gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
             [uVar6 * which_voltage_domain + which_asic];
        if ((uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
                  [uVar6 * which_voltage_domain + which_asic] < uVar3 * uVar4) {
          how_many_core_not_receive_all_nonce_per_asic = 0;
          for (which_core = 0; which_core < statistics_core_num; which_core = which_core + 1) {
            iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+");
            if (iVar1 == 0) {
              if ((uint)gHistory_Result[gPattern_test_counter].asic_core_nonce_num
                        [uVar6 * which_voltage_domain + which_asic][which_core] <=
                  (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core) {
                how_many_core_not_receive_all_nonce_per_asic =
                     how_many_core_not_receive_all_nonce_per_asic + 1;
              }
            }
            else if ((uint)gHistory_Result[gPattern_test_counter].asic_core_nonce_num
                           [uVar6 * which_voltage_domain + which_asic][which_core] <
                     (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core) {
              how_many_core_not_receive_all_nonce_per_asic =
                   how_many_core_not_receive_all_nonce_per_asic + 1;
            }
          }
          if ((Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number <
              how_many_core_not_receive_all_nonce_per_asic) {
            gHistory_Result[gPattern_test_counter].asic_ok = false;
            gHistory_Result[gPattern_test_counter].bad_asic_list
            [uVar6 * which_voltage_domain + which_asic] = false;
          }
          iVar1 = strcmp(Local_Config_Information->Test_Process,"SWEEP");
          if ((iVar1 == 0) ||
             (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar1 == 0)) {
            (Local_Config_Information->Test_Info).Test_Standard.Asic_Nonce_Rate = 0x26ac;
          }
          if ((uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
                    [uVar6 * which_voltage_domain + which_asic] <
              ((Local_Config_Information->Test_Info).Test_Standard.Asic_Nonce_Rate *
              (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
              (Local_Config_Information->Hash_Board).Small_Core_Num) / 10000) {
            gHistory_Result[gPattern_test_counter].asic_ok = false;
            gHistory_Result[gPattern_test_counter].bad_asic_list
            [uVar6 * which_voltage_domain + which_asic] = false;
          }
        }
      }
      if (uVar6 < 6) {
        printf("Voltage domain [%02d] :",which_voltage_domain);
        for (which_asic = 0; which_asic < uVar6; which_asic = which_asic + 1) {
          if (gHistory_Result[gPattern_test_counter].bad_asic_list
              [uVar6 * which_voltage_domain + which_asic] == false) {
            printf("  !!! asic[%03d] = %4d,",uVar6 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
                         [uVar6 * which_voltage_domain + which_asic]);
          }
          else {
            printf("      asic[%03d] = %4d,",uVar6 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
                         [uVar6 * which_voltage_domain + which_asic]);
          }
          if (uVar6 - 1 == which_asic) {
            printf("      : domain nonce number :  %5d\n",voltage_domain_received_nonce_number);
          }
        }
        putchar(10);
      }
      else {
        printf("Voltage domain [%02d] nonce number :   %5d\n",which_voltage_domain,
               voltage_domain_received_nonce_number);
        for (which_asic = 0; which_asic < uVar6; which_asic = which_asic + 1) {
          if (gHistory_Result[gPattern_test_counter].bad_asic_list
              [uVar6 * which_voltage_domain + which_asic] == false) {
            printf("  !!! asic[%03d] = %4d,",uVar6 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
                         [uVar6 * which_voltage_domain + which_asic]);
          }
          else {
            printf("      asic[%03d] = %4d,",uVar6 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num
                         [uVar6 * which_voltage_domain + which_asic]);
          }
          if ((which_asic != 0) && (__aeabi_uidivmod(which_asic + 1,uVar6 >> 1), extraout_r1 == 0))
          {
            putchar(10);
          }
        }
        puts("\n");
      }
    }
  }
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  if ((Local_Config_Information->Test_Info).Display.Display_result_Every_Core != false) {
    gHistory_Result[gPattern_test_counter].asic_ok = true;
    for (which_asic = 0; which_asic < uVar2; which_asic = which_asic + 1) {
      if ((uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[which_asic] <
          uVar3 * uVar4) {
        printf("asic[%03d] = %d\n",which_asic,
               (uint)gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[which_asic]);
        pwVar7 = pattern_info_new.works[which_asic];
        how_many_core_not_receive_all_nonce_per_asic = 0;
        for (which_core = 0; which_core < statistics_core_num; which_core = which_core + 1) {
          if (gHistory_Result[gPattern_test_counter].asic_core_nonce_num[which_asic][which_core] <
              uVar4) {
            iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+");
            if (iVar1 == 0) {
              if ((uint)gHistory_Result[gPattern_test_counter].asic_core_nonce_num[which_asic]
                        [which_core] <=
                  (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core) {
                how_many_core_not_receive_all_nonce_per_asic =
                     how_many_core_not_receive_all_nonce_per_asic + 1;
              }
            }
            else if ((uint)gHistory_Result[gPattern_test_counter].asic_core_nonce_num[which_asic]
                           [which_core] <
                     (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core) {
              how_many_core_not_receive_all_nonce_per_asic =
                   how_many_core_not_receive_all_nonce_per_asic + 1;
            }
            printf("core[%03d] = %d,      lost these nonce : ",which_core,
                   (uint)gHistory_Result[gPattern_test_counter].asic_core_nonce_num[which_asic]
                         [which_core]);
            for (which_pattern = 0; which_pattern < uVar4; which_pattern = which_pattern + 1) {
              if (pwVar7[which_pattern + uVar4 * which_core].is_nonce_return_back == 0) {
                printf("%d  ",which_pattern);
              }
            }
            putchar(10);
          }
        }
        putchar(10);
      }
      if ((Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number <
          how_many_core_not_receive_all_nonce_per_asic) {
        gHistory_Result[gPattern_test_counter].asic_ok = false;
        printf("asic[%03d] has %d cores not receive %d nonce\n",which_asic,
               how_many_core_not_receive_all_nonce_per_asic,uVar4);
      }
    }
  }
  puts(
      "------------------------------------------------------------------------------------------------------\n"
      );
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bad asic list:\n","get_result");
  builtin_strncpy(tmp1,"bad asic lis",0xc);
  tmp1[0xc] = 't';
  tmp1[0xd] = ':';
  tmp1[0xe] = '\0';
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < uVar2; i = i + 1) {
    if (gHistory_Result[gPattern_test_counter].bad_asic_list[i] != true) {
      if (j % 5 == 0) {
        putchar(10);
      }
      printf("asic[%03d]      ",i);
      j = j + 1;
    }
  }
  puts("\n");
  puts(
      "------------------------------------------------------------------------------------------------------\n"
      );
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gPattern_test_counter = %d\n\n","get_result",(uint)gPattern_test_counter);
  snprintf(tmp1,0x100,"gPattern_test_counter = %d\n",(uint)gPattern_test_counter);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : valid nonce number = %d,      lost nonce number = %d\n\n","get_result",
         gHistory_Result[gPattern_test_counter].valid_nonce_num,
         uVar4 * uVar3 * uVar2 - gHistory_Result[gPattern_test_counter].valid_nonce_num);
  snprintf(tmp1,0x100,"valid nonce number = %d,      lost nonce number = %d\n",
           gHistory_Result[gPattern_test_counter].valid_nonce_num,
           uVar4 * uVar3 * uVar2 - gHistory_Result[gPattern_test_counter].valid_nonce_num);
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].nonce_rate =
       (double)gHistory_Result[gPattern_test_counter].valid_nonce_num /
       (double)(uVar4 * uVar3 * uVar2);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  dVar9 = gHistory_Result[gPattern_test_counter].nonce_rate * 100.0;
  printf("%s : nonce_rate = %f %%\n\n","get_result",SUB84(dVar9,0),(int)((ulonglong)dVar9 >> 0x20));
  snprintf(tmp1,0x100,"nonce_rate = %f %%\n",tmp1,
           gHistory_Result[gPattern_test_counter].nonce_rate * 100.0);
  log_to_file(tmp1,time_stamp);
  if ((double)(Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate <=
      gHistory_Result[gPattern_test_counter].nonce_rate * 10000.0) {
    gHistory_Result[gPattern_test_counter].nonce_rate_ok = true;
  }
  bVar8 = gHistory_Result[gPattern_test_counter].asic_ok == false;
  if (bVar8) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ASIC NG\n\n","get_result");
    builtin_strncpy(tmp1,"ASIC NG\n",8);
    tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ASIC OK\n\n","get_result");
    builtin_strncpy(tmp1,"ASIC OK\n",8);
    tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  result = (uint32_t)!bVar8;
  if (gHistory_Result[gPattern_test_counter].nonce_rate_ok == false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : NONCE RATE NG\n\n","get_result");
    builtin_strncpy(tmp1,"NONCE RATE N",0xc);
    tmp1[0xc] = 'G';
    tmp1[0xd] = '\n';
    tmp1[0xe] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    result = result | 2;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : NONCE RATE OK\n\n","get_result");
    builtin_strncpy(tmp1,"NONCE RATE O",0xc);
    tmp1[0xc] = 'K';
    tmp1[0xd] = '\n';
    tmp1[0xe] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  if ((Local_Config_Information->Hash_Board).Asic_Num != 1) {
    if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : EEPROM OK\n\n","get_result");
      builtin_strncpy(tmp1,"EEPROM O",8);
      tmp1[8] = 'K';
      tmp1[9] = '\n';
      tmp1[10] = '\0';
      log_to_file(tmp1,time_stamp);
    }
    else {
      result = result | 4;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : EEPROM OK\n\n","get_result");
      builtin_strncpy(tmp1,"EEPROM O",8);
      tmp1[8] = 'K';
      tmp1[9] = '\n';
      tmp1[10] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    bVar8 = true;
    for (i = 0; i < gPic_sensor_num; i = i + 1) {
      if (gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] != true) {
        bVar8 = false;
      }
    }
    if (bVar8) {
      result = result | 8;
      gHistory_Result[gPattern_test_counter].pic_sensor_all_OK = true;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC sensor OK\n\n","get_result");
      builtin_strncpy(tmp1,"PIC sensor O",0xc);
      tmp1[0xc] = 'K';
      tmp1[0xd] = '\n';
      tmp1[0xe] = '\0';
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC sensor NG\n\n","get_result");
      builtin_strncpy(tmp1,"PIC sensor N",0xc);
      tmp1[0xc] = 'G';
      tmp1[0xd] = '\n';
      tmp1[0xe] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false) {
    bVar8 = true;
    for (i = 0; i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + 1) {
      if (gHistory_Result[gPattern_test_counter].asic_sensor_OK[i] != true) {
        bVar8 = false;
      }
    }
    if (bVar8) {
      result = result | 0x10;
      gHistory_Result[gPattern_test_counter].asic_sensor_all_OK = true;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : ASIC sensor OK\n\n","get_result");
      builtin_strncpy(tmp1,"ASIC sensor OK\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : ASIC sensor NG\n\n","get_result");
      builtin_strncpy(tmp1,"ASIC sensor NG\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((gHistory_Result[gPattern_test_counter].asic_ok == false) ||
     (gHistory_Result[gPattern_test_counter].nonce_rate_ok == false)) {
    if ((gHistory_Result[gPattern_test_counter].asic_ok == true) ||
       (gHistory_Result[gPattern_test_counter].nonce_rate_ok == false)) {
      gHistory_Result[gPattern_test_counter].test_standard = 0xf0;
    }
    else {
      gHistory_Result[gPattern_test_counter].test_standard = '\x01';
    }
  }
  else {
    gHistory_Result[gPattern_test_counter].test_standard = '\0';
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : result = 0x%08x\n\n","get_result",result);
  snprintf(tmp1,0x100,"result = 0x%08x\n",result);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : test level: %d\n\n","get_result",gHistory_Result[gPattern_test_counter].level);
  snprintf(tmp1,0x100,"test level: %d\n",gHistory_Result[gPattern_test_counter].level);
  log_to_file(tmp1,time_stamp);
  print_history_result((uint)gPattern_test_counter);
  return result;
}

