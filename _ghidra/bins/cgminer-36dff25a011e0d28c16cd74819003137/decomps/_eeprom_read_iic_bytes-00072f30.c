
int _eeprom_read_iic_bytes(uint8_t chain,int reg_addr_start,int reg_count,uint8_t *buf)

{
  uint8_t uVar1;
  FILE *__stream;
  int iVar2;
  uint8_t *buf_local;
  int reg_count_local;
  int reg_addr_start_local;
  uint8_t chain_local;
  FILE *pFile;
  int i;
  
  if (reg_addr_start + reg_count < 0x101) {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    for (i = 0; i < reg_count; i = i + 1) {
      uVar1 = _eeprom_read_iic(chain,(char)reg_addr_start + (char)i);
      buf[i] = uVar1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    iVar2 = 0;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Over EEPROM size.\n","eeprom.c",0x58,"_eeprom_read_iic_bytes");
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  return iVar2;
}

