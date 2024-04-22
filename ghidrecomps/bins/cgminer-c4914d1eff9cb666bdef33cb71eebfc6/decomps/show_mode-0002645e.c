
/* WARNING: Unknown calling convention */

void show_mode(void)

{
  _Bool _Var1;
  
  memset(displayed_mode,0,0x10);
  _Var1 = is_economic_mode();
  if (_Var1) {
    displayed_mode[0] = 'L';
  }
  else {
    displayed_mode[0] = 'H';
  }
  return;
}

