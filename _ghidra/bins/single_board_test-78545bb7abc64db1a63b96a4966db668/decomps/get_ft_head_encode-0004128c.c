
int get_ft_head_encode(char x)

{
  byte abStack_65 [60];
  char x_local;
  uint8_t FT_CODE [26];
  
  x_local = x;
  FT_CODE[0] = '\0';
  FT_CODE[1] = '\0';
  FT_CODE[2] = '\0';
  FT_CODE[3] = '\0';
  FT_CODE[8] = '\0';
  FT_CODE[9] = '\0';
  FT_CODE[10] = '\0';
  FT_CODE[0xb] = '\0';
  FT_CODE[0xc] = '\0';
  FT_CODE[0xd] = '\0';
  FT_CODE[0xe] = '\0';
  FT_CODE[0xf] = '\0';
  FT_CODE[0x10] = '\0';
  FT_CODE[0x11] = '\0';
  FT_CODE[0x12] = '\0';
  FT_CODE[0x13] = '\0';
  FT_CODE[0x14] = '\0';
  FT_CODE[0x15] = '\0';
  FT_CODE[0x16] = '\0';
  FT_CODE[0x17] = '\0';
  FT_CODE[0x18] = '\0';
  FT_CODE[0x19] = '\0';
  FT_CODE[4] = '\x02';
  FT_CODE[5] = '\x01';
  FT_CODE[6] = '\0';
  FT_CODE[7] = '\0';
  return (uint)abStack_65[(byte)x];
}

