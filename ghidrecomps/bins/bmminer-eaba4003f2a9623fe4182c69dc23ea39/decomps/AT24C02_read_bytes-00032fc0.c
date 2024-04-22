
void AT24C02_read_bytes(uchar address,uchar *buf,uchar which_iic,uchar length)

{
  uchar uVar1;
  uchar *buf_local;
  uchar length_local;
  uchar which_iic_local;
  uchar address_local;
  uchar i;
  
  if ((uint)address + (uint)length < 0x101) {
    for (i = '\0'; i < length; i = i + '\x01') {
      uVar1 = AT24C02_read_one_byte(address + i,which_iic);
      buf[i] = uVar1;
    }
  }
  return;
}

