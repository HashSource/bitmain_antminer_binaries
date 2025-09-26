
_Bool show_sweep_setup_err(int err_code)

{
  int err_code_local;
  
  switch(err_code) {
  case 0:
    return true;
  case 1:
    lcd_common_show("Init fail","No PT2 data",(char *)0x0);
    break;
  case 2:
    lcd_common_show("Init fail","Eeprom err",(char *)0x0);
    break;
  default:
    lcd_common_show("Init fail","Stop test",(char *)0x0);
    break;
  case 5:
  case 6:
    lcd_common_show("Init fail","Hal err",(char *)0x0);
  }
  return false;
}

