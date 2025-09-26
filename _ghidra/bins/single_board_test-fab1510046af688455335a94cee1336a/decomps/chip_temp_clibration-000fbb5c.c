
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void chip_temp_clibration(void)

{
  lcd_show(2,"clib chip temp");
  lcd_show(2,"wait 60s");
  sleep(0x3c);
  return;
}

