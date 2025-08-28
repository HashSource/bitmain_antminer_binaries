
void power_set_da_value(uint8_t da_value)

{
  uint8_t da_value_local;
  uint8_t reply [32];
  uint8_t cmd [8];
  uint16_t i;
  uint16_t crc;
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x06';
  cmd[3] = 0x83;
  cmd[4] = '\0';
  cmd[5] = '\0';
  cmd[6] = '\0';
  cmd[7] = '\0';
  memset(reply,0,0x20);
  crc = 0;
  cmd[4] = da_value;
  for (i = 2; i < 6; i = i + 1) {
    crc = cmd[i] + crc;
  }
  cmd[6] = (uint8_t)crc;
  cmd[7] = (uint8_t)(crc >> 8);
  power_send_cmd(cmd,'\b',reply,'\b');
  return;
}

