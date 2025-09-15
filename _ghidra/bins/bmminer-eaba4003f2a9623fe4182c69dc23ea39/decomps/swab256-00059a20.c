
void swab256(void *dest_p,void *src_p)

{
  uint uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint *src;
  uint *dest;
  
  uVar1 = swab32(*(uint *)((int)src_p + 0x1c));
  *(uint *)dest_p = uVar1;
  uVar1 = swab32(*(uint *)((int)src_p + 0x18));
  *(uint *)((int)dest_p + 4) = uVar1;
  uVar1 = swab32(*(uint *)((int)src_p + 0x14));
  *(uint *)((int)dest_p + 8) = uVar1;
  uVar1 = swab32(*(uint *)((int)src_p + 0x10));
  *(uint *)((int)dest_p + 0xc) = uVar1;
  uVar1 = swab32(*(uint *)((int)src_p + 0xc));
  *(uint *)((int)dest_p + 0x10) = uVar1;
  uVar1 = swab32(*(uint *)((int)src_p + 8));
  *(uint *)((int)dest_p + 0x14) = uVar1;
  uVar1 = swab32(*(uint *)((int)src_p + 4));
  *(uint *)((int)dest_p + 0x18) = uVar1;
                    /* WARNING: Load size is inaccurate */
  uVar1 = swab32(*src_p);
  *(uint *)((int)dest_p + 0x1c) = uVar1;
  return;
}

