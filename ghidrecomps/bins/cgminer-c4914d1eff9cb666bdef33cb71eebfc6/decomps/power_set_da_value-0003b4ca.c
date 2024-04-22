
void power_set_da_value(uint8_t da_value)

{
  uint8_t da_value_local;
  uint8_t reply [32];
  uint8_t cmd [8];
  uint16_t i;
  uint16_t crc;
  
  cmd._0_4_ = DAT_00087110;
  cmd._4_4_ = DAT_00087114;
  memset(reply,0,0x20);
  crc = 0;
  cmd[4] = da_value;
  for (i = 2; i < 6; i = i + 1) {
    crc = crc + cmd[i];
  }
  cmd._4_3_ = CONCAT12((uint8_t)crc,cmd._4_2_);
  cmd[7] = (uint8_t)(crc >> 8);
  power_send_cmd(cmd,'\b',reply,'\b');
  return;
}

