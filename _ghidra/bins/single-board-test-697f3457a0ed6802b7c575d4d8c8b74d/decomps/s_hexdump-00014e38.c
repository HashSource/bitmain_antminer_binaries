
char * s_hexdump(void *_a,uint32_t a_len)

{
  uint32_t a_len_local;
  void *_a_local;
  uint8_t *a;
  uint32_t i;
  
  for (i = 0; (i < a_len && (i + 2 < 0x1000)); i = i + 1) {
    sprintf(s_hexdump::buf + i * 2,"%02x",(uint)*(byte *)(i + (int)_a));
  }
  s_hexdump::buf[i * 2] = '\0';
  return s_hexdump::buf;
}

