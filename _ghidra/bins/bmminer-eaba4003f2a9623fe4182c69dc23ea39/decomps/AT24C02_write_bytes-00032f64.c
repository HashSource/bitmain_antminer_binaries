
void AT24C02_write_bytes(uchar address,uchar *buf,uchar which_iic,uchar length)

{
  uchar *buf_local;
  uchar length_local;
  uchar which_iic_local;
  uchar address_local;
  uchar i;
  
  if ((uint)address + (uint)length < 0x101) {
    for (i = '\0'; i < length; i = i + '\x01') {
      AT24C02_write_one_byte(address + i,buf[i],which_iic);
    }
  }
  return;
}

