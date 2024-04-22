
/* WARNING: Unknown calling convention */

void _show_mode(void)

{
  memset(displayed_mode,0,0x10);
  if (opt_bitmain_economic_mode == false) {
    displayed_mode[0] = 'H';
  }
  else {
    displayed_mode[0] = 'L';
  }
  return;
}

