
_Bool Check_EEPROM(uint32_t EEPROM_length)

{
  int32_t iVar1;
  _Bool _Var2;
  uint8_t auStack_ea0 [512];
  byte abStack_ca0 [512];
  byte abStack_aa0 [496];
  undefined1 auStack_8b0 [16];
  undefined4 local_8a0;
  undefined4 local_89c;
  undefined4 local_898;
  undefined4 local_894;
  undefined4 local_890;
  undefined4 local_88c;
  undefined1 *local_888;
  uint32_t EEPROM_length_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t marker;
  uint8_t_0_ *backup_buf;
  uint8_t_0_ *read_buf;
  uint8_t_0_ *write_buf;
  int32_t ret;
  uint32_t buf_length;
  uint32_t i;
  
  local_888 = auStack_8b0;
  local_88c = 0;
  local_890 = 0x1000;
  local_894 = 0;
  local_898 = 0x1000;
  local_89c = 0;
  local_8a0 = 0x1000;
  gHistory_Result[gPattern_test_counter].eeprom_ok = false;
  EEPROM_length_local = EEPROM_length;
  iVar1 = eeprom_open(gChain);
  if (iVar1 < 0) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(2,"EEPROM init fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM init fail!!!\n","Check_EEPROM");
    builtin_strncpy(tmp1,"EEPROM init fail!!!",0x14);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  else {
    for (i = 0; i < EEPROM_length_local; i = i + 1) {
      abStack_aa0[i] = (byte)i;
      abStack_ca0[i] = 0xff;
    }
    if ((Local_Config_Information->Repair_Mode).Clear_EEPROM_Data == false) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Check EEPROM without clear data\n","Check_EEPROM");
      builtin_strncpy(tmp1,"Check EEPROM without clear data",0x20);
      log_to_file(tmp1,time_stamp);
      iVar1 = eeprom_read(gChain,'\0',auStack_ea0,EEPROM_length_local);
      if (iVar1 == 0) {
        iVar1 = eeprom_write(gChain,'\0',abStack_aa0,EEPROM_length_local);
        if (iVar1 == 0) {
          iVar1 = eeprom_read(gChain,'\0',abStack_ca0,EEPROM_length_local);
          if (iVar1 == 0) {
            for (i = 0; i < EEPROM_length_local; i = i + 1) {
              if (abStack_aa0[i] != abStack_ca0[i]) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: EEPROM check fail! write_buf[%d] = 0x%02x, read_buf[%d] = 0x%02x\n",
                       "Check_EEPROM",i,(uint)abStack_aa0[i]);
                snprintf(tmp1,0x800,
                         "EEPROM check fail! write_buf[%d] = 0x%02x, read_buf[%d] = 0x%02x",i);
                log_to_file(tmp1,time_stamp);
                return false;
              }
            }
            iVar1 = eeprom_write(gChain,'\0',auStack_ea0,EEPROM_length_local);
            if (iVar1 == 0) {
              gHistory_Result[gPattern_test_counter].eeprom_ok = true;
              _Var2 = true;
            }
            else {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: Backup write EEPROM fail\n","Check_EEPROM");
              builtin_strncpy(tmp1,"Backup write EEPROM fail",0x18);
              tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
              _Var2 = false;
            }
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Read EEPROM fail\n","Check_EEPROM");
            builtin_strncpy(tmp1,"Read EEPROM fail",0x10);
            tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
            log_to_file(tmp1,time_stamp);
            _Var2 = false;
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Write EEPROM fail\n","Check_EEPROM");
          builtin_strncpy(tmp1,"Write EEPROM fai",0x10);
          tmp1[0x10] = 'l';
          tmp1[0x11] = '\0';
          log_to_file(tmp1,time_stamp);
          _Var2 = false;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Read EEPROM fail\n","Check_EEPROM");
        builtin_strncpy(tmp1,"Read EEPROM fail",0x10);
        tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        _Var2 = false;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Check EEPROM with clear data\n","Check_EEPROM");
      builtin_strncpy(tmp1,"Check EEPROM with clear data",0x1c);
      tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      iVar1 = eeprom_write(gChain,'\0',abStack_aa0,EEPROM_length_local);
      if (iVar1 == 0) {
        iVar1 = eeprom_read(gChain,'\0',abStack_ca0,EEPROM_length_local);
        if (iVar1 == 0) {
          for (i = 0; i < EEPROM_length_local; i = i + 1) {
            if (abStack_aa0[i] != abStack_ca0[i]) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: EEPROM check fail! write_buf[%d] = 0x%02x, read_buf[%d] = 0x%02x\n",
                     "Check_EEPROM",i,(uint)abStack_aa0[i]);
              snprintf(tmp1,0x800,"EEPROM check fail! write_buf[%d] = 0x%02x, read_buf[%d] = 0x%02x"
                       ,i);
              log_to_file(tmp1,time_stamp);
              return false;
            }
          }
          for (i = 0; i < EEPROM_length_local; i = i + 1) {
            abStack_aa0[i] = 0xff;
          }
          iVar1 = eeprom_write(gChain,'\0',abStack_aa0,EEPROM_length_local);
          if (iVar1 == 0) {
            gHistory_Result[gPattern_test_counter].eeprom_ok = true;
            _Var2 = true;
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Write EEPROM fail\n","Check_EEPROM");
            builtin_strncpy(tmp1,"Write EEPROM fai",0x10);
            tmp1[0x10] = 'l';
            tmp1[0x11] = '\0';
            log_to_file(tmp1,time_stamp);
            _Var2 = false;
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Read EEPROM fail\n","Check_EEPROM");
          builtin_strncpy(tmp1,"Read EEPROM fail",0x10);
          tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          _Var2 = false;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Write EEPROM fail\n","Check_EEPROM");
        builtin_strncpy(tmp1,"Write EEPROM fai",0x10);
        tmp1[0x10] = 'l';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
        _Var2 = false;
      }
    }
  }
  return _Var2;
}

