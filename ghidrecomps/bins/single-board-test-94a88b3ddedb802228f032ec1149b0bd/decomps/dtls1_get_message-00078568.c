
uint dtls1_get_message(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                      uint *param_6)

{
  undefined uVar1;
  undefined2 uVar2;
  undefined uVar3;
  undefined uVar4;
  ushort uVar5;
  uint *puVar6;
  uint *puVar7;
  pqueue pq;
  pitem *ppVar8;
  uint *ptr;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined *puVar13;
  uint uVar14;
  uint *puVar15;
  void *pvVar16;
  uint uVar17;
  uint *puVar18;
  undefined4 local_16c;
  int local_168;
  byte local_164;
  byte local_163;
  byte local_162;
  byte local_161;
  undefined local_160;
  undefined local_15f;
  byte local_15e;
  byte local_15d;
  byte local_15c;
  byte local_15b;
  byte local_15a;
  byte local_159;
  uint local_158 [8];
  uint local_138;
  uint local_134;
  uint local_130;
  undefined auStack_128 [260];
  
  iVar9 = param_1[0x16];
  if (*(int *)(iVar9 + 0x354) != 0) {
    *(undefined4 *)(iVar9 + 0x354) = 0;
    if ((param_4 < 0) || (*(int *)(iVar9 + 0x340) == param_4)) {
      uVar14 = *(uint *)(iVar9 + 0x33c);
      iVar9 = *(int *)(param_1[0xf] + 4);
      *param_6 = 1;
      param_1[0x11] = uVar14;
      param_1[0x10] = iVar9 + 0xc;
    }
    else {
      iVar9 = 0x1d7;
LAB_00078a50:
      uVar14 = 0xffffffff;
      ERR_put_error(0x14,0xfc,0xf4,DAT_00078b44,iVar9);
      ssl3_send_alert(param_1,2,10);
      *param_6 = 0;
    }
    return uVar14;
  }
  iVar9 = param_1[0x17];
  memset((void *)(iVar9 + 0x28c),0,0x2c);
LAB_000785ce:
  iVar11 = param_1[0x17];
LAB_000785d2:
  pq = *(pqueue *)(iVar11 + 0x244);
  *param_6 = 0;
  ppVar8 = pqueue_peek(pq);
  if (((ppVar8 != (pitem *)0x0) && (pvVar16 = ppVar8->data, *(int *)((int)pvVar16 + 0x30) == 0)) &&
     (*(short *)(param_1[0x17] + 0x228) == *(short *)((int)pvVar16 + 8))) {
    uVar14 = *(uint *)((int)pvVar16 + 0x10);
    pqueue_pop(*(pqueue *)(param_1[0x17] + 0x244));
    iVar11 = dtls1_preprocess_fragment(param_1,pvVar16,param_5);
    if (iVar11 == 0) {
      memcpy((void *)(*(int *)(param_1[0xf] + 4) + 0xc + *(int *)((int)pvVar16 + 0xc)),
             *(void **)((int)pvVar16 + 0x2c),*(size_t *)((int)pvVar16 + 0x10));
    }
    if (*(int *)((int)pvVar16 + 0x14) != 0) {
      EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)pvVar16 + 0x18));
      EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar16 + 0x1c));
    }
    if (*(void **)((int)pvVar16 + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar16 + 0x2c));
    }
    if (*(void **)((int)pvVar16 + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)pvVar16 + 0x30));
    }
    CRYPTO_free(pvVar16);
    pitem_free(ppVar8);
    if (iVar11 != 0) {
      uVar14 = 0xffffffff;
      ssl3_send_alert(param_1,2,iVar11);
      param_1[0x11] = 0;
      *param_6 = 0;
      goto LAB_00078ab6;
    }
    uVar12 = uVar14 + 3;
    *param_6 = 1;
