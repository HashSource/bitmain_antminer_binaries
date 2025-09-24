
/* WARNING: Unknown calling convention */

uint32_t get_result_super_software_pattern(void)

{
  int extraout_r1;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t how_many_core_not_receive_all_nonce_per_asic;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t asic_num_per_voltage_domain;
  uint32_t voltage_domain;
  uint32_t pattern_num;
  uint32_t core_num;
  uint32_t asic_num;
  _Bool temp;
  uint32_t total_ntick_nonce;
  uint32_t how_many_asic_not_receive_all_nonce;
  uint32_t voltage_domain_received_nonce_number;
  uint32_t which_voltage_domain;
  uint32_t which_asic;
  uint32_t j;
  uint32_t i;
  uint32_t result;
  
  uVar1 = (Local_Config_Information->Hash_Board).Asic_Num;
  uVar2 = (Local_Config_Information->Hash_Board).Small_Core_Num;
  uVar3 = (Local_Config_Information->Hash_Board).Voltage_Domain;
  uVar4 = (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain;
  j = 0;
  total_ntick_nonce = 0;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  if (uVar1 != 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Hashboard require nonce number:               %d\n\n",
           "get_result_super_software_pattern",uVar1 * uVar2);
    snprintf(tmp1,0x100,"Hashboard require nonce number:               %d\n",uVar1 * uVar2);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every voltage domain require nonce number:     %d\n\n",
         "get_result_super_software_pattern",uVar4 * uVar2);
  snprintf(tmp1,0x100,"every voltage domain require nonce number:     %d\n",uVar4 * uVar2);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every ASIC require nonce number:               %d\n\n",
         "get_result_super_software_pattern",uVar2);
  snprintf(tmp1,0x100,"every ASIC require nonce number:               %d\n",uVar2);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every CORE require nonce number:               %d\n\n",
         "get_result_super_software_pattern",1);
  snprintf(tmp1,0x100,"every CORE require nonce number:               %d\n",1);
  log_to_file(tmp1,time_stamp);
  puts(
      "--------------------------every_asic_got_nonce_num---------------------------------------------------------------\n"
      );
  puts(
      "----------every_asic_reg_ntick_nonce_num--------------------------------------------------------------------------------------------\n"
      );
  if ((Local_Config_Information->Test_Info).Display.Display_result_Voltage_Domain != false) {
    gHistory_Result[gPattern_test_counter].asic_ok = true;
    for (which_voltage_domain = 0; which_voltage_domain < uVar3;
        which_voltage_domain = which_voltage_domain + 1) {
      voltage_domain_received_nonce_number = 0;
      for (which_asic = 0; which_asic < uVar4; which_asic = which_asic + 1) {
        voltage_domain_received_nonce_number =
             voltage_domain_received_nonce_number +
             gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
             [uVar4 * which_voltage_domain + which_asic];
        if ((gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
             [uVar4 * which_voltage_domain + which_asic] < uVar2) &&
           ((uint)gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
                  [uVar4 * which_voltage_domain + which_asic] <
            ((Local_Config_Information->Test_Info).Test_Standard.Asic_Nonce_Rate *
            (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
            (Local_Config_Information->Hash_Board).Small_Core_Num) / 10000)) {
          gHistory_Result[gPattern_test_counter].asic_ok = false;
          gHistory_Result[gPattern_test_counter].bad_asic_list
          [uVar4 * which_voltage_domain + which_asic] = false;
        }
      }
      total_ntick_nonce = voltage_domain_received_nonce_number + total_ntick_nonce;
      if (uVar4 < 6) {
        printf("Voltage domain [%02d] :",which_voltage_domain);
        for (which_asic = 0; which_asic < uVar4; which_asic = which_asic + 1) {
          if (gHistory_Result[gPattern_test_counter].bad_asic_list
              [uVar4 * which_voltage_domain + which_asic] == false) {
            printf("  !!! asic[%03d] = %4d,",uVar4 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
                         [uVar4 * which_voltage_domain + which_asic]);
          }
          else {
            printf("      asic[%03d] = %4d,",uVar4 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
                         [uVar4 * which_voltage_domain + which_asic]);
          }
          if (uVar4 - 1 == which_asic) {
            printf("      : domain nonce number :  %5d\n",voltage_domain_received_nonce_number);
          }
        }
        putchar(10);
      }
      else {
        printf("Voltage domain [%02d] nonce number :   %5d\n",which_voltage_domain,
               voltage_domain_received_nonce_number);
        for (which_asic = 0; which_asic < uVar4; which_asic = which_asic + 1) {
          if (gHistory_Result[gPattern_test_counter].bad_asic_list
              [uVar4 * which_voltage_domain + which_asic] == false) {
            printf("  !!! asic[%03d] = %4d,",uVar4 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
                         [uVar4 * which_voltage_domain + which_asic]);
          }
          else {
            printf("      asic[%03d] = %4d,",uVar4 * which_voltage_domain + which_asic,
                   (uint)gHistory_Result[gPattern_test_counter].every_asic_reg_ntick_nonce_num
                         [uVar4 * which_voltage_domain + which_asic]);
          }
          if ((which_asic != 0) && (__aeabi_uidivmod(which_asic + 1,uVar4 >> 1), extraout_r1 == 0))
          {
            putchar(10);
          }
        }
      }
    }
  }
  if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern != false) {
    gHistory_Result[gPattern_test_counter].valid_nonce_num = total_ntick_nonce;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bad asic list:\n","get_result_super_software_pattern");
  builtin_strncpy(tmp1,"bad asic lis",0xc);
  tmp1[0xc] = 't';
  tmp1[0xd] = ':';
  tmp1[0xe] = '\0';
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < uVar1; i = i + 1) {
    if (gHistory_Result[gPattern_test_counter].bad_asic_list[i] != true) {
      if (j % 5 == 0) {
        putchar(10);
        get_result_super_software_pattern::lexical_block_23::tmp1_5[0] = '\n';
        get_result_super_software_pattern::lexical_block_23::tmp1_5[1] = '\0';
        log_to_filex(get_result_super_software_pattern::lexical_block_23::tmp1_5,tmp1);
      }
      printf("asic[%03d]      ",i);
      snprintf(get_result_super_software_pattern::lexical_block_24::tmp1_6,0x100,"asic[%03d]      ",
               i);
      log_to_filex(get_result_super_software_pattern::lexical_block_24::tmp1_6,tmp1);
      j = j + 1;
    }
  }
  puts("\n");
  get_result_super_software_pattern::lexical_block_25::tmp1_7[0] = '\n';
  get_result_super_software_pattern::lexical_block_25::tmp1_7[1] = '\n';
  get_result_super_software_pattern::lexical_block_25::tmp1_7[2] = '\0';
  log_to_filex(get_result_super_software_pattern::lexical_block_25::tmp1_7,tmp1);
  puts(
      "------------------------------------------------------------------------------------------------------\n"
      );
  memcpy(get_result_super_software_pattern::lexical_block_26::tmp1_8,
         "------------------------------------------------------------------------------------------------------\n\n"
         ,0x69);
  log_to_filex(get_result_super_software_pattern::lexical_block_26::tmp1_8,tmp1);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : gPattern_test_counter = %d\n\n","get_result_super_software_pattern",
         (uint)gPattern_test_counter);
  snprintf(tmp1,0x100,"gPattern_test_counter = %d\n",(uint)gPattern_test_counter);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic_num = %d, core_num = %d, pattern_num = %d\n\n",
         "get_result_super_software_pattern",uVar1,uVar2,1);
  snprintf(tmp1,0x100,"asic_num = %d, core_num = %d, pattern_num = %d\n",uVar1,uVar2,1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : valid nonce number = %d,      lost nonce number = %d\n\n",
         "get_result_super_software_pattern",gHistory_Result[gPattern_test_counter].valid_nonce_num,
         uVar2 * uVar1 - gHistory_Result[gPattern_test_counter].valid_nonce_num);
  snprintf(tmp1,0x100,"valid nonce number = %d,      lost nonce number = %d\n",
           gHistory_Result[gPattern_test_counter].valid_nonce_num,
           uVar2 * uVar1 - gHistory_Result[gPattern_test_counter].valid_nonce_num);
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].nonce_rate =
       (double)gHistory_Result[gPattern_test_counter].valid_nonce_num / (double)(uVar2 * uVar1);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  dVar6 = gHistory_Result[gPattern_test_counter].nonce_rate * 100.0;
  printf("%s : nonce_rate = %f %%\n\n","get_result_super_software_pattern",SUB84(dVar6,0),
         (int)((ulonglong)dVar6 >> 0x20));
  snprintf(tmp1,0x100,"nonce_rate = %f %%\n",tmp1,
           gHistory_Result[gPattern_test_counter].nonce_rate * 100.0);
  log_to_file(tmp1,time_stamp);
  if ((double)(Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate <=
      gHistory_Result[gPattern_test_counter].nonce_rate * 10000.0) {
    gHistory_Result[gPattern_test_counter].nonce_rate_ok = true;
  }
  bVar5 = gHistory_Result[gPattern_test_counter].asic_ok == false;
  if (bVar5) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ASIC NG\n\n","get_result_super_software_pattern");
    builtin_strncpy(tmp1,"ASIC NG\n",8);
    tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ASIC OK\n\n","get_result_super_software_pattern");
    builtin_strncpy(tmp1,"ASIC OK\n",8);
    tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
  }
  result = (uint32_t)!bVar5;
  if (gHistory_Result[gPattern_test_counter].nonce_rate_ok == false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : NONCE RATE NG\n\n","get_result_super_software_pattern");
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
    printf("%s : NONCE RATE OK\n\n","get_result_super_software_pattern");
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
      printf("%s : EEPROM OK\n\n","get_result_super_software_pattern");
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
      printf("%s : EEPROM OK\n\n","get_result_super_software_pattern");
      builtin_strncpy(tmp1,"EEPROM O",8);
      tmp1[8] = 'K';
      tmp1[9] = '\n';
      tmp1[10] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    bVar5 = true;
    for (i = 0; i < gPic_sensor_num; i = i + 1) {
      if (gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] != true) {
        bVar5 = false;
      }
    }
    if (bVar5) {
      result = result | 8;
      gHistory_Result[gPattern_test_counter].pic_sensor_all_OK = true;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC sensor OK\n\n","get_result_super_software_pattern");
      builtin_strncpy(tmp1,"PIC sensor O",0xc);
      tmp1[0xc] = 'K';
      tmp1[0xd] = '\n';
      tmp1[0xe] = '\0';
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PIC sensor NG\n\n","get_result_super_software_pattern");
      builtin_strncpy(tmp1,"PIC sensor N",0xc);
      tmp1[0xc] = 'G';
      tmp1[0xd] = '\n';
      tmp1[0xe] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false) {
    bVar5 = true;
    for (i = 0; i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + 1) {
      if (gHistory_Result[gPattern_test_counter].asic_sensor_OK[i] != true) {
        bVar5 = false;
      }
    }
    if (bVar5) {
      result = result | 0x10;
      gHistory_Result[gPattern_test_counter].asic_sensor_all_OK = true;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : ASIC sensor OK\n\n","get_result_super_software_pattern");
      builtin_strncpy(tmp1,"ASIC sensor OK\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : ASIC sensor NG\n\n","get_result_super_software_pattern");
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
  printf("%s : result = 0x%08x\n\n","get_result_super_software_pattern",result);
  snprintf(tmp1,0x100,"result = 0x%08x\n",result);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : test level: %d\n\n","get_result_super_software_pattern",
         gHistory_Result[gPattern_test_counter].level);
  snprintf(tmp1,0x100,"test level: %d\n",gHistory_Result[gPattern_test_counter].level);
  log_to_file(tmp1,time_stamp);
  print_history_result((uint)gPattern_test_counter);
  return result;
}

