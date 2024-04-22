
int do_ssl3_write(int *param_1,int param_2,void *param_3,size_t param_4,uint param_5)

{
  EVP_MD *pEVar1;
  COMP_CTX *ctx;
  ulong uVar2;
  undefined uVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined *unaff_r11;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar8 = param_1[0x16];
  if (*(int *)(iVar8 + 0x108) != 0) goto LAB_0006bf6a;
  if ((*(int *)(iVar8 + 0x18c) != 0) && (iVar7 = (**(code **)(param_1[2] + 0x3c))(), iVar7 < 1)) {
    return iVar7;
  }
  if ((*(int *)(iVar8 + 0xfc) == 0) && (iVar7 = ssl3_setup_write_buffer(param_1), iVar7 == 0)) {
    return -1;
  }
  if (param_5 == 0 && param_4 == 0) {
    return 0;
  }
  uVar9 = 0;
  iVar7 = param_1[0x16];
  if (param_1[0x30] == 0) {
LAB_0006bf74:
    uVar5 = param_1[0x23];
LAB_0006bf78:
    uVar9 = 1 - uVar5;
    if (1 < uVar5) {
      uVar9 = 0;
    }
    local_34 = 0;
  }
  else {
    uVar5 = param_1[0x23];
    if (uVar5 == 0) goto LAB_0006bf78;
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    if (pEVar1 == (EVP_MD *)0x0) goto LAB_0006bf74;
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    local_34 = EVP_MD_size(pEVar1);
    if (local_34 < 0) {
      return -1;
    }
  }
  if ((uVar9 | param_5) == 0) {
    iVar4 = param_1[0x16];
    if (*(int *)(iVar4 + 0xe4) == 0) {
      if (*(int *)(iVar4 + 0xe0) == 0) {
        local_2c = 0;
      }
      else if (param_2 == 0x17) {
        local_2c = do_ssl3_write(param_1,0x17,param_3,0,1);
        if (local_2c < 1) {
          return -1;
        }
        if (0x55 < local_2c) {
          ERR_put_error(0x14,0x68,0x44,DAT_0006c0fc,0x3a6);
          return -1;
        }
        iVar4 = param_1[0x16];
      }
      else {
        local_2c = 0;
      }
      *(undefined4 *)(iVar4 + 0xe4) = 1;
      if (local_2c != 0) {
        puVar6 = (undefined *)(*(int *)(iVar8 + 0xfc) + local_2c + *(int *)(iVar8 + 0x104));
        goto LAB_0006be34;
      }
    }
LAB_0006bfd4:
    local_2c = 0;
    uVar9 = 3U - *(int *)(iVar8 + 0xfc) & 7;
    puVar6 = (undefined *)(*(int *)(iVar8 + 0xfc) + uVar9);
    *(uint *)(iVar8 + 0x104) = uVar9;
  }
  else {
    if (param_5 == 0) goto LAB_0006bfd4;
    local_2c = 0;
    uVar9 = 6U - *(int *)(iVar8 + 0xfc) & 7;
    puVar6 = (undefined *)(*(int *)(iVar8 + 0xfc) + uVar9);
    *(uint *)(iVar8 + 0x104) = uVar9;
  }
LAB_0006be34:
  *puVar6 = (char)param_2;
  iVar4 = *param_1;
  *(int *)(iVar7 + 0x130) = param_2;
  puVar6[1] = (char)((uint)iVar4 >> 8);
  if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
    iVar10 = *param_1;
    iVar4 = iVar10;
    if (iVar10 >> 8 != 3) goto LAB_0006be50;
    if (0x301 < iVar10) {
      unaff_r11 = puVar6 + 3;
      iVar4 = 1;
    }
    uVar3 = (undefined)iVar4;
    if (iVar10 < 0x302) goto LAB_0006be50;
  }
  else {
    iVar4 = *param_1;
LAB_0006be50:
    uVar3 = (undefined)iVar4;
    unaff_r11 = puVar6 + 3;
  }
  puVar6[2] = uVar3;
  puVar6 = unaff_r11 + 2;
  if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) ||
     (-1 < *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1f)) {
LAB_0006be70:
    local_30 = 0;
  }
  else {
    uVar2 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
    if ((uVar2 & 0xf0007) == 2) {
      local_30 = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
      if (local_30 < 2) goto LAB_0006be70;
    }
    else {
      if ((uVar2 & 0xf0007) != 6) goto LAB_0006be70;
      local_30 = 8;
    }
  }
  ctx = (COMP_CTX *)param_1[0x25];
  *(size_t *)(iVar7 + 0x134) = param_4;
  *(undefined **)(iVar7 + 0x13c) = puVar6 + local_30;
  *(void **)(iVar7 + 0x140) = param_3;
  if (ctx == (COMP_CTX *)0x0) {
    memcpy(puVar6 + local_30,param_3,param_4);
    *(undefined4 *)(iVar7 + 0x140) = *(undefined4 *)(iVar7 + 0x13c);
  }
  else {
    iVar10 = param_1[0x16];
    iVar4 = COMP_compress_block(ctx,*(uchar **)(iVar10 + 0x13c),0x4400,*(uchar **)(iVar10 + 0x140),
                                *(int *)(iVar10 + 0x134));
    if (iVar4 < 0) {
      ERR_put_error(0x14,0x68,0x8d,DAT_0006c0fc,0x3f4);
      return -1;
    }
    *(int *)(iVar10 + 0x134) = iVar4;
    *(undefined4 *)(iVar10 + 0x140) = *(undefined4 *)(iVar10 + 0x13c);
  }
  if (local_34 != 0) {
    iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,puVar6 + local_30 + *(int *)(iVar7 + 0x134),1);
    if (iVar4 < 0) {
      return -1;
    }
    *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + local_34;
  }
  *(undefined **)(iVar7 + 0x140) = puVar6;
  *(undefined **)(iVar7 + 0x13c) = puVar6;
  if (local_30 != 0) {
    *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + local_30;
  }
  iVar4 = (***(code ***)(param_1[2] + 100))(param_1,1);
  if (iVar4 < 1) {
    return -1;
  }
  *unaff_r11 = (char)((uint)*(undefined4 *)(iVar7 + 0x134) >> 8);
  unaff_r11[1] = (char)*(undefined4 *)(iVar7 + 0x134);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])(1,0,0x100,unaff_r11 + -3,5,param_1,param_1[0x1a]);
  }
  *(int *)(iVar7 + 0x130) = param_2;
  iVar4 = *(int *)(iVar7 + 0x134) + 5;
  *(int *)(iVar7 + 0x134) = iVar4;
  if (param_5 != 0) {
    return iVar4;
  }
  iVar7 = param_1[0x16];
  *(int *)(iVar8 + 0x108) = local_2c + iVar4;
  *(size_t *)(iVar7 + 0x168) = param_4;
  *(void **)(iVar7 + 0x174) = param_3;
  *(int *)(iVar7 + 0x16c) = param_2;
  *(size_t *)(iVar7 + 0x170) = param_4;
LAB_0006bf6a:
  iVar8 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar8;
}

