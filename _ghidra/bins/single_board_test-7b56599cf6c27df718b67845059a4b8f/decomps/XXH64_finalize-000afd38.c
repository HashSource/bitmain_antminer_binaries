
U64 XXH64_finalize(U64 h64,void *ptr,size_t len,XXH_endianess endian,XXH_alignment align)

{
  longlong lVar1;
  longlong lVar2;
  U32 UVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  U64 UVar9;
  size_t len_local;
  void *ptr_local;
  U64 h64_local;
  U64 k1_23;
  U64 k1_22;
  U64 k1_21;
  U64 k1_20;
  U64 k1_19;
  U64 k1_18;
  U64 k1_17;
  U64 k1_16;
  U64 k1_15;
  U64 k1_14;
  U64 k1_13;
  U64 k1_12;
  U64 k1_11;
  U64 k1_10;
  U64 k1_9;
  U64 k1_8;
  U64 k1_7;
  U64 k1_6;
  U64 k1_5;
  U64 k1_4;
  U64 k1_3;
  U64 k1_2;
  U64 k1_1;
  U64 k1;
  BYTE *p;
  
  h64_local._0_4_ = (uint)h64;
  h64_local._4_4_ = (uint)(h64 >> 0x20);
  UVar9 = h64;
  p = (BYTE *)ptr;
  switch(len & 0x1f) {
  case 0x18:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1._0_4_ = (uint)UVar9;
    k1._4_4_ = (uint)(UVar9 >> 0x20);
    uVar5 = (k1._4_4_ ^ h64_local._4_4_) >> 5 | ((uint)k1 ^ (uint)h64_local) << 0x1b;
    lVar2 = (ulonglong)uVar5 * 0x85ebca87;
    uVar4 = (uint)lVar2;
    h64_local = CONCAT44(uVar5 * -0x61c8864f +
                         (((uint)k1 ^ (uint)h64_local) >> 5 | (k1._4_4_ ^ h64_local._4_4_) << 0x1b)
                         * -0x7a143579 + (int)((ulonglong)lVar2 >> 0x20) +
                         (0x3d4d519c < uVar4) + 0x85ebca77,uVar4 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x10:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_1._0_4_ = (uint)UVar9;
    k1_1._4_4_ = (uint)(UVar9 >> 0x20);
    uVar5 = (k1_1._4_4_ ^ h64_local._4_4_) >> 5 | ((uint)k1_1 ^ (uint)h64_local) << 0x1b;
    lVar2 = (ulonglong)uVar5 * 0x85ebca87;
    uVar4 = (uint)lVar2;
    h64_local = CONCAT44(uVar5 * -0x61c8864f +
                         (((uint)k1_1 ^ (uint)h64_local) >> 5 |
                         (k1_1._4_4_ ^ h64_local._4_4_) << 0x1b) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar4) + 0x85ebca77,
                         uVar4 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 8:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    k1_2._0_4_ = (uint)UVar9;
    k1_2._4_4_ = (uint)(UVar9 >> 0x20);
    uVar5 = (k1_2._4_4_ ^ h64_local._4_4_) >> 5 | ((uint)k1_2 ^ (uint)h64_local) << 0x1b;
    lVar2 = (ulonglong)uVar5 * 0x85ebca87;
    uVar4 = (uint)lVar2;
    h64_local = CONCAT44(uVar5 * -0x61c8864f +
                         (((uint)k1_2 ^ (uint)h64_local) >> 5 |
                         (k1_2._4_4_ ^ h64_local._4_4_) << 0x1b) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar4) + 0x85ebca77,
                         uVar4 + 0xc2b2ae63);
    UVar9 = XXH64_avalanche(h64_local);
    break;
  case 0x19:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_6._0_4_ = (uint)UVar9;
    k1_6._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_6 ^ (uint)h64_local) << 0x1b | (k1_6._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_6._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_6 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x11:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_7._0_4_ = (uint)UVar9;
    k1_7._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_7 ^ (uint)h64_local) << 0x1b | (k1_7._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_7._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_7 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 9:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    k1_8._0_4_ = (uint)UVar9;
    k1_8._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_8 ^ (uint)h64_local) << 0x1b | (k1_8._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    lVar1 = (ulonglong)(uint)p[8] * 0x165667c5;
    uVar6 = (uint)lVar1 ^ uVar5 + 0xc2b2ae63;
    uVar5 = (uint)p[8] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f +
            ((k1_8._4_4_ ^ h64_local._4_4_) << 0x1b | ((uint)k1_8 ^ (uint)h64_local) >> 5) *
            -0x7a143579 + (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77;
    uVar4 = uVar6 << 0xb | uVar5 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    UVar9 = XXH64_avalanche(CONCAT44(uVar4 * -0x61c8864f +
                                     (uVar5 << 0xb | uVar6 >> 0x15) * -0x7a143579 +
                                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2));
    break;
  case 0x1a:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_12._0_4_ = (uint)UVar9;
    k1_12._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_12 ^ (uint)h64_local) << 0x1b | (k1_12._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_12._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_12 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x12:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_13._0_4_ = (uint)UVar9;
    k1_13._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_13 ^ (uint)h64_local) << 0x1b | (k1_13._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_13._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_13 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 10:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    k1_14._0_4_ = (uint)UVar9;
    k1_14._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_14 ^ (uint)h64_local) << 0x1b | (k1_14._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    lVar1 = (ulonglong)(uint)p[8] * 0x165667c5;
    uVar6 = (uint)lVar1 ^ uVar5 + 0xc2b2ae63;
    uVar8 = (uint)p[8] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f +
            ((k1_14._4_4_ ^ h64_local._4_4_) << 0x1b | ((uint)k1_14 ^ (uint)h64_local) >> 5) *
            -0x7a143579 + (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77;
    uVar4 = uVar6 << 0xb | uVar8 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    lVar1 = (ulonglong)(uint)p[9] * 0x165667c5;
    uVar5 = (uint)lVar1 ^ (uint)lVar2;
    uVar6 = (uint)p[9] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f + (uVar8 << 0xb | uVar6 >> 0x15) * -0x7a143579 +
            (int)((ulonglong)lVar2 >> 0x20);
    uVar4 = uVar5 << 0xb | uVar6 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    UVar9 = XXH64_avalanche(CONCAT44(uVar4 * -0x61c8864f +
                                     (uVar6 << 0xb | uVar5 >> 0x15) * -0x7a143579 +
                                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2));
    break;
  case 0x1b:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_18._0_4_ = (uint)UVar9;
    k1_18._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_18 ^ (uint)h64_local) << 0x1b | (k1_18._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_18._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_18 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x13:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_19._0_4_ = (uint)UVar9;
    k1_19._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_19 ^ (uint)h64_local) << 0x1b | (k1_19._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_19._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_19 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0xb:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    k1_20._0_4_ = (uint)UVar9;
    k1_20._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_20 ^ (uint)h64_local) << 0x1b | (k1_20._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    lVar1 = (ulonglong)(uint)p[8] * 0x165667c5;
    uVar6 = (uint)lVar1 ^ uVar5 + 0xc2b2ae63;
    uVar8 = (uint)p[8] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f +
            ((k1_20._4_4_ ^ h64_local._4_4_) << 0x1b | ((uint)k1_20 ^ (uint)h64_local) >> 5) *
            -0x7a143579 + (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77;
    uVar4 = uVar6 << 0xb | uVar8 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    lVar1 = (ulonglong)(uint)p[9] * 0x165667c5;
    uVar5 = (uint)lVar1 ^ (uint)lVar2;
    uVar8 = (uint)p[9] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f + (uVar8 << 0xb | uVar6 >> 0x15) * -0x7a143579 +
            (int)((ulonglong)lVar2 >> 0x20);
    uVar4 = uVar5 << 0xb | uVar8 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    lVar1 = (ulonglong)(uint)p[10] * 0x165667c5;
    uVar6 = (uint)lVar1 ^ (uint)lVar2;
    uVar5 = (uint)p[10] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f + (uVar8 << 0xb | uVar5 >> 0x15) * -0x7a143579 +
            (int)((ulonglong)lVar2 >> 0x20);
    uVar4 = uVar6 << 0xb | uVar5 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    UVar9 = XXH64_avalanche(CONCAT44(uVar4 * -0x61c8864f +
                                     (uVar5 << 0xb | uVar6 >> 0x15) * -0x7a143579 +
                                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2));
    break;
  case 0x1c:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_3._0_4_ = (uint)UVar9;
    k1_3._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_3 ^ (uint)h64_local) << 0x1b | (k1_3._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_3._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_3 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x14:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_4._0_4_ = (uint)UVar9;
    k1_4._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_4 ^ (uint)h64_local) << 0x1b | (k1_4._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_4._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_4 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0xc:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_5._0_4_ = (uint)UVar9;
    k1_5._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_5 ^ (uint)h64_local) << 0x1b | (k1_5._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_5._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_5 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 4:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar3 = XXH_read32(p);
      }
      else {
        UVar3 = XXH_read32(p);
        UVar3 = UVar3 << 0x18 | (UVar3 >> 8 & 0xff) << 0x10 | (UVar3 >> 0x10 & 0xff) << 8 |
                UVar3 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar3 = *(U32 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      UVar3 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
              uVar4 >> 0x18;
    }
    uVar4 = (uint)((ulonglong)UVar3 * 0x85ebca87) ^ (uint)h64_local;
    uVar8 = UVar3 * -0x61c8864f + (int)((ulonglong)UVar3 * 0x85ebca87 >> 0x20) ^ h64_local._4_4_;
    uVar5 = uVar4 << 0x17 | uVar8 >> 9;
    lVar2 = (ulonglong)uVar5 * 0x27d4eb4f;
    uVar6 = (uint)lVar2;
    h64_local = CONCAT44(uVar5 * -0x3d4d51c3 + (uVar8 << 0x17 | uVar4 >> 9) * 0x27d4eb4f +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x61c88606 < uVar6) + 0x165667b1,
                         uVar6 + 0x9e3779f9);
    UVar9 = XXH64_avalanche(h64_local);
    break;
  case 0x1d:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_9._0_4_ = (uint)UVar9;
    k1_9._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_9 ^ (uint)h64_local) << 0x1b | (k1_9._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_9._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_9 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x15:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_10._0_4_ = (uint)UVar9;
    k1_10._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_10 ^ (uint)h64_local) << 0x1b | (k1_10._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_10._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_10 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0xd:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_11._0_4_ = (uint)UVar9;
    k1_11._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_11 ^ (uint)h64_local) << 0x1b | (k1_11._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_11._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_11 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 5:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar3 = XXH_read32(p);
      }
      else {
        UVar3 = XXH_read32(p);
        UVar3 = UVar3 << 0x18 | (UVar3 >> 8 & 0xff) << 0x10 | (UVar3 >> 0x10 & 0xff) << 8 |
                UVar3 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar3 = *(U32 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      UVar3 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
              uVar4 >> 0x18;
    }
    uVar4 = (uint)((ulonglong)UVar3 * 0x85ebca87) ^ (uint)h64_local;
    uVar7 = UVar3 * -0x61c8864f + (int)((ulonglong)UVar3 * 0x85ebca87 >> 0x20) ^ h64_local._4_4_;
    uVar5 = uVar4 << 0x17 | uVar7 >> 9;
    lVar2 = (ulonglong)uVar5 * 0x27d4eb4f;
    uVar6 = (uint)lVar2;
    lVar1 = (ulonglong)(uint)p[4] * 0x165667c5;
    uVar8 = (uint)lVar1 ^ uVar6 + 0x9e3779f9;
    uVar5 = (uint)p[4] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar5 * -0x3d4d51c3 + (uVar7 << 0x17 | uVar4 >> 9) * 0x27d4eb4f +
            (int)((ulonglong)lVar2 >> 0x20) + (0x61c88606 < uVar6) + 0x165667b1;
    uVar4 = uVar8 << 0xb | uVar5 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    UVar9 = XXH64_avalanche(CONCAT44(uVar4 * -0x61c8864f +
                                     (uVar5 << 0xb | uVar8 >> 0x15) * -0x7a143579 +
                                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2));
    break;
  case 0x1e:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_15._0_4_ = (uint)UVar9;
    k1_15._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_15 ^ (uint)h64_local) << 0x1b | (k1_15._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_15._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_15 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x16:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_16._0_4_ = (uint)UVar9;
    k1_16._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_16 ^ (uint)h64_local) << 0x1b | (k1_16._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_16._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_16 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0xe:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_17._0_4_ = (uint)UVar9;
    k1_17._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_17 ^ (uint)h64_local) << 0x1b | (k1_17._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_17._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_17 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 6:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar3 = XXH_read32(p);
      }
      else {
        UVar3 = XXH_read32(p);
        UVar3 = UVar3 << 0x18 | (UVar3 >> 8 & 0xff) << 0x10 | (UVar3 >> 0x10 & 0xff) << 8 |
                UVar3 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar3 = *(U32 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      UVar3 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
              uVar4 >> 0x18;
    }
    uVar4 = (uint)((ulonglong)UVar3 * 0x85ebca87) ^ (uint)h64_local;
    uVar7 = UVar3 * -0x61c8864f + (int)((ulonglong)UVar3 * 0x85ebca87 >> 0x20) ^ h64_local._4_4_;
    uVar5 = uVar4 << 0x17 | uVar7 >> 9;
    lVar2 = (ulonglong)uVar5 * 0x27d4eb4f;
    uVar6 = (uint)lVar2;
    lVar1 = (ulonglong)(uint)p[4] * 0x165667c5;
    uVar8 = (uint)lVar1 ^ uVar6 + 0x9e3779f9;
    uVar6 = (uint)p[4] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar5 * -0x3d4d51c3 + (uVar7 << 0x17 | uVar4 >> 9) * 0x27d4eb4f +
            (int)((ulonglong)lVar2 >> 0x20) + (0x61c88606 < uVar6) + 0x165667b1;
    uVar4 = uVar8 << 0xb | uVar6 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    lVar1 = (ulonglong)(uint)p[5] * 0x165667c5;
    uVar5 = (uint)lVar1 ^ (uint)lVar2;
    uVar6 = (uint)p[5] * 0x27d4eb2f + (int)((ulonglong)lVar1 >> 0x20) ^
            uVar4 * -0x61c8864f + (uVar6 << 0xb | uVar8 >> 0x15) * -0x7a143579 +
            (int)((ulonglong)lVar2 >> 0x20);
    uVar4 = uVar5 << 0xb | uVar6 >> 0x15;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    UVar9 = XXH64_avalanche(CONCAT44(uVar4 * -0x61c8864f +
                                     (uVar6 << 0xb | uVar5 >> 0x15) * -0x7a143579 +
                                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2));
    break;
  case 0x1f:
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(ptr);
      }
      else {
        UVar9 = XXH_read64(ptr);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
                    /* WARNING: Load size is inaccurate */
      UVar9 = *ptr;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *ptr;
      uVar5 = *(uint *)((int)ptr + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = (BYTE *)((int)ptr + 8);
    k1_21._0_4_ = (uint)UVar9;
    k1_21._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_21 ^ (uint)h64_local) << 0x1b | (k1_21._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_21._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_21 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0x17:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_22._0_4_ = (uint)UVar9;
    k1_22._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_22 ^ (uint)h64_local) << 0x1b | (k1_22._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_22._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_22 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 0xf:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar9 = XXH_read64(p);
      }
      else {
        UVar9 = XXH_read64(p);
        uVar5 = (uint)(UVar9 >> 0x20);
        uVar4 = (uint)UVar9;
        UVar9 = CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 |
                         (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18,
                         (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 | (uVar5 >> 8 & 0xff) << 0x10
                         | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18);
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar9 = *(U64 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      uVar5 = *(uint *)(p + 4);
      UVar9 = CONCAT44(uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                       uVar4 >> 0x18,
                       uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18);
    }
    UVar9 = XXH64_round(0,UVar9);
    p = p + 8;
    k1_23._0_4_ = (uint)UVar9;
    k1_23._4_4_ = (uint)(UVar9 >> 0x20);
    uVar4 = ((uint)k1_23 ^ (uint)h64_local) << 0x1b | (k1_23._4_4_ ^ h64_local._4_4_) >> 5;
    lVar2 = (ulonglong)uVar4 * 0x85ebca87;
    uVar5 = (uint)lVar2;
    h64_local = CONCAT44(uVar4 * -0x61c8864f +
                         ((k1_23._4_4_ ^ h64_local._4_4_) << 0x1b |
                         ((uint)k1_23 ^ (uint)h64_local) >> 5) * -0x7a143579 +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x3d4d519c < uVar5) + 0x85ebca77,
                         uVar5 + 0xc2b2ae63);
    UVar9 = h64_local;
  case 7:
    h64_local = UVar9;
    if (align == XXH_unaligned) {
      if (endian == XXH_littleEndian) {
        UVar3 = XXH_read32(p);
      }
      else {
        UVar3 = XXH_read32(p);
        UVar3 = UVar3 << 0x18 | (UVar3 >> 8 & 0xff) << 0x10 | (UVar3 >> 0x10 & 0xff) << 8 |
                UVar3 >> 0x18;
      }
    }
    else if (endian == XXH_littleEndian) {
      UVar3 = *(U32 *)p;
    }
    else {
      uVar4 = *(uint *)p;
      UVar3 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
              uVar4 >> 0x18;
    }
    uVar4 = (uint)((ulonglong)UVar3 * 0x85ebca87) ^ (uint)h64_local;
    uVar8 = UVar3 * -0x61c8864f + (int)((ulonglong)UVar3 * 0x85ebca87 >> 0x20) ^ h64_local._4_4_;
    p = p + 4;
    uVar5 = uVar4 << 0x17 | uVar8 >> 9;
    lVar2 = (ulonglong)uVar5 * 0x27d4eb4f;
    uVar6 = (uint)lVar2;
    h64_local = CONCAT44(uVar5 * -0x3d4d51c3 + (uVar8 << 0x17 | uVar4 >> 9) * 0x27d4eb4f +
                         (int)((ulonglong)lVar2 >> 0x20) + (0x61c88606 < uVar6) + 0x165667b1,
                         uVar6 + 0x9e3779f9);
    UVar9 = h64_local;
  case 3:
    h64_local = UVar9;
    lVar2 = (ulonglong)(uint)*p * 0x165667c5;
    uVar4 = (uint)lVar2 ^ (uint)h64_local;
    uVar6 = (uint)*p * 0x27d4eb2f + (int)((ulonglong)lVar2 >> 0x20) ^ h64_local._4_4_;
    uVar5 = uVar4 << 0xb | uVar6 >> 0x15;
    lVar2 = (ulonglong)uVar5 * 0x85ebca87;
    UVar9 = CONCAT44(uVar5 * -0x61c8864f + (uVar6 << 0xb | uVar4 >> 0x15) * -0x7a143579 +
                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2);
    p = p + 1;
  case 2:
    h64_local = UVar9;
    lVar2 = (ulonglong)(uint)*p * 0x165667c5;
    uVar4 = (uint)lVar2 ^ (uint)h64_local;
    uVar6 = (uint)*p * 0x27d4eb2f + (int)((ulonglong)lVar2 >> 0x20) ^ h64_local._4_4_;
    uVar5 = uVar4 << 0xb | uVar6 >> 0x15;
    lVar2 = (ulonglong)uVar5 * 0x85ebca87;
    UVar9 = CONCAT44(uVar5 * -0x61c8864f + (uVar6 << 0xb | uVar4 >> 0x15) * -0x7a143579 +
                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2);
    p = p + 1;
  case 1:
    h64_local = UVar9;
    lVar2 = (ulonglong)(uint)*p * 0x165667c5;
    uVar4 = (uint)lVar2 ^ (uint)h64_local;
    uVar6 = (uint)*p * 0x27d4eb2f + (int)((ulonglong)lVar2 >> 0x20) ^ h64_local._4_4_;
    uVar5 = uVar4 << 0xb | uVar6 >> 0x15;
    lVar2 = (ulonglong)uVar5 * 0x85ebca87;
    UVar9 = CONCAT44(uVar5 * -0x61c8864f + (uVar6 << 0xb | uVar4 >> 0x15) * -0x7a143579 +
                     (int)((ulonglong)lVar2 >> 0x20),(int)lVar2);
  case 0:
    h64_local = UVar9;
    UVar9 = XXH64_avalanche(h64_local);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    __assert_fail("0","../zhiju/log_file/xxhash.c",0x326,"XXH64_finalize");
  }
  return UVar9;
}

