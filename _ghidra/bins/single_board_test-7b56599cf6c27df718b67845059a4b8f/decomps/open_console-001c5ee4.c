
undefined4 open_console(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char acStack_14 [12];
  
  CRYPTO_THREAD_write_lock(*(undefined4 *)(param_1 + 0x14));
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
  if (iVar1 == -1) {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    if ((((iVar1 == 0x19) || (iVar1 == 0x16)) || (iVar1 - 5U < 2)) ||
       ((iVar1 == 1 || (iVar1 == 0x13)))) {
      is_a_tty = 0;
      return 1;
    }
    BIO_snprintf(acStack_14,9,"%d");
    ERR_put_error(0x28,0x72,0x6c,"crypto/ui/ui_openssl.c",0x1d0);
    ERR_add_error_data(2,"errno=",acStack_14);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

