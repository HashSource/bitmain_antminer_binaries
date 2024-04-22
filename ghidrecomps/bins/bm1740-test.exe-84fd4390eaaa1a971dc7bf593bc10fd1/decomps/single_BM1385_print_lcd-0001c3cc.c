
void single_BM1385_print_lcd(undefined4 param_1,uint param_2)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20 = s__HW_time__ds_0002d514._0_4_;
  uStack_1c = s__HW_time__ds_0002d514._4_4_;
  uStack_18 = s__HW_time__ds_0002d514._8_4_;
  uStack_14 = s__HW_time__ds_0002d514._12_4_;
  display_level_result_on_lcd();
  if ((param_2 & 1) == 0) {
    write_lcd_no_memset(2,"   Pattern NG   ",0x10);
  }
  else {
    write_lcd_no_memset(2,"   Pattern OK   ",0x10);
  }
  sprintf((char *)((int)&uStack_18 + 2),"%d",(&gHw_Nonce_Num)[gChain]);
  write_lcd_no_memset(1,&local_20,0x10);
  return;
}

