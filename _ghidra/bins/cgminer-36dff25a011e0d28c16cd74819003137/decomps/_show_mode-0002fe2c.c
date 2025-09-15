
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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