LAB_0007877e:
    param_1[0x11] = uVar14;
    goto LAB_00078782;
  }
  uVar12 = *param_6;
  if (uVar12 != 0) {
    uVar12 = 3;
    uVar14 = 0;
    goto LAB_0007877e;
  }
  uVar14 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,&local_164,0xc,0);
  if ((int)uVar14 < 1) {
    param_1[6] = 3;
    uVar12 = uVar14 + 3;
    *param_6 = 0;
    goto LAB_00078782;
  }
  if (uVar14 == 0xc) {
    uVar5 = CONCAT11(local_160,local_15f);
    uVar17 = (uint)local_15a << 8 | (uint)local_15b << 0x10 | (uint)local_159;
    uVar14 = (uint)local_15d << 8 | (uint)local_15e << 0x10 | (uint)local_15c;
    local_158[1] = (uint)local_162 << 8 | (uint)local_163 << 0x10 | (uint)local_161;
    local_158[2] = (uint)uVar5;
    local_158[0] = (uint)local_164;
    local_158[3] = uVar14;
    local_158[4] = uVar17;
    local_158[5] = uVar12;
    local_158[6] = uVar12;
    local_158[7] = uVar12;
    local_138 = uVar12;
    local_134 = uVar12;
    local_130 = uVar12;
    if (*(uint *)(param_1[0x16] + 0x110) < uVar17) {
      ERR_put_error(0x14,0xfd,0x10f,DAT_00078b44,0x37c);
      iVar11 = 0x2f;
      goto LAB_00078890;
    }
    iVar11 = param_1[0x17];
    if ((*(ushort *)(iVar11 + 0x228) != uVar5) && ((*(int *)(iVar11 + 0x254) == 0 || (uVar5 != 1))))
    {
      if (local_158[1] < uVar17 + uVar14) goto LAB_000788b0;
      local_16c = 0;
      local_168 = (uint)CONCAT11(local_15f,local_160) << 0x10;
      ppVar8 = pqueue_find(*(pqueue *)(iVar11 + 0x244),(uchar *)&local_16c);
      if ((ppVar8 != (pitem *)0x0) && (uVar17 != local_158[1])) {
        ppVar8 = (pitem *)0x0;
      }
      iVar11 = param_1[0x17];
      uVar14 = (uint)*(ushort *)(iVar11 + 0x228);
      if ((((uVar14 < (local_158[2] & 0xffff)) && ((local_158[2] & 0xffff) <= uVar14 + 10)) &&
          (ppVar8 == (pitem *)0x0)) && ((uVar14 != 0 || ((char)local_158[0] != '\x14')))) {
        if (uVar17 != local_158[1]) goto LAB_000789f6;
        uVar14 = param_1[0x42];
        if (uVar14 < 0x454c) {
          uVar14 = 0x454c;
        }
        if ((uVar14 < uVar17) ||
           (ptr = (uint *)CRYPTO_malloc(0x34,DAT_00078b44,0xb5), ptr == (uint *)0x0)) {
LAB_000788b0:
          uVar12 = 2;
          uVar14 = 0xffffffff;
          goto LAB_000788b6;
        }
        if (uVar17 == 0) {
          ptr[0xb] = 0;
          ptr[0xc] = 0;
          puVar6 = ptr;
          puVar7 = local_158;
          do {
            puVar18 = puVar7;
            puVar15 = puVar6;
            uVar14 = puVar18[1];
            uVar12 = puVar18[2];
            uVar17 = puVar18[3];
            *puVar15 = *puVar18;
            puVar15[1] = uVar14;
            puVar15[2] = uVar12;
            puVar15[3] = uVar17;
            puVar6 = puVar15 + 4;
            puVar7 = puVar18 + 4;
          } while (puVar18 + 4 != &local_138);
          uVar14 = 0xffffffff;
          uVar12 = puVar18[5];
          uVar17 = puVar18[6];
          puVar15[4] = puVar18[4];
          puVar15[5] = uVar12;
          puVar15[6] = uVar17;
LAB_00078966:
          ppVar8 = pitem_new((uchar *)&local_16c,ptr);
          if (ppVar8 != (pitem *)0x0) {
            ppVar8 = pqueue_insert(*(pqueue *)(param_1[0x17] + 0x244),ppVar8);
            if (ppVar8 != (pitem *)0x0) goto LAB_000785ce;
            OpenSSLDie(DAT_00078b44,0x344,DAT_00078b48);
            iVar11 = param_1[0x17];
            goto LAB_000785d2;
          }
        }
        else {
          pvVar16 = CRYPTO_malloc(uVar17,DAT_00078b44,0xba);
          if (pvVar16 == (void *)0x0) {
            CRYPTO_free(ptr);
            goto LAB_000788b0;
          }
          ptr[0xb] = (uint)pvVar16;
          ptr[0xc] = 0;
          puVar6 = ptr;
          puVar7 = local_158;
          do {
            puVar18 = puVar7;
            puVar15 = puVar6;
            uVar14 = puVar18[1];
            uVar12 = puVar18[2];
            uVar10 = puVar18[3];
            *puVar15 = *puVar18;
            puVar15[1] = uVar14;
            puVar15[2] = uVar12;
            puVar15[3] = uVar10;
            puVar6 = puVar15 + 4;
            puVar7 = puVar18 + 4;
          } while (puVar18 + 4 != &local_138);
          uVar14 = puVar18[5];
          uVar12 = puVar18[6];
          puVar15[4] = puVar18[4];
          puVar15[5] = uVar14;
          puVar15[6] = uVar12;
          uVar14 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,ptr[0xb],uVar17,0);
          if (uVar17 == uVar14) {
            if (0 < (int)uVar14) goto LAB_00078966;
          }
          else {
            uVar14 = 0xffffffff;
          }
        }
        if (ptr[5] != 0) {
          EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ptr[6]);
          EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[7]);
        }
        if ((void *)ptr[0xb] != (void *)0x0) {
          CRYPTO_free((void *)ptr[0xb]);
        }
        if ((void *)ptr[0xc] != (void *)0x0) {
          CRYPTO_free((void *)ptr[0xc]);
        }
        CRYPTO_free(ptr);
        uVar12 = uVar14 + 3;
        goto LAB_000788b6;
      }
      if (uVar17 != 0) goto LAB_000789a4;
      goto LAB_000785d2;
    }
    uVar12 = uVar17;
    if (uVar17 != 0) {
      uVar12 = 1;
    }
    if ((uVar17 == 0 || uVar17 <= local_158[1]) && (uVar17 != 0 && local_158[1] != uVar17)) {
LAB_000789f6:
      uVar14 = dtls1_reassemble_fragment(param_1,local_158,param_6);
      uVar12 = uVar14 + 3;
      goto LAB_00078782;
    }
    if (((param_1[9] == 0) && (*(int *)(iVar11 + 0x298) == 0)) && (local_164 == 0)) {
      if (((local_163 != 0) || (local_162 != 0)) || (local_161 != 0)) {
        iVar9 = 0x3a0;
        goto LAB_00078880;
      }
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(0,*param_1,0x16,&local_164,0xc,param_1,param_1[0x1a]);
        iVar11 = param_1[0x17];
      }
      param_1[0x11] = 0;
      goto LAB_000785d2;
    }
    iVar11 = dtls1_preprocess_fragment(param_1,local_158,param_5);
    if (iVar11 == 0) {
      if (uVar12 == 0) {
        uVar14 = 0;
      }
      else {
        uVar14 = (**(code **)(param_1[2] + 0x34))
                           (param_1,0x16,*(int *)(param_1[0xf] + 4) + 0xc + uVar14,uVar17,0);
        if ((int)uVar14 < 1) {
          param_1[6] = 3;
          uVar12 = uVar14 + 3;
          *param_6 = 0;
          goto LAB_00078782;
        }
      }
      if (uVar14 != uVar17) {
        ERR_put_error(0x14,0xfd,0x2f,DAT_00078b44,0x3c1);
        iVar11 = 0x2f;
        goto LAB_00078890;
      }
      *param_6 = 1;
      param_1[0xd] = param_3;
      param_1[0x11] = uVar14;
      goto LAB_000787bc;
    }
  }
  else {
    iVar9 = 0x36b;
LAB_00078880:
    iVar11 = 10;
    ERR_put_error(0x14,0xfd,0xf4,DAT_00078b44,iVar9);
  }
