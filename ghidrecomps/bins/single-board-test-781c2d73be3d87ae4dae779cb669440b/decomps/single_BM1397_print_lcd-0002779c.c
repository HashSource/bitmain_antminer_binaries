
/* WARNING: Unknown calling convention */

void single_BM1397_print_lcd(uchar which_chain,uint result)

{
  char *pcVar1;
  char lcd_display_buf [16];
  
  lcd_display_buf._0_4_ = *DAT_0002782c;
  lcd_display_buf._4_4_ = DAT_0002782c[1];
  lcd_display_buf._8_4_ = DAT_0002782c[2];
  lcd_display_buf._12_4_ = DAT_0002782c[3];
  display_level_result_on_lcd();
  sprintf(lcd_display_buf + 10,"%d",gHw_Nonce_Num[gChain]);
  write_lcd_no_memset(1,lcd_display_buf,0x10);
  if ((int)(result << 0x1f) < 0) {
    pcVar1 = "   Pattern OK   ";
  }
  else {
    pcVar1 = "   Pattern NG   ";
  }
  write_lcd_no_memset(2,pcVar1,0x10);
  if ((int)(result << 0x1e) < 0) {
    pcVar1 = "    Sensor OK   ";
  }
  else {
    pcVar1 = "    Sensor NG   ";
  }
  write_lcd_no_memset(3,pcVar1,0x10);
  return;
}

