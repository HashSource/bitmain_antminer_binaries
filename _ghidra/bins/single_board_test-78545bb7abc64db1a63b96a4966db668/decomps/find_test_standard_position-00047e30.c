
/* WARNING: Type propagation algorithm not settling */

_Bool find_test_standard_position
                (char *miner_type,char *board_name,char *asic_type,char *hardware_version,
                char *bom_version,char *chip_technology)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined4 uVar7;
  _Bool _Var8;
  byte bVar9;
  int iVar10;
  char *pcVar11;
  char *hardware_version_local;
  char *asic_type_local;
  char *board_name_local;
  char *miner_type_local;
  char time_stamp [48];
  char tmp1 [256];
  _Bool find_test_loop [60];
  json_t *test_loop_id;
  Mes_System_Data *Mes_System_Data_ptr_next;
  size_t test_loop_id_array_index;
  size_t data_array_index;
  size_t power_version_array_index;
  _Bool find_ft_bin;
  uint32_t bin;
  char *ft_version;
  uint32_t test_method_id;
  uint32_t asic_reg_id;
  uint32_t pattern_id;
  Mes_System_Test_Loop *Mes_System_Test_Loop_ptr;
  Mes_System_Test_Method *Mes_System_Test_Method_ptr;
  Mes_System_Asic_Reg *Mes_System_Asic_Reg_ptr;
  Mes_System_Pattern *Mes_System_Pattern_ptr;
  Mes_System_Data *Mes_System_Data_ptr_find_version;
  Mes_System_Data *Mes_System_Data_ptr;
  Mes_System_Test_Config *Mes_System_Test_Config_ptr;
  Mes_System_Hw_Info *Mes_System_Hw_Info_ptr;
  Mes_System_Configs *Mes_System_Configs_ptr;
  size_t test_config_array_index;
  size_t test_loop_array_index;
  size_t test_method_array_index;
  size_t asic_reg_array_index;
  size_t pattern_array_index;
  size_t hw_info_array_index;
  size_t configs_array_index;
  _Bool find_all_test_loop;
  _Bool find_test_method;
  _Bool find_asic_reg;
  _Bool find_pattern;
  _Bool find_test_config;
  _Bool find_hw_info;
  uint32_t index;
  
  bVar1 = false;
  bVar3 = false;
  bVar4 = false;
  bVar5 = false;
  bVar6 = false;
  memset(find_test_loop,0,0x3c);
  find_all_test_loop = true;
  pattern_array_index = 0;
  asic_reg_array_index = 0;
  test_method_array_index = 0;
  test_loop_array_index = 0;
  pattern_id = 0;
  asic_reg_id = 0;
  test_method_id = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s %s %s%s%s %s\n","find_test_standard_position",miner_type,board_name,
         hardware_version,bom_version,chip_technology,asic_type);
  snprintf(tmp1,0x100,"%s %s %s%s%s %s",miner_type,board_name,hardware_version,bom_version,
           chip_technology,asic_type);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : find standard : \n","find_test_standard_position");
  builtin_strncpy(tmp1,"find standard : ",0x10);
  tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
  log_to_file(tmp1,time_stamp);
  _Var8 = check_is_multiple_ft_version(qr_code.chip_ftversion);
  if (_Var8) {
    log_out_multiple_ft_bin_info(&qr_code.ft_bin_list);
  }
  else {
    ft_version = qr_code.chip_ftversion;
    bVar9 = get_chip_bin(&qr_code);
    bin = (uint32_t)bVar9;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : FT info:%s BIN%d\n","find_test_standard_position",0x21bb9b8,bin);
    snprintf(tmp1,0x100,"FT info:%s BIN%d",0x21bb9b8,bin);
    log_to_file(tmp1,time_stamp);
  }
  Mes_System_Configs_ptr = (Mes_System_Config_File_Information->result).configs;
  do {
    if (Mes_System_Configs_ptr == (Mes_System_Configs *)0x0) {
      return false;
    }
    iVar10 = strcmp(Mes_System_Configs_ptr->miner_type,miner_type);
    if (iVar10 == 0) {
      Mes_System_Hw_Info_ptr = Mes_System_Configs_ptr->hw_info;
LAB_00048382:
      if (Mes_System_Hw_Info_ptr != (Mes_System_Hw_Info *)0x0) {
        iVar10 = strcmp(Mes_System_Hw_Info_ptr->board_name,board_name);
        if ((iVar10 != 0) ||
           (iVar10 = strcmp(Mes_System_Hw_Info_ptr->asic_type,asic_type), iVar10 != 0)) break;
        (Local_Config_Information->Hash_Board).Asic_Num = Mes_System_Hw_Info_ptr->asic_num;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Asic_Num: %d\n","find_test_standard_position",
               (Local_Config_Information->Hash_Board).Asic_Num);
        snprintf(tmp1,0x100,"Asic_Num: %d",(Local_Config_Information->Hash_Board).Asic_Num);
        log_to_file(tmp1,time_stamp);
        (Local_Config_Information->Hash_Board).Voltage_Domain =
             Mes_System_Hw_Info_ptr->voltage_domain;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Voltage_Domain: %d\n","find_test_standard_position",
               (Local_Config_Information->Hash_Board).Voltage_Domain);
        snprintf(tmp1,0x100,"Voltage_Domain: %d",
                 (Local_Config_Information->Hash_Board).Voltage_Domain);
        log_to_file(tmp1,time_stamp);
        (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain =
             Mes_System_Hw_Info_ptr->asic_num_per_voltage_domain;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Asic_Num_Per_Voltage_Domain: %d\n","find_test_standard_position",
               (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
        snprintf(tmp1,0x100,"Asic_Num_Per_Voltage_Domain: %d",
                 (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
        log_to_file(tmp1,time_stamp);
        for (index = 0; index < gPower_version_array_size; index = index + 1) {
          APW_power_version[index] = (uint8_t)Mes_System_Hw_Info_ptr->power_version[index];
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : APW_power_version[%d]: %d\n","find_test_standard_position",index,
                 (uint)APW_power_version[index]);
          snprintf(tmp1,0x100,"APW_power_version[%d]: %d",index,(uint)APW_power_version[index]);
          log_to_file(tmp1,time_stamp);
        }
        bVar1 = true;
      }
      if (bVar1) {
        Mes_System_Test_Config_ptr = Mes_System_Configs_ptr->test_config;
LAB_00048ca6:
        if (Mes_System_Test_Config_ptr != (Mes_System_Test_Config *)0x0) {
          bVar2 = false;
          _Var8 = check_is_multiple_ft_version(Mes_System_Test_Config_ptr->ft_version);
          if (_Var8) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : remote:%d-%d, local:%d-%d\n","find_test_standard_position",
                   (Mes_System_Test_Config_ptr->ft_bin_list).ft_value.u.data[0],
                   (Mes_System_Test_Config_ptr->ft_bin_list).ft_value.u.data[1],
                   qr_code.ft_bin_list.ft_value.u.data[0],qr_code.ft_bin_list.ft_value.u.data[1]);
            snprintf(tmp1,0x100,"remote:%d-%d, local:%d-%d",
                     (Mes_System_Test_Config_ptr->ft_bin_list).ft_value.u.data[0],
                     (Mes_System_Test_Config_ptr->ft_bin_list).ft_value.u.data[1],
                     qr_code.ft_bin_list.ft_value.u.data[0],qr_code.ft_bin_list.ft_value.u.data[1]);
            log_to_file(tmp1,time_stamp);
            _Var8 = check_is_multiple_ft_version(qr_code.chip_ftversion);
            if (((_Var8) &&
                ((Mes_System_Test_Config_ptr->ft_bin_list).ft_value.u.data[0] ==
                 qr_code.ft_bin_list.ft_value.u.data[0])) &&
               ((Mes_System_Test_Config_ptr->ft_bin_list).ft_value.u.data[1] ==
                qr_code.ft_bin_list.ft_value.u.data[1])) {
              bVar2 = true;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : local:\n","find_test_standard_position");
              uVar7 = tmp1._4_4_;
              builtin_strncpy(tmp1,"local:",7);
              tmp1[7] = SUB41(uVar7,3);
              log_to_file(tmp1,time_stamp);
              log_out_multiple_ft_bin_info(&qr_code.ft_bin_list);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : remote:\n","find_test_standard_position");
              builtin_strncpy(tmp1,"remote:",8);
              log_to_file(tmp1,time_stamp);
              log_out_multiple_ft_bin_info(&Mes_System_Test_Config_ptr->ft_bin_list);
            }
          }
          else {
            iVar10 = strcmp(Mes_System_Test_Config_ptr->ft_version,ft_version);
            if ((iVar10 == 0) && (Mes_System_Test_Config_ptr->bin == bin)) {
              bVar2 = true;
            }
            else {
              bVar2 = false;
            }
          }
          if (!bVar2) goto LAB_00048c90;
          Mes_System_Data_ptr_find_version = Mes_System_Test_Config_ptr->data;
          Mes_System_Data_ptr = Mes_System_Data_ptr_find_version->next;
          while (Mes_System_Data_ptr != (Mes_System_Data *)0x0) {
            iVar10 = strcmp(Mes_System_Data_ptr_find_version->version,Mes_System_Data_ptr->version);
            if (iVar10 < 0) {
              Mes_System_Data_ptr_find_version = Mes_System_Data_ptr;
            }
            Mes_System_Data_ptr = (Mes_System_Data *)0x0;
          }
          strcpy((Local_Config_Information->Test_Info).Test_Config_Data_Version,
                 Mes_System_Data_ptr_find_version->version);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : version: %s\n","find_test_standard_position",
                 (Local_Config_Information->Test_Info).Test_Config_Data_Version);
          snprintf(tmp1,0x100,"version: %s",
                   (Local_Config_Information->Test_Info).Test_Config_Data_Version);
          log_to_file(tmp1,time_stamp);
          pattern_id = Mes_System_Data_ptr_find_version->pattern_id;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : pattern_id: %d\n","find_test_standard_position",pattern_id);
          snprintf(tmp1,0x100,"pattern_id: %d",pattern_id);
          log_to_file(tmp1,time_stamp);
          asic_reg_id = Mes_System_Data_ptr_find_version->asic_reg_id;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : asic_reg_id: %d\n","find_test_standard_position",asic_reg_id);
          snprintf(tmp1,0x100,"asic_reg_id: %d",asic_reg_id);
          log_to_file(tmp1,time_stamp);
          test_method_id = Mes_System_Data_ptr_find_version->test_method_id;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : test_method_id: %d\n","find_test_standard_position",test_method_id);
          snprintf(tmp1,0x100,"test_method_id: %d",test_method_id);
          log_to_file(tmp1,time_stamp);
          (Local_Config_Information->Test_Info).Voltage_Accuracy =
               Mes_System_Data_ptr_find_version->voltage_accuracy;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : version: %d\n","find_test_standard_position",
                 (Local_Config_Information->Test_Info).Voltage_Accuracy);
          snprintf(tmp1,0x100,"version: %d",(Local_Config_Information->Test_Info).Voltage_Accuracy);
          log_to_file(tmp1,time_stamp);
          (Local_Config_Information->Test_Info).Fan.Fan_Speed =
               Mes_System_Data_ptr_find_version->fan_speed;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Fan_Speed: %d\n","find_test_standard_position",
                 (Local_Config_Information->Test_Info).Fan.Fan_Speed);
          snprintf(tmp1,0x100,"Fan_Speed: %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
          log_to_file(tmp1,time_stamp);
          gTest_loop_id_array_size = Mes_System_Data_ptr_find_version->test_loop_id_number;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : gTest_loop_id_array_size: %d\n","find_test_standard_position",
                 gTest_loop_id_array_size);
          snprintf(tmp1,0x100,"gTest_loop_id_array_size: %d",gTest_loop_id_array_size);
          log_to_file(tmp1,time_stamp);
          if (0x3c < gTest_loop_id_array_size) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : gTest_loop_id_array_size is %d, bigger than %d\n",
                   "find_test_standard_position",gTest_loop_id_array_size,0x3c);
            snprintf(tmp1,0x100,"gTest_loop_id_array_size is %d, bigger than %d",
                     gTest_loop_id_array_size,0x3c);
            log_to_file(tmp1,time_stamp);
            goto LAB_0004a0c0;
          }
          gTest_loop = gTest_loop_id_array_size;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : gTest_loop: %d\n","find_test_standard_position",gTest_loop_id_array_size);
          snprintf(tmp1,0x100,"gTest_loop: %d",gTest_loop_id_array_size);
          log_to_file(tmp1,time_stamp);
          for (index = 0; index < gTest_loop_id_array_size; index = index + 1) {
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level =
                 Mes_System_Data_ptr_find_version->test_loop_id[index];
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Test_Loop[%d]->Level: %d\n","find_test_standard_position",index,
                   (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level);
            snprintf(tmp1,0x100,"Test_Loop[%d]->Level: %d",index,
                     (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level);
            log_to_file(tmp1,time_stamp);
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
            Pre_Open_Core_Voltage = Mes_System_Data_ptr_find_version->pre_open_core_voltage;
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Test_Loop[%d]->Pre_Open_Core_Voltage: %d\n","find_test_standard_position",
                   index,(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                         Pre_Open_Core_Voltage);
            snprintf(tmp1,0x100,"Test_Loop[%d]->Pre_Open_Core_Voltage: %d",index,
                     (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                     Pre_Open_Core_Voltage);
            log_to_file(tmp1,time_stamp);
          }
          bVar3 = true;
        }
        if (bVar3) {
          for (Mes_System_Pattern_ptr = (Mes_System_Configs_ptr->rule).pattern;
              Mes_System_Pattern_ptr != (Mes_System_Pattern *)0x0;
              Mes_System_Pattern_ptr = Mes_System_Pattern_ptr->next) {
            if (Mes_System_Pattern_ptr->id == pattern_id) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->id: %d\n","find_test_standard_position",pattern_array_index,
                     Mes_System_Pattern_ptr->id);
              snprintf(tmp1,0x100,"pattern[%d]->id: %d",pattern_array_index,
                       Mes_System_Pattern_ptr->id);
              log_to_file(tmp1,time_stamp);
              (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number =
                   Mes_System_Pattern_ptr->pattern_number;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->Pattern_Number: %d\n","find_test_standard_position",
                     pattern_array_index,
                     (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
              snprintf(tmp1,0x100,"pattern[%d]->Pattern_Number: %d",pattern_array_index,
                       (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
              log_to_file(tmp1,time_stamp);
              (Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number =
                   Mes_System_Pattern_ptr->invalid_core_num;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->Invalid_Core_Number: %d\n","find_test_standard_position",
                     pattern_array_index,
                     (Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number);
              snprintf(tmp1,0x100,"pattern[%d]->Invalid_Core_Number: %d",pattern_array_index,
                       (Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number);
              log_to_file(tmp1,time_stamp);
              (Local_Config_Information->Test_Info).Test_Standard.Most_HW_Num =
                   Mes_System_Pattern_ptr->most_hw_num;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->Most_HW_Num: %d\n","find_test_standard_position",
                     pattern_array_index,
                     (Local_Config_Information->Test_Info).Test_Standard.Most_HW_Num);
              snprintf(tmp1,0x100,"pattern[%d]->Most_HW_Num: %d",pattern_array_index,
                       (Local_Config_Information->Test_Info).Test_Standard.Most_HW_Num);
              log_to_file(tmp1,time_stamp);
              (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core =
                   Mes_System_Pattern_ptr->least_nonce_per_core;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->Least_Nonce_Per_Core: %d\n","find_test_standard_position",
                     pattern_array_index,
                     (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core);
              snprintf(tmp1,0x100,"pattern[%d]->Least_Nonce_Per_Core: %d",pattern_array_index,
                       (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core);
              log_to_file(tmp1,time_stamp);
              (Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate =
                   Mes_System_Pattern_ptr->nonce_rate;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->Nonce_Rate: %d\n","find_test_standard_position",
                     pattern_array_index,
                     (Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate);
              snprintf(tmp1,0x100,"pattern[%d]->Nonce_Rate: %d",pattern_array_index,
                       (Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate);
              log_to_file(tmp1,time_stamp);
              (Local_Config_Information->Test_Info).Test_Method.Midstate_Number =
                   Mes_System_Pattern_ptr->midstate_number;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : pattern[%d]->Midstate_Number: %d\n","find_test_standard_position",
                     pattern_array_index,
                     (Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
              snprintf(tmp1,0x100,"pattern[%d]->Midstate_Number: %d",pattern_array_index,
                       (Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
              log_to_file(tmp1,time_stamp);
              bVar4 = true;
              break;
            }
            pattern_array_index = pattern_array_index + 1;
          }
          if (bVar4) {
            for (Mes_System_Asic_Reg_ptr = (Mes_System_Configs_ptr->rule).asic_reg;
                Mes_System_Asic_Reg_ptr != (Mes_System_Asic_Reg *)0x0;
                Mes_System_Asic_Reg_ptr = Mes_System_Asic_Reg_ptr->next) {
              if (Mes_System_Asic_Reg_ptr->id == asic_reg_id) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->id: %d\n","find_test_standard_position",
                       asic_reg_array_index,Mes_System_Asic_Reg_ptr->id);
                snprintf(tmp1,0x100,"asic_reg[%d]->id: %d",asic_reg_array_index,
                         Mes_System_Asic_Reg_ptr->id);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel =
                     Mes_System_Asic_Reg_ptr->ccdly_sel;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->CCdly_Sel: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel);
                snprintf(tmp1,0x100,"asic_reg[%d]->CCdly_Sel: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel =
                     Mes_System_Asic_Reg_ptr->pwth_sel;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->Pwth_Sel: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel);
                snprintf(tmp1,0x100,"asic_reg[%d]->Pwth_Sel: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode =
                     Mes_System_Asic_Reg_ptr->swpf_mode;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->Swpf_Mode: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
                snprintf(tmp1,0x100,"asic_reg[%d]->Swpf_Mode: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode =
                     Mes_System_Asic_Reg_ptr->pulse_mode;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->Pulse_Mode: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode);
                snprintf(tmp1,0x100,"asic_reg[%d]->Pulse_Mode: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel =
                     Mes_System_Asic_Reg_ptr->clk_sel;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->Clk_Sel: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
                snprintf(tmp1,0x100,"asic_reg[%d]->Clk_Sel: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.RO_Relay_En =
                     Mes_System_Asic_Reg_ptr->ro_relay_en;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->RO_Relay_En: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.RO_Relay_En);
                snprintf(tmp1,0x100,"asic_reg[%d]->RO_Relay_En: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.RO_Relay_En);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.CO_Relay_En =
                     Mes_System_Asic_Reg_ptr->ro_relay_en;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->CO_Relay_En: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.CO_Relay_En);
                snprintf(tmp1,0x100,"asic_reg[%d]->CO_Relay_En: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.CO_Relay_En);
                log_to_file(tmp1,time_stamp);
                (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel =
                     Mes_System_Asic_Reg_ptr->diode_vdd_mux_sel;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : asic_reg[%d]->Diode_Vdd_Mux_Sel: %d\n","find_test_standard_position",
                       asic_reg_array_index,
                       (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
                snprintf(tmp1,0x100,"asic_reg[%d]->Diode_Vdd_Mux_Sel: %d",asic_reg_array_index,
                         (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
                log_to_file(tmp1,time_stamp);
                bVar5 = true;
                break;
              }
              asic_reg_array_index = asic_reg_array_index + 1;
            }
            if (!bVar5) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : can\'t find:: asic_reg_id: %d\n","find_test_standard_position",
                     asic_reg_id);
              snprintf(tmp1,0x100,"can\'t find:: asic_reg_id: %d",asic_reg_id);
              log_to_file(tmp1,time_stamp);
              goto LAB_0004a0c0;
            }
            Mes_System_Test_Method_ptr = (Mes_System_Configs_ptr->rule).test_method;
            do {
              if (Mes_System_Test_Method_ptr == (Mes_System_Test_Method *)0x0) {
LAB_00049ca4:
                if (bVar6) {
                  for (index = 0; index < gTest_loop_id_array_size; index = index + 1) {
                    find_test_loop[index] = false;
                    for (Mes_System_Test_Loop_ptr = (Mes_System_Configs_ptr->rule).test_loop;
                        Mes_System_Test_Loop_ptr != (Mes_System_Test_Loop *)0x0;
                        Mes_System_Test_Loop_ptr = Mes_System_Test_Loop_ptr->next) {
                      if (Mes_System_Test_Loop_ptr->id ==
                          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level
                         ) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s : test_loop[%d]->id: %d\n","find_test_standard_position",
                               test_loop_array_index,Mes_System_Test_Loop_ptr->id);
                        snprintf(tmp1,0x100,"test_loop[%d]->id: %d",test_loop_array_index,
                                 Mes_System_Test_Loop_ptr->id);
                        log_to_file(tmp1,time_stamp);
                        (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                        Frequence = Mes_System_Test_Loop_ptr->frequency;
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s : test_loop[%d]->Frequence: %d\n","find_test_standard_position",
                               test_loop_array_index,
                               (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                               Frequence);
                        snprintf(tmp1,0x100,"test_loop[%d]->Frequence: %d",test_loop_array_index,
                                 (Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                                 [index].Frequence);
                        log_to_file(tmp1,time_stamp);
                        (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Voltage
                             = Mes_System_Test_Loop_ptr->voltage;
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s : test_loop[%d]->Voltage: %d\n","find_test_standard_position",
                               test_loop_array_index,
                               (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                               Voltage);
                        snprintf(tmp1,0x100,"test_loop[%d]->Voltage: %d",test_loop_array_index,
                                 (Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                                 [index].Voltage);
                        log_to_file(tmp1,time_stamp);
                        find_test_loop[index] = true;
                        break;
                      }
                      test_loop_array_index = test_loop_array_index + 1;
                    }
                  }
                  for (index = 0; index < gTest_loop_id_array_size; index = index + 1) {
                    find_all_test_loop = (find_all_test_loop & find_test_loop[index]) != 0;
                    if (find_test_loop[index] != true) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : can\'t find:: test_loop id: %d\n","find_test_standard_position",
                             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                             Level);
                      snprintf(tmp1,0x100,"can\'t find:: test_loop id: %d",
                               (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
                               Level);
                      log_to_file(tmp1,time_stamp);
                    }
                  }
                  if (find_all_test_loop == true) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : find all test standard\n","find_test_standard_position");
                    builtin_strncpy(tmp1,"find all test standa",0x14);
                    tmp1[0x14] = 'r';
                    tmp1[0x15] = 'd';
                    tmp1[0x16] = '\0';
                    log_to_file(tmp1,time_stamp);
                    return true;
                  }
                }
                else {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : can\'t find:: test_method_id: %d\n","find_test_standard_position",
                         test_method_id);
                  snprintf(tmp1,0x100,"can\'t find:: test_method_id: %d",test_method_id);
                  log_to_file(tmp1,time_stamp);
                }
                goto LAB_0004a0c0;
              }
              if (Mes_System_Test_Method_ptr->id == test_method_id) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : test_method[%d]->id: %d\n","find_test_standard_position",
                       test_method_array_index,Mes_System_Test_Method_ptr->id);
                snprintf(tmp1,0x100,"test_method[%d]->id: %d",test_method_array_index,
                         Mes_System_Test_Method_ptr->id);
                log_to_file(tmp1,time_stamp);
                iVar10 = strcmp(Mes_System_Test_Method_ptr->method,"SOFTWARE_PATTERN");
                if (iVar10 == 0) {
                  (Local_Config_Information->Test_Info).Test_Method.Software_Pattern = true;
                  (Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern = false;
                  (Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern = false;
                  (Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern = false;
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
                    pcVar11 = "false";
                  }
                  else {
                    pcVar11 = "true";
                  }
                  printf("%s : Software_Pattern : %s\n","find_test_standard_position",pcVar11);
                  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
                    pcVar11 = "false";
                  }
                  else {
                    pcVar11 = "true";
                  }
                  snprintf(tmp1,0x100,"Software_Pattern : %s",pcVar11);
                  log_to_file(tmp1,time_stamp);
                }
                else {
                  iVar10 = strcmp(Mes_System_Test_Method_ptr->method,"SUPER_SOFTWARE_PATTERN");
                  if (iVar10 == 0) {
                    (Local_Config_Information->Test_Info).Test_Method.Software_Pattern = false;
                    (Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern = true;
                    (Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern = false;
                    (Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern = false;
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern ==
                        false) {
                      pcVar11 = "false";
                    }
                    else {
                      pcVar11 = "true";
                    }
                    printf("%s : Super_Software_Pattern : %s\n","find_test_standard_position",
                           pcVar11);
                    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern ==
                        false) {
                      pcVar11 = "false";
                    }
                    else {
                      pcVar11 = "true";
                    }
                    snprintf(tmp1,0x100,"Super_Software_Pattern : %s",pcVar11);
                    log_to_file(tmp1,time_stamp);
                  }
                  else {
                    iVar10 = strcmp(Mes_System_Test_Method_ptr->method,"HARDWARE_PATTERN");
                    if (iVar10 == 0) {
                      (Local_Config_Information->Test_Info).Test_Method.Software_Pattern = false;
                      (Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern = true;
                      (Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern = false;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern ==
                          false) {
                        pcVar11 = "false";
                      }
                      else {
                        pcVar11 = "true";
                      }
                      printf("%s : Software_Pattern : %s\n","find_test_standard_position",pcVar11);
                      if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern ==
                          false) {
                        pcVar11 = "false";
                      }
                      else {
                        pcVar11 = "true";
                      }
                      snprintf(tmp1,0x100,"Software_Pattern : %s",pcVar11);
                      log_to_file(tmp1,time_stamp);
                    }
                    else {
                      iVar10 = strcmp(Mes_System_Test_Method_ptr->method,"AUTOGEN_PATTERN");
                      if (iVar10 == 0) {
                        (Local_Config_Information->Test_Info).Test_Method.Software_Pattern = false;
                        (Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern =
                             false;
                        (Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern = false;
                        (Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern = true;
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern ==
                            false) {
                          pcVar11 = "false";
                        }
                        else {
                          pcVar11 = "true";
                        }
                        printf("%s : Software_Pattern : %s\n","find_test_standard_position",pcVar11)
                        ;
                        if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern ==
                            false) {
                          pcVar11 = "false";
                        }
                        else {
                          pcVar11 = "true";
                        }
                        snprintf(tmp1,0x100,"Software_Pattern : %s",pcVar11);
                        log_to_file(tmp1,time_stamp);
                      }
                      else {
                        (Local_Config_Information->Test_Info).Test_Method.Software_Pattern = false;
                        (Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern =
                             false;
                        (Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern = false;
                        (Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern = false;
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s : test_method[%d]: %s. error\n","find_test_standard_position",
                               test_method_array_index,Mes_System_Test_Method_ptr->method);
                        snprintf(tmp1,0x100,"test_method[%d]: %s. error",test_method_array_index,
                                 Mes_System_Test_Method_ptr->method);
                        log_to_file(tmp1,time_stamp);
                      }
                    }
                  }
                }
                bVar6 = true;
                goto LAB_00049ca4;
              }
              Mes_System_Test_Method_ptr = Mes_System_Test_Method_ptr->next;
              test_method_array_index = test_method_array_index + 1;
            } while( true );
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : can\'t find:: pattern_id: %d\n","find_test_standard_position",pattern_id);
          snprintf(tmp1,0x100,"can\'t find:: pattern_id: %d",pattern_id);
          log_to_file(tmp1,time_stamp);
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : can\'t find::  %s%s%s, %s, BIN%d\n","find_test_standard_position",
                 hardware_version,bom_version,chip_technology,ft_version,bin);
          snprintf(tmp1,0x100,"can\'t find::  %s%s%s, %s, BIN%d",hardware_version,bom_version,
                   chip_technology,ft_version,bin);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : can\'t find:: board_name: %s, asic_type: %s\n","find_test_standard_position",
               board_name,asic_type);
        snprintf(tmp1,0x100,"can\'t find:: board_name: %s, asic_type: %s",board_name,asic_type);
        log_to_file(tmp1,time_stamp);
      }
    }
LAB_0004a0c0:
    Mes_System_Configs_ptr = Mes_System_Configs_ptr->next;
  } while( true );
  Mes_System_Hw_Info_ptr = Mes_System_Hw_Info_ptr->next;
  goto LAB_00048382;
LAB_00048c90:
  Mes_System_Test_Config_ptr = Mes_System_Test_Config_ptr->next;
  goto LAB_00048ca6;
}

