
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_uart_baud(void)

{
  int iVar1;
  uchar bauddiv;
  char logstr [256];
  
  iVar1 = __aeabi_uidiv(0x196e6a,dev->timeout);
  iVar1 = __aeabi_uidiv(0x2faf08,iVar1 * 0x1b0);
  if (iVar1 - 1U < 0x1b) {
    bauddiv = (uchar)(iVar1 - 1U);
  }
  else {
    bauddiv = '\x1a';
  }
  sprintf(logstr,"set baud=%d\n");
  writeInitLogFile(logstr);
  set_baud(bauddiv,1);
  return;
}

