
void flip32(void *dest_p,void *src_p)

{
  uint32_t uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  int i;
  
  for (i = 0; i < 8; i = i + 1) {
    uVar1 = swab32(*(uint32_t *)((int)src_p + i * 4));
    *(uint32_t *)((int)dest_p + i * 4) = uVar1;
  }
  return;
}