LAB_00078890:
  ssl3_send_alert(param_1,2,iVar11);
  param_1[0x11] = 0;
  *param_6 = 0;
  return 0xffffffff;
LAB_000789a4:
  uVar14 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,auStack_128);
  if (0 < (int)uVar14) goto LAB_0007899e;
  uVar12 = uVar14 + 3;
LAB_000788b6:
  *param_6 = 0;
LAB_00078782:
  if (1 < uVar12) {
LAB_000787bc:
    if ((int)uVar14 < 1) {
LAB_00078ab6:
      if (*param_6 == 0) {
        return uVar14;
      }
    }
    if ((param_4 < 0) || (*(int *)(param_1[0x16] + 0x340) == param_4)) {
      iVar11 = *(int *)(iVar9 + 0x290);
      uVar1 = *(undefined *)(iVar9 + 0x28c);
      puVar13 = *(undefined **)(param_1[0xf] + 4);
      uVar3 = (undefined)((uint)iVar11 >> 0x10);
      puVar13[1] = uVar3;
      uVar4 = (undefined)((uint)iVar11 >> 8);
      puVar13[2] = uVar4;
      puVar13[3] = (char)iVar11;
      *puVar13 = uVar1;
      puVar13[4] = (char)((ushort)*(undefined2 *)(iVar9 + 0x294) >> 8);
      uVar2 = *(undefined2 *)(iVar9 + 0x294);
      puVar13[9] = uVar3;
      puVar13[10] = uVar4;
      puVar13[5] = (char)uVar2;
      puVar13[0xb] = (char)iVar11;
      puVar13[6] = 0;
      puVar13[7] = 0;
      puVar13[8] = 0;
      if (*param_1 == 0x100) {
        puVar13 = puVar13 + 0xc;
      }
      else {
        iVar11 = iVar11 + 0xc;
      }
      ssl3_finish_mac(param_1,puVar13,iVar11);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(0,*param_1,0x16,puVar13,iVar11,param_1,param_1[0x1a]);
      }
      memset((void *)(iVar9 + 0x28c),0,0x2c);
      iVar9 = param_1[0x17];
      if (*(int *)(iVar9 + 0x254) == 0) {
        *(short *)(iVar9 + 0x228) = *(short *)(iVar9 + 0x228) + 1;
      }
      param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
      return param_1[0x11];
    }
    iVar9 = 0x1ee;
    goto LAB_00078a50;
  }
  goto LAB_000785ce;
LAB_0007899e:
  uVar17 = uVar17 - uVar14;
  if (uVar17 == 0) goto LAB_000785ce;
  goto LAB_000789a4;
}

