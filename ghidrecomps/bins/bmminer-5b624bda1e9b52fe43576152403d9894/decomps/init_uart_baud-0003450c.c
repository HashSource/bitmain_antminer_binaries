
/* WARNING: Unknown calling convention */

void init_uart_baud(void)

{
  int iVar1;
  uchar bauddiv;
  char logstr [256];
  
  iVar1 = __aeabi_uidiv(0x196e6a,*(undefined4 *)(*DAT_00034560 + 0x48));
  iVar1 = __aeabi_uidiv(0x2faf08,iVar1 * 0x1b0);
  if (iVar1 - 1U < 0x1b) {
    bauddiv = (uchar)(iVar1 - 1U);
  }
  else {
    bauddiv = '\x1a';
  }
  sprintf(logstr,DAT_00034564);
  writeInitLogFile(logstr);
  set_baud(bauddiv,1);
  return;
}

