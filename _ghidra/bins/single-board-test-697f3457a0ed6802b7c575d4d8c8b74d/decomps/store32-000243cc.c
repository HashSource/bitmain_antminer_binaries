
void store32(void *dst,uint32_t w)

{
  uint32_t w_local;
  void *dst_local;
  uint8_t *p;
  
  *(char *)dst = (char)w;
  *(char *)((int)dst + 1) = (char)(w >> 8);
  *(char *)((int)dst + 2) = (char)(w >> 0x10);
  *(char *)((int)dst + 3) = (char)(w >> 0x18);
  return;
}

