
void flip_swab(void *dest_p,void *src_p,uint length)

{
  uint32_t uVar1;
  uint length_local;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  int i;
  
  for (i = 0; (uint)i < length >> 2; i = i + 1) {
    uVar1 = swab32(*(uint32_t *)(i * 4 + (int)src_p));
    *(uint32_t *)((int)dest_p + i * 4) = uVar1;
  }
  return;
}

