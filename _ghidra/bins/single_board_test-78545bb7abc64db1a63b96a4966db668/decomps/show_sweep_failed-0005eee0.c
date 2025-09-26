
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_sweep_failed(void)

{
  size_t sVar1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  char num_1 [4];
  char lcd_data_1 [16];
  char num [4];
  char lcd_data [16];
  sweep_bad_asic_info_t m_bad_asics;
  int i_2;
  int i_1;
  int line_1;
  int i;
  int count;
  int line;
  
  if (g_need_repair_asic_count == 0) {
    memset(&m_bad_asics,0,0x34);
    get_sweep_bad_asics(&m_bad_asics);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : bad asic list size:%d\n","show_sweep_failed",m_bad_asics.bad_asic_num);
    snprintf(tmp1,0x100,"bad asic list size:%d",m_bad_asics.bad_asic_num);
    log_to_file(tmp1,time_stamp);
    if (m_bad_asics.bad_asic_num == 0) {
      lcd_clear_result();
      lcd_common_show("Sweep Failed","levle match F",(char *)0x0);
    }
    else {
      lcd_data_1[0] = '\0';
      lcd_data_1[1] = '\0';
      lcd_data_1[2] = '\0';
      lcd_data_1[3] = '\0';
      lcd_data_1[4] = '\0';
      lcd_data_1[5] = '\0';
      lcd_data_1[6] = '\0';
      lcd_data_1[7] = '\0';
      lcd_data_1[8] = '\0';
      lcd_data_1[9] = '\0';
      lcd_data_1[10] = '\0';
      lcd_data_1[0xb] = '\0';
      lcd_data_1[0xc] = '\0';
      lcd_data_1[0xd] = '\0';
      lcd_data_1[0xe] = '\0';
      lcd_data_1[0xf] = '\0';
      lcd_clear_result();
      lcd_show(0,"BAD ASIC");
      line_1 = 1;
      for (i_1 = 0; i_1 < m_bad_asics.bad_asic_num; i_1 = i_1 + 1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : bad asic list[%d]:%d\n","show_sweep_failed",i_1,m_bad_asics.bad_asic_ids[i_1]);
        snprintf(tmp1,0x100,"bad asic list[%d]:%d",i_1,m_bad_asics.bad_asic_ids[i_1]);
        log_to_file(tmp1,time_stamp);
      }
      for (i_2 = 0; i_2 < m_bad_asics.bad_asic_num; i_2 = i_2 + 1) {
        snprintf(num_1,4,"%d",m_bad_asics.bad_asic_ids[i_2] + 1);
        strcat(lcd_data_1,num_1);
        sVar1 = strlen(lcd_data_1);
        (lcd_data_1 + sVar1)[0] = ' ';
        (lcd_data_1 + sVar1)[1] = '\0';
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : line:%d,id:%s\n","show_sweep_failed",line_1,num_1);
        snprintf(tmp1,0x100,"line:%d,id:%s",line_1,num_1);
        log_to_file(tmp1,time_stamp);
        if (((i_2 == 3) || (i_2 == 7)) || (m_bad_asics.bad_asic_num + -1 == i_2)) {
          lcd_show(line_1,lcd_data_1);
          memset(lcd_data_1,0,0x10);
          line_1 = line_1 + 1;
        }
        if (0xb < i_2) {
          return;
        }
      }
    }
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
    lcd_show(0,"NEED REPLACE");
    line = 1;
    count = 0;
    for (i = 0; i < (g_rt.config)->asics; i = i + 1) {
      iVar2 = i + 0x1f;
      if (-1 < i) {
        iVar2 = i;
      }
      if ((1 << (i % 0x20 & 0xffU) & g_asic_need_repair_list[iVar2 >> 5]) != 0) {
        snprintf(num,4,"%d",i);
        strcat(lcd_data,num);
        sVar1 = strlen(lcd_data);
        (lcd_data + sVar1)[0] = ' ';
        (lcd_data + sVar1)[1] = '\0';
        if (((count == 3) || (count == 7)) || (count == g_need_repair_asic_count - 1)) {
          lcd_show(line,lcd_data);
          memset(lcd_data,0,0x10);
          line = line + 1;
        }
        if (0xb < count) {
          return;
        }
        count = count + 1;
      }
    }
  }
  return;
}

