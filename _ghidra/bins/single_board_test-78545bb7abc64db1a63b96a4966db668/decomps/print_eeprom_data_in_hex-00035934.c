
void print_eeprom_data_in_hex(uint8_t *buf,uint32_t buf_length)

{
  uint32_t buf_length_local;
  uint8_t *buf_local;
  uint8_t i;
  
  for (i = '\0'; i < buf_length; i = i + '\x01') {
    printf("%02x",(uint)buf[i]);
  }
  puts("\n");
  return;
}

