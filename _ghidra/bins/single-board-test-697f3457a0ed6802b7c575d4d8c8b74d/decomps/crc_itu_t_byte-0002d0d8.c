
ushort crc_itu_t_byte(ushort crc,uchar data)

{
  uchar data_local;
  ushort crc_local;
  
  return crc_itu_t_table[(uint)data ^ (uint)(crc >> 8)] ^ crc << 8;
}

