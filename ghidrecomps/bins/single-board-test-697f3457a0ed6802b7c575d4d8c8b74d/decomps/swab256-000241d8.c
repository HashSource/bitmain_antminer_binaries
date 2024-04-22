
void swab256(void *dest_p,void *src_p)

{
  uint uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  
  uVar1 = *(uint *)((int)src_p + 0x1c);
  *(uint *)dest_p =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 0x18);
  *(uint *)((int)dest_p + 4) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 0x14);
  *(uint *)((int)dest_p + 8) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 0x10);
  *(uint *)((int)dest_p + 0xc) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 0xc);
  *(uint *)((int)dest_p + 0x10) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 8);
  *(uint *)((int)dest_p + 0x14) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 4);
  *(uint *)((int)dest_p + 0x18) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
                    /* WARNING: Load size is inaccurate */
  uVar1 = *src_p;
  *(uint *)((int)dest_p + 0x1c) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  return;
}

