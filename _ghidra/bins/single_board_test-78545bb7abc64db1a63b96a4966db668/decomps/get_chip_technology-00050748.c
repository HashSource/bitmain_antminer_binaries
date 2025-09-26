
void get_chip_technology(hashboard_qr_code *qr_code)

{
  hashboard_qr_code *qr_code_local;
  
  zhiju_eeprom_data.zhiju_information.chip_technology[0] = qr_code->hashboard_ctrl_code[5];
  zhiju_eeprom_data.zhiju_information.chip_technology[1] = qr_code->hashboard_ctrl_code[6];
  return;
}

