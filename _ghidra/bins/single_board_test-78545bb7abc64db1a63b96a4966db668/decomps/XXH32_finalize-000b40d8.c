
U32 XXH32_finalize(U32 h32,void *ptr,size_t len,XXH_endianess endian,XXH_alignment align)

{
  U32 UVar1;
  uint uVar2;
  XXH_endianess endian_local;
  size_t len_local;
  void *ptr_local;
  U32 h32_local;
  BYTE *p;
  
  h32_local = h32;
  p = (BYTE *)ptr;
  switch(len & 0xf) {
  case 0xc:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(ptr);
      }
      else {
        UVar1 = XXH_read32(ptr);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar1 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *ptr;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32;
    p = (BYTE *)((int)ptr + 4);
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 8:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    p = p + 4;
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 4:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    UVar1 = XXH32_avalanche((uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f);
    break;
  case 0xd:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(ptr);
      }
      else {
        UVar1 = XXH_read32(ptr);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar1 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *ptr;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32;
    p = (BYTE *)((int)ptr + 4);
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 9:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    p = p + 4;
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 5:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    uVar2 = (uint)p[4] * 0x165667b1 + (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
    UVar1 = XXH32_avalanche((uVar2 >> 0x15 | uVar2 * 0x800) * -0x61c8864f);
    break;
  case 0xe:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(ptr);
      }
      else {
        UVar1 = XXH_read32(ptr);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar1 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *ptr;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32;
    p = (BYTE *)((int)ptr + 4);
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 10:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    p = p + 4;
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 6:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    uVar2 = (uint)p[4] * 0x165667b1 + (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
    uVar2 = (uint)p[5] * 0x165667b1 + (uVar2 >> 0x15 | uVar2 * 0x800) * -0x61c8864f;
    UVar1 = XXH32_avalanche((uVar2 >> 0x15 | uVar2 * 0x800) * -0x61c8864f);
    break;
  case 0xf:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(ptr);
      }
      else {
        UVar1 = XXH_read32(ptr);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar1 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *ptr;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32;
    p = (BYTE *)((int)ptr + 4);
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 0xb:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    p = p + 4;
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 7:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar1 = XXH_read32(p);
      }
      else {
        UVar1 = XXH_read32(p);
        UVar1 = UVar1 << 0x18 | (UVar1 >> 8 & 0xff) << 0x10 | (UVar1 >> 0x10 & 0xff) << 8 |
                UVar1 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar1 = *(U32 *)p;
    }
    else {
      uVar2 = *(uint *)p;
      UVar1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
    }
    uVar2 = UVar1 * -0x3d4d51c3 + h32_local;
    p = p + 4;
    h32_local = (uVar2 >> 0xf | uVar2 * 0x20000) * 0x27d4eb2f;
  case 3:
    uVar2 = (uint)*p * 0x165667b1 + h32_local;
    h32_local = (uVar2 >> 0x15 | uVar2 * 0x800) * -0x61c8864f;
    p = p + 1;
  case 2:
    uVar2 = (uint)*p * 0x165667b1 + h32_local;
    h32_local = (uVar2 >> 0x15 | uVar2 * 0x800) * -0x61c8864f;
    p = p + 1;
  case 1:
    uVar2 = (uint)*p * 0x165667b1 + h32_local;
    h32_local = (uVar2 >> 0x15 | uVar2 * 0x800) * -0x61c8864f;
  case 0:
    UVar1 = XXH32_avalanche(h32_local);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    __assert_fail("0","../zhiju/log_file/xxhash.c",0x15a,"XXH32_finalize");
  }
  return UVar1;
}

