
void swap256(void *dest_p,void *src_p)

{
  void *src_p_local;
  void *dest_p_local;
  uint *src;
  uint *dest;
  
  *(undefined4 *)dest_p = *(undefined4 *)((int)src_p + 0x1c);
  *(undefined4 *)((int)dest_p + 4) = *(undefined4 *)((int)src_p + 0x18);
  *(undefined4 *)((int)dest_p + 8) = *(undefined4 *)((int)src_p + 0x14);
  *(undefined4 *)((int)dest_p + 0xc) = *(undefined4 *)((int)src_p + 0x10);
  *(undefined4 *)((int)dest_p + 0x10) = *(undefined4 *)((int)src_p + 0xc);
  *(undefined4 *)((int)dest_p + 0x14) = *(undefined4 *)((int)src_p + 8);
  *(undefined4 *)((int)dest_p + 0x18) = *(undefined4 *)((int)src_p + 4);
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)((int)dest_p + 0x1c) = *src_p;
  return;
}

