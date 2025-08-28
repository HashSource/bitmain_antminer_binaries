
void store64(void *dst,uint64_t w)

{
  uint64_t w_local;
  void *dst_local;
  uint8_t *p;
  
  w_local._0_1_ = (undefined1)w;
  *(undefined1 *)dst = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 8);
  *(undefined1 *)((int)dst + 1) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x10);
  *(undefined1 *)((int)dst + 2) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x18);
  *(undefined1 *)((int)dst + 3) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x20);
  *(undefined1 *)((int)dst + 4) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x28);
  *(undefined1 *)((int)dst + 5) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x30);
  *(undefined1 *)((int)dst + 6) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x38);
  *(undefined1 *)((int)dst + 7) = (undefined1)w_local;
  return;
}

