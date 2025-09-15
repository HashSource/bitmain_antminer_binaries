
uint64_t rotr64(uint64_t w,uint c)

{
  uint uVar1;
  uint c_local;
  uint64_t w_local;
  
  w_local._0_4_ = (uint)w;
  w_local._4_4_ = (uint)(w >> 0x20);
  uVar1 = -c & 0x3f;
  return CONCAT44(w_local._4_4_ << uVar1 | (uint)w_local << (uVar1 - 0x20 & 0xff) |
                  (uint)w_local >> (0x20 - uVar1 & 0xff) | w_local._4_4_ >> (c & 0xff),
                  (uint)w_local << uVar1 |
                  (uint)w_local >> (c & 0xff) | w_local._4_4_ << (0x20 - c & 0xff) |
                  w_local._4_4_ >> (c - 0x20 & 0xff));
}

