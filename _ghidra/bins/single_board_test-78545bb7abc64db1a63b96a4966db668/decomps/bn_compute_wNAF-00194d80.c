
undefined1 * bn_compute_wNAF(BIGNUM *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  undefined1 *local_38;
  
  iVar1 = BN_is_zero();
  if (iVar1 == 0) {
    if (6 < param_2 - 1) {
      ERR_put_error(3,0x8e,0x44,"crypto/bn/bn_intern.c",0x2b);
      local_38 = (undefined1 *)0x0;
      goto LAB_00194eb0;
    }
    iVar1 = BN_is_negative(param_1);
    uVar8 = 1 << (param_2 & 0xff);
    uVar9 = uVar8 * 2;
    if (iVar1 == 0) {
      cVar5 = '\x01';
    }
    else {
      cVar5 = -1;
    }
    if ((param_1->d == (ulong *)0x0) || (param_1->top == 0)) {
      ERR_put_error(3,0x8e,0x44,"crypto/bn/bn_intern.c",0x37);
      local_38 = (undefined1 *)0x0;
      goto LAB_00194eb0;
    }
    uVar2 = BN_num_bits(param_1);
    local_38 = (undefined1 *)CRYPTO_malloc(uVar2 + 1,"crypto/bn/bn_intern.c",0x3c);
    if (local_38 != (undefined1 *)0x0) {
      param_2 = param_2 + 1;
      uVar3 = *param_1->d & uVar9 - 1;
      pcVar10 = local_38 + -1;
      uVar11 = 0;
      do {
        if (uVar3 == 0) {
          if (uVar2 <= param_2) {
            if (uVar11 <= uVar2 + 1) {
              *param_3 = uVar11;
              return local_38;
            }
            iVar1 = 0x82;
            goto LAB_00194ea2;
          }
          cVar6 = '\0';
        }
        else {
          cVar6 = (char)(uVar3 & 1);
          if ((uVar3 & 1) != 0) {
            uVar7 = uVar3;
            if ((uVar3 & uVar8) == 0) {
LAB_00194e96:
              if ((int)-uVar8 < (int)uVar7) goto LAB_00194e5a;
            }
            else {
              if (param_2 < uVar2) {
                uVar7 = uVar3 + uVar8 * -2;
                goto LAB_00194e96;
              }
              uVar7 = uVar3 & (int)(uVar9 - 1) >> 1;
LAB_00194e5a:
              if (((int)uVar7 < (int)uVar8) && ((int)(uVar7 << 0x1f) < 0)) {
                uVar3 = uVar3 - uVar7;
                if (uVar8 == uVar3 || (uVar9 == uVar3 || uVar3 == 0)) {
                  cVar6 = (char)uVar7 * cVar5;
                  goto LAB_00194e1c;
                }
                iVar1 = 0x71;
                goto LAB_00194ea2;
              }
            }
            iVar1 = 0x65;
            goto LAB_00194ea2;
          }
        }
LAB_00194e1c:
        pcVar10 = pcVar10 + 1;
        *pcVar10 = cVar6;
        uVar11 = uVar11 + 1;
        iVar1 = BN_is_bit_set(param_1,param_2);
        uVar3 = iVar1 * uVar8 + ((int)uVar3 >> 1);
        param_2 = param_2 + 1;
      } while ((int)uVar3 <= (int)uVar9);
      iVar1 = 0x7c;
LAB_00194ea2:
      ERR_put_error(3,0x8e,0x44,"crypto/bn/bn_intern.c",iVar1);
      goto LAB_00194eb0;
    }
    iVar1 = 0x42;
  }
  else {
    puVar4 = (undefined1 *)CRYPTO_malloc(1,"crypto/bn/bn_intern.c",0x1f);
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 0;
      *param_3 = 1;
      return puVar4;
    }
    iVar1 = 0x21;
    local_38 = (undefined1 *)0x0;
  }
  ERR_put_error(3,0x8e,0x41,"crypto/bn/bn_intern.c",iVar1);
LAB_00194eb0:
  CRYPTO_free(local_38);
  return (undefined1 *)0x0;
}

