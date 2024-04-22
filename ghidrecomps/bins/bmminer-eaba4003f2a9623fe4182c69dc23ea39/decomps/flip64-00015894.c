
void flip64(void *dest_p,void *src_p)

{
  uint uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint *src;
  uint *dest;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    uVar1 = swab32(*(uint *)((int)src_p + i * 4));
    *(uint *)((int)dest_p + i * 4) = uVar1;
  }
  return;
}

