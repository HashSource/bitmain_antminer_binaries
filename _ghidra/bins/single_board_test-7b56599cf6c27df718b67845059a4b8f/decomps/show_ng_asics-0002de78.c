
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_ng_asics(void)

{
  uint32_t uVar1;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t id_buf [5];
  char lcd_data [16];
  uint32_t num;
  int i;
  
  memset(lcd_data,0,0x10);
  sprintf(lcd_data,"ASIC: NG %d %d",gAsic_num,gAsic_num1);
  lcd_show(0,lcd_data);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ASIC:   NG\n\n","show_ng_asics");
  builtin_strncpy(tmp1,"ASIC:   NG\n",0xc);
  log_to_file(tmp1,time_stamp);
  uVar1 = find_ng_asic_id(id_buf,5);
  memset(lcd_data,0,0x10);
  for (i = 0; (uint)i < uVar1; i = i + 1) {
    sprintf(lcd_data + i * 3," %02d",id_buf[i]);
  }
  lcd_show(1,lcd_data);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ASIC NG ID:%s\n\n","show_ng_asics",lcd_data);
  snprintf(tmp1,0x100,"ASIC NG ID:%s\n",lcd_data);
  log_to_file(tmp1,time_stamp);
  return;
}

