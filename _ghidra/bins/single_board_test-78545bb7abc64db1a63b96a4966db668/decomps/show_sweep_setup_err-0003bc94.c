
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
  case 4:
  case 5:
    lcd_common_show("Init fail","Hal err",(char *)0x0);
    break;
  case 0xc:
    lcd_common_show("ASIC NUM","first err",(char *)0x0);
    break;
  case 0xd:
    lcd_common_show("ASIC NUM","second err",(char *)0x0);
    break;
  case 0xe:
    show_sweep_failed();
    break;
  case 0x12:
    show_sweep_failed();
  }
  return false;
}

