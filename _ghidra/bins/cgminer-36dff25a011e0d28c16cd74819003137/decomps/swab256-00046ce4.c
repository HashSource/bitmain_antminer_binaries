
void swab256(void *dest_p,void *src_p)

{
  uint32_t uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  
  uVar1 = swab32(*(uint32_t *)((int)src_p + 0x1c));
  *(uint32_t *)dest_p = uVar1;
  uVar1 = swab32(*(uint32_t *)((int)src_p + 0x18));
  *(uint32_t *)((int)dest_p + 4) = uVar1;
  uVar1 = swab32(*(uint32_t *)((int)src_p + 0x14));
  *(uint32_t *)((int)dest_p + 8) = uVar1;
  uVar1 = swab32(*(uint32_t *)((int)src_p + 0x10));
  *(uint32_t *)((int)dest_p + 0xc) = uVar1;
  uVar1 = swab32(*(uint32_t *)((int)src_p + 0xc));
  *(uint32_t *)((int)dest_p + 0x10) = uVar1;
  uVar1 = swab32(*(uint32_t *)((int)src_p + 8));
  *(uint32_t *)((int)dest_p + 0x14) = uVar1;
  uVar1 = swab32(*(uint32_t *)((int)src_p + 4));
  *(uint32_t *)((int)dest_p + 0x18) = uVar1;
                    /* WARNING: Load size is inaccurate */
  uVar1 = swab32(*src_p);
  *(uint32_t *)((int)dest_p + 0x1c) = uVar1;
  return;
}

