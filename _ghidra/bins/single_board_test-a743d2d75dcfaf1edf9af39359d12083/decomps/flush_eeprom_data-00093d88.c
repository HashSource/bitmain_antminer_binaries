
int flush_eeprom_data(float *matrix,int chain)

{
  _Bool _Var1;
  int32_t iVar2;
  int iVar3;
  int chain_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp42 [256];
  size_t offset;
  size_t len;
  uint8_t eeprom_data_cmp [256];
  uint8_t eeprom_data [256];
  _Bool temp;
  
  memset(eeprom_data,0,0x100);
  eeprom_data[0] = 0xff;
  memset(eeprom_data_cmp,0,0x100);
  eeprom_data_cmp[0] = 0xff;
  len = 0x100;
  _Var1 = build_eeprom_data_pt2(true,eeprom_data,&len,&offset,&g_rt,matrix);
  if (_Var1) {
    snprintf(tmp42,0x100,"version %d,len=%d, offset=%d",(uint)eeprom_data[0],len,offset);
    puts(tmp42);
    iVar2 = eeprom_write(chain,(uint8_t)offset,eeprom_data,len);
    if (iVar2 == 0) {
      builtin_strncpy(tmp42,"Write EEPROM ok\n",0x10);
      tmp42._16_4_ = tmp42._16_4_ & 0xffffff00;
      puts(tmp42);
    }
    iVar2 = eeprom_read(chain,(uint8_t)offset,eeprom_data_cmp,len);
    if (iVar2 == 0) {
      iVar3 = memcmp(eeprom_data,eeprom_data_cmp,len);
      if (iVar3 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Write EEPROM ok\n\n","flush_eeprom_data");
        builtin_strncpy(tmp42,"Write EEPROM ok\n",0x10);
        tmp42._16_4_ = tmp42._16_4_ & 0xffffff00;
        log_to_file(tmp42,time_stamp);
        iVar3 = 0;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Check EEPROM data fail\n\n","flush_eeprom_data");
        builtin_strncpy(tmp42,"Check EEPROM data fail\n",0x18);
        log_to_file(tmp42,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: maybe: REMOTE_DEBUG_MODE did not write eeprom\n","flush_eeprom_data");
        builtin_strncpy(tmp42,"maybe: REMOTE_DEBUG_MODE did not write eepro",0x2c);
        tmp42[0x2c] = 'm';
        tmp42[0x2d] = '\0';
        log_to_file(tmp42,time_stamp);
        iVar3 = -1;
      }
    }
    else {
      builtin_strncpy(tmp42,"Read EEPROM fail",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      puts(tmp42);
      iVar3 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42,"build eeprom data failed",0x18);
    tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
    puts(tmp42);
    iVar3 = -1;
  }
  return iVar3;
}

