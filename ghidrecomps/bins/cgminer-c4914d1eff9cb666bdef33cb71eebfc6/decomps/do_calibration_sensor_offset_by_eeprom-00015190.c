
void do_calibration_sensor_offset_by_eeprom
               (uchar device,uchar chip_addr,int chain,int temp_chip_index)

{
  FILE *__stream;
  int temp_chip_index_local;
  int chain_local;
  uchar chip_addr_local;
  uchar device_local;
  FILE *pFile;
  int8_t local;
  int8_t middle;
  
  check_reg_temp(device,9,'\x04','\x01',chip_addr,chain);
  check_reg_temp(device,0x11,middle_Offset[chain][temp_chip_index],'\x01',chip_addr,chain);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,
              "%s:%d:%s: New offset - Chain[%d] Chip[%d] local:%hhd remote:%hhd offset:%hhd \n",
              "temperature.c",0x151,"do_calibration_sensor_offset_by_eeprom",chain,
              (chip_addr >> 2) + 1,0,0,(int)middle_Offset[chain][temp_chip_index]);
    }
    fclose(__stream);
  }
  return;
}

