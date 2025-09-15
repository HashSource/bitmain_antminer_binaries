
ushort crc_itu_t_byte(ushort param_1,byte param_2)

{
  return *(ushort *)(&crc_itu_t_table + ((uint)param_2 ^ (uint)(param_1 >> 8)) * 2) ^ param_1 << 8;
}

