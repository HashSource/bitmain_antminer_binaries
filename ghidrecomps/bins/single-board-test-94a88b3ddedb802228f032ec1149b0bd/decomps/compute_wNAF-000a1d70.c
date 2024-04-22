
ulong * compute_wNAF(BIGNUM *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulong *ptr;
  uint uVar6;
  uint uVar7;
  char cVar8;
  uint uVar9;
  
  if (param_1->top == 0) {
    ptr = (ulong *)CRYPTO_malloc(1,DAT_000a1ee4,0xc3);
    iVar5 = 0xc5;
    if (ptr != (ulong *)0x0) {
      *(undefined *)ptr = 0;
      *param_3 = 1;
      return ptr;
    }
LAB_000a1eb2:
    ERR_put_error(0x10,0x8f,0x41,DAT_000a1ee4,iVar5);
  }
  else {
    if (6 < param_2 - 1) {
      ERR_put_error(0x10,0x8f,0x44,DAT_000a1ee4,0xcf);
      ptr = (ulong *)0x0;
      goto LAB_000a1e1e;
    }
    ptr = param_1->d;
    if (param_1->neg == 0) {
      cVar8 = '\x01';
    }
    else {
      cVar8 = -1;
    }
    iVar5 = 0xdb;
    if (ptr != (ulong *)0x0) {
      uVar1 = BN_num_bits(param_1);
      ptr = (ulong *)CRYPTO_malloc(uVar1 + 1,DAT_000a1ee4,0xe0);
      if (ptr == (ulong *)0x0) {
        iVar5 = 0xe5;
        goto LAB_000a1eb2;
      }
      uVar6 = 1 << (param_2 & 0xff);
      uVar7 = uVar6 * 2;
      param_2 = param_2 + 1;
      uVar9 = 0;
      uVar2 = *param_1->d & uVar7 - 1;
      do {
        if (uVar2 == 0) {
          if (uVar1 <= param_2) {
            if (uVar9 <= uVar1 + 1) {
              *param_3 = uVar9;
              return ptr;
            }
            iVar5 = 0x125;
            goto LAB_000a1e10;
          }
          cVar3 = '\0';
        }
        else {
          cVar3 = (char)(uVar2 & 1);
          if ((uVar2 & 1) != 0) {
            uVar4 = uVar2;
            if ((uVar2 & uVar6) != 0) {
              if (param_2 < uVar1) {
                uVar4 = uVar2 + uVar6 * -2;
              }
              else {
                uVar4 = uVar2 & (int)(uVar7 - 1) >> 1;
              }
            }
            if ((((int)uVar4 <= (int)-uVar6) || ((int)uVar6 <= (int)uVar4)) ||
               (-1 < (int)(uVar4 << 0x1f))) {
              iVar5 = 0x108;
              goto LAB_000a1e10;
            }
            uVar2 = uVar2 - uVar4;
            if (uVar2 == uVar7 || uVar2 == 0) {
              cVar3 = (char)uVar4 * cVar8;
            }
            else {
              if (uVar2 != uVar6) {
                iVar5 = 0x114;
                goto LAB_000a1e10;
              }
              cVar3 = (char)uVar4 * cVar8;
            }
          }
        }
        *(char *)((int)ptr + uVar9) = cVar3;
        uVar9 = uVar9 + 1;
        iVar5 = BN_is_bit_set(param_1,param_2);
        uVar2 = uVar6 * iVar5 + ((int)uVar2 >> 1);
        param_2 = param_2 + 1;
      } while ((int)uVar2 <= (int)uVar7);
      iVar5 = 0x11f;
    }
LAB_000a1e10:
    ERR_put_error(0x10,0x8f,0x44,DAT_000a1ee4,iVar5);
  }
LAB_000a1e1e:
  CRYPTO_free(ptr);
  return (ulong *)0x0;
}

