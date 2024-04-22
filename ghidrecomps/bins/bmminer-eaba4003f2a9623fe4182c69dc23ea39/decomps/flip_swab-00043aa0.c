
void flip_swab(void *dest_p,void *src_p,uint length)

{
  uint uVar1;
  uint length_local;
  void *src_p_local;
  void *dest_p_local;
  uint *src;
  uint *dest;
  int i;
  
  for (i = 0; (uint)i < length >> 2; i = i + 1) {
    uVar1 = swab32(*(uint *)((int)src_p + i * 4));
    *(uint *)((int)dest_p + i * 4) = uVar1;
  }
  return;
}

