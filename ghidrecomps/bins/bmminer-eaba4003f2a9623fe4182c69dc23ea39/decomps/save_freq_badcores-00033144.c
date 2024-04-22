
uchar save_freq_badcores(uchar chain,uchar *buf)

{
  uchar *buf_local;
  uchar chain_local;
  
  if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
    if ((uint)chain % 3 != 0) {
      return '\0';
    }
    AT24C02_write_bytes('\0',buf,chain / 3,0x80);
  }
  else {
    if ((chain == '\0') || (3 < chain)) {
      return '\0';
    }
    AT24C02_write_bytes('\0',buf,chain,0x80);
  }
  return 0x80;
}

