
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_eeprom_data(void)

{
  char time_stamp [48];
  char tmp1 [256];
  uint8_t i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : algorithm_and_key_version:             0x%02x\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.algorithm_and_key_version);
  snprintf(tmp1,0x100,"algorithm_and_key_version:             0x%02x",
           (uint)zhiju_eeprom_data.algorithm_and_key_version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : zhiju_information_length:              %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information_length);
  snprintf(tmp1,0x100,"zhiju_information_length:              %d",
           (uint)zhiju_eeprom_data.zhiju_information_length);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : zhiju_information_format_version:      %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.zhiju_information_format_version);
  snprintf(tmp1,0x100,"zhiju_information_format_version:      %d",
           (uint)zhiju_eeprom_data.zhiju_information.zhiju_information_format_version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : hashboard_sn:                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
         "print_eeprom_data",(uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[1],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[2],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[3],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[4],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[5],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[6],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[7],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[8],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[9],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[10],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xb],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xc],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xd],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xe],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xf],
         (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0x10]);
  snprintf(tmp1,0x100,"hashboard_sn:                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[1],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[2],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[3],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[4],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[5],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[6],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[7],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[8],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[9],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[10],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xb],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xc],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xd],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xe],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0xf],
           (uint)zhiju_eeprom_data.zhiju_information.hashboard_sn[0x10]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : chip_die:                              %c%c\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.chip_die[0],
         (uint)zhiju_eeprom_data.zhiju_information.chip_die[1]);
  snprintf(tmp1,0x100,"chip_die:                              %c%c",
           (uint)zhiju_eeprom_data.zhiju_information.chip_die[0],
           (uint)zhiju_eeprom_data.zhiju_information.chip_die[1]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : chip_marking:                          %c%c%c%c%c%c%c%c%c%c%c%c%c\n",
         "print_eeprom_data",(uint)zhiju_eeprom_data.zhiju_information.chip_marking[0],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[1],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[2],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[3],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[4],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[5],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[6],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[7],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[8],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[9],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[10],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[0xb],
         (uint)zhiju_eeprom_data.zhiju_information.chip_marking[0xc]);
  snprintf(tmp1,0x100,"chip_marking:                          %c%c%c%c%c%c%c%c%c%c%c%c%c",
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[0],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[1],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[2],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[3],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[4],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[5],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[6],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[7],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[8],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[9],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[10],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[0xb],
           (uint)zhiju_eeprom_data.zhiju_information.chip_marking[0xc]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : chip_bin:                              %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.chip_bin);
  snprintf(tmp1,0x100,"chip_bin:                              %d",
           (uint)zhiju_eeprom_data.zhiju_information.chip_bin);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : chip_ft_program_version:               %c%c%c%c%c%c%c%c%c\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7],
         (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[8]);
  snprintf(tmp1,0x100,"chip_ft_program_version:               %c%c%c%c%c%c%c%c%c",
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7],
           (uint)zhiju_eeprom_data.zhiju_information.chip_ft_program_version[8]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic_sensor:                           0x%02x\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.asic_sensor);
  snprintf(tmp1,0x100,"asic_sensor:                           0x%02x",
           (uint)zhiju_eeprom_data.zhiju_information.asic_sensor);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic_sensor_addr:                      %d, %d, %d, %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[0],
         (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[1],
         (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[2],
         (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[3]);
  snprintf(tmp1,0x100,"asic_sensor_addr:                      %d, %d, %d, %d",
           (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[0],
           (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[1],
           (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[2],
           (uint)zhiju_eeprom_data.zhiju_information.asic_sensor_addr[3]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pic_sensor:                            0x%02x\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.pic_sensor);
  snprintf(tmp1,0x100,"pic_sensor:                            0x%02x",
           (uint)zhiju_eeprom_data.zhiju_information.pic_sensor);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pic_sensor_addr:                       0x%02x\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.pic_sensor_addr);
  snprintf(tmp1,0x100,"pic_sensor_addr:                       0x%02x",
           (uint)zhiju_eeprom_data.zhiju_information.pic_sensor_addr);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pcb_version_v1:                        %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v1);
  snprintf(tmp1,0x100,"pcb_version_v1:                        %d",
           (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pcb_version_v2:                        %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v2);
  snprintf(tmp1,0x100,"pcb_version_v2:                        %d",
           (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v2);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bom_version_v1:                        %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.bom_version_v1);
  snprintf(tmp1,0x100,"bom_version_v1:                        %d",
           (uint)zhiju_eeprom_data.zhiju_information.bom_version_v1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bom_version_v2:                        %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.bom_version_v2);
  snprintf(tmp1,0x100,"bom_version_v2:                        %d",
           (uint)zhiju_eeprom_data.zhiju_information.bom_version_v2);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : chip_technology:                       %c%c\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.chip_technology[0],
         (uint)zhiju_eeprom_data.zhiju_information.chip_technology[1]);
  snprintf(tmp1,0x100,"chip_technology:                       %c%c",
           (uint)zhiju_eeprom_data.zhiju_information.chip_technology[0],
           (uint)zhiju_eeprom_data.zhiju_information.chip_technology[1]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : voltage:                               %d\n","print_eeprom_data",
         (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.voltage[0],
                        zhiju_eeprom_data.zhiju_information.voltage[1]));
  snprintf(tmp1,0x100,"voltage:                               %d",
           (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.voltage[0],
                          zhiju_eeprom_data.zhiju_information.voltage[1]));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : frequency:                             %d\n","print_eeprom_data",
         (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.frequency[0],
                        zhiju_eeprom_data.zhiju_information.frequency[1]));
  snprintf(tmp1,0x100,"frequency:                             %d",
           (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.frequency[0],
                          zhiju_eeprom_data.zhiju_information.frequency[1]));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : nonce_rate:                            %d\n","print_eeprom_data",
         (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.nonce_rate[0],
                        zhiju_eeprom_data.zhiju_information.nonce_rate[1]));
  snprintf(tmp1,0x100,"nonce_rate:                            %d",
           (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.nonce_rate[0],
                          zhiju_eeprom_data.zhiju_information.nonce_rate[1]));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pcb_temprature_in:                     %d\n","print_eeprom_data",
         (int)zhiju_eeprom_data.zhiju_information.pcb_temprature_in);
  snprintf(tmp1,0x100,"pcb_temprature_in:                     %d",
           (int)zhiju_eeprom_data.zhiju_information.pcb_temprature_in);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pcb_temprature_out:                    %d\n","print_eeprom_data",
         (int)zhiju_eeprom_data.zhiju_information.pcb_temprature_out);
  snprintf(tmp1,0x100,"pcb_temprature_out:                    %d",
           (int)zhiju_eeprom_data.zhiju_information.pcb_temprature_out);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : test_version:                          %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.test_version);
  snprintf(tmp1,0x100,"test_version:                          %d",
           (uint)zhiju_eeprom_data.zhiju_information.test_version);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : test_standard:                         %d\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.test_standard);
  snprintf(tmp1,0x100,"test_standard:                         %d",
           (uint)zhiju_eeprom_data.zhiju_information.test_standard);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : zhiju_information_crc5:                0x%02x\n","print_eeprom_data",
         (uint)zhiju_eeprom_data.zhiju_information.zhiju_information_crc5);
  snprintf(tmp1,0x100,"zhiju_information_crc5:                0x%02x",
           (uint)zhiju_eeprom_data.zhiju_information.zhiju_information_crc5);
  log_to_file(tmp1,time_stamp);
  return;
}

