
uint64_t bswap_64(uint64_t in)

{
  uint64_t in_local;
  
  in_local._4_4_ = (uint)(in >> 0x20);
  in_local._0_4_ = (uint)in;
  return CONCAT44((uint)in_local >> 0x18 |
                  (uint)in_local << 0x18 | (int)(in & 0xff000000ff00) << 8 |
                  (uint)in_local >> 8 & 0xff00,
                  in_local._4_4_ << 0x18 |
                  in_local._4_4_ >> 0x18 | in_local._4_4_ >> 8 & 0xff00 |
                  (int)((in & 0xff000000ff00) >> 0x20) << 8);
}

