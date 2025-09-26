
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_sweep_failed(void)

{
  size_t sVar1;
  char time_stamp [48];
  char tmp1 [2048];
  char num [4];
  char lcd_data [16];
  sweep_bad_asic_info_t m_bad_asics;
  int i_1;
  int i;
  int line;
  
  memset(&m_bad_asics,0,0x404);
  get_sweep_bad_asics(&m_bad_asics);
  if (m_bad_asics.bad_asic_num == 0) {
    lcd_common_show("Sweep failed","other err",(char *)0x0);
  }
  else {
    lcd_data[0] = '\0';
    lcd_data[1] = '\0';
    lcd_data[2] = '\0';
    lcd_data[3] = '\0';
    lcd_data[4] = '\0';
    lcd_data[5] = '\0';
    lcd_data[6] = '\0';
    lcd_data[7] = '\0';
    lcd_data[8] = '\0';
    lcd_data[9] = '\0';
    lcd_data[10] = '\0';
    lcd_data[0xb] = '\0';
    lcd_data[0xc] = '\0';
    lcd_data[0xd] = '\0';
    lcd_data[0xe] = '\0';
    lcd_data[0xf] = '\0';
    lcd_clear_result();
    lcd_show(0,"BAD ASIC");
    line = 1;
    for (i = 0; i < m_bad_asics.bad_asic_num; i = i + 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: bad asic list[%d]: %d\n","show_sweep_failed",i,m_bad_asics.bad_asic_ids[i]);
      snprintf(tmp1,0x800,"bad asic list[%d]: %d",i,m_bad_asics.bad_asic_ids[i]);
      log_to_file(tmp1,time_stamp);
    }
    for (i_1 = 0; i_1 < m_bad_asics.bad_asic_num; i_1 = i_1 + 1) {
      snprintf(num,4,"%d",m_bad_asics.bad_asic_ids[i_1] + 1);
      strcat(lcd_data,num);
      sVar1 = strlen(lcd_data);
      (lcd_data + sVar1)[0] = ' ';
      (lcd_data + sVar1)[1] = '\0';
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: line: %d, id: %s\n","show_sweep_failed",line,num);
      snprintf(tmp1,0x800,"line: %d, id: %s",line,num);
      log_to_file(tmp1,time_stamp);
      if (((i_1 == 3) || (i_1 == 7)) || (m_bad_asics.bad_asic_num + -1 == i_1)) {
        lcd_show(line,lcd_data);
        memset(lcd_data,0,0x10);
        line = line + 1;
      }
    }
  }
  return;
}

