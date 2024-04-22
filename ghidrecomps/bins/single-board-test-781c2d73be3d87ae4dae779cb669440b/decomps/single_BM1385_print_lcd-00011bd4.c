
/* WARNING: Unknown calling convention */

void single_BM1385_print_lcd(uchar which_chain,uint result)

{
  char *buf;
  char lcd_display_buf [16];
  
  lcd_display_buf._4_4_ = DAT_00011c44[1];
  lcd_display_buf._8_4_ = DAT_00011c44[2];
  lcd_display_buf._0_4_ = *DAT_00011c44;
  lcd_display_buf._12_4_ = DAT_00011c44[3];
  display_level_result_on_lcd();
  if ((int)(result << 0x1f) < 0) {
    buf = "   Pattern OK   ";
  }
  else {
    buf = "   Pattern NG   ";
  }
  write_lcd_no_memset(2,buf,0x10);
  sprintf(lcd_display_buf + 10,"%d",gHw_Nonce_Num[gChain]);
  write_lcd_no_memset(1,lcd_display_buf,0x10);
  return;
}

