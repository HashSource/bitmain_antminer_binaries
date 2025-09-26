
_STACK * ssl_create_cipher_list
                   (int param_1,undefined4 *param_2,undefined4 *param_3,char *param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *ptr;
  int *piVar7;
  _STACK *st;
  _STACK *p_Var8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  undefined1 *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  int *piVar30;
  int *piVar31;
  int *piVar32;
  int *piVar33;
  int iVar34;
  char *local_48;
  int *local_38;
  int *local_34;
  ENGINE *local_30;
  int local_2c [2];
  
  local_38 = (int *)0x0;
  local_34 = (int *)0x0;
  uVar28 = (uint)(param_2 == (undefined4 *)0x0 || param_4 == (char *)0x0);
  if (param_2 == (undefined4 *)0x0 || param_4 == (char *)0x0) {
    return (_STACK *)0x0;
  }
  if (param_3 == (undefined4 *)0x0) {
    return (_STACK *)0x0;
  }
  uVar2 = strcmp(param_4,"SUITEB128");
  local_48 = param_4;
  if (uVar2 == 0) {
LAB_00119c86:
    uVar18 = 0x30000;
    uVar28 = uVar2;
LAB_00119c8a:
    *(uint *)(param_5 + 0x38) = *(uint *)(param_5 + 0x38) & 0xfffcffff | uVar18;
LAB_00119c94:
    iVar13 = *(int *)(*(int *)(param_1 + 100) + 0x38);
    if (-1 < iVar13 << 0x1b) {
      if (iVar13 << 0x1c < 0) {
        iVar34 = 0x596;
        iVar13 = 0x183;
      }
      else {
        iVar34 = 0x599;
        iVar13 = 0x17b;
      }
      ERR_put_error(0x14,0x14b,iVar13,"ssl_ciph.c",iVar34);
      return (_STACK *)0x0;
    }
    if (uVar18 == 0x20000) {
      local_48 = "ECDHE-ECDSA-AES256-GCM-SHA384";
    }
    else if (uVar18 == 0x30000) {
      local_48 = "ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384";
      if (uVar28 != 0) {
        local_48 = "ECDHE-ECDSA-AES256-GCM-SHA384";
      }
    }
    else if (uVar18 == 0x10000) {
      local_48 = "ECDHE-ECDSA-AES128-GCM-SHA256";
    }
    *(undefined4 *)(param_5 + 0x34) = 1;
  }
  else {
    iVar13 = strcmp(param_4,"SUITEB128ONLY");
    if (iVar13 == 0) {
      uVar18 = 0x10000;
      uVar28 = 0;
      goto LAB_00119c8a;
    }
    iVar13 = strcmp(param_4,"SUITEB128C2");
    if (iVar13 == 0) {
      uVar2 = 1;
      goto LAB_00119c86;
    }
    iVar13 = strcmp(param_4,"SUITEB192");
    if (iVar13 == 0) {
      uVar18 = 0x20000;
      uVar28 = 0;
      goto LAB_00119c8a;
    }
    uVar18 = *(uint *)(param_5 + 0x38) & 0x30000;
    if (uVar18 != 0) goto LAB_00119c94;
  }
  local_30 = (ENGINE *)0x0;
  local_2c[0] = 0;
  pEVar3 = EVP_PKEY_asn1_find_str(&local_30,"gost94",-1);
  if (pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(local_2c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3);
  }
  if (local_30 != (ENGINE *)0x0) {
    ENGINE_finish(local_30);
  }
  local_30 = (ENGINE *)0x0;
  if (local_2c[0] == 0) {
    uVar28 = 0x120;
  }
  else {
    uVar28 = 0x20;
  }
  local_2c[0] = 0;
  pEVar3 = EVP_PKEY_asn1_find_str(&local_30,"gost2001",-1);
  if (pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(local_2c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3);
  }
  if (local_30 != (ENGINE *)0x0) {
    ENGINE_finish(local_30);
  }
  if (local_2c[0] == 0) {
    uVar28 = uVar28 | 0x200;
  }
  if ((uVar28 & 0x300) == 0x300) {
    uVar2 = 0x210;
    uVar18 = 0xfffffdef;
  }
  else {
    uVar2 = 0x10;
    uVar18 = 0xffffffef;
  }
  if (ssl_cipher_methods._4_4_ == 0) {
    uVar9 = 2;
  }
  else {
    uVar9 = 0;
  }
  if (ssl_cipher_methods._0_4_ == 0) {
    uVar9 = uVar9 | 1;
  }
  if (ssl_cipher_methods._8_4_ == 0) {
    uVar4 = 4;
  }
  else {
    uVar4 = 0;
  }
  if (ssl_cipher_methods._12_4_ == 0) {
    uVar19 = 8;
  }
  else {
    uVar19 = 0;
  }
  if (ssl_cipher_methods._16_4_ == 0) {
    uVar22 = 0x10;
  }
  else {
    uVar22 = 0;
  }
  if (ssl_cipher_methods._24_4_ == 0) {
    uVar10 = 0x40;
  }
  else {
    uVar10 = 0;
  }
  if (ssl_cipher_methods._28_4_ == 0) {
    uVar14 = 0x80;
  }
  else {
    uVar14 = 0;
  }
  if (ssl_cipher_methods._48_4_ == 0) {
    uVar5 = 0x1000;
  }
  else {
    uVar5 = 0;
  }
  if (ssl_cipher_methods._32_4_ == 0) {
    uVar11 = 0x100;
  }
  else {
    uVar11 = 0;
  }
  if (ssl_cipher_methods._52_4_ == 0) {
    uVar20 = 0x2000;
  }
  else {
    uVar20 = 0;
  }
  if (ssl_cipher_methods._36_4_ == 0) {
    uVar6 = 0x200;
  }
  else {
    uVar6 = 0;
  }
  if (ssl_digest_methods._4_4_ == 0) {
    uVar23 = 2;
  }
  else {
    uVar23 = 0;
  }
  if (ssl_digest_methods._20_4_ == 0) {
    uVar21 = 0x20;
  }
  else {
    uVar21 = 0;
  }
  if (ssl_digest_methods._0_4_ == 0) {
    uVar23 = uVar23 | 1;
  }
  if (ssl_digest_methods._16_4_ == 0) {
    uVar24 = 0x10;
  }
  else {
    uVar24 = 0;
  }
  if (ssl_cipher_methods._44_4_ == 0) {
    uVar29 = 0x800;
  }
  else {
    uVar29 = 0;
  }
  if (ssl_cipher_methods._40_4_ == 0) {
    uVar15 = 0x400;
  }
  else {
    uVar15 = 0;
  }
  if (ssl_digest_methods._8_4_ == 0) {
    uVar25 = 4;
  }
  else {
    uVar25 = 0;
  }
  uVar29 = uVar15 | uVar6 | uVar11 | uVar9 | uVar4 | uVar19 | uVar22 | uVar10 | uVar14 | uVar5 |
                                     uVar20 | uVar29;
  if ((ssl_digest_methods._12_4_ == 0) || (DAT_00248508 == 0)) {
    uVar9 = 8;
  }
  else {
    uVar9 = 0;
  }
  uVar9 = uVar9 | uVar23 | uVar24 | uVar21 | uVar25;
  iVar13 = (**(code **)(param_1 + 0x54))();
  ptr = (int *)CRYPTO_malloc(iVar13 * 0x14,"ssl_ciph.c",0x5e0);
  if (ptr == (int *)0x0) {
    iVar13 = 0x5e2;
    goto LAB_0011a614;
  }
  if (iVar13 < 1) {
LAB_0011a582:
    if (local_34 == (int *)0x0) goto LAB_0011a60a;
    piVar7 = local_38;
    piVar16 = local_34;
    if (local_38 != (int *)0x0) goto LAB_0011a012;
LAB_0011a548:
    local_38 = (int *)0x0;
  }
  else {
    iVar27 = 0;
    iVar34 = 0;
    do {
      piVar7 = (int *)(**(code **)(param_1 + 0x58))(iVar27);
      iVar27 = iVar27 + 1;
      iVar26 = iVar34;
      if (((((piVar7 != (int *)0x0) && (*piVar7 != 0)) && ((uVar2 & piVar7[3]) == 0)) &&
          (((uVar28 & piVar7[4]) == 0 && ((uVar29 & piVar7[5]) == 0)))) &&
         ((uVar9 & piVar7[6]) == 0)) {
        iVar26 = iVar34 + 1;
        ptr[iVar34 * 5 + 3] = 0;
        ptr[iVar34 * 5 + 4] = 0;
        ptr[iVar34 * 5] = (int)piVar7;
        ptr[iVar34 * 5 + 1] = 0;
      }
      iVar34 = iVar26;
    } while (iVar27 != iVar13);
    if (iVar26 == 0) goto LAB_0011a582;
    ptr[4] = 0;
    local_34 = ptr;
    if (iVar26 != 1) {
      iVar34 = iVar26 + -1;
      ptr[3] = (int)(ptr + 5);
      if (iVar34 != 1) {
        iVar27 = 1;
        piVar7 = ptr + 10;
        do {
          iVar27 = iVar27 + 1;
          piVar7[-2] = (int)piVar7;
          piVar7[-1] = (int)(piVar7 + -10);
          piVar7 = piVar7 + 5;
        } while (iVar27 != iVar34);
      }
      (ptr + iVar34 * 5)[4] = (int)(ptr + iVar26 * 5 + -10);
      local_34 = ptr + iVar34 * 5;
    }
    local_34[3] = 0;
    local_38 = ptr;
    piVar7 = ptr;
    piVar16 = local_34;
LAB_0011a012:
    do {
      piVar12 = (int *)piVar7[3];
      if ((*(int *)(*piVar7 + 0xc) << 0x18 < 0) && (piVar7[1] == 0)) {
        if (piVar7 != local_34) {
          iVar34 = piVar7[4];
          if (piVar7 == local_38) {
            local_38 = piVar12;
          }
          piVar31 = piVar12;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar12;
            piVar31 = (int *)piVar7[3];
          }
          if (piVar31 != (int *)0x0) {
            piVar31[4] = iVar34;
          }
          local_34[3] = (int)piVar7;
          piVar7[4] = (int)local_34;
          piVar7[3] = 0;
        }
        piVar7[1] = 1;
        local_34 = piVar7;
      }
    } while ((piVar16 != piVar7) && (piVar7 = piVar12, piVar12 != (int *)0x0));
    piVar7 = local_38;
    piVar16 = local_34;
    if (local_38 == (int *)0x0) goto LAB_0011a548;
    do {
      piVar12 = (int *)piVar16[4];
      if ((*(int *)(*piVar16 + 0xc) << 0x18 < 0) && (piVar16[1] != 0)) {
        if (piVar16 != piVar7) {
          iVar34 = piVar16[3];
          if (piVar16 == local_34) {
            local_34 = piVar12;
          }
          piVar31 = piVar12;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0x10) = piVar12;
            piVar31 = (int *)piVar16[4];
          }
          if (piVar31 != (int *)0x0) {
            piVar31[3] = iVar34;
          }
          piVar7[4] = (int)piVar16;
          piVar16[3] = (int)piVar7;
          piVar16[4] = 0;
        }
        piVar16[1] = 0;
        piVar7 = piVar16;
      }
    } while ((piVar16 != local_38) && (piVar16 = piVar12, piVar12 != (int *)0x0));
    local_38 = piVar7;
    if (local_34 == (int *)0x0) goto LAB_0011a60a;
    piVar16 = local_34;
    piVar12 = piVar7;
    if (piVar7 == (int *)0x0) goto LAB_0011a548;
    do {
      piVar31 = (int *)piVar7[3];
      if (((*(uint *)(*piVar7 + 0x14) & 0x30c0) != 0) && (piVar7[1] == 0)) {
        if (piVar7 != piVar16) {
          iVar34 = piVar7[4];
          if (piVar7 == piVar12) {
            piVar12 = piVar31;
          }
          piVar30 = piVar31;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar31;
            piVar30 = (int *)piVar7[3];
          }
          if (piVar30 != (int *)0x0) {
            piVar30[4] = iVar34;
          }
          piVar16[3] = (int)piVar7;
          piVar7[4] = (int)piVar16;
          piVar7[3] = 0;
        }
        piVar7[1] = 1;
        piVar16 = piVar7;
      }
    } while ((local_34 != piVar7) && (piVar7 = piVar31, piVar31 != (int *)0x0));
    piVar7 = piVar12;
    local_34 = piVar16;
    if (piVar12 == (int *)0x0) goto LAB_0011a548;
    do {
      piVar31 = (int *)piVar12[3];
      if (piVar12[1] == 0) {
        if (piVar12 != local_34) {
          iVar34 = piVar12[4];
          if (piVar12 == piVar7) {
            piVar7 = piVar31;
          }
          piVar30 = piVar31;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar31;
            piVar30 = (int *)piVar12[3];
          }
          if (piVar30 != (int *)0x0) {
            piVar30[4] = iVar34;
          }
          local_34[3] = (int)piVar12;
          piVar12[4] = (int)local_34;
          piVar12[3] = 0;
        }
        piVar12[1] = 1;
        local_34 = piVar12;
      }
    } while ((piVar16 != piVar12) && (piVar12 = piVar31, piVar31 != (int *)0x0));
    local_38 = piVar7;
    piVar16 = local_34;
    if (piVar7 == (int *)0x0) goto LAB_0011a548;
    do {
      piVar31 = (int *)piVar7[3];
      piVar12 = piVar16;
      if (((*(int *)(*piVar7 + 0x18) << 0x1f < 0) && (piVar7[1] != 0)) &&
         (piVar12 = piVar7, piVar7 != piVar16)) {
        iVar34 = piVar7[4];
        if (piVar7 == local_38) {
          local_38 = piVar31;
        }
        piVar30 = piVar31;
        if (iVar34 != 0) {
          *(int **)(iVar34 + 0xc) = piVar31;
          piVar30 = (int *)piVar7[3];
        }
        if (piVar30 != (int *)0x0) {
          piVar30[4] = iVar34;
        }
        piVar16[3] = (int)piVar7;
        piVar7[4] = (int)piVar16;
        piVar7[3] = 0;
      }
    } while ((piVar7 != local_34) && (piVar7 = piVar31, piVar16 = piVar12, piVar31 != (int *)0x0));
    if (piVar12 == (int *)0x0) {
LAB_0011a60a:
      local_34 = (int *)0x0;
    }
    else {
      piVar7 = local_38;
      local_34 = piVar12;
      piVar16 = piVar12;
      if (local_38 == (int *)0x0) goto LAB_0011a548;
      do {
        piVar31 = (int *)local_38[3];
        local_34 = piVar16;
        if (((*(int *)(*local_38 + 0x10) << 0x1d < 0) && (local_38[1] != 0)) &&
           (local_34 = local_38, local_38 != piVar16)) {
          iVar34 = local_38[4];
          if (local_38 == piVar7) {
            piVar7 = piVar31;
          }
          piVar30 = piVar31;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar31;
            piVar30 = (int *)local_38[3];
          }
          if (piVar30 != (int *)0x0) {
            piVar30[4] = iVar34;
          }
          piVar16[3] = (int)local_38;
          local_38[4] = (int)piVar16;
          local_38[3] = 0;
        }
      } while ((piVar12 != local_38) &&
              (local_38 = piVar31, piVar16 = local_34, piVar31 != (int *)0x0));
      local_38 = piVar7;
      if (local_34 == (int *)0x0) goto LAB_0011a60a;
      piVar16 = piVar7;
      piVar12 = local_34;
      if (piVar7 == (int *)0x0) goto LAB_0011a548;
      do {
        piVar30 = (int *)piVar16[3];
        piVar31 = piVar12;
        if (((*(int *)(*piVar16 + 0x10) << 0x1b < 0) && (piVar16[1] != 0)) &&
           (piVar31 = piVar16, piVar16 != piVar12)) {
          iVar34 = piVar16[4];
          if (piVar16 == piVar7) {
            piVar7 = piVar30;
          }
          piVar32 = piVar30;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar30;
            piVar32 = (int *)piVar16[3];
          }
          if (piVar32 != (int *)0x0) {
            piVar32[4] = iVar34;
          }
          piVar12[3] = (int)piVar16;
          piVar16[4] = (int)piVar12;
          piVar16[3] = 0;
        }
      } while ((piVar16 != local_34) &&
              (piVar16 = piVar30, piVar12 = piVar31, piVar30 != (int *)0x0));
      local_38 = piVar7;
      if (piVar31 == (int *)0x0) goto LAB_0011a60a;
      piVar16 = piVar7;
      local_34 = piVar31;
      piVar12 = piVar31;
      if (piVar7 == (int *)0x0) goto LAB_0011a548;
      do {
        piVar32 = (int *)piVar16[3];
        piVar30 = piVar12;
        if (((*(int *)(*piVar16 + 0xc) << 0x1f < 0) && (piVar16[1] != 0)) &&
           (piVar30 = piVar16, piVar16 != piVar12)) {
          iVar34 = piVar16[4];
          if (piVar16 == piVar7) {
            piVar7 = piVar32;
          }
          piVar33 = piVar32;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar32;
            piVar33 = (int *)piVar16[3];
          }
          if (piVar33 != (int *)0x0) {
            piVar33[4] = iVar34;
          }
          piVar12[3] = (int)piVar16;
          piVar16[4] = (int)piVar12;
          piVar16[3] = 0;
        }
      } while ((piVar31 != piVar16) && (piVar16 = piVar32, piVar12 = piVar30, piVar32 != (int *)0x0)
              );
      local_38 = piVar7;
      if (piVar30 == (int *)0x0) goto LAB_0011a60a;
      local_34 = piVar30;
      if (piVar7 == (int *)0x0) goto LAB_0011a548;
      do {
        piVar16 = (int *)piVar7[3];
        if (((*(int *)(*piVar7 + 0xc) << 0x17 < 0) && (piVar7[1] != 0)) && (local_34 != piVar7)) {
          iVar34 = piVar7[4];
          if (local_38 == piVar7) {
            local_38 = piVar16;
          }
          piVar12 = piVar16;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar16;
            piVar12 = (int *)piVar7[3];
          }
          if (piVar12 != (int *)0x0) {
            piVar12[4] = iVar34;
          }
          local_34[3] = (int)piVar7;
          piVar7[4] = (int)local_34;
          piVar7[3] = 0;
          local_34 = piVar7;
        }
      } while ((piVar7 != piVar30) && (piVar7 = piVar16, piVar16 != (int *)0x0));
      if (local_34 == (int *)0x0) goto LAB_0011a60a;
      piVar16 = local_38;
      piVar7 = local_34;
      if (local_38 == (int *)0x0) goto LAB_0011a548;
      do {
        piVar12 = (int *)piVar16[3];
        if (((*(int *)(*piVar16 + 0xc) << 0x1b < 0) && (piVar16[1] != 0)) && (piVar7 != piVar16)) {
          iVar34 = piVar16[4];
          if (local_38 == piVar16) {
            local_38 = piVar12;
          }
          piVar31 = piVar12;
          if (iVar34 != 0) {
            *(int **)(iVar34 + 0xc) = piVar12;
            piVar31 = (int *)piVar16[3];
          }
          if (piVar31 != (int *)0x0) {
            piVar31[4] = iVar34;
          }
          piVar7[3] = (int)piVar16;
          piVar16[4] = (int)piVar7;
          piVar16[3] = 0;
          piVar7 = piVar16;
        }
      } while ((piVar16 != local_34) && (piVar16 = piVar12, piVar12 != (int *)0x0));
      local_34 = piVar7;
      piVar16 = local_38;
      if (piVar7 != (int *)0x0) {
        do {
          if (piVar16 == (int *)0x0) break;
          piVar12 = (int *)piVar16[3];
          if (((*(int *)(*piVar16 + 0x14) << 0x1d < 0) && (piVar16[1] != 0)) &&
             (local_34 != piVar16)) {
            iVar34 = piVar16[4];
            if (local_38 == piVar16) {
              local_38 = piVar12;
            }
            piVar31 = piVar12;
            if (iVar34 != 0) {
              *(int **)(iVar34 + 0xc) = piVar12;
              piVar31 = (int *)piVar16[3];
            }
            if (piVar31 != (int *)0x0) {
              piVar31[4] = iVar34;
            }
            local_34[3] = (int)piVar16;
            piVar16[4] = (int)local_34;
            piVar16[3] = 0;
            local_34 = piVar16;
          }
          bVar1 = piVar7 != piVar16;
          piVar16 = piVar12;
        } while (bVar1);
      }
    }
  }
  st = (_STACK *)ssl_cipher_strength_sort(&local_38,&local_34);
  if (st != (_STACK *)0x0) {
    piVar7 = local_38;
    piVar16 = local_34;
    if (local_38 != (int *)0x0) {
      do {
        if (piVar16 == (int *)0x0) break;
        piVar12 = (int *)piVar16[4];
        if (piVar16[1] != 0) {
          if (piVar7 != piVar16) {
            iVar34 = piVar16[3];
            if (local_34 == piVar16) {
              local_34 = piVar12;
            }
            piVar31 = piVar12;
            if (iVar34 != 0) {
              *(int **)(iVar34 + 0x10) = piVar12;
              piVar31 = (int *)piVar16[4];
            }
            if (piVar31 != (int *)0x0) {
              piVar31[3] = iVar34;
            }
            piVar7[4] = (int)piVar16;
            piVar16[3] = (int)piVar7;
            piVar16[4] = 0;
            piVar7 = piVar16;
          }
          piVar16[1] = 0;
        }
        bVar1 = piVar16 != local_38;
        piVar16 = piVar12;
      } while (bVar1);
    }
    local_38 = piVar7;
    piVar7 = (int *)CRYPTO_malloc((iVar13 + 0x55) * 4,"ssl_ciph.c",0x631);
    if (piVar7 == (int *)0x0) {
      CRYPTO_free(ptr);
      iVar13 = 0x634;
LAB_0011a614:
      ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",iVar13);
      return (_STACK *)0x0;
    }
    piVar16 = piVar7;
    for (piVar12 = local_38; piVar12 != (int *)0x0; piVar12 = (int *)piVar12[3]) {
      *piVar16 = *piVar12;
      piVar16 = piVar16 + 1;
    }
    puVar17 = cipher_aliases;
    iVar13 = 0;
    do {
      iVar34 = iVar13 + 1;
      HintPreloadData(iVar13 * 0x30 + 0x1f0cc0);
      piVar12 = piVar16;
      if ((((*(uint *)(puVar17 + 0xc) == 0) || ((*(uint *)(puVar17 + 0xc) & uVar18) != 0)) &&
          (((*(uint *)(puVar17 + 0x10) == 0 || ((*(uint *)(puVar17 + 0x10) & ~uVar28) != 0)) &&
           ((*(uint *)(puVar17 + 0x14) == 0 || ((*(uint *)(puVar17 + 0x14) & ~uVar29) != 0)))))) &&
         ((*(uint *)(puVar17 + 0x18) == 0 || ((*(uint *)(puVar17 + 0x18) & ~uVar9) != 0)))) {
        piVar12 = piVar16 + 1;
        *piVar16 = (int)puVar17;
      }
      puVar17 = puVar17 + 0x30;
      iVar13 = iVar34;
      piVar16 = piVar12;
    } while (iVar34 != 0x54);
    *piVar12 = 0;
    iVar13 = strncmp(local_48,"DEFAULT",7);
    if (iVar13 == 0) {
      iVar13 = ssl_cipher_process_rulestr
                         ("ALL:!EXPORT:!aNULL:!eNULL:!SSLv2",&local_38,&local_34,piVar7);
      if (local_48[7] == ':') {
        local_48 = local_48 + 8;
      }
      else {
        local_48 = local_48 + 7;
      }
      if (iVar13 == 0) {
        CRYPTO_free(piVar7);
        goto LAB_0011a572;
      }
    }
    if (*local_48 == '\0') {
      CRYPTO_free(piVar7);
    }
    else {
      iVar13 = ssl_cipher_process_rulestr(local_48,&local_38,&local_34,piVar7);
      CRYPTO_free(piVar7);
      if (iVar13 == 0) {
LAB_0011a572:
        CRYPTO_free(ptr);
        return (_STACK *)0x0;
      }
    }
    st = sk_new_null();
    piVar7 = local_38;
    if (st != (_STACK *)0x0) {
      for (; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[3]) {
        while (piVar7[1] == 0) {
          piVar7 = (int *)piVar7[3];
          if (piVar7 == (int *)0x0) goto LAB_0011a4f2;
        }
        sk_push(st,(void *)*piVar7);
      }
LAB_0011a4f2:
      CRYPTO_free(ptr);
      p_Var8 = sk_dup(st);
      if (p_Var8 != (_STACK *)0x0) {
        if ((_STACK *)*param_2 != (_STACK *)0x0) {
          sk_free((_STACK *)*param_2);
        }
        *param_2 = st;
        if ((_STACK *)*param_3 != (_STACK *)0x0) {
          sk_free((_STACK *)*param_3);
        }
        *param_3 = p_Var8;
        sk_set_cmp_func(p_Var8,(void *)0x114795);
        sk_sort((_STACK *)*param_3);
        return st;
      }
      sk_free(st);
      return (_STACK *)0x0;
    }
  }
  CRYPTO_free(ptr);
  return st;
}

