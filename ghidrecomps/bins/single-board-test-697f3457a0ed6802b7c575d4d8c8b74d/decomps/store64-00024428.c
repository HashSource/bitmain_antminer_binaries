
void store64(void *dst,uint64_t w)

{
  undefined4 in_r2;
  undefined4 in_r3;
  uint64_t w_local;
  void *dst_local;
  uint8_t *p;
  
  w_local._0_1_ = (undefined)in_r2;
  *(undefined *)dst = (undefined)w_local;
  w_local._0_1_ = (undefined)((uint)in_r2 >> 8);
  *(undefined *)((int)dst + 1) = (undefined)w_local;
  w_local._0_1_ = (undefined)((uint)in_r2 >> 0x10);
  *(undefined *)((int)dst + 2) = (undefined)w_local;
  w_local._0_1_ = (undefined)((uint)in_r2 >> 0x18);
  *(undefined *)((int)dst + 3) = (undefined)w_local;
  w_local._0_1_ = (undefined)in_r3;
  *(undefined *)((int)dst + 4) = (undefined)w_local;
  w_local._0_1_ = (undefined)((uint)in_r3 >> 8);
  *(undefined *)((int)dst + 5) = (undefined)w_local;
  w_local._0_1_ = (undefined)((uint)in_r3 >> 0x10);
  *(undefined *)((int)dst + 6) = (undefined)w_local;
  *(char *)((int)dst + 7) = (char)((uint)in_r3 >> 0x18);
  return;
}

