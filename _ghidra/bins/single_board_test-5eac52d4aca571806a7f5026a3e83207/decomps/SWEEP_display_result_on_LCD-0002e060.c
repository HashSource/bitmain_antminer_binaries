
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SWEEP_display_result_on_LCD(void)

{
  test_ctx level_info;
  
  level_info.level = 0;
  level_info.pre_open_core_voltage = 0;
  level_info.voltage = 0;
  level_info.freq = 0;
  get_match_level(&level_info);
  if (level_info.level < 0) {
    lcd_common_show("Sweep test","Err",(char *)0x0);
  }
  else {
    lcd_common_show("Repaire mode","Sweep OK",(char *)0x0);
  }
  return;
}

