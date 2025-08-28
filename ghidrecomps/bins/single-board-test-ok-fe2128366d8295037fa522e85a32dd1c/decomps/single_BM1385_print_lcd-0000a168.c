
void single_BM1385_print_lcd(undefined4 param_1,uint param_2)

{
  char local_20 [20];
  
  builtin_strncpy(local_20,"      HW        ",0x10);
  display_level_result_on_lcd();
  if ((param_2 & 1) == 0) {
    write_lcd_no_memset(2,"   Pattern NG   ",0x10);
  }
  else {
    write_lcd_no_memset(2,"   Pattern OK   ",0x10);
  }
  sprintf(local_20 + 10,"%d",*(undefined4 *)(gHw_Nonce_Num + (uint)gChain * 4));
  write_lcd_no_memset(1,local_20,0x10);
  return;
}

