
_STACK * ssl_create_cipher_list
                   (int param_1,_STACK **param_2,_STACK **param_3,char *param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  void **ptr;
  int *piVar7;
  _STACK *st;
  void **ppvVar8;
  _STACK *p_Var9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void **ppvVar13;
  void *pvVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  void **ppvVar18;
  void *pvVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  void **ppvVar32;
  void **ppvVar33;
  void **ppvVar34;
  void **ppvVar35;
  int iVar36;
  char *local_48;
  void **local_38;
  void **local_34;
  ENGINE *local_30;
  int local_2c [2];
  
  local_38 = (void **)0x0;
  local_34 = (void **)0x0;
  uVar30 = (uint)(param_2 == (_STACK **)0x0 || param_4 == (char *)0x0);
  if (param_2 == (_STACK **)0x0 || param_4 == (char *)0x0) {
    return (_STACK *)0x0;
  }
  if (param_3 == (_STACK **)0x0) {
    return (_STACK *)0x0;
  }
  uVar2 = strcmp(param_4,DAT_00080374);
  local_48 = param_4;
  if (uVar2 == 0) {
LAB_000802f2:
    uVar20 = 0x30000;
    uVar30 = uVar2;
LAB_000802f6:
    *(uint *)(param_5 + 0x38) = *(uint *)(param_5 + 0x38) & 0xfffcffff | uVar20;
LAB_00080300:
    iVar15 = *(int *)(*(int *)(param_1 + 100) + 0x38);
    if (-1 < iVar15 << 0x1b) {
      if (iVar15 << 0x1c < 0) {
        iVar36 = 0x596;
        iVar15 = 0x183;
      }
      else {
        iVar36 = 0x599;
        iVar15 = 0x17b;
      }
      ERR_put_error(0x14,0x14b,iVar15,DAT_00080378,iVar36);
      return (_STACK *)0x0;
    }
    if (uVar20 == 0x20000) {
      local_48 = DAT_00080cc4;
    }
    else if (uVar20 == 0x30000) {
      local_48 = DAT_00080ccc;
      if (uVar30 != 0) {
        local_48 = DAT_00080cc4;
      }
    }
    else if (uVar20 == 0x10000) {
      local_48 = DAT_00080630;
    }
    *(undefined4 *)(param_5 + 0x34) = 1;
  }
  else {
    iVar15 = strcmp(param_4,DAT_0008037c);
    if (iVar15 == 0) {
      uVar20 = 0x10000;
      uVar30 = 0;
      goto LAB_000802f6;
    }
    iVar15 = strcmp(param_4,DAT_00080380);
    if (iVar15 == 0) {
      uVar2 = 1;
      goto LAB_000802f2;
    }
    iVar15 = strcmp(param_4,DAT_00080384);
    if (iVar15 == 0) {
      uVar20 = 0x20000;
      uVar30 = 0;
      goto LAB_000802f6;
    }
    uVar20 = *(uint *)(param_5 + 0x38) & 0x30000;
    if (uVar20 != 0) goto LAB_00080300;
  }
  local_30 = (ENGINE *)0x0;
  local_2c[0] = 0;
  pEVar3 = EVP_PKEY_asn1_find_str(&local_30,DAT_00080634,-1);
  if (pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(local_2c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3);
  }
  if (local_30 != (ENGINE *)0x0) {
    ENGINE_finish(local_30);
  }
  local_30 = (ENGINE *)0x0;
  if (local_2c[0] == 0) {
    uVar30 = 0x120;
  }
  else {
    uVar30 = 0x20;
  }
  local_2c[0] = 0;
  pEVar3 = EVP_PKEY_asn1_find_str(&local_30,DAT_00080638,-1);
  if (pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(local_2c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3);
  }
  if (local_30 != (ENGINE *)0x0) {
    ENGINE_finish(local_30);
  }
  if (local_2c[0] == 0) {
    uVar30 = uVar30 | 0x200;
  }
  if ((uVar30 & 0x300) == 0x300) {
    uVar2 = 0x210;
    uVar20 = 0xfffffdef;
  }
  else {
    uVar2 = 0x10;
    uVar20 = 0xffffffef;
  }
  if (*(int *)(DAT_0008063c + 8) == 0) {
    uVar10 = 2;
  }
  else {
    uVar10 = 0;
  }
  if (*(int *)(DAT_0008063c + 4) == 0) {
    uVar10 = uVar10 | 1;
  }
  if (*(int *)(DAT_0008063c + 0xc) == 0) {
    uVar4 = 4;
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x10) == 0) {
    uVar21 = 8;
  }
  else {
    uVar21 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x14) == 0) {
    uVar24 = 0x10;
  }
  else {
    uVar24 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x1c) == 0) {
    uVar11 = 0x40;
  }
  else {
    uVar11 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x20) == 0) {
    uVar16 = 0x80;
  }
  else {
    uVar16 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x34) == 0) {
    uVar5 = 0x1000;
  }
  else {
    uVar5 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x24) == 0) {
    uVar12 = 0x100;
  }
  else {
    uVar12 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x38) == 0) {
    uVar22 = 0x2000;
  }
  else {
    uVar22 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x28) == 0) {
    uVar6 = 0x200;
  }
  else {
    uVar6 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x40) == 0) {
    uVar25 = 2;
  }
  else {
    uVar25 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x50) == 0) {
    uVar23 = 0x20;
  }
  else {
    uVar23 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x3c) == 0) {
    uVar25 = uVar25 | 1;
  }
  if (*(int *)(DAT_0008063c + 0x4c) == 0) {
    uVar26 = 0x10;
  }
  else {
    uVar26 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x30) == 0) {
    uVar31 = 0x800;
  }
  else {
    uVar31 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x2c) == 0) {
    uVar17 = 0x400;
  }
  else {
    uVar17 = 0;
  }
  if (*(int *)(DAT_0008063c + 0x44) == 0) {
    uVar27 = 4;
  }
  else {
    uVar27 = 0;
  }
  uVar31 = uVar17 | uVar6 | uVar12 | uVar10 | uVar4 | uVar21 | uVar24 | uVar11 | uVar16 | uVar5 |
                                     uVar22 | uVar31;
  if ((*(int *)(DAT_0008063c + 0x48) == 0) || (*(int *)(DAT_00080640 + 0xc) == 0)) {
    uVar10 = 8;
  }
  else {
    uVar10 = 0;
  }
  uVar10 = uVar10 | uVar25 | uVar26 | uVar23 | uVar27;
  iVar15 = (**(code **)(param_1 + 0x54))();
  ptr = (void **)CRYPTO_malloc(iVar15 * 0x14,DAT_00080644,0x5e0);
  if (ptr == (void **)0x0) {
    iVar15 = 0x5e2;
    goto LAB_00080c80;
  }
  if (iVar15 < 1) {
LAB_00080bee:
    if (local_34 == (void **)0x0) goto LAB_00080c76;
    ppvVar8 = local_38;
    ppvVar18 = local_34;
    if (local_38 != (void **)0x0) goto LAB_0008067e;
LAB_00080bb4:
    local_38 = (void **)0x0;
  }
  else {
    iVar29 = 0;
    iVar36 = 0;
    do {
      piVar7 = (int *)(**(code **)(param_1 + 0x58))(iVar29);
      iVar29 = iVar29 + 1;
      iVar28 = iVar36;
      if (((((piVar7 != (int *)0x0) && (*piVar7 != 0)) && ((uVar2 & piVar7[3]) == 0)) &&
          (((uVar30 & piVar7[4]) == 0 && ((uVar31 & piVar7[5]) == 0)))) &&
         ((uVar10 & piVar7[6]) == 0)) {
        iVar28 = iVar36 + 1;
        ptr[iVar36 * 5 + 3] = (void *)0x0;
        ptr[iVar36 * 5 + 4] = (void *)0x0;
        ptr[iVar36 * 5] = piVar7;
        ptr[iVar36 * 5 + 1] = (void *)0x0;
      }
      iVar36 = iVar28;
    } while (iVar29 != iVar15);
    if (iVar28 == 0) goto LAB_00080bee;
    ptr[4] = (void *)0x0;
    local_34 = ptr;
    if (iVar28 != 1) {
      iVar36 = iVar28 + -1;
      ptr[3] = ptr + 5;
      if (iVar36 != 1) {
        iVar29 = 1;
        ppvVar8 = ptr + 10;
        do {
          iVar29 = iVar29 + 1;
          ppvVar8[-2] = ppvVar8;
          ppvVar8[-1] = ppvVar8 + -10;
          ppvVar8 = ppvVar8 + 5;
        } while (iVar29 != iVar36);
      }
      (ptr + iVar36 * 5)[4] = ptr + iVar28 * 5 + -10;
      local_34 = ptr + iVar36 * 5;
    }
    local_34[3] = (void *)0x0;
    local_38 = ptr;
    ppvVar8 = ptr;
    ppvVar18 = local_34;
LAB_0008067e:
    do {
      ppvVar13 = (void **)ppvVar8[3];
      if ((*(int *)((int)*ppvVar8 + 0xc) << 0x18 < 0) && (ppvVar8[1] == (void *)0x0)) {
        if (ppvVar8 != local_34) {
          pvVar14 = ppvVar8[4];
          if (ppvVar8 == local_38) {
            local_38 = ppvVar13;
          }
          ppvVar33 = ppvVar13;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar13;
            ppvVar33 = (void **)ppvVar8[3];
          }
          if (ppvVar33 != (void **)0x0) {
            ppvVar33[4] = pvVar14;
          }
          local_34[3] = ppvVar8;
          ppvVar8[4] = local_34;
          ppvVar8[3] = (void *)0x0;
        }
        ppvVar8[1] = (void *)0x1;
        local_34 = ppvVar8;
      }
    } while ((ppvVar18 != ppvVar8) && (ppvVar8 = ppvVar13, ppvVar13 != (void **)0x0));
    ppvVar8 = local_38;
    ppvVar18 = local_34;
    if (local_38 == (void **)0x0) goto LAB_00080bb4;
    do {
      ppvVar13 = (void **)ppvVar18[4];
      if ((*(int *)((int)*ppvVar18 + 0xc) << 0x18 < 0) && (ppvVar18[1] != (void *)0x0)) {
        if (ppvVar18 != ppvVar8) {
          pvVar14 = ppvVar18[3];
          if (ppvVar18 == local_34) {
            local_34 = ppvVar13;
          }
          ppvVar33 = ppvVar13;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0x10) = ppvVar13;
            ppvVar33 = (void **)ppvVar18[4];
          }
          if (ppvVar33 != (void **)0x0) {
            ppvVar33[3] = pvVar14;
          }
          ppvVar8[4] = ppvVar18;
          ppvVar18[3] = ppvVar8;
          ppvVar18[4] = (void *)0x0;
        }
        ppvVar18[1] = (void *)0x0;
        ppvVar8 = ppvVar18;
      }
    } while ((ppvVar18 != local_38) && (ppvVar18 = ppvVar13, ppvVar13 != (void **)0x0));
    local_38 = ppvVar8;
    if (local_34 == (void **)0x0) goto LAB_00080c76;
    ppvVar18 = local_34;
    ppvVar13 = ppvVar8;
    if (ppvVar8 == (void **)0x0) goto LAB_00080bb4;
    do {
      ppvVar33 = (void **)ppvVar8[3];
      if (((*(uint *)((int)*ppvVar8 + 0x14) & 0x30c0) != 0) && (ppvVar8[1] == (void *)0x0)) {
        if (ppvVar8 != ppvVar18) {
          pvVar14 = ppvVar8[4];
          if (ppvVar8 == ppvVar13) {
            ppvVar13 = ppvVar33;
          }
          ppvVar32 = ppvVar33;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar33;
            ppvVar32 = (void **)ppvVar8[3];
          }
          if (ppvVar32 != (void **)0x0) {
            ppvVar32[4] = pvVar14;
          }
          ppvVar18[3] = ppvVar8;
          ppvVar8[4] = ppvVar18;
          ppvVar8[3] = (void *)0x0;
        }
        ppvVar8[1] = (void *)0x1;
        ppvVar18 = ppvVar8;
      }
    } while ((local_34 != ppvVar8) && (ppvVar8 = ppvVar33, ppvVar33 != (void **)0x0));
    ppvVar8 = ppvVar13;
    local_34 = ppvVar18;
    if (ppvVar13 == (void **)0x0) goto LAB_00080bb4;
    do {
      ppvVar33 = (void **)ppvVar13[3];
      if (ppvVar13[1] == (void *)0x0) {
        if (ppvVar13 != local_34) {
          pvVar14 = ppvVar13[4];
          if (ppvVar13 == ppvVar8) {
            ppvVar8 = ppvVar33;
          }
          ppvVar32 = ppvVar33;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar33;
            ppvVar32 = (void **)ppvVar13[3];
          }
          if (ppvVar32 != (void **)0x0) {
            ppvVar32[4] = pvVar14;
          }
          local_34[3] = ppvVar13;
          ppvVar13[4] = local_34;
          ppvVar13[3] = (void *)0x0;
        }
        ppvVar13[1] = (void *)0x1;
        local_34 = ppvVar13;
      }
    } while ((ppvVar18 != ppvVar13) && (ppvVar13 = ppvVar33, ppvVar33 != (void **)0x0));
    local_38 = ppvVar8;
    ppvVar18 = local_34;
    if (ppvVar8 == (void **)0x0) goto LAB_00080bb4;
    do {
      ppvVar33 = (void **)ppvVar8[3];
      ppvVar13 = ppvVar18;
      if (((*(int *)((int)*ppvVar8 + 0x18) << 0x1f < 0) && (ppvVar8[1] != (void *)0x0)) &&
         (ppvVar13 = ppvVar8, ppvVar8 != ppvVar18)) {
        pvVar14 = ppvVar8[4];
        if (ppvVar8 == local_38) {
          local_38 = ppvVar33;
        }
        ppvVar32 = ppvVar33;
        if (pvVar14 != (void *)0x0) {
          *(void ***)((int)pvVar14 + 0xc) = ppvVar33;
          ppvVar32 = (void **)ppvVar8[3];
        }
        if (ppvVar32 != (void **)0x0) {
          ppvVar32[4] = pvVar14;
        }
        ppvVar18[3] = ppvVar8;
        ppvVar8[4] = ppvVar18;
        ppvVar8[3] = (void *)0x0;
      }
    } while ((ppvVar8 != local_34) &&
            (ppvVar8 = ppvVar33, ppvVar18 = ppvVar13, ppvVar33 != (void **)0x0));
    if (ppvVar13 == (void **)0x0) {
LAB_00080c76:
      local_34 = (void **)0x0;
    }
    else {
      ppvVar8 = local_38;
      local_34 = ppvVar13;
      ppvVar18 = ppvVar13;
      if (local_38 == (void **)0x0) goto LAB_00080bb4;
      do {
        ppvVar33 = (void **)local_38[3];
        local_34 = ppvVar18;
        if (((*(int *)((int)*local_38 + 0x10) << 0x1d < 0) && (local_38[1] != (void *)0x0)) &&
           (local_34 = local_38, local_38 != ppvVar18)) {
          pvVar14 = local_38[4];
          if (local_38 == ppvVar8) {
            ppvVar8 = ppvVar33;
          }
          ppvVar32 = ppvVar33;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar33;
            ppvVar32 = (void **)local_38[3];
          }
          if (ppvVar32 != (void **)0x0) {
            ppvVar32[4] = pvVar14;
          }
          ppvVar18[3] = local_38;
          local_38[4] = ppvVar18;
          local_38[3] = (void *)0x0;
        }
      } while ((ppvVar13 != local_38) &&
              (local_38 = ppvVar33, ppvVar18 = local_34, ppvVar33 != (void **)0x0));
      local_38 = ppvVar8;
      if (local_34 == (void **)0x0) goto LAB_00080c76;
      ppvVar18 = ppvVar8;
      ppvVar13 = local_34;
      if (ppvVar8 == (void **)0x0) goto LAB_00080bb4;
      do {
        ppvVar32 = (void **)ppvVar18[3];
        ppvVar33 = ppvVar13;
        if (((*(int *)((int)*ppvVar18 + 0x10) << 0x1b < 0) && (ppvVar18[1] != (void *)0x0)) &&
           (ppvVar33 = ppvVar18, ppvVar18 != ppvVar13)) {
          pvVar14 = ppvVar18[4];
          if (ppvVar18 == ppvVar8) {
            ppvVar8 = ppvVar32;
          }
          ppvVar34 = ppvVar32;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar32;
            ppvVar34 = (void **)ppvVar18[3];
          }
          if (ppvVar34 != (void **)0x0) {
            ppvVar34[4] = pvVar14;
          }
          ppvVar13[3] = ppvVar18;
          ppvVar18[4] = ppvVar13;
          ppvVar18[3] = (void *)0x0;
        }
      } while ((ppvVar18 != local_34) &&
              (ppvVar18 = ppvVar32, ppvVar13 = ppvVar33, ppvVar32 != (void **)0x0));
      local_38 = ppvVar8;
      if (ppvVar33 == (void **)0x0) goto LAB_00080c76;
      ppvVar18 = ppvVar8;
      local_34 = ppvVar33;
      ppvVar13 = ppvVar33;
      if (ppvVar8 == (void **)0x0) goto LAB_00080bb4;
      do {
        ppvVar34 = (void **)ppvVar18[3];
        ppvVar32 = ppvVar13;
        if (((*(int *)((int)*ppvVar18 + 0xc) << 0x1f < 0) && (ppvVar18[1] != (void *)0x0)) &&
           (ppvVar32 = ppvVar18, ppvVar18 != ppvVar13)) {
          pvVar14 = ppvVar18[4];
          if (ppvVar18 == ppvVar8) {
            ppvVar8 = ppvVar34;
          }
          ppvVar35 = ppvVar34;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar34;
            ppvVar35 = (void **)ppvVar18[3];
          }
          if (ppvVar35 != (void **)0x0) {
            ppvVar35[4] = pvVar14;
          }
          ppvVar13[3] = ppvVar18;
          ppvVar18[4] = ppvVar13;
          ppvVar18[3] = (void *)0x0;
        }
      } while ((ppvVar33 != ppvVar18) &&
              (ppvVar18 = ppvVar34, ppvVar13 = ppvVar32, ppvVar34 != (void **)0x0));
      local_38 = ppvVar8;
      if (ppvVar32 == (void **)0x0) goto LAB_00080c76;
      local_34 = ppvVar32;
      if (ppvVar8 == (void **)0x0) goto LAB_00080bb4;
      do {
        ppvVar18 = (void **)ppvVar8[3];
        if (((*(int *)((int)*ppvVar8 + 0xc) << 0x17 < 0) && (ppvVar8[1] != (void *)0x0)) &&
           (local_34 != ppvVar8)) {
          pvVar14 = ppvVar8[4];
          if (local_38 == ppvVar8) {
            local_38 = ppvVar18;
          }
          ppvVar13 = ppvVar18;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar18;
            ppvVar13 = (void **)ppvVar8[3];
          }
          if (ppvVar13 != (void **)0x0) {
            ppvVar13[4] = pvVar14;
          }
          local_34[3] = ppvVar8;
          ppvVar8[4] = local_34;
          ppvVar8[3] = (void *)0x0;
          local_34 = ppvVar8;
        }
      } while ((ppvVar8 != ppvVar32) && (ppvVar8 = ppvVar18, ppvVar18 != (void **)0x0));
      if (local_34 == (void **)0x0) goto LAB_00080c76;
      ppvVar18 = local_38;
      ppvVar8 = local_34;
      if (local_38 == (void **)0x0) goto LAB_00080bb4;
      do {
        ppvVar13 = (void **)ppvVar18[3];
        if (((*(int *)((int)*ppvVar18 + 0xc) << 0x1b < 0) && (ppvVar18[1] != (void *)0x0)) &&
           (ppvVar8 != ppvVar18)) {
          pvVar14 = ppvVar18[4];
          if (local_38 == ppvVar18) {
            local_38 = ppvVar13;
          }
          ppvVar33 = ppvVar13;
          if (pvVar14 != (void *)0x0) {
            *(void ***)((int)pvVar14 + 0xc) = ppvVar13;
            ppvVar33 = (void **)ppvVar18[3];
          }
          if (ppvVar33 != (void **)0x0) {
            ppvVar33[4] = pvVar14;
          }
          ppvVar8[3] = ppvVar18;
          ppvVar18[4] = ppvVar8;
          ppvVar18[3] = (void *)0x0;
          ppvVar8 = ppvVar18;
        }
      } while ((ppvVar18 != local_34) && (ppvVar18 = ppvVar13, ppvVar13 != (void **)0x0));
      local_34 = ppvVar8;
      ppvVar18 = local_38;
      if (ppvVar8 != (void **)0x0) {
        do {
          if (ppvVar18 == (void **)0x0) break;
          ppvVar13 = (void **)ppvVar18[3];
          if (((*(int *)((int)*ppvVar18 + 0x14) << 0x1d < 0) && (ppvVar18[1] != (void *)0x0)) &&
             (local_34 != ppvVar18)) {
            pvVar14 = ppvVar18[4];
            if (local_38 == ppvVar18) {
              local_38 = ppvVar13;
            }
            ppvVar33 = ppvVar13;
            if (pvVar14 != (void *)0x0) {
              *(void ***)((int)pvVar14 + 0xc) = ppvVar13;
              ppvVar33 = (void **)ppvVar18[3];
            }
            if (ppvVar33 != (void **)0x0) {
              ppvVar33[4] = pvVar14;
            }
            local_34[3] = ppvVar18;
            ppvVar18[4] = local_34;
            ppvVar18[3] = (void *)0x0;
            local_34 = ppvVar18;
          }
          bVar1 = ppvVar8 != ppvVar18;
          ppvVar18 = ppvVar13;
        } while (bVar1);
      }
    }
  }
  st = (_STACK *)ssl_cipher_strength_sort(&local_38,&local_34);
  if (st != (_STACK *)0x0) {
    ppvVar8 = local_38;
    ppvVar18 = local_34;
    if (local_38 != (void **)0x0) {
      do {
        if (ppvVar18 == (void **)0x0) break;
        ppvVar13 = (void **)ppvVar18[4];
        if (ppvVar18[1] != (void *)0x0) {
          if (ppvVar8 != ppvVar18) {
            pvVar14 = ppvVar18[3];
            if (local_34 == ppvVar18) {
              local_34 = ppvVar13;
            }
            ppvVar33 = ppvVar13;
            if (pvVar14 != (void *)0x0) {
              *(void ***)((int)pvVar14 + 0x10) = ppvVar13;
              ppvVar33 = (void **)ppvVar18[4];
            }
            if (ppvVar33 != (void **)0x0) {
              ppvVar33[3] = pvVar14;
            }
            ppvVar8[4] = ppvVar18;
            ppvVar18[3] = ppvVar8;
            ppvVar18[4] = (void *)0x0;
            ppvVar8 = ppvVar18;
          }
          ppvVar18[1] = (void *)0x0;
        }
        bVar1 = ppvVar18 != local_38;
        ppvVar18 = ppvVar13;
      } while (bVar1);
    }
    local_38 = ppvVar8;
    ppvVar8 = (void **)CRYPTO_malloc((iVar15 + 0x55) * 4,DAT_00080cb8,0x631);
    if (ppvVar8 == (void **)0x0) {
      CRYPTO_free(ptr);
      iVar15 = 0x634;
LAB_00080c80:
      ERR_put_error(0x14,0xa6,0x41,DAT_00080cb8,iVar15);
      return (_STACK *)0x0;
    }
    ppvVar18 = ppvVar8;
    pvVar14 = DAT_00080cd0;
    for (ppvVar13 = local_38; DAT_00080cd0 = pvVar14, ppvVar13 != (void **)0x0;
        ppvVar13 = (void **)ppvVar13[3]) {
      *ppvVar18 = *ppvVar13;
      ppvVar18 = ppvVar18 + 1;
      pvVar14 = DAT_00080cd0;
    }
    iVar15 = 0;
    pvVar19 = pvVar14;
    do {
      iVar36 = iVar15 + 1;
      HintPreloadData((int)pvVar14 + iVar15 * 0x30 + 0x15c);
      ppvVar13 = ppvVar18;
      if ((((*(uint *)((int)pvVar19 + 0xc) == 0) || ((*(uint *)((int)pvVar19 + 0xc) & uVar20) != 0))
          && (((*(uint *)((int)pvVar19 + 0x10) == 0 ||
               ((*(uint *)((int)pvVar19 + 0x10) & ~uVar30) != 0)) &&
              ((*(uint *)((int)pvVar19 + 0x14) == 0 ||
               ((*(uint *)((int)pvVar19 + 0x14) & ~uVar31) != 0)))))) &&
         ((*(uint *)((int)pvVar19 + 0x18) == 0 || ((*(uint *)((int)pvVar19 + 0x18) & ~uVar10) != 0))
         )) {
        ppvVar13 = ppvVar18 + 1;
        *ppvVar18 = pvVar19;
      }
      pvVar19 = (void *)((int)pvVar19 + 0x30);
      iVar15 = iVar36;
      ppvVar18 = ppvVar13;
    } while (iVar36 != 0x54);
    *ppvVar13 = (void *)0x0;
    iVar15 = strncmp(local_48,DAT_00080cbc,7);
    if (iVar15 == 0) {
      iVar15 = ssl_cipher_process_rulestr(DAT_00080cc8,&local_38,&local_34,ppvVar8);
      if (local_48[7] == ':') {
        local_48 = local_48 + 8;
      }
      else {
        local_48 = local_48 + 7;
      }
      if (iVar15 == 0) {
        CRYPTO_free(ppvVar8);
        goto LAB_00080bde;
      }
    }
    if (*local_48 == '\0') {
      CRYPTO_free(ppvVar8);
    }
    else {
      iVar15 = ssl_cipher_process_rulestr(local_48,&local_38,&local_34,ppvVar8);
      CRYPTO_free(ppvVar8);
      if (iVar15 == 0) {
LAB_00080bde:
        CRYPTO_free(ptr);
        return (_STACK *)0x0;
      }
    }
    st = sk_new_null();
    ppvVar8 = local_38;
    if (st != (_STACK *)0x0) {
      for (; ppvVar8 != (void **)0x0; ppvVar8 = (void **)ppvVar8[3]) {
        while (ppvVar8[1] == (void *)0x0) {
          ppvVar8 = (void **)ppvVar8[3];
          if (ppvVar8 == (void **)0x0) goto LAB_00080b5e;
        }
        sk_push(st,*ppvVar8);
      }
LAB_00080b5e:
      CRYPTO_free(ptr);
      p_Var9 = sk_dup(st);
      if (p_Var9 != (_STACK *)0x0) {
        if (*param_2 != (_STACK *)0x0) {
          sk_free(*param_2);
        }
        *param_2 = st;
        if (*param_3 != (_STACK *)0x0) {
          sk_free(*param_3);
        }
        *param_3 = p_Var9;
        sk_set_cmp_func(p_Var9,DAT_00080cc0);
        sk_sort(*param_3);
        return st;
      }
      sk_free(st);
      return (_STACK *)0x0;
    }
  }
  CRYPTO_free(ptr);
  return st;
}

