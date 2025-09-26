
/* WARNING: Unknown calling convention */

int32_t check_read_back_data(uint8_t *send_data,uint8_t *read_back_data,uint32_t read_back_data_len)

{
  short sVar1;
  byte *pbVar2;
  byte *pbVar3;
  char tmp42 [2048];
  
  if (send_data == (uint8_t *)0x0 || (read_back_data_len == 0 || read_back_data == (uint8_t *)0x0))
  {
    return -0x7ffffcff;
  }
  sVar1 = 0;
  if (2 < read_back_data_len - 2) {
    pbVar3 = read_back_data + 1;
    sVar1 = 0;
    do {
      pbVar3 = pbVar3 + 1;
      sVar1 = sVar1 + (ushort)*pbVar3;
    } while (read_back_data + (read_back_data_len - 3) != pbVar3);
  }
  if (CONCAT11((read_back_data + read_back_data_len)[-1],read_back_data[read_back_data_len - 2]) ==
      sVar1) {
    if ((((*send_data == *read_back_data) && (send_data[1] == read_back_data[1])) &&
        (send_data[3] == read_back_data[3])) && (read_back_data_len == read_back_data[2] + 2)) {
      return 0;
    }
    builtin_strncpy(tmp42,"power reply the bad data",0x18);
    tmp42[0x18] = '\n';
    tmp42[0x19] = '\0';
    _applog(0,tmp42,false);
  }
  else {
    snprintf(tmp42,0x800,"power reply the bad crc, crc = 0x%04x, crc_read = 0x%04x\n");
    _applog(0,tmp42,false);
  }
  pbVar3 = read_back_data;
  do {
    pbVar2 = pbVar3 + 1;
    snprintf(tmp42,0x800,"read_back_data[%d] = 0x%02x",(int)pbVar3 - (int)read_back_data,
             (uint)*pbVar3);
    _applog(0,tmp42,false);
    pbVar3 = pbVar2;
  } while (read_back_data + read_back_data_len != pbVar2);
  return -0x7ffffd00;
}

