
uint32_t hashlittle(void *key,size_t length,uint32_t initval)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint32_t initval_local;
  size_t length_local;
  void *key_local;
  anon_union_4_2_f9ecd746 u;
  uint8_t *k8_1;
  uint8_t *k8;
  uint8_t *k_2;
  uint16_t *k_1;
  uint32_t *k;
  uint32_t c;
  uint32_t b;
  uint32_t a;
  
  c = length + initval + 0xdeadbeef;
  length_local = length;
  k = (uint32_t *)key;
  b = c;
  a = c;
  if (((uint)key & 3) != 0) {
    k_2 = (uint8_t *)key;
    k_1 = (uint16_t *)key;
    if (((uint)key & 1) != 0) {
      do {
        switch(length_local) {
        case 0:
          return c;
        case 0xc:
          c = c + (uint)k_2[0xb] * 0x1000000;
        case 0xb:
          c = c + (uint)k_2[10] * 0x10000;
        case 10:
          c = c + (uint)k_2[9] * 0x100;
        case 9:
          c = c + k_2[8];
        case 8:
          b = b + (uint)k_2[7] * 0x1000000;
        case 7:
          b = b + (uint)k_2[6] * 0x10000;
        case 6:
          b = b + (uint)k_2[5] * 0x100;
        case 5:
          b = b + k_2[4];
        case 4:
          a = a + (uint)k_2[3] * 0x1000000;
        case 3:
          a = a + (uint)k_2[2] * 0x10000;
        case 2:
          a = a + (uint)k_2[1] * 0x100;
        case 1:
          a = a + *k_2;
          goto switchD_00065296_caseD_d;
        default:
          iVar1 = b + k_2[4] + (uint)k_2[5] * 0x100 + (uint)k_2[6] * 0x10000 +
                  (uint)k_2[7] * 0x1000000;
          uVar3 = c + k_2[8] + (uint)k_2[9] * 0x100 + (uint)k_2[10] * 0x10000 +
                  (uint)k_2[0xb] * 0x1000000;
          uVar4 = (uVar3 >> 0x1c | uVar3 * 0x10) ^
                  (a + *k_2 + (uint)k_2[1] * 0x100 + (uint)k_2[2] * 0x10000 +
                  (uint)k_2[3] * 0x1000000) - uVar3;
          iVar2 = uVar3 + iVar1;
          uVar3 = (uVar4 >> 0x1a | uVar4 << 6) ^ iVar1 - uVar4;
          iVar1 = uVar4 + iVar2;
          uVar4 = (uVar3 >> 0x18 | uVar3 << 8) ^ iVar2 - uVar3;
          iVar2 = uVar3 + iVar1;
          uVar3 = (uVar4 >> 0x10 | uVar4 << 0x10) ^ iVar1 - uVar4;
          iVar1 = uVar4 + iVar2;
          uVar4 = (uVar3 >> 0xd | uVar3 << 0x13) ^ iVar2 - uVar3;
          a = uVar3 + iVar1;
          c = (uVar4 >> 0x1c | uVar4 << 4) ^ iVar1 - uVar4;
          b = uVar4 + a;
          length_local = length_local - 0xc;
          k_2 = k_2 + 0xc;
          break;
        case 0xbad1abe1:
          goto switchD_00065296_caseD_d;
        }
      } while( true );
    }
    do {
      switch(length_local) {
      case 0:
        return c;
      case 1:
        a = a + *(byte *)k_1;
        goto switchD_00065296_caseD_d;
      case 3:
        a = a + (uint)*(byte *)(k_1 + 1) * 0x10000;
      case 2:
        a = a + *k_1;
        goto switchD_00065296_caseD_d;
      case 5:
        b = b + *(byte *)(k_1 + 2);
      case 4:
        a = a + (uint)*k_1 + (uint)k_1[1] * 0x10000;
        goto switchD_00065296_caseD_d;
      case 7:
        b = b + (uint)*(byte *)(k_1 + 3) * 0x10000;
      case 6:
        b = b + k_1[2];
        a = a + (uint)*k_1 + (uint)k_1[1] * 0x10000;
        goto switchD_00065296_caseD_d;
      case 9:
        c = c + *(byte *)(k_1 + 4);
      case 8:
        b = b + (uint)k_1[2] + (uint)k_1[3] * 0x10000;
        a = a + (uint)*k_1 + (uint)k_1[1] * 0x10000;
        goto switchD_00065296_caseD_d;
      case 0xb:
        c = c + (uint)*(byte *)(k_1 + 5) * 0x10000;
      case 10:
        c = c + k_1[4];
        b = b + (uint)k_1[2] + (uint)k_1[3] * 0x10000;
        a = a + (uint)*k_1 + (uint)k_1[1] * 0x10000;
        goto switchD_00065296_caseD_d;
      case 0xc:
        c = c + (uint)k_1[4] + (uint)k_1[5] * 0x10000;
        b = b + (uint)k_1[2] + (uint)k_1[3] * 0x10000;
        a = a + (uint)*k_1 + (uint)k_1[1] * 0x10000;
        goto switchD_00065296_caseD_d;
      default:
        iVar1 = b + (uint)k_1[2] + (uint)k_1[3] * 0x10000;
        uVar3 = c + (uint)k_1[4] + (uint)k_1[5] * 0x10000;
        uVar4 = (uVar3 >> 0x1c | uVar3 * 0x10) ^ (a + (uint)*k_1 + (uint)k_1[1] * 0x10000) - uVar3;
        iVar2 = uVar3 + iVar1;
        uVar3 = (uVar4 >> 0x1a | uVar4 << 6) ^ iVar1 - uVar4;
        iVar1 = uVar4 + iVar2;
        uVar4 = (uVar3 >> 0x18 | uVar3 << 8) ^ iVar2 - uVar3;
        iVar2 = uVar3 + iVar1;
        uVar3 = (uVar4 >> 0x10 | uVar4 << 0x10) ^ iVar1 - uVar4;
        iVar1 = uVar4 + iVar2;
        uVar4 = (uVar3 >> 0xd | uVar3 << 0x13) ^ iVar2 - uVar3;
        a = uVar3 + iVar1;
        c = (uVar4 >> 0x1c | uVar4 << 4) ^ iVar1 - uVar4;
        b = uVar4 + a;
        length_local = length_local - 0xc;
        k_1 = k_1 + 6;
        break;
      case 0xbad1abe1:
        goto switchD_00065296_caseD_d;
      }
    } while( true );
  }
  do {
    switch(length_local) {
    case 0:
      return c;
    case 3:
      a = a + (uint)*(byte *)((int)k + 2) * 0x10000;
    case 2:
      a = a + (uint)*(byte *)((int)k + 1) * 0x100;
    case 1:
      a = a + *(byte *)k;
    case 0xbad1abe1:
switchD_00065296_caseD_d:
      uVar3 = (b ^ c) - (b >> 0x12 | b << 0xe);
      uVar4 = (uVar3 ^ a) - (uVar3 >> 0x15 | uVar3 * 0x800);
      uVar5 = (uVar4 ^ b) - (uVar4 >> 7 | uVar4 * 0x2000000);
      uVar3 = (uVar5 ^ uVar3) - (uVar5 >> 0x10 | uVar5 * 0x10000);
      uVar4 = (uVar3 ^ uVar4) - (uVar3 >> 0x1c | uVar3 * 0x10);
      uVar4 = (uVar4 ^ uVar5) - (uVar4 >> 0x12 | uVar4 * 0x4000);
      return (uVar4 ^ uVar3) - (uVar4 >> 8 | uVar4 * 0x1000000);
    case 7:
      b = b + (uint)*(byte *)((int)k + 6) * 0x10000;
    case 6:
      b = b + (uint)*(byte *)((int)k + 5) * 0x100;
    case 5:
      b = b + *(byte *)(k + 1);
    case 4:
      a = a + *k;
      goto switchD_00065296_caseD_d;
    case 0xb:
      c = c + (uint)*(byte *)((int)k + 10) * 0x10000;
    case 10:
      c = c + (uint)*(byte *)((int)k + 9) * 0x100;
    case 9:
      c = c + *(byte *)(k + 2);
    case 8:
      b = b + k[1];
      a = a + *k;
      goto switchD_00065296_caseD_d;
    case 0xc:
      c = c + k[2];
      b = b + k[1];
      a = a + *k;
      goto switchD_00065296_caseD_d;
    default:
      uVar3 = c + k[2];
      uVar4 = (uVar3 >> 0x1c | uVar3 * 0x10) ^ (a + *k) - uVar3;
      iVar1 = uVar3 + b + k[1];
      uVar3 = (uVar4 >> 0x1a | uVar4 << 6) ^ (b + k[1]) - uVar4;
      iVar2 = uVar4 + iVar1;
      uVar4 = (uVar3 >> 0x18 | uVar3 << 8) ^ iVar1 - uVar3;
      iVar1 = uVar3 + iVar2;
      uVar3 = (uVar4 >> 0x10 | uVar4 << 0x10) ^ iVar2 - uVar4;
      iVar2 = uVar4 + iVar1;
      uVar4 = (uVar3 >> 0xd | uVar3 << 0x13) ^ iVar1 - uVar3;
      a = uVar3 + iVar2;
      c = (uVar4 >> 0x1c | uVar4 << 4) ^ iVar2 - uVar4;
      b = uVar4 + a;
      length_local = length_local - 0xc;
      k = k + 3;
    }
  } while( true );
}

