
/* WARNING: Unknown calling convention */

void set_nonce_fifo_interrupt(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e768;
  *(uint *)(*(int *)(DAT_0002e764 + 0x8d4) + 0x1c) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e76c != '\0' || (*DAT_0002e770 != '\0')) || (6 < *DAT_0002e774)))) {
    snprintf(tmp42,0x800,DAT_0002e778,DAT_0002e77c,value);
    _applog(7,tmp42,false);
  }
  get_nonce_fifo_interrupt();
  return;
}

