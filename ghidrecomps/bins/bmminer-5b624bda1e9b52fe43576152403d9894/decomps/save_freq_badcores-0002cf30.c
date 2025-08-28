
/* WARNING: Unknown calling convention */

uchar save_freq_badcores(uchar chain,uchar *buf)

{
  if (fpga_version < 0xe) {
    if ((uint)chain % 3 == 0) {
      AT24C02_write_bytes('\0',buf,chain / 3,0x80);
      return 0x80;
    }
  }
  else if (chain - 1 < 3) {
    AT24C02_write_bytes('\0',buf,chain,0x80);
    return 0x80;
  }
  return '\0';
}

