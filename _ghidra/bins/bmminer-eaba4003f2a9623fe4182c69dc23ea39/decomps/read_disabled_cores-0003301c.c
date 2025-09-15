
uchar read_disabled_cores(uchar chain,uchar *buf)

{
  uchar *buf_local;
  uchar chain_local;
  
  if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
    if ((uint)chain % 3 != 0) {
      return '\0';
    }
    AT24C02_read_bytes(0xa0,buf,chain / 3,'\x10');
  }
  else {
    if ((chain == '\0') || (3 < chain)) {
      return '\0';
    }
    AT24C02_read_bytes(0xa0,buf,chain,'\x10');
  }
  return '\x10';
}

