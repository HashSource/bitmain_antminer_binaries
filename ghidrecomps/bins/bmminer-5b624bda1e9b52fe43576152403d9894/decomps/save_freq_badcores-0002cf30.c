
/* WARNING: Unknown calling convention */

uchar save_freq_badcores(uchar chain,uchar *buf)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)chain;
  if (*DAT_0002cf78 < 0xe) {
    uVar2 = uVar1 - (uVar1 / 3 + ((uint)((ulonglong)uVar1 * 0xaaaaaaab >> 0x20) & 0xfffffffe));
    if ((uVar2 & 0xff) == 0) {
      AT24C02_write_bytes((uchar)uVar2,buf,(uchar)(uVar1 / 3),0x80);
      return 0x80;
    }
  }
  else if (uVar1 - 1 < 3) {
    AT24C02_write_bytes('\0',buf,chain,0x80);
    return 0x80;
  }
  return '\0';
}

