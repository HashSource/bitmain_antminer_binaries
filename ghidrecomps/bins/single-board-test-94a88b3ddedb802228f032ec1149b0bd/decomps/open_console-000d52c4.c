
undefined4 open_console(void)

{
  int iVar1;
  int *piVar2;
  
  CRYPTO_lock(9,0x1f,"ui_openssl.c",0x1de);
  is_a_tty = 1;
  tty_in = fopen("/dev/tty","r");
  if (tty_in == (FILE *)0x0) {
    tty_in = stdin;
  }
  tty_out = fopen("/dev/tty","w");
  if (tty_out == (FILE *)0x0) {
    tty_out = stderr;
  }
  iVar1 = fileno(tty_in);
  iVar1 = tcgetattr(iVar1,(termios *)tty_orig);
  if (iVar1 != -1) {
    return 1;
  }
  piVar2 = __errno_location();
  if ((*piVar2 != 0x19) && (*piVar2 != 0x16)) {
    return 0;
  }
  is_a_tty = 0;
  return 1;
}

