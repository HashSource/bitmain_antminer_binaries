
/* WARNING: Type propagation algorithm not settling */

_Bool parse_local_config_file(char *config_file_path)

{
  Test_Info *pTVar1;
  Local_Config_Info *pLVar2;
  _Bool _Var3;
  json_t *json;
  json_t *pjVar4;
  char *pcVar5;
  json_t *pjVar6;
  json_t *pjVar7;
  json_t *pjVar8;
  int iVar9;
  Hash_Board *pHVar10;
  json_int_t jVar11;
  char *config_file_path_local;
  char time_stamp [48];
  char tmp1 [256];
  json_error_t error;
  json_t *Test_Loop_array [50];
  json_t *CtrlBoard_Sensor_Addr_array [2];
  json_t *Pic_Sensor_Addr_array [4];
  json_t *m_obj;
  json_t *Freq_Flex;
  json_t *Find_Stupid_Asic;
  json_t *Force_Local_Cfg_Level;
  json_t *Sweep_Max_Freq;
  json_t *Sweep_Min_Freq;
  json_t *Force_Reset_Freq_Range;
  json_t *Freq_Float_Percent;
  json_t *Force_PT2_Before_Sweep;
  json_t *Data_Reuse_Mode;
  json_t *Force_Reset_Power_Mode;
  json_t *Sweep_Cfg;
  json_t *Enable_Repair;
  json_t *Clear_EEPROM_Data;
  json_t *Close_Power_Delay;
  json_t *Repair_Mode;
  json_t *Voltage_Accuracy;
  json_t *Test_Config_Data_Version;
  json_t *Display_result_Every_Core;
  json_t *Display_result_Voltage_Domain;
  json_t *Display;
  json_t *Work_Fan_Speed;
  json_t *Fan_Speed;
  json_t *Fan_Limit;
  json_t *Fan;
  json_t *Time_For_Cooling_Hashboard;
  json_t *Max_Board_Temp;
  json_t *Max_Wait_Cooling_Down_Time;
  json_t *Start_Temp_Gap_Pic;
  json_t *Temperature;
  json_t *Diode_Vdd_Mux_Sel;
  json_t *CO_Relay_En;
  json_t *RO_Relay_En;
  json_t *Clk_Sel;
  json_t *Pulse_Mode;
  json_t *Swpf_Mode;
  json_t *Pwth_Sel;
  json_t *CCdly_Sel;
  json_t *Asic_Register;
  json_t *Timeout;
  json_t *Baudrate;
  json_t *Test_Speed;
  json_t *Voltage_Adjust_Step;
  json_t *Inc_Freq_Delay;
  json_t *Wait_Board_Temp;
  json_t *Smooth_Voltage;
  json_t *Frequence;
  json_t *Voltage;
  json_t *Pre_Open_Core_Voltage;
  json_t *Level;
  json_t *Test_Loop;
  json_t *Most_HW_Num;
  json_t *Nonce_Rate;
  json_t *Asic_Nonce_Rate;
  json_t *Least_Nonce_Per_Core;
  json_t *Invalid_Core_Number;
  json_t *Pattern_Number;
  json_t *Test_Standard;
  json_t *Capture_Pattern;
  json_t *Midstate_Number;
  json_t *Autogen_Pattern;
  json_t *Hardware_Pattern;
  json_t *Super_Software_Pattern;
  json_t *Software_Pattern;
  json_t *Test_Method;
  json_t *Bypass_Scan_Code_Gun;
  json_t *Factory_Mode;
  json_t *Max_PT1_Board_Poweron_Time;
  json_t *Test_Info;
  json_t *Power_Version_array;
  json_t *Power_Version;
  json_t *CtrlBoard_Sensor_Addr;
  json_t *CtrlBoard_Sensor_Model;
  json_t *CtrlBoard_Sensor;
  json_t *Pic_Sensor_Addr;
  json_t *Pic_Sensor_Model;
  json_t *Pic_Sensor;
  json_t *Read_Temperature_From_CtrlBoard;
  json_t *Read_Temperature_From_Asic;
  json_t *Read_Temperature_From_Pic;
  json_t *Sensor_Info;
  json_t *Has_Pic;
  json_t *Asic_Num_Per_Voltage_Domain;
  json_t *Voltage_Domain;
  json_t *Asic_Num;
  json_t *Asic_Type;
  json_t *Board_Name;
  json_t *Miner_Type;
  json_t *Hash_Board;
  json_t *Test_Process;
  json_t *Local_Config_File;
  _Bool ret;
  uint32_t index;
  
  Pic_Sensor_Addr_array[0] = (json_t *)0x0;
  Pic_Sensor_Addr_array[1] = (json_t *)0x0;
  Pic_Sensor_Addr_array[2] = (json_t *)0x0;
  Pic_Sensor_Addr_array[3] = (json_t *)0x0;
  CtrlBoard_Sensor_Addr_array[0] = (json_t *)0x0;
  CtrlBoard_Sensor_Addr_array[1] = (json_t *)0x0;
  memset(Test_Loop_array,0,200);
  ret = true;
  json = json_load_file(config_file_path,0,&error);
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Can\'t read out local config file : %s\n","parse_local_config_file",
           config_file_path);
    snprintf(tmp1,0x100,"Can\'t read out local config file : %s",config_file_path);
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    pjVar4 = json_object_get(json,"Test_Process");
    pLVar2 = Local_Config_Information;
    if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_STRING)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Can\'t read out Test_Process in %s\n","parse_local_config_file",config_file_path)
      ;
      snprintf(tmp1,0x100,"Can\'t read out Test_Process in %s",config_file_path);
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      pcVar5 = json_string_value(pjVar4);
      strcpy(pLVar2->Test_Process,pcVar5);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Test_Process : %s\n","parse_local_config_file",Local_Config_Information);
      snprintf(tmp1,0x100,"Test_Process : %s",Local_Config_Information);
      log_to_file(tmp1,time_stamp);
      pjVar4 = json_object_get(json,"Hash_Board");
      if ((pjVar4 == (json_t *)0x0) || (pjVar4->type != JSON_OBJECT)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Can\'t read out Hash_Board in %s\n","parse_local_config_file",config_file_path)
        ;
        snprintf(tmp1,0x100,"Can\'t read out Hash_Board in %s",config_file_path);
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        pjVar6 = json_object_get(pjVar4,"Miner_Type");
        if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Can\'t read out Miner_Type in %s\n","parse_local_config_file",
                 config_file_path);
          snprintf(tmp1,0x100,"Can\'t read out Miner_Type in %s",config_file_path);
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          pHVar10 = &Local_Config_Information->Hash_Board;
          pcVar5 = json_string_value(pjVar6);
          strcpy(pHVar10->Miner_Type,pcVar5);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Miner_Type : %s\n","parse_local_config_file",
                 &Local_Config_Information->Hash_Board);
          snprintf(tmp1,0x100,"Miner_Type : %s",&Local_Config_Information->Hash_Board);
          log_to_file(tmp1,time_stamp);
          pjVar6 = json_object_get(pjVar4,"Board_Name");
          if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Can\'t read out Board_Name in %s\n","parse_local_config_file",
                   config_file_path);
            snprintf(tmp1,0x100,"Can\'t read out Board_Name in %s",config_file_path);
            log_to_file(tmp1,time_stamp);
            ret = false;
          }
          else {
            pHVar10 = &Local_Config_Information->Hash_Board;
            pcVar5 = json_string_value(pjVar6);
            strcpy(pHVar10->Board_Name,pcVar5);
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Board_Name : %s\n","parse_local_config_file",
                   (Local_Config_Information->Hash_Board).Board_Name);
            snprintf(tmp1,0x100,"Board_Name : %s",(Local_Config_Information->Hash_Board).Board_Name)
            ;
            log_to_file(tmp1,time_stamp);
            pjVar6 = json_object_get(pjVar4,"Asic_Type");
            if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_STRING)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Can\'t read out Asic_Type in %s\n","parse_local_config_file",
                     config_file_path);
              snprintf(tmp1,0x100,"Can\'t read out Asic_Type in %s",config_file_path);
              log_to_file(tmp1,time_stamp);
              ret = false;
            }
            else {
              pHVar10 = &Local_Config_Information->Hash_Board;
              pcVar5 = json_string_value(pjVar6);
              strcpy(pHVar10->Asic_Type,pcVar5);
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Asic_Type : %s\n","parse_local_config_file",
                     (Local_Config_Information->Hash_Board).Asic_Type);
              snprintf(tmp1,0x100,"Asic_Type : %s",(Local_Config_Information->Hash_Board).Asic_Type)
              ;
              log_to_file(tmp1,time_stamp);
              pjVar6 = json_object_get(pjVar4,"Asic_Num");
              pLVar2 = Local_Config_Information;
              if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Can\'t read out Asic_Num in %s\n","parse_local_config_file",
                       config_file_path);
                snprintf(tmp1,0x100,"Can\'t read out Asic_Num in %s",config_file_path);
                log_to_file(tmp1,time_stamp);
                ret = false;
              }
              else {
                jVar11 = json_integer_value(pjVar6);
                (pLVar2->Hash_Board).Asic_Num = (uint32_t)jVar11;
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Asic_Num : %d\n","parse_local_config_file",
                       (Local_Config_Information->Hash_Board).Asic_Num);
                snprintf(tmp1,0x100,"Asic_Num : %d",(Local_Config_Information->Hash_Board).Asic_Num)
                ;
                log_to_file(tmp1,time_stamp);
                pjVar6 = json_object_get(pjVar4,"Voltage_Domain");
                pLVar2 = Local_Config_Information;
                if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Can\'t read out Voltage_Domain in %s\n","parse_local_config_file",
                         config_file_path);
                  snprintf(tmp1,0x100,"Can\'t read out Voltage_Domain in %s",config_file_path);
                  log_to_file(tmp1,time_stamp);
                  ret = false;
                }
                else {
                  jVar11 = json_integer_value(pjVar6);
                  (pLVar2->Hash_Board).Voltage_Domain = (uint32_t)jVar11;
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Voltage_Domain : %d\n","parse_local_config_file",
                         (Local_Config_Information->Hash_Board).Voltage_Domain);
                  snprintf(tmp1,0x100,"Voltage_Domain : %d",
                           (Local_Config_Information->Hash_Board).Voltage_Domain);
                  log_to_file(tmp1,time_stamp);
                  pjVar6 = json_object_get(pjVar4,"Asic_Num_Per_Voltage_Domain");
                  pLVar2 = Local_Config_Information;
                  if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : Can\'t read out Asic_Num_Per_Voltage_Domain in %s\n",
                           "parse_local_config_file",config_file_path);
                    snprintf(tmp1,0x100,"Can\'t read out Asic_Num_Per_Voltage_Domain in %s",
                             config_file_path);
                    log_to_file(tmp1,time_stamp);
                    ret = false;
                  }
                  else {
                    jVar11 = json_integer_value(pjVar6);
                    (pLVar2->Hash_Board).Asic_Num_Per_Voltage_Domain = (uint32_t)jVar11;
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : Asic_Num_Per_Voltage_Domain : %d\n","parse_local_config_file",
                           (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
                    snprintf(tmp1,0x100,"Asic_Num_Per_Voltage_Domain : %d",
                             (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
                    log_to_file(tmp1,time_stamp);
                    pjVar6 = json_object_get(pjVar4,"Has_Pic");
                    if (((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_TRUE)) &&
                       ((pjVar6 == (json_t *)0x0 || (pjVar6->type != JSON_FALSE)))) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Can\'t read out Has_Pic in %s,will set default value\n",
                             "parse_local_config_file",config_file_path);
                      snprintf(tmp1,0x100,"Can\'t read out Has_Pic in %s,will set default value",
                               config_file_path);
                      log_to_file(tmp1,time_stamp);
                      (Local_Config_Information->Hash_Board).Has_Pic = true;
                    }
                    else {
                      if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_TRUE)) {
                        _Var3 = false;
                      }
                      else {
                        _Var3 = true;
                      }
                      (Local_Config_Information->Hash_Board).Has_Pic = _Var3;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      if ((Local_Config_Information->Hash_Board).Has_Pic == false) {
                        pcVar5 = "false";
                      }
                      else {
                        pcVar5 = "true";
                      }
                      printf("%s : Has_Pic : %s\n","parse_local_config_file",pcVar5);
                      if ((Local_Config_Information->Hash_Board).Has_Pic == false) {
                        pcVar5 = "false";
                      }
                      else {
                        pcVar5 = "true";
                      }
                      snprintf(tmp1,0x100,"Has_Pic : %s",pcVar5);
                      log_to_file(tmp1,time_stamp);
                    }
                    pjVar6 = json_object_get(pjVar4,"Smooth_Voltage");
                    if (((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_TRUE)) &&
                       ((pjVar6 == (json_t *)0x0 || (pjVar6->type != JSON_FALSE)))) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Can\'t read out Smooth_Voltage in %s,will set default value\n",
                             "parse_local_config_file",config_file_path);
                      snprintf(tmp1,0x100,
                               "Can\'t read out Smooth_Voltage in %s,will set default value",
                               config_file_path);
                      log_to_file(tmp1,time_stamp);
                      (Local_Config_Information->Hash_Board).Smooth_Voltage = false;
                    }
                    else {
                      if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_TRUE)) {
                        _Var3 = false;
                      }
                      else {
                        _Var3 = true;
                      }
                      (Local_Config_Information->Hash_Board).Smooth_Voltage = _Var3;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      if ((Local_Config_Information->Hash_Board).Smooth_Voltage == false) {
                        pcVar5 = "false";
                      }
                      else {
                        pcVar5 = "true";
                      }
                      printf("%s : Smooth_Voltage : %s\n","parse_local_config_file",pcVar5);
                      if ((Local_Config_Information->Hash_Board).Smooth_Voltage == false) {
                        pcVar5 = "false";
                      }
                      else {
                        pcVar5 = "true";
                      }
                      snprintf(tmp1,0x100,"Smooth_Voltage : %s",pcVar5);
                      log_to_file(tmp1,time_stamp);
                    }
                    pjVar6 = json_object_get(pjVar4,"Inc_Freq_Delay");
                    pLVar2 = Local_Config_Information;
                    if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Can\'t read out Inc_Freq_Delay in %s,will set default value\n",
                             "parse_local_config_file",config_file_path);
                      snprintf(tmp1,0x100,
                               "Can\'t read out Inc_Freq_Delay in %s,will set default value",
                               config_file_path);
                      log_to_file(tmp1,time_stamp);
                      (Local_Config_Information->Hash_Board).Inc_Freq_Delay = 400;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Inc_Freq_Delay : %d\n","parse_local_config_file",
                             (Local_Config_Information->Hash_Board).Inc_Freq_Delay);
                      snprintf(tmp1,0x100,"Inc_Freq_Delay : %d",
                               (Local_Config_Information->Hash_Board).Inc_Freq_Delay);
                      log_to_file(tmp1,time_stamp);
                    }
                    else {
                      jVar11 = json_integer_value(pjVar6);
                      (pLVar2->Hash_Board).Inc_Freq_Delay = (uint32_t)jVar11;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Inc_Freq_Delay : %d\n","parse_local_config_file",
                             (Local_Config_Information->Hash_Board).Inc_Freq_Delay);
                      snprintf(tmp1,0x100,"Inc_Freq_Delay : %d",
                               (Local_Config_Information->Hash_Board).Inc_Freq_Delay);
                      log_to_file(tmp1,time_stamp);
                    }
                    pjVar6 = json_object_get(pjVar4,"Voltage_Adjust_Step");
                    pLVar2 = Local_Config_Information;
                    if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Can\'t read out Voltage_Adjust_Step in %s,will set default value\n"
                             ,"parse_local_config_file",config_file_path);
                      snprintf(tmp1,0x100,
                               "Can\'t read out Voltage_Adjust_Step in %s,will set default value",
                               config_file_path);
                      log_to_file(tmp1,time_stamp);
                      (Local_Config_Information->Hash_Board).Voltage_Adjust_Step = 5;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Voltage_Adjust_Step : %d\n","parse_local_config_file",
                             (Local_Config_Information->Hash_Board).Voltage_Adjust_Step);
                      snprintf(tmp1,0x100,"Voltage_Adjust_Step : %d",
                               (Local_Config_Information->Hash_Board).Voltage_Adjust_Step);
                      log_to_file(tmp1,time_stamp);
                    }
                    else {
                      jVar11 = json_integer_value(pjVar6);
                      (pLVar2->Hash_Board).Voltage_Adjust_Step = (uint32_t)jVar11;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Voltage_Adjust_Step : %d\n","parse_local_config_file",
                             (Local_Config_Information->Hash_Board).Voltage_Adjust_Step);
                      snprintf(tmp1,0x100,"Voltage_Adjust_Step : %d",
                               (Local_Config_Information->Hash_Board).Voltage_Adjust_Step);
                      log_to_file(tmp1,time_stamp);
                    }
                    pjVar6 = json_object_get(pjVar4,"Wait_Board_Temp");
                    pLVar2 = Local_Config_Information;
                    if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_INTEGER)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Can\'t read out Wait_Board_Temp in %s,will set default value\n",
                             "parse_local_config_file",config_file_path);
                      snprintf(tmp1,0x100,
                               "Can\'t read out Wait_Board_Temp in %s,will set default value",
                               config_file_path);
                      log_to_file(tmp1,time_stamp);
                      (Local_Config_Information->Hash_Board).Wait_Board_Temp = 0;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Wait_Board_Temp : %d\n","parse_local_config_file",
                             (Local_Config_Information->Hash_Board).Wait_Board_Temp);
                      snprintf(tmp1,0x100,"Wait_Board_Temp : %d",
                               (Local_Config_Information->Hash_Board).Wait_Board_Temp);
                      log_to_file(tmp1,time_stamp);
                    }
                    else {
                      jVar11 = json_integer_value(pjVar6);
                      (pLVar2->Hash_Board).Wait_Board_Temp = (uint32_t)jVar11;
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Wait_Board_Temp : %d\n","parse_local_config_file",
                             (Local_Config_Information->Hash_Board).Wait_Board_Temp);
                      snprintf(tmp1,0x100,"Wait_Board_Temp : %d",
                               (Local_Config_Information->Hash_Board).Wait_Board_Temp);
                      log_to_file(tmp1,time_stamp);
                    }
                    pjVar6 = json_object_get(pjVar4,"Sensor_Info");
                    if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_OBJECT)) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : Can\'t read out Sensor_Info in %s\n","parse_local_config_file",
                             config_file_path);
                      snprintf(tmp1,0x100,"Can\'t read out Sensor_Info in %s",config_file_path);
                      log_to_file(tmp1,time_stamp);
                      ret = false;
                    }
                    else {
                      pjVar7 = json_object_get(pjVar6,"Read_Temperature_From_Pic");
                      if (((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) &&
                         ((pjVar7 == (json_t *)0x0 || (pjVar7->type != JSON_FALSE)))) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s : Can\'t read out Read_Temperature_From_Pic in %s\n",
                               "parse_local_config_file",config_file_path);
                        snprintf(tmp1,0x100,"Can\'t read out Read_Temperature_From_Pic in %s",
                                 config_file_path);
                        log_to_file(tmp1,time_stamp);
                        ret = false;
                      }
                      else {
                        if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) {
                          _Var3 = false;
                        }
                        else {
                          _Var3 = true;
                        }
                        (Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic
                             = _Var3;
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        if ((Local_Config_Information->Hash_Board).Sensor_Info.
                            Read_Temperature_From_Pic == false) {
                          pcVar5 = "false";
                        }
                        else {
                          pcVar5 = "true";
                        }
                        printf("%s : Read_Temperature_From_Pic : %s\n","parse_local_config_file",
                               pcVar5);
                        if ((Local_Config_Information->Hash_Board).Sensor_Info.
                            Read_Temperature_From_Pic == false) {
                          pcVar5 = "false";
                        }
                        else {
                          pcVar5 = "true";
                        }
                        snprintf(tmp1,0x100,"Read_Temperature_From_Pic : %s",pcVar5);
                        log_to_file(tmp1,time_stamp);
                        pjVar7 = json_object_get(pjVar6,"Read_Temperature_From_Asic");
                        if (((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) &&
                           ((pjVar7 == (json_t *)0x0 || (pjVar7->type != JSON_FALSE)))) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s : Can\'t read out Read_Temperature_From_Asic in %s\n",
                                 "parse_local_config_file",config_file_path);
                          snprintf(tmp1,0x100,"Can\'t read out Read_Temperature_From_Asic in %s",
                                   config_file_path);
                          log_to_file(tmp1,time_stamp);
                          ret = false;
                        }
                        else {
                          if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) {
                            _Var3 = false;
                          }
                          else {
                            _Var3 = true;
                          }
                          (Local_Config_Information->Hash_Board).Sensor_Info.
                          Read_Temperature_From_Asic = _Var3;
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          if ((Local_Config_Information->Hash_Board).Sensor_Info.
                              Read_Temperature_From_Asic == false) {
                            pcVar5 = "false";
                          }
                          else {
                            pcVar5 = "true";
                          }
                          printf("%s : Read_Temperature_From_Asic : %s\n","parse_local_config_file",
                                 pcVar5);
                          if ((Local_Config_Information->Hash_Board).Sensor_Info.
                              Read_Temperature_From_Asic == false) {
                            pcVar5 = "false";
                          }
                          else {
                            pcVar5 = "true";
                          }
                          snprintf(tmp1,0x100,"Read_Temperature_From_Asic : %s",pcVar5);
                          log_to_file(tmp1,time_stamp);
                          pjVar7 = json_object_get(pjVar6,"Read_Temperature_From_CtrlBoard");
                          if (((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) &&
                             ((pjVar7 == (json_t *)0x0 || (pjVar7->type != JSON_FALSE)))) {
                            print_time_stamp(time_stamp,0x30);
                            printf("%s ",time_stamp);
                            printf("%s : Can\'t read out Read_Temperature_From_CtrlBoard in %s,will set default value\n"
                                   ,"parse_local_config_file",config_file_path);
                            snprintf(tmp1,0x100,
                                     "Can\'t read out Read_Temperature_From_CtrlBoard in %s,will set default value"
                                     ,config_file_path);
                            log_to_file(tmp1,time_stamp);
                            (Local_Config_Information->Hash_Board).Sensor_Info.
                            Read_Temperature_From_CtrlBoard = false;
                          }
                          else {
                            if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_TRUE)) {
                              _Var3 = false;
                            }
                            else {
                              _Var3 = true;
                            }
                            (Local_Config_Information->Hash_Board).Sensor_Info.
                            Read_Temperature_From_CtrlBoard = _Var3;
                            print_time_stamp(time_stamp,0x30);
                            printf("%s ",time_stamp);
                            if ((Local_Config_Information->Hash_Board).Sensor_Info.
                                Read_Temperature_From_CtrlBoard == false) {
                              pcVar5 = "false";
                            }
                            else {
                              pcVar5 = "true";
                            }
                            printf("%s : Read_Temperature_From_CtrlBoard : %s\n",
                                   "parse_local_config_file",pcVar5);
                            if ((Local_Config_Information->Hash_Board).Sensor_Info.
                                Read_Temperature_From_CtrlBoard == false) {
                              pcVar5 = "false";
                            }
                            else {
                              pcVar5 = "true";
                            }
                            snprintf(tmp1,0x100,"Read_Temperature_From_CtrlBoard : %s",pcVar5);
                            log_to_file(tmp1,time_stamp);
                          }
                          pjVar7 = json_object_get(pjVar6,"Pic_Sensor");
                          if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_OBJECT)) {
                            print_time_stamp(time_stamp,0x30);
                            printf("%s ",time_stamp);
                            printf("%s : Can\'t read out Pic_Sensor in %s\n",
                                   "parse_local_config_file",config_file_path);
                            snprintf(tmp1,0x100,"Can\'t read out Pic_Sensor in %s",config_file_path)
                            ;
                            log_to_file(tmp1,time_stamp);
                            ret = false;
                          }
                          else {
                            pjVar8 = json_object_get(pjVar7,"Pic_Sensor_Model");
                            if ((pjVar8 == (json_t *)0x0) || (pjVar8->type != JSON_STRING)) {
                              print_time_stamp(time_stamp,0x30);
                              printf("%s ",time_stamp);
                              printf("%s : Can\'t read out Pic_Sensor_Model in %s\n",
                                     "parse_local_config_file",config_file_path);
                              snprintf(tmp1,0x100,"Can\'t read out Pic_Sensor_Model in %s",
                                       config_file_path);
                              log_to_file(tmp1,time_stamp);
                              ret = false;
                            }
                            else {
                              pHVar10 = &Local_Config_Information->Hash_Board;
                              pcVar5 = json_string_value(pjVar8);
                              strcpy((pHVar10->Sensor_Info).Pic_Sensor.Pic_Sensor_Model,pcVar5);
                              print_time_stamp(time_stamp,0x30);
                              printf("%s ",time_stamp);
                              printf("%s : Pic_Sensor_Model : %s\n","parse_local_config_file",
                                     &(Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor)
                              ;
                              snprintf(tmp1,0x100,"Pic_Sensor_Model : %s",
                                       &(Local_Config_Information->Hash_Board).Sensor_Info.
                                        Pic_Sensor);
                              log_to_file(tmp1,time_stamp);
                              _Var3 = check_pic_sensor_type
                                                ((Local_Config_Information->Hash_Board).Sensor_Info.
                                                 Pic_Sensor.Pic_Sensor_Model);
                              if (!_Var3) {
                                return false;
                              }
                              pjVar7 = json_object_get(pjVar7,"Pic_Sensor_Addr");
                              if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_ARRAY)) {
                                print_time_stamp(time_stamp,0x30);
                                printf("%s ",time_stamp);
                                printf("%s : Can\'t read out Pic_Sensor_Addr in %s\n",
                                       "parse_local_config_file",config_file_path);
                                snprintf(tmp1,0x100,"Can\'t read out Pic_Sensor_Addr in %s",
                                         config_file_path);
                                log_to_file(tmp1,time_stamp);
                                ret = false;
                              }
                              else {
                                gPic_sensor_num = json_array_size(pjVar7);
                                if (gPic_sensor_num < 5) {
                                  print_time_stamp(time_stamp,0x30);
                                  printf("%s ",time_stamp);
                                  printf("%s : gPic_sensor_num : %d\n","parse_local_config_file",
                                         gPic_sensor_num);
                                  snprintf(tmp1,0x100,"gPic_sensor_num : %d",gPic_sensor_num);
                                  log_to_file(tmp1,time_stamp);
                                  memset(gPic_sensor_low_3_bits_addr,0,4);
                                  for (index = 0; index < gPic_sensor_num; index = index + 1) {
                                    pjVar8 = json_array_get(pjVar7,index);
                                    Pic_Sensor_Addr_array[index] = pjVar8;
                                    if ((Pic_Sensor_Addr_array[index] == (json_t *)0x0) ||
                                       (Pic_Sensor_Addr_array[index]->type != JSON_INTEGER)) {
                                      print_time_stamp(time_stamp,0x30);
                                      printf("%s ",time_stamp);
                                      printf("%s : Can\'t find Pic_Sensor_Addr_array[%d]\n",
                                             "parse_local_config_file",index);
                                      snprintf(tmp1,0x100,"Can\'t find Pic_Sensor_Addr_array[%d]",
                                               index);
                                      log_to_file(tmp1,time_stamp);
                                      ret = false;
                                      goto LAB_00021460;
                                    }
                                    jVar11 = json_integer_value(Pic_Sensor_Addr_array[index]);
                                    gPic_sensor_low_3_bits_addr[index] = (uint8_t)jVar11;
                                    print_time_stamp(time_stamp,0x30);
                                    printf("%s ",time_stamp);
                                    printf("%s : gPic_sensor_low_3_bits_addr[%d] : %d\n",
                                           "parse_local_config_file",index,
                                           (uint)gPic_sensor_low_3_bits_addr[index]);
                                    snprintf(tmp1,0x100,"gPic_sensor_low_3_bits_addr[%d] : %d",index
                                             ,(uint)gPic_sensor_low_3_bits_addr[index]);
                                    log_to_file(tmp1,time_stamp);
                                  }
                                  pjVar6 = json_object_get(pjVar6,"CtrlBoard_Sensor");
                                  if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_OBJECT)) {
                                    print_time_stamp(time_stamp,0x30);
                                    printf("%s ",time_stamp);
                                    printf("%s : Can\'t read out CtrlBoard_Sensor in %s\n",
                                           "parse_local_config_file",config_file_path);
                                    snprintf(tmp1,0x100,"Can\'t read out CtrlBoard_Sensor in %s",
                                             config_file_path);
                                    log_to_file(tmp1,time_stamp);
                                    ret = false;
                                  }
                                  else {
                                    pjVar7 = json_object_get(pjVar6,"CtrlBoard_Sensor_Model");
                                    if ((pjVar7 == (json_t *)0x0) || (pjVar7->type != JSON_STRING))
                                    {
                                      print_time_stamp(time_stamp,0x30);
                                      printf("%s ",time_stamp);
                                      printf("%s : Can\'t read out CtrlBoard_Sensor_Model in %s\n",
                                             "parse_local_config_file",config_file_path);
                                      snprintf(tmp1,0x100,
                                               "Can\'t read out CtrlBoard_Sensor_Model in %s",
                                               config_file_path);
                                      log_to_file(tmp1,time_stamp);
                                      ret = false;
                                    }
                                    else {
                                      pHVar10 = &Local_Config_Information->Hash_Board;
                                      pcVar5 = json_string_value(pjVar7);
                                      strcpy((pHVar10->Sensor_Info).CtrlBoard_Sensor.
                                             CtrlBoard_Sensor_Model,pcVar5);
                                      print_time_stamp(time_stamp,0x30);
                                      printf("%s ",time_stamp);
                                      printf("%s : CtrlBoard_Sensor_Model : %s\n",
                                             "parse_local_config_file",
                                             &(Local_Config_Information->Hash_Board).Sensor_Info.
                                              CtrlBoard_Sensor);
                                      snprintf(tmp1,0x100,"CtrlBoard_Sensor_Model : %s",
                                               &(Local_Config_Information->Hash_Board).Sensor_Info.
                                                CtrlBoard_Sensor);
                                      log_to_file(tmp1,time_stamp);
                                      _Var3 = check_ctrlboard_sensor_type
                                                        ((Local_Config_Information->Hash_Board).
                                                         Sensor_Info.CtrlBoard_Sensor.
                                                         CtrlBoard_Sensor_Model);
                                      if (!_Var3) {
                                        return false;
                                      }
                                      pjVar6 = json_object_get(pjVar6,"CtrlBoard_Sensor_Addr");
                                      if ((pjVar6 == (json_t *)0x0) || (pjVar6->type != JSON_ARRAY))
                                      {
                                        print_time_stamp(time_stamp,0x30);
                                        printf("%s ",time_stamp);
                                        printf("%s : Can\'t read out CtrlBoard_Sensor_Addr in %s\n",
                                               "parse_local_config_file",config_file_path);
                                        snprintf(tmp1,0x100,
                                                 "Can\'t read out CtrlBoard_Sensor_Addr in %s",
                                                 config_file_path);
                                        log_to_file(tmp1,time_stamp);
                                        ret = false;
                                      }
                                      else {
                                        gCtrlBoard_sensor_num = json_array_size(pjVar6);
                                        if (gCtrlBoard_sensor_num < 3) {
                                          print_time_stamp(time_stamp,0x30);
                                          printf("%s ",time_stamp);
                                          printf("%s : gCtrlBoard_sensor_num : %d\n",
                                                 "parse_local_config_file",gCtrlBoard_sensor_num);
                                          snprintf(tmp1,0x100,"gCtrlBoard_sensor_num : %d",
                                                   gCtrlBoard_sensor_num);
                                          log_to_file(tmp1,time_stamp);
                                          memset(gCtrlBoard_sensor_low_3_bits_addr,0,2);
                                          for (index = 0; index < gCtrlBoard_sensor_num;
                                              index = index + 1) {
                                            pjVar7 = json_array_get(pjVar6,index);
                                            CtrlBoard_Sensor_Addr_array[index] = pjVar7;
                                            if ((CtrlBoard_Sensor_Addr_array[index] == (json_t *)0x0
                                                ) || (CtrlBoard_Sensor_Addr_array[index]->type !=
                                                      JSON_INTEGER)) {
                                              print_time_stamp(time_stamp,0x30);
                                              printf("%s ",time_stamp);
                                              printf(
                                                  "%s : Can\'t find CtrlBoard_Sensor_Addr_array[%d]\n"
                                                  ,"parse_local_config_file",index);
                                              snprintf(tmp1,0x100,
                                                       "Can\'t find CtrlBoard_Sensor_Addr_array[%d]"
                                                       ,index);
                                              log_to_file(tmp1,time_stamp);
                                              ret = false;
                                              goto LAB_00021460;
                                            }
                                            jVar11 = json_integer_value(CtrlBoard_Sensor_Addr_array
                                                                        [index]);
                                            gCtrlBoard_sensor_low_3_bits_addr[index] =
                                                 (uint8_t)jVar11;
                                            print_time_stamp(time_stamp,0x30);
                                            printf("%s ",time_stamp);
                                            printf(
                                                  "%s : gCtrlBoard_sensor_low_3_bits_addr[%d] : %d\n"
                                                  ,"parse_local_config_file",index,
                                                  (uint)gCtrlBoard_sensor_low_3_bits_addr[index]);
                                            snprintf(tmp1,0x100,
                                                     "gCtrlBoard_sensor_low_3_bits_addr[%d] : %d",
                                                     index,(uint)gCtrlBoard_sensor_low_3_bits_addr
                                                                 [index]);
                                            log_to_file(tmp1,time_stamp);
                                            (Local_Config_Information->Hash_Board).Sensor_Info.
                                            CtrlBoard_Sensor.trlBoard_Sensor_Addr[index] =
                                                 (uint)gCtrlBoard_sensor_low_3_bits_addr[index];
                                          }
                                          pjVar4 = json_object_get(pjVar4,"Power_Version");
                                          if ((pjVar4 == (json_t *)0x0) ||
                                             (pjVar4->type != JSON_ARRAY)) {
                                            print_time_stamp(time_stamp,0x30);
                                            printf("%s ",time_stamp);
                                            printf("%s : Can\'t read out Power_Version in %s\n",
                                                   "parse_local_config_file",config_file_path);
                                            snprintf(tmp1,0x100,
                                                     "Can\'t read out Power_Version in %s",
                                                     config_file_path);
                                            log_to_file(tmp1,time_stamp);
                                            ret = false;
                                          }
                                          else {
                                            gPower_version_array_size = json_array_size(pjVar4);
                                            if (gPower_version_array_size < 0x11) {
                                              print_time_stamp(time_stamp,0x30);
                                              printf("%s ",time_stamp);
                                              printf("%s : Can support %d apw power type\n",
                                                     "parse_local_config_file",
                                                     gPower_version_array_size);
                                              snprintf(tmp1,0x100,"Can support %d apw power type",
                                                       gPower_version_array_size);
                                              log_to_file(tmp1,time_stamp);
                                              for (index = 0; index < gPower_version_array_size;
                                                  index = index + 1) {
                                                pjVar6 = json_array_get(pjVar4,index);
                                                if ((pjVar6 == (json_t *)0x0) ||
                                                   (pjVar6->type != JSON_INTEGER)) {
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Can\'t find Power_Version[%d]\n",
                                                         "parse_local_config_file",index);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t find Power_Version[%d]",index);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                }
                                                jVar11 = json_integer_value(pjVar6);
                                                APW_power_version[index] = (uint8_t)jVar11;
                                                print_time_stamp(time_stamp,0x30);
                                                printf("%s ",time_stamp);
                                                printf("%s : APW_power_version[%d] = %d\n",
                                                       "parse_local_config_file",index,
                                                       (uint)APW_power_version[index]);
                                                snprintf(tmp1,0x100,"APW_power_version[%d] = %d",
                                                         index,(uint)APW_power_version[index]);
                                                log_to_file(tmp1,time_stamp);
                                              }
                                              pjVar4 = json_object_get(json,"Test_Info");
                                              if ((pjVar4 == (json_t *)0x0) ||
                                                 (pjVar4->type != JSON_OBJECT)) {
                                                print_time_stamp(time_stamp,0x30);
                                                printf("%s ",time_stamp);
                                                printf("%s : Can\'t read out Test_Info in %s\n",
                                                       "parse_local_config_file",config_file_path);
                                                snprintf(tmp1,0x100,
                                                         "Can\'t read out Test_Info in %s",
                                                         config_file_path);
                                                log_to_file(tmp1,time_stamp);
                                                ret = false;
                                              }
                                              else {
                                                pjVar6 = json_object_get(pjVar4,"Factory_Mode");
                                                if (((pjVar6 == (json_t *)0x0) ||
                                                    (pjVar6->type != JSON_TRUE)) &&
                                                   ((pjVar6 == (json_t *)0x0 ||
                                                    (pjVar6->type != JSON_FALSE)))) {
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Can\'t read out Factory_Mode in %s\n"
                                                         ,"parse_local_config_file",config_file_path
                                                        );
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Factory_Mode in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                }
                                                else {
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_TRUE)) {
                                                    _Var3 = false;
                                                  }
                                                  else {
                                                    _Var3 = true;
                                                  }
                                                  (Local_Config_Information->Test_Info).Factory_Mode
                                                       = _Var3;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  if ((Local_Config_Information->Test_Info).
                                                      Factory_Mode == false) {
                                                    pcVar5 = "false";
                                                  }
                                                  else {
                                                    pcVar5 = "true";
                                                  }
                                                  printf("%s : Factory_Mode : %s\n",
                                                         "parse_local_config_file",pcVar5);
                                                  if ((Local_Config_Information->Test_Info).
                                                      Factory_Mode == false) {
                                                    pcVar5 = "false";
                                                  }
                                                  else {
                                                    pcVar5 = "true";
                                                  }
                                                  snprintf(tmp1,0x100,"Factory_Mode : %s",pcVar5);
                                                  log_to_file(tmp1,time_stamp);
                                                  pjVar6 = json_object_get(pjVar4,
                                                  "Bypass_Scan_Code_Gun");
                                                  if (((pjVar6 == (json_t *)0x0) ||
                                                      (pjVar6->type != JSON_TRUE)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Bypass_Scan_Code_Gun in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Bypass_Scan_Code_Gun in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).
                                                    Bypass_Scan_Code_Gun = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Bypass_Scan_Code_Gun == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Bypass_Scan_Code_Gun : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Bypass_Scan_Code_Gun == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Bypass_Scan_Code_Gun : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar4,"Freq_Flex");
                                                    if (pjVar6 == (json_t *)0x0) {
                                                      (Local_Config_Information->Test_Info).
                                                      Freq_Flex = 0;
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Freq_Flex,set it 0\n",
                                                  "parse_local_config_file");
                                                  builtin_strncpy(tmp1,
                                                  "Can\'t read out Freq_Flex,set it 0",0x22);
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  else {
                                                    pjVar6 = json_object_get(pjVar4,"Freq_Flex");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Freq_Flex in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Freq_Flex in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar6);
                                                  (pLVar2->Test_Info).Freq_Flex = (int)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Freq_Flex : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Freq_Flex);
                                                  snprintf(tmp1,0x100,"Freq_Flex : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Freq_Flex);
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,"Find_Stupid_Asic"
                                                                          );
                                                  if (pjVar6 == (json_t *)0x0) {
                                                    (Local_Config_Information->Test_Info).
                                                    Find_Stupid_Asic = true;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Find_Stupid_Asic,set it true def\n"
                                                  ,"parse_local_config_file");
                                                  builtin_strncpy(tmp1,
                                                  "Can\'t read out Find_Stupid_Asic,set it true def"
                                                  ,0x30);
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  else {
                                                    pjVar6 = json_object_get(pjVar4,
                                                  "Find_Stupid_Asic");
                                                  if (((pjVar6 == (json_t *)0x0) ||
                                                      (pjVar6->type != JSON_TRUE)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Find_Stupid_Asic in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Find_Stupid_Asic in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                  }
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_TRUE)) {
                                                    _Var3 = false;
                                                  }
                                                  else {
                                                    _Var3 = true;
                                                  }
                                                  (Local_Config_Information->Test_Info).
                                                  Find_Stupid_Asic = _Var3;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  if ((Local_Config_Information->Test_Info).
                                                      Find_Stupid_Asic == false) {
                                                    pcVar5 = "false";
                                                  }
                                                  else {
                                                    pcVar5 = "true";
                                                  }
                                                  printf("%s : Find_Stupid_Asic : %s\n",
                                                         "parse_local_config_file",pcVar5);
                                                  if ((Local_Config_Information->Test_Info).
                                                      Find_Stupid_Asic == false) {
                                                    pcVar5 = "false";
                                                  }
                                                  else {
                                                    pcVar5 = "true";
                                                  }
                                                  snprintf(tmp1,0x100,"Find_Stupid_Asic : %s",pcVar5
                                                          );
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,
                                                  "Max_PT1_Board_Poweron_Time");
                                                  if (pjVar6 == (json_t *)0x0) {
                                                    (Local_Config_Information->Test_Info).
                                                    Max_PT1_Board_Poweron_Time = 5;
                                                  }
                                                  else {
                                                    pjVar6 = json_object_get(pjVar4,
                                                  "Max_PT1_Board_Poweron_Time");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Max_PT1_Board_Poweron_Time in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Max_PT1_Board_Poweron_Time in %s"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar6);
                                                  (pLVar2->Test_Info).Max_PT1_Board_Poweron_Time =
                                                       (int)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Max_PT1_Board_Poweron_Time : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Max_PT1_Board_Poweron_Time);
                                                  snprintf(tmp1,0x100,
                                                           "Max_PT1_Board_Poweron_Time : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Max_PT1_Board_Poweron_Time);
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,"Test_Method");
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_OBJECT)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Test_Method in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Test_Method in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Software_Pattern");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Software_Pattern in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Software_Pattern in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).
                                                    Test_Method.Software_Pattern = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Software_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Software_Pattern : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Software_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Software_Pattern : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Super_Software_Pattern");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Super_Software_Pattern in %s,will set default value\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Super_Software_Pattern in %s,will set default value"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  (Local_Config_Information->Test_Info).Test_Method.
                                                  Super_Software_Pattern = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).
                                                    Test_Method.Super_Software_Pattern = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Super_Software_Pattern == false)
                                                    {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Super_Software_Pattern : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Super_Software_Pattern == false)
                                                    {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,
                                                             "Super_Software_Pattern : %s",pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar7 = json_object_get(pjVar6,"Hardware_Pattern"
                                                                          );
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Hardware_Pattern in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Hardware_Pattern in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).
                                                    Test_Method.Hardware_Pattern = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Hardware_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Hardware_Pattern : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Hardware_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Hardware_Pattern : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Autogen_Pattern");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Autogen_Pattern in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Autogen_Pattern in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).
                                                    Test_Method.Autogen_Pattern = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Autogen_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Autogen_Pattern : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Autogen_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Autogen_Pattern : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Midstate_Number");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Midstate_Number in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Midstate_Number in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Method.Midstate_Number
                                                         = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Midstate_Number : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Method.Midstate_Number);
                                                    snprintf(tmp1,0x100,"Midstate_Number : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Method.Midstate_Number);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar6,
                                                  "Capture_Pattern");
                                                  if (((pjVar6 == (json_t *)0x0) ||
                                                      (pjVar6->type != JSON_TRUE)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Capture_Pattern in %s,will set default value\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Capture_Pattern in %s,will set default value"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  (Local_Config_Information->Test_Info).Test_Method.
                                                  Capture_Pattern = false;
                                                  }
                                                  else {
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).
                                                    Test_Method.Capture_Pattern = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Capture_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Capture_Pattern : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Test_Method.Capture_Pattern == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Capture_Pattern : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,"Sweep_Cfg");
                                                  iVar9 = strncmp(Local_Config_Information->
                                                                  Test_Process,"SWEEP",5);
                                                  if (((iVar9 == 0) ||
                                                      (iVar9 = strncmp(Local_Config_Information->
                                                                       Test_Process,"PT3",3),
                                                      iVar9 == 0)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_OBJECT)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : SWEEP Process but no Sweep_Cfg info\n",
                                                  "parse_local_config_file");
                                                  builtin_strncpy(tmp1,
                                                  "SWEEP Process but no Sweep_Cfg info",0x24);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Force_Reset_Power_Mode");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Force_Reset_Power_Mode in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Force_Reset_Power_Mode in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      iVar9 = 0;
                                                    }
                                                    else {
                                                      iVar9 = 1;
                                                    }
                                                    (Local_Config_Information->Test_Info).Sweep_Cfg.
                                                    Force_Reset_Power_Mode = iVar9;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_Reset_Power_Mode == 0) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Force_Reset_Power_Mode : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_Reset_Power_Mode == 0) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,
                                                             "Force_Reset_Power_Mode : %s",pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Force_PT2_Before_Sweep");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Force_PT2_Before_Sweep in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Force_PT2_Before_Sweep in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).Sweep_Cfg.
                                                    Force_PT2_Before_Sweep = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_PT2_Before_Sweep == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Force_PT2_Before_Sweep : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_PT2_Before_Sweep == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,
                                                             "Force_PT2_Before_Sweep : %s",pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Data_Reuse_Mode");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Data_Reuse_Mode in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Data_Reuse_Mode in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).Sweep_Cfg.
                                                    Data_Reuse_Mode = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Data_Reuse_Mode == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Data_Reuse_Mode : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Data_Reuse_Mode == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Data_Reuse_Mode : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Freq_Float_Percent");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Freq_Float_Percent in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Freq_Float_Percent in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Sweep_Cfg.Freq_Float_Percent
                                                         = (int)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Freq_Float_Percent : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Sweep_Cfg.Freq_Float_Percent);
                                                    snprintf(tmp1,0x100,"Freq_Float_Percent : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Sweep_Cfg.Freq_Float_Percent);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Force_Reset_Freq_Range");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Force_Reset_Freq_Range in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Force_Reset_Freq_Range in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).Sweep_Cfg.
                                                    Force_Reset_Freq_Range = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_Reset_Freq_Range == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Force_Reset_Freq_Range : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_Reset_Freq_Range == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,
                                                             "Force_Reset_Freq_Range : %s",pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Sweep_Min_Freq"
                                                                            );
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Sweep_Min_Freq in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Sweep_Min_Freq in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Sweep_Cfg.Sweep_Min_Freq =
                                                         (int)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Sweep_Min_Freq : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Sweep_Cfg.Sweep_Min_Freq);
                                                    snprintf(tmp1,0x100,"Sweep_Min_Freq : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Sweep_Cfg.Sweep_Min_Freq);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Sweep_Max_Freq"
                                                                            );
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Sweep_Max_Freq in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Sweep_Max_Freq in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Sweep_Cfg.Sweep_Max_Freq =
                                                         (int)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Sweep_Max_Freq : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Sweep_Cfg.Sweep_Max_Freq);
                                                    snprintf(tmp1,0x100,"Sweep_Max_Freq : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Sweep_Cfg.Sweep_Max_Freq);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar6,
                                                  "Force_Local_Cfg_Level");
                                                  if (((pjVar6 == (json_t *)0x0) ||
                                                      (pjVar6->type != JSON_TRUE)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Force_Local_Cfg_Level in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Force_Local_Cfg_Level in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).Sweep_Cfg.
                                                    Force_Local_Cfg_Level = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_Local_Cfg_Level == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Force_Local_Cfg_Level : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Sweep_Cfg.Force_Local_Cfg_Level == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Force_Local_Cfg_Level : %s"
                                                             ,pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar4,"Test_Standard")
                                                    ;
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_OBJECT)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Test_Standard in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Test_Standard in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,"Pattern_Number"
                                                                            );
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Pattern_Number in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Pattern_Number in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Standard.Pattern_Number
                                                         = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Pattern_Number : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Pattern_Number);
                                                    snprintf(tmp1,0x100,"Pattern_Number : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Standard.Pattern_Number);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Invalid_Core_Number");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Invalid_Core_Number in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Invalid_Core_Number in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Standard.
                                                    Invalid_Core_Number = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Invalid_Core_Number : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Invalid_Core_Number);
                                                    snprintf(tmp1,0x100,"Invalid_Core_Number : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Standard.Invalid_Core_Number);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Least_Nonce_Per_Core");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Least_Nonce_Per_Core in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Least_Nonce_Per_Core in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Standard.
                                                    Least_Nonce_Per_Core = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Least_Nonce_Per_Core : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Least_Nonce_Per_Core);
                                                    snprintf(tmp1,0x100,"Least_Nonce_Per_Core : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Standard.Least_Nonce_Per_Core);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Nonce_Rate");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Nonce_Rate in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Nonce_Rate in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Standard.Nonce_Rate =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Nonce_Rate : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Nonce_Rate);
                                                    snprintf(tmp1,0x100,"Nonce_Rate : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Standard.Nonce_Rate);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Most_HW_Num");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Most_HW_Num in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Most_HW_Num in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Standard.Most_HW_Num =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Most_HW_Num : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Most_HW_Num);
                                                    snprintf(tmp1,0x100,"Most_HW_Num : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Standard.Most_HW_Num);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Asic_Nonce_Rate");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Asic_Nonce_Rate in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Asic_Nonce_Rate in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Test_Standard.
                                                    Asic_Nonce_Rate = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Asic_Nonce_Rate : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Asic_Nonce_Rate);
                                                    snprintf(tmp1,0x100,"Asic_Nonce_Rate : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Standard.Asic_Nonce_Rate);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar6,"Test_Loop");
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_ARRAY)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Test_Loop in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Test_Loop in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    gTest_loop = json_array_size(pjVar6);
                                                    if (gTest_loop < 0x33) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : In local config file, gTest_loop : %d\n",
                                                  "parse_local_config_file",gTest_loop);
                                                  snprintf(tmp1,0x100,
                                                           "In local config file, gTest_loop : %d",
                                                           gTest_loop);
                                                  log_to_file(tmp1,time_stamp);
                                                  for (index = 0; index < gTest_loop;
                                                      index = index + 1) {
                                                    pjVar7 = json_array_get(pjVar6,index);
                                                    Test_Loop_array[index] = pjVar7;
                                                    if ((Test_Loop_array[index] == (json_t *)0x0) ||
                                                       (Test_Loop_array[index]->type != JSON_OBJECT)
                                                       ) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t find Test_Loop_array[%d]\n",
                                                  "parse_local_config_file",index);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t find Test_Loop_array[%d]",index);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                  }
                                                  pjVar7 = json_object_get(Test_Loop_array[index],
                                                                           "Level");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Can\'t read out Level in %s\n",
                                                           "parse_local_config_file",
                                                           config_file_path);
                                                    snprintf(tmp1,0x100,
                                                             "Can\'t read out Level in %s",
                                                             config_file_path);
                                                    log_to_file(tmp1,time_stamp);
                                                    ret = false;
                                                    goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar7);
                                                  (pLVar2->Test_Info).Test_Standard.Test_Loop[index]
                                                  .Level = (uint32_t)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Level : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Test_Standard.Test_Loop[index].Level);
                                                  snprintf(tmp1,0x100,"Level : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Test_Loop[index].Level);
                                                  log_to_file(tmp1,time_stamp);
                                                  pjVar7 = json_object_get(Test_Loop_array[index],
                                                                           "Pre_Open_Core_Voltage");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Pre_Open_Core_Voltage in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Pre_Open_Core_Voltage in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar7);
                                                  (pLVar2->Test_Info).Test_Standard.Test_Loop[index]
                                                  .Pre_Open_Core_Voltage = (uint32_t)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Pre_Open_Core_Voltage : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Test_Standard.Test_Loop[index].
                                                         Pre_Open_Core_Voltage);
                                                  snprintf(tmp1,0x100,"Pre_Open_Core_Voltage : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Test_Loop[index].
                                                           Pre_Open_Core_Voltage);
                                                  log_to_file(tmp1,time_stamp);
                                                  pjVar7 = json_object_get(Test_Loop_array[index],
                                                                           "Voltage");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Can\'t read out Voltage in %s\n",
                                                           "parse_local_config_file",
                                                           config_file_path);
                                                    snprintf(tmp1,0x100,
                                                             "Can\'t read out Voltage in %s",
                                                             config_file_path);
                                                    log_to_file(tmp1,time_stamp);
                                                    ret = false;
                                                    goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar7);
                                                  (pLVar2->Test_Info).Test_Standard.Test_Loop[index]
                                                  .Voltage = (uint32_t)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Voltage : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Test_Standard.Test_Loop[index].Voltage);
                                                  snprintf(tmp1,0x100,"Voltage : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Test_Loop[index].Voltage);
                                                  log_to_file(tmp1,time_stamp);
                                                  pjVar7 = json_object_get(Test_Loop_array[index],
                                                                           "Frequence");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Can\'t read out Frequence in %s\n",
                                                           "parse_local_config_file",
                                                           config_file_path);
                                                    snprintf(tmp1,0x100,
                                                             "Can\'t read out Frequence in %s",
                                                             config_file_path);
                                                    log_to_file(tmp1,time_stamp);
                                                    ret = false;
                                                    goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar7);
                                                  (pLVar2->Test_Info).Test_Standard.Test_Loop[index]
                                                  .Frequence = (uint32_t)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Frequence : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Test_Standard.Test_Loop[index].Frequence);
                                                  snprintf(tmp1,0x100,"Frequence : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Standard.Test_Loop[index].Frequence)
                                                  ;
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,"Test_Speed");
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_OBJECT)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Can\'t read out Test_Speed in %s\n"
                                                           ,"parse_local_config_file",
                                                           config_file_path);
                                                    snprintf(tmp1,0x100,
                                                             "Can\'t read out Test_Speed in %s",
                                                             config_file_path);
                                                    log_to_file(tmp1,time_stamp);
                                                    ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,"Baudrate");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf("%s : Can\'t read out Baudrate in %s\n"
                                                             ,"parse_local_config_file",
                                                             config_file_path);
                                                      snprintf(tmp1,0x100,
                                                               "Can\'t read out Baudrate in %s",
                                                               config_file_path);
                                                      log_to_file(tmp1,time_stamp);
                                                      ret = false;
                                                    }
                                                    else {
                                                      jVar11 = json_integer_value(pjVar7);
                                                      (pLVar2->Test_Info).Test_Speed.Baudrate =
                                                           (uint32_t)jVar11;
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf("%s : Baudrate : %d\n",
                                                             "parse_local_config_file",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Speed.Baudrate);
                                                      snprintf(tmp1,0x100,"Baudrate : %d",
                                                               (Local_Config_Information->Test_Info)
                                                               .Test_Speed.Baudrate);
                                                      log_to_file(tmp1,time_stamp);
                                                      pjVar6 = json_object_get(pjVar6,"Timeout");
                                                      pLVar2 = Local_Config_Information;
                                                      if ((pjVar6 == (json_t *)0x0) ||
                                                         (pjVar6->type != JSON_INTEGER)) {
                                                        print_time_stamp(time_stamp,0x30);
                                                        printf("%s ",time_stamp);
                                                        printf(
                                                  "%s : Can\'t read out Timeout in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Timeout in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar6);
                                                    (pLVar2->Test_Info).Test_Speed.Timeout =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Timeout : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Speed.Timeout);
                                                    snprintf(tmp1,0x100,"Timeout : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Speed.Timeout);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar4,"Asic_Register")
                                                    ;
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_OBJECT)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Asic_Register in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Asic_Register in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,"CCdly_Sel");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out CCdly_Sel in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out CCdly_Sel in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Asic_Register.CCdly_Sel =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : CCdly_Sel : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Asic_Register.CCdly_Sel);
                                                    snprintf(tmp1,0x100,"CCdly_Sel : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.CCdly_Sel);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Pwth_Sel");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf("%s : Can\'t read out Pwth_Sel in %s\n"
                                                             ,"parse_local_config_file",
                                                             config_file_path);
                                                      snprintf(tmp1,0x100,
                                                               "Can\'t read out Pwth_Sel in %s",
                                                               config_file_path);
                                                      log_to_file(tmp1,time_stamp);
                                                      ret = false;
                                                    }
                                                    else {
                                                      jVar11 = json_integer_value(pjVar7);
                                                      (pLVar2->Test_Info).Asic_Register.Pwth_Sel =
                                                           (uint32_t)jVar11;
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf("%s : Pwth_Sel : %d\n",
                                                             "parse_local_config_file",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.Pwth_Sel);
                                                      snprintf(tmp1,0x100,"Pwth_Sel : %d",
                                                               (Local_Config_Information->Test_Info)
                                                               .Asic_Register.Pwth_Sel);
                                                      log_to_file(tmp1,time_stamp);
                                                      pjVar7 = json_object_get(pjVar6,"Swpf_Mode");
                                                      pLVar2 = Local_Config_Information;
                                                      if ((pjVar7 == (json_t *)0x0) ||
                                                         (pjVar7->type != JSON_INTEGER)) {
                                                        print_time_stamp(time_stamp,0x30);
                                                        printf("%s ",time_stamp);
                                                        printf(
                                                  "%s : Can\'t read out Swpf_Mode in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Swpf_Mode in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Asic_Register.Swpf_Mode =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Swpf_Mode : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Asic_Register.Swpf_Mode);
                                                    snprintf(tmp1,0x100,"Swpf_Mode : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.Swpf_Mode);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Pulse_Mode");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Pulse_Mode in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Pulse_Mode in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Asic_Register.Pulse_Mode =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Pulse_Mode : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Asic_Register.Pulse_Mode);
                                                    snprintf(tmp1,0x100,"Pulse_Mode : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.Pulse_Mode);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Clk_Sel");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf("%s : Can\'t read out Clk_Sel in %s\n",
                                                             "parse_local_config_file",
                                                             config_file_path);
                                                      snprintf(tmp1,0x100,
                                                               "Can\'t read out Clk_Sel in %s",
                                                               config_file_path);
                                                      log_to_file(tmp1,time_stamp);
                                                      ret = false;
                                                    }
                                                    else {
                                                      jVar11 = json_integer_value(pjVar7);
                                                      (pLVar2->Test_Info).Asic_Register.Clk_Sel =
                                                           (uint32_t)jVar11;
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf("%s : Clk_Sel : %d\n",
                                                             "parse_local_config_file",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.Clk_Sel);
                                                      snprintf(tmp1,0x100,"Clk_Sel : %d",
                                                               (Local_Config_Information->Test_Info)
                                                               .Asic_Register.Clk_Sel);
                                                      log_to_file(tmp1,time_stamp);
                                                      pjVar7 = json_object_get(pjVar6,"RO_Relay_En")
                                                      ;
                                                      pLVar2 = Local_Config_Information;
                                                      if ((pjVar7 == (json_t *)0x0) ||
                                                         (pjVar7->type != JSON_INTEGER)) {
                                                        print_time_stamp(time_stamp,0x30);
                                                        printf("%s ",time_stamp);
                                                        printf(
                                                  "%s : Can\'t read out RO_Relay_En in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out RO_Relay_En in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Asic_Register.RO_Relay_En =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : RO_Relay_En : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Asic_Register.RO_Relay_En);
                                                    snprintf(tmp1,0x100,"RO_Relay_En : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.RO_Relay_En);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"CO_Relay_En");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out CO_Relay_En in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out CO_Relay_En in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Asic_Register.CO_Relay_En =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : CO_Relay_En : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Asic_Register.CO_Relay_En);
                                                    snprintf(tmp1,0x100,"CO_Relay_En : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.CO_Relay_En);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar6,
                                                  "Diode_Vdd_Mux_Sel");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Diode_Vdd_Mux_Sel in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Diode_Vdd_Mux_Sel in %s"
                                                           ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar6);
                                                    (pLVar2->Test_Info).Asic_Register.
                                                    Diode_Vdd_Mux_Sel = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Diode_Vdd_Mux_Sel : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Asic_Register.Diode_Vdd_Mux_Sel);
                                                    snprintf(tmp1,0x100,"Diode_Vdd_Mux_Sel : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Asic_Register.Diode_Vdd_Mux_Sel);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar4,"Temperature");
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_OBJECT)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Temperature in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Temperature in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Start_Temp_Gap_Pic");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Start_Temp_Gap_Pic in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Start_Temp_Gap_Pic in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Temperature.
                                                    Start_Temp_Gap_Pic = (int32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Start_Temp_Gap_Pic : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Temperature.Start_Temp_Gap_Pic);
                                                    snprintf(tmp1,0x100,"Start_Temp_Gap_Pic : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Temperature.Start_Temp_Gap_Pic);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Max_Wait_Cooling_Down_Time");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Max_Wait_Cooling_Down_Time in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Max_Wait_Cooling_Down_Time in %s"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Temperature.
                                                    Max_Wait_Cooling_Down_Time = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Max_Wait_Cooling_Down_Time : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Temperature.Max_Wait_Cooling_Down_Time);
                                                    snprintf(tmp1,0x100,
                                                             "Max_Wait_Cooling_Down_Time : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Temperature.Max_Wait_Cooling_Down_Time)
                                                    ;
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Time_For_Cooling_Hashboard");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar7 == (json_t *)0x0) ||
                                                     (pjVar7->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Time_For_Cooling_Hashboard in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Time_For_Cooling_Hashboard in %s"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Temperature.
                                                    Time_For_Cooling_Hashboard = (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Time_For_Cooling_Hashboard : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Temperature.Time_For_Cooling_Hashboard);
                                                    snprintf(tmp1,0x100,
                                                             "Time_For_Cooling_Hashboard : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Temperature.Time_For_Cooling_Hashboard)
                                                    ;
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Max_Board_Temp"
                                                                            );
                                                    if (pjVar7 == (json_t *)0x0) {
                                                      (Local_Config_Information->Test_Info).
                                                      Temperature.Max_Board_Temp = 0x46;
                                                    }
                                                    else {
                                                      pjVar6 = json_object_get(pjVar6,
                                                  "Max_Board_Temp");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Max_Board_Temp in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Max_Board_Temp in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  goto LAB_00021460;
                                                  }
                                                  jVar11 = json_integer_value(pjVar6);
                                                  (pLVar2->Test_Info).Temperature.Max_Board_Temp =
                                                       (int32_t)jVar11;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Max_Board_Temp : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).
                                                         Temperature.Max_Board_Temp);
                                                  snprintf(tmp1,0x100,"Max_Board_Temp : %d",
                                                           (Local_Config_Information->Test_Info).
                                                           Temperature.Max_Board_Temp);
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,"Fan");
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_OBJECT)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Can\'t read out Fan in %s\n",
                                                           "parse_local_config_file",
                                                           config_file_path);
                                                    snprintf(tmp1,0x100,"Can\'t read out Fan in %s",
                                                             config_file_path);
                                                    log_to_file(tmp1,time_stamp);
                                                    ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,"Fan_Speed");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Fan_Speed in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Fan_Speed in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Fan.Fan_Speed =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Fan_Speed : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).Fan
                                                           .Fan_Speed);
                                                    snprintf(tmp1,0x100,"Fan_Speed : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Fan.Fan_Speed);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar7 = json_object_get(pjVar6,"Fan_Limit");
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Fan_Limit in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Fan_Limit in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar7);
                                                    (pLVar2->Test_Info).Fan.Fan_Limit =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Fan_Limit : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).Fan
                                                           .Fan_Limit);
                                                    snprintf(tmp1,0x100,"Fan_Limit : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Fan.Fan_Limit);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar6,"Work_Fan_Speed"
                                                                            );
                                                    pLVar2 = Local_Config_Information;
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_INTEGER)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Work_Fan_Speed in %s,will set default value\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Work_Fan_Speed in %s,will set default value"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  (Local_Config_Information->Test_Info).Fan.
                                                  Work_Fan_Speed = 100;
                                                  print_time_stamp(time_stamp,0x30);
                                                  printf("%s ",time_stamp);
                                                  printf("%s : Work_Fan_Speed : %d\n",
                                                         "parse_local_config_file",
                                                         (Local_Config_Information->Test_Info).Fan.
                                                         Work_Fan_Speed);
                                                  snprintf(tmp1,0x100,"Work_Fan_Speed : %d",
                                                           (Local_Config_Information->Test_Info).Fan
                                                           .Work_Fan_Speed);
                                                  log_to_file(tmp1,time_stamp);
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar6);
                                                    (pLVar2->Test_Info).Fan.Work_Fan_Speed =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Work_Fan_Speed : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).Fan
                                                           .Work_Fan_Speed);
                                                    snprintf(tmp1,0x100,"Work_Fan_Speed : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Fan.Work_Fan_Speed);
                                                    log_to_file(tmp1,time_stamp);
                                                  }
                                                  pjVar6 = json_object_get(pjVar4,"Display");
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_OBJECT)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Can\'t read out Display in %s\n",
                                                           "parse_local_config_file",
                                                           config_file_path);
                                                    snprintf(tmp1,0x100,
                                                             "Can\'t read out Display in %s",
                                                             config_file_path);
                                                    log_to_file(tmp1,time_stamp);
                                                    ret = false;
                                                  }
                                                  else {
                                                    pjVar7 = json_object_get(pjVar6,
                                                  "Display_result_Voltage_Domain");
                                                  if (((pjVar7 == (json_t *)0x0) ||
                                                      (pjVar7->type != JSON_TRUE)) &&
                                                     ((pjVar7 == (json_t *)0x0 ||
                                                      (pjVar7->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Display_result_Voltage_Domain in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Display_result_Voltage_Domain in %s"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar7 == (json_t *)0x0) ||
                                                       (pjVar7->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).Display.
                                                    Display_result_Voltage_Domain = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Display.Display_result_Voltage_Domain ==
                                                        false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf(
                                                  "%s : Display_result_Voltage_Domain : %s\n",
                                                  "parse_local_config_file",pcVar5);
                                                  if ((Local_Config_Information->Test_Info).Display.
                                                      Display_result_Voltage_Domain == false) {
                                                    pcVar5 = "false";
                                                  }
                                                  else {
                                                    pcVar5 = "true";
                                                  }
                                                  snprintf(tmp1,0x100,
                                                           "Display_result_Voltage_Domain : %s",
                                                           pcVar5);
                                                  log_to_file(tmp1,time_stamp);
                                                  pjVar6 = json_object_get(pjVar6,
                                                  "Display_result_Every_Core");
                                                  if (((pjVar6 == (json_t *)0x0) ||
                                                      (pjVar6->type != JSON_TRUE)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Display_result_Every_Core in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Display_result_Every_Core in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Test_Info).Display.
                                                    Display_result_Every_Core = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Display.Display_result_Every_Core == false)
                                                    {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Display_result_Every_Core : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Test_Info).
                                                        Display.Display_result_Every_Core == false)
                                                    {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,
                                                             "Display_result_Every_Core : %s",pcVar5
                                                            );
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar4,
                                                  "Test_Config_Data_Version");
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_STRING)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Test_Config_Data_Version in %s\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Test_Config_Data_Version in %s",
                                                  config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pTVar1 = &Local_Config_Information->Test_Info;
                                                    pcVar5 = json_string_value(pjVar6);
                                                    strcpy(pTVar1->Test_Config_Data_Version,pcVar5);
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Test_Config_Data_Version : %s\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Test_Config_Data_Version);
                                                    snprintf(tmp1,0x100,
                                                             "Test_Config_Data_Version : %s",
                                                             (Local_Config_Information->Test_Info).
                                                             Test_Config_Data_Version);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar4 = json_object_get(pjVar4,
                                                  "Voltage_Accuracy");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar4 == (json_t *)0x0) ||
                                                     (pjVar4->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Voltage_Accuracy in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Voltage_Accuracy in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar4);
                                                    (pLVar2->Test_Info).Voltage_Accuracy =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Voltage_Accuracy : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Test_Info).
                                                           Voltage_Accuracy);
                                                    snprintf(tmp1,0x100,"Voltage_Accuracy : %d",
                                                             (Local_Config_Information->Test_Info).
                                                             Voltage_Accuracy);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar4 = json_object_get(json,"Repair_Mode");
                                                    if ((pjVar4 == (json_t *)0x0) ||
                                                       (pjVar4->type != JSON_OBJECT)) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Repair_Mode in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Repair_Mode in %s",
                                                           config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    pjVar6 = json_object_get(pjVar4,
                                                  "Close_Power_Delay");
                                                  pLVar2 = Local_Config_Information;
                                                  if ((pjVar6 == (json_t *)0x0) ||
                                                     (pjVar6->type != JSON_INTEGER)) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Close_Power_Delay in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Close_Power_Delay in %s"
                                                           ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    jVar11 = json_integer_value(pjVar6);
                                                    (pLVar2->Repair_Mode).Close_Power_Delay =
                                                         (uint32_t)jVar11;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf("%s : Close_Power_Delay : %d\n",
                                                           "parse_local_config_file",
                                                           (Local_Config_Information->Repair_Mode).
                                                           Close_Power_Delay);
                                                    snprintf(tmp1,0x100,"Close_Power_Delay : %d",
                                                             (Local_Config_Information->Repair_Mode)
                                                             .Close_Power_Delay);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar6 = json_object_get(pjVar4,
                                                  "Clear_EEPROM_Data");
                                                  if (((pjVar6 == (json_t *)0x0) ||
                                                      (pjVar6->type != JSON_TRUE)) &&
                                                     ((pjVar6 == (json_t *)0x0 ||
                                                      (pjVar6->type != JSON_FALSE)))) {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : Can\'t read out Clear_EEPROM_Data in %s\n",
                                                  "parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                           "Can\'t read out Clear_EEPROM_Data in %s"
                                                           ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  else {
                                                    if ((pjVar6 == (json_t *)0x0) ||
                                                       (pjVar6->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Repair_Mode).
                                                    Clear_EEPROM_Data = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Repair_Mode).
                                                        Clear_EEPROM_Data == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Clear_EEPROM_Data : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Repair_Mode).
                                                        Clear_EEPROM_Data == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Clear_EEPROM_Data : %s",
                                                             pcVar5);
                                                    log_to_file(tmp1,time_stamp);
                                                    pjVar4 = json_object_get(pjVar4,"Enable_Repair")
                                                    ;
                                                    if (((pjVar4 == (json_t *)0x0) ||
                                                        (pjVar4->type != JSON_TRUE)) &&
                                                       ((pjVar4 == (json_t *)0x0 ||
                                                        (pjVar4->type != JSON_FALSE)))) {
                                                      print_time_stamp(time_stamp,0x30);
                                                      printf("%s ",time_stamp);
                                                      printf(
                                                  "%s : Can\'t read out Enable_Repair in %s,will set default value\n"
                                                  ,"parse_local_config_file",config_file_path);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "Can\'t read out Enable_Repair in %s,will set default value"
                                                  ,config_file_path);
                                                  log_to_file(tmp1,time_stamp);
                                                  (Local_Config_Information->Repair_Mode).
                                                  Enable_Repair = false;
                                                  }
                                                  else {
                                                    if ((pjVar4 == (json_t *)0x0) ||
                                                       (pjVar4->type != JSON_TRUE)) {
                                                      _Var3 = false;
                                                    }
                                                    else {
                                                      _Var3 = true;
                                                    }
                                                    (Local_Config_Information->Repair_Mode).
                                                    Enable_Repair = _Var3;
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    if ((Local_Config_Information->Repair_Mode).
                                                        Enable_Repair == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    printf("%s : Enable_Repair : %s\n",
                                                           "parse_local_config_file",pcVar5);
                                                    if ((Local_Config_Information->Repair_Mode).
                                                        Enable_Repair == false) {
                                                      pcVar5 = "false";
                                                    }
                                                    else {
                                                      pcVar5 = "true";
                                                    }
                                                    snprintf(tmp1,0x100,"Enable_Repair : %s",pcVar5)
                                                    ;
                                                    log_to_file(tmp1,time_stamp);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    print_time_stamp(time_stamp,0x30);
                                                    printf("%s ",time_stamp);
                                                    printf(
                                                  "%s : There are %d test loop in local config file, but LOCAL_CONFIG_MAX_TEST_LOOP_NUM is %d\n"
                                                  ,"parse_local_config_file",gTest_loop,0x32);
                                                  snprintf(tmp1,0x100,
                                                                                                                      
                                                  "There are %d test loop in local config file, but LOCAL_CONFIG_MAX_TEST_LOOP_NUM is %d"
                                                  ,gTest_loop,0x32);
                                                  log_to_file(tmp1,time_stamp);
                                                  ret = false;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                            else {
                                              print_time_stamp(time_stamp,0x30);
                                              printf("%s ",time_stamp);
                                              printf(
                                                  "%s : There are %d power version in local config file, but LOCAL_CONFIG_MAX_SUPPORT_POWER_TYPE is %d\n"
                                                  ,"parse_local_config_file",
                                                  gPower_version_array_size,0x10);
                                              snprintf(tmp1,0x100,
                                                                                                              
                                                  "There are %d power version in local config file, but LOCAL_CONFIG_MAX_SUPPORT_POWER_TYPE is %d"
                                                  ,gPower_version_array_size,0x10);
                                              log_to_file(tmp1,time_stamp);
                                              ret = false;
                                            }
                                          }
                                        }
                                        else {
                                          print_time_stamp(time_stamp,0x30);
                                          printf("%s ",time_stamp);
                                          printf("%s : There are %d ctrlboard sensors in local config file, but LOCAL_CONFIG_MAX_CTRLBOARD_SENSOR_NUM is %d\n"
                                                 ,"parse_local_config_file",gCtrlBoard_sensor_num,2)
                                          ;
                                          snprintf(tmp1,0x100,
                                                                                                      
                                                  "There are %d ctrlboard sensors in local config file, but LOCAL_CONFIG_MAX_CTRLBOARD_SENSOR_NUM is %d"
                                                  ,gCtrlBoard_sensor_num,2);
                                          log_to_file(tmp1,time_stamp);
                                          ret = false;
                                        }
                                      }
                                    }
                                  }
                                }
                                else {
                                  print_time_stamp(time_stamp,0x30);
                                  printf("%s ",time_stamp);
                                  printf("%s : There are %d pic sensors in local config file, but LOCAL_CONFIG_MAX_PIC_SENSOR_NUM is %d\n"
                                         ,"parse_local_config_file",gPic_sensor_num,4);
                                  snprintf(tmp1,0x100,
                                           "There are %d pic sensors in local config file, but LOCAL_CONFIG_MAX_PIC_SENSOR_NUM is %d"
                                           ,gPic_sensor_num,4);
                                  log_to_file(tmp1,time_stamp);
                                  ret = false;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00021460:
  if (json != (json_t *)0x0) {
    json_decref(json);
  }
  return ret;
}

