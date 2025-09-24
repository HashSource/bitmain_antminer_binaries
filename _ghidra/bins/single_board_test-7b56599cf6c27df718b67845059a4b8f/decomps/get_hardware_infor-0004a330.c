
void get_hardware_infor(hashboard_qr_code *qr_code)

{
  int iVar1;
  hashboard_qr_code *qr_code_local;
  char time_stamp [48];
  char tmp1 [256];
  char temp [3];
  
  temp[1] = '\0';
  temp[2] = '\0';
  temp[0] = qr_code->hashboard_ctrl_code[0];
  iVar1 = atoi(temp);
  zhiju_eeprom_data.zhiju_information.pcb_version_v1 = (uint8_t)iVar1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pcb_version_v1 = %d\n","get_hardware_infor",
         (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v1);
  snprintf(tmp1,0x100,"pcb_version_v1 = %d",(uint)zhiju_eeprom_data.zhiju_information.pcb_version_v1
          );
  log_to_file(tmp1,time_stamp);
  temp[0] = qr_code->hashboard_ctrl_code[1];
  temp[1] = qr_code->hashboard_ctrl_code[2];
  iVar1 = atoi(temp);
  zhiju_eeprom_data.zhiju_information.pcb_version_v2 = (uint8_t)iVar1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pcb_version_v2 = %02d\n","get_hardware_infor",
         (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v2);
  snprintf(tmp1,0x100,"pcb_version_v2 = %02d",
           (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v2);
  log_to_file(tmp1,time_stamp);
  temp[0] = qr_code->hashboard_ctrl_code[3];
  temp[1] = '\0';
  iVar1 = atoi(temp);
  zhiju_eeprom_data.zhiju_information.bom_version_v1 = (uint8_t)iVar1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bom_version_v1 = %d\n","get_hardware_infor",
         (uint)zhiju_eeprom_data.zhiju_information.bom_version_v1);
  snprintf(tmp1,0x100,"bom_version_v1 = %d",(uint)zhiju_eeprom_data.zhiju_information.bom_version_v1
          );
  log_to_file(tmp1,time_stamp);
  temp[0] = qr_code->hashboard_ctrl_code[4];
  iVar1 = atoi(temp);
  zhiju_eeprom_data.zhiju_information.bom_version_v2 = (uint8_t)iVar1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bom_version_v2 = %d\n","get_hardware_infor",
         (uint)zhiju_eeprom_data.zhiju_information.bom_version_v2);
  snprintf(tmp1,0x100,"bom_version_v2 = %d",(uint)zhiju_eeprom_data.zhiju_information.bom_version_v2
          );
  log_to_file(tmp1,time_stamp);
  return;
}

