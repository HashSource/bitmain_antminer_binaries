
void LZ4F_writeLE64(void *dst,U64 value64)

{
  undefined1 local_58;
  undefined1 local_50;
  undefined1 local_48;
  undefined1 local_40;
  U64 value64_local;
  void *dst_local;
  BYTE *dstPtr;
  
  value64_local._0_1_ = (undefined1)value64;
  *(undefined1 *)dst = (undefined1)value64_local;
  *(char *)((int)dst + 1) = (char)(value64 >> 8);
  *(char *)((int)dst + 2) = (char)(value64 >> 0x10);
  *(char *)((int)dst + 3) = (char)(value64 >> 0x18);
  local_40 = (undefined1)(value64 >> 0x20);
  *(undefined1 *)((int)dst + 4) = local_40;
  local_48 = (undefined1)(value64 >> 0x28);
  *(undefined1 *)((int)dst + 5) = local_48;
  local_50 = (undefined1)(value64 >> 0x30);
  *(undefined1 *)((int)dst + 6) = local_50;
  local_58 = (undefined1)(value64 >> 0x38);
  *(undefined1 *)((int)dst + 7) = local_58;
  return;
}

