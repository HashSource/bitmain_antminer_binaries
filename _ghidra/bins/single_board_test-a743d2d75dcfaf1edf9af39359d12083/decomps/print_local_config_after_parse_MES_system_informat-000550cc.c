
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_local_config_after_parse_MES_system_information(void)

{
  char *pcVar1;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t index;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","print_local_config_after_parse_MES_system_information");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Test_Process : %s\n","print_local_config_after_parse_MES_system_information",
         Local_Config_Information);
  snprintf(tmp1,0x800,"Test_Process : %s",Local_Config_Information);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Miner_Type : %s\n","print_local_config_after_parse_MES_system_information",
         &Local_Config_Information->Hash_Board);
  snprintf(tmp1,0x800,"Miner_Type : %s",&Local_Config_Information->Hash_Board);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Board_Name : %s\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Hash_Board).Board_Name);
  snprintf(tmp1,0x800,"Board_Name : %s",(Local_Config_Information->Hash_Board).Board_Name);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Asic_Type : %s\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Hash_Board).Asic_Type);
  snprintf(tmp1,0x800,"Asic_Type : %s",(Local_Config_Information->Hash_Board).Asic_Type);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Asic_Num : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Hash_Board).Asic_Num);
  snprintf(tmp1,0x800,"Asic_Num : %d",(Local_Config_Information->Hash_Board).Asic_Num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Voltage_Domain : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Hash_Board).Voltage_Domain);
  snprintf(tmp1,0x800,"Voltage_Domain : %d",(Local_Config_Information->Hash_Board).Voltage_Domain);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Asic_Num_Per_Voltage_Domain : %d\n",
         "print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
  snprintf(tmp1,0x800,"Asic_Num_Per_Voltage_Domain : %d",
           (Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Read_Temperature_From_Pic : %s\n",
         "print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Read_Temperature_From_Pic : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Read_Temperature_From_Asic : %s\n",
         "print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Read_Temperature_From_Asic : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Read_Temperature_From_CtrlBoard : %s\n",
         "print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Read_Temperature_From_CtrlBoard : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Read_Temperature_From_Switch : %s\n",
         "print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Read_Temperature_From_Switch : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Pic_Sensor_Model : %s\n","print_local_config_after_parse_MES_system_information",
         &(Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor);
  snprintf(tmp1,0x800,"Pic_Sensor_Model : %s",
           &(Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: gPic_sensor_num : %d\n","print_local_config_after_parse_MES_system_information",
         gPic_sensor_num);
  snprintf(tmp1,0x800,"gPic_sensor_num : %d",gPic_sensor_num);
  log_to_file(tmp1,time_stamp);
  for (index = 0; index < gPic_sensor_num; index = index + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: gPic_sensor_low_3_bits_addr[%d] : %d\n",
           "print_local_config_after_parse_MES_system_information",index,
           (uint)gPic_sensor_low_3_bits_addr[index]);
    snprintf(tmp1,0x800,"gPic_sensor_low_3_bits_addr[%d] : %d",index,
             (uint)gPic_sensor_low_3_bits_addr[index]);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Asic_Sensor_Model : %s\n","print_local_config_after_parse_MES_system_information",
         &(Local_Config_Information->Hash_Board).Sensor_Info.Asic_Sensor);
  snprintf(tmp1,0x800,"Asic_Sensor_Model : %s",
           &(Local_Config_Information->Hash_Board).Sensor_Info.Asic_Sensor);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: gAsic_sensor_num : %d\n","print_local_config_after_parse_MES_system_information",
         gAsic_sensor_num);
  snprintf(tmp1,0x800,"gAsic_sensor_num : %d",gAsic_sensor_num);
  log_to_file(tmp1,time_stamp);
  for (index = 0; index < gAsic_sensor_num; index = index + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: gAsic_sensor_addr[%d] : %d\n",
           "print_local_config_after_parse_MES_system_information",index,
           (uint)gAsic_sensor_addr[index]);
    snprintf(tmp1,0x800,"gAsic_sensor_addr[%d] : %d",index,(uint)gAsic_sensor_addr[index]);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: CtrlBoard_Sensor_Model : %s\n","print_local_config_after_parse_MES_system_information"
         ,&(Local_Config_Information->Hash_Board).Sensor_Info.CtrlBoard_Sensor);
  snprintf(tmp1,0x800,"CtrlBoard_Sensor_Model : %s",
           &(Local_Config_Information->Hash_Board).Sensor_Info.CtrlBoard_Sensor);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: gCtrlBoard_sensor_num : %d\n","print_local_config_after_parse_MES_system_information",
         gCtrlBoard_sensor_num);
  snprintf(tmp1,0x800,"gCtrlBoard_sensor_num : %d",gCtrlBoard_sensor_num);
  log_to_file(tmp1,time_stamp);
  for (index = 0; index < gCtrlBoard_sensor_num; index = index + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: gCtrlBoard_sensor_low_3_bits_addr[%d] : %d\n",
           "print_local_config_after_parse_MES_system_information",index,
           (uint)gCtrlBoard_sensor_low_3_bits_addr[index]);
    snprintf(tmp1,0x800,"gCtrlBoard_sensor_low_3_bits_addr[%d] : %d",index,
             (uint)gCtrlBoard_sensor_low_3_bits_addr[index]);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Factory_Mode == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Factory_Mode : %s\n","print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Test_Info).Factory_Mode == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Factory_Mode : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Bypass_Scan_Code_Gun : %s\n","print_local_config_after_parse_MES_system_information",
         pcVar1);
  if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Bypass_Scan_Code_Gun : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Software_Pattern : %s\n","print_local_config_after_parse_MES_system_information",
         pcVar1);
  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Software_Pattern : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Super_Software_Pattern : %s\n","print_local_config_after_parse_MES_system_information"
         ,pcVar1);
  if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Super_Software_Pattern : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Hardware_Pattern : %s\n","print_local_config_after_parse_MES_system_information",
         pcVar1);
  if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Hardware_Pattern : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Autogen_Pattern : %s\n","print_local_config_after_parse_MES_system_information",pcVar1
        );
  if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Autogen_Pattern : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Midstate_Number : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
  snprintf(tmp1,0x800,"Midstate_Number : %d",
           (Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Pattern_Number : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
  snprintf(tmp1,0x800,"Pattern_Number : %d",
           (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Invalid_Core_Number : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number);
  snprintf(tmp1,0x800,"Invalid_Core_Number : %d",
           (Local_Config_Information->Test_Info).Test_Standard.Invalid_Core_Number);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Least_Nonce_Per_Core : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core);
  snprintf(tmp1,0x800,"Least_Nonce_Per_Core : %d",
           (Local_Config_Information->Test_Info).Test_Standard.Least_Nonce_Per_Core);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Asic_Nonce_Rate : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.Asic_Nonce_Rate);
  snprintf(tmp1,0x800,"Asic_Nonce_Rate : %d",
           (Local_Config_Information->Test_Info).Test_Standard.Asic_Nonce_Rate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Nonce_Rate : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate);
  snprintf(tmp1,0x800,"Nonce_Rate : %d",
           (Local_Config_Information->Test_Info).Test_Standard.Nonce_Rate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Most_HW_Num : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.Most_HW_Num);
  snprintf(tmp1,0x800,"Most_HW_Num : %d",
           (Local_Config_Information->Test_Info).Test_Standard.Most_HW_Num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: leakage_current : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Standard.leakage_current);
  snprintf(tmp1,0x800,"leakage_current : %d",
           (Local_Config_Information->Test_Info).Test_Standard.leakage_current);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: In local config file, gTest_loop : %d\n",
         "print_local_config_after_parse_MES_system_information",gTest_loop);
  snprintf(tmp1,0x800,"In local config file, gTest_loop : %d",gTest_loop);
  log_to_file(tmp1,time_stamp);
  for (index = 0; index < gTest_loop; index = index + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Test_Loop[%d]->Level : %d\n","print_local_config_after_parse_MES_system_information"
           ,index,(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level);
    snprintf(tmp1,0x800,"Test_Loop[%d]->Level : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Test_Loop[%d]->Pre_Open_Core_Voltage : %d\n",
           "print_local_config_after_parse_MES_system_information",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
           Pre_Open_Core_Voltage);
    snprintf(tmp1,0x800,"Test_Loop[%d]->Pre_Open_Core_Voltage : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
             Pre_Open_Core_Voltage);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Test_Loop[%d]->Voltage : %d\n",
           "print_local_config_after_parse_MES_system_information",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Voltage);
    snprintf(tmp1,0x800,"Test_Loop[%d]->Voltage : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Voltage);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Test_Loop[%d]->Frequence : %d\n",
           "print_local_config_after_parse_MES_system_information",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Frequence);
    snprintf(tmp1,0x800,"Test_Loop[%d]->Frequence : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Frequence);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Baudrate : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  snprintf(tmp1,0x800,"Baudrate : %d",(Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Timeout : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Speed.Timeout);
  snprintf(tmp1,0x800,"Timeout : %d",(Local_Config_Information->Test_Info).Test_Speed.Timeout);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: CCdly_Sel : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel);
  snprintf(tmp1,0x800,"CCdly_Sel : %d",(Local_Config_Information->Test_Info).Asic_Register.CCdly_Sel
          );
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Pwth_Sel : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel);
  snprintf(tmp1,0x800,"Pwth_Sel : %d",(Local_Config_Information->Test_Info).Asic_Register.Pwth_Sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Swpf_Mode : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode);
  snprintf(tmp1,0x800,"Swpf_Mode : %d",(Local_Config_Information->Test_Info).Asic_Register.Swpf_Mode
          );
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Pulse_Mode : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode);
  snprintf(tmp1,0x800,"Pulse_Mode : %d",
           (Local_Config_Information->Test_Info).Asic_Register.Pulse_Mode);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Clk_Sel : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
  snprintf(tmp1,0x800,"Clk_Sel : %d",(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: RO_Relay_En : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.RO_Relay_En);
  snprintf(tmp1,0x800,"RO_Relay_En : %d",
           (Local_Config_Information->Test_Info).Asic_Register.RO_Relay_En);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: CO_Relay_En : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.CO_Relay_En);
  snprintf(tmp1,0x800,"CO_Relay_En : %d",
           (Local_Config_Information->Test_Info).Asic_Register.CO_Relay_En);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Diode_Vdd_Mux_Sel : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
  snprintf(tmp1,0x800,"Diode_Vdd_Mux_Sel : %d",
           (Local_Config_Information->Test_Info).Asic_Register.Diode_Vdd_Mux_Sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start_Temp_Gap_Pic : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic);
  snprintf(tmp1,0x800,"Start_Temp_Gap_Pic : %d",
           (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Time_For_Cooling_Hashboard : %d\n",
         "print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  snprintf(tmp1,0x800,"Time_For_Cooling_Hashboard : %d",
           (Local_Config_Information->Test_Info).Temperature.Time_For_Cooling_Hashboard);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Fan_Speed : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Fan.Fan_Speed);
  snprintf(tmp1,0x800,"Fan_Speed : %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Display.Display_result_Voltage_Domain == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Display_result_Voltage_Domain : %s\n",
         "print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Test_Info).Display.Display_result_Voltage_Domain == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Display_result_Voltage_Domain : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Test_Info).Display.Display_result_Every_Core == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Display_result_Every_Core : %s\n",
         "print_local_config_after_parse_MES_system_information",pcVar1);
  if ((Local_Config_Information->Test_Info).Display.Display_result_Every_Core == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Display_result_Every_Core : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Test_Config_Data_Version : %s\n",
         "print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Test_Config_Data_Version);
  snprintf(tmp1,0x800,"Test_Config_Data_Version : %s",
           (Local_Config_Information->Test_Info).Test_Config_Data_Version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Voltage_Accuracy : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Test_Info).Voltage_Accuracy);
  snprintf(tmp1,0x800,"Voltage_Accuracy : %d",(Local_Config_Information->Test_Info).Voltage_Accuracy
          );
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Close_Power_Delay : %d\n","print_local_config_after_parse_MES_system_information",
         (Local_Config_Information->Repair_Mode).Close_Power_Delay);
  snprintf(tmp1,0x800,"Close_Power_Delay : %d",
           (Local_Config_Information->Repair_Mode).Close_Power_Delay);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  if ((Local_Config_Information->Repair_Mode).Clear_EEPROM_Data == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  printf("%s: Clear_EEPROM_Data : %s\n","print_local_config_after_parse_MES_system_information",
         pcVar1);
  if ((Local_Config_Information->Repair_Mode).Clear_EEPROM_Data == false) {
    pcVar1 = "false";
  }
  else {
    pcVar1 = "true";
  }
  snprintf(tmp1,0x800,"Clear_EEPROM_Data : %s",pcVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","print_local_config_after_parse_MES_system_information");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}

