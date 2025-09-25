
void gen_midstate_char(char *dst,uint64_t src)

{
  uint64_t src_local;
  char *dst_local;
  char mid_last8 [17];
  
  builtin_strncpy(mid_last8,"0000000000000000",0x10);
  mid_last8[0x10] = '\0';
  src_local._0_4_ = (undefined4)src;
  src_local._4_4_ = (undefined4)(src >> 0x20);
  snprintf(mid_last8,0x11,"%016llx",(undefined4)src_local,(undefined4)src_local,src_local._4_4_);
  memcpy(dst + 0x30,mid_last8,0x10);
  return;
}

