
int do_ssl3_write(int *param_1,int param_2,void *param_3,size_t param_4,int param_5)

{
  EVP_MD *pEVar1;
  COMP_CTX *ctx;
  ulong uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *unaff_r11;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar7 = param_1[0x16];
  if (*(int *)(iVar7 + 0x108) != 0) goto LAB_00127ae2;
  if ((*(int *)(iVar7 + 0x18c) != 0) && (iVar6 = (**(code **)(param_1[2] + 0x3c))(), iVar6 < 1)) {
    return iVar6;
  }
  if ((*(int *)(iVar7 + 0xfc) == 0) && (iVar6 = ssl3_setup_write_buffer(param_1), iVar6 == 0)) {
    return -1;
  }
  if (param_5 == 0 && param_4 == 0) {
    return 0;
  }
  iVar8 = 0;
  iVar6 = param_1[0x16];
  if (param_1[0x30] == 0) {
LAB_00127aec:
    uVar4 = param_1[0x23];
LAB_00127af0:
    iVar8 = 1 - uVar4;
    if (1 < uVar4) {
      iVar8 = 0;
    }
    local_34 = 0;
  }
  else {
    uVar4 = param_1[0x23];
    if (uVar4 == 0) goto LAB_00127af0;
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    if (pEVar1 == (EVP_MD *)0x0) goto LAB_00127aec;
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    local_34 = EVP_MD_size(pEVar1);
    if (local_34 < 0) {
      return -1;
    }
  }
  if (iVar8 == 0 && param_5 == 0) {
    iVar8 = param_1[0x16];
    if (*(int *)(iVar8 + 0xe4) == 0) {
      if (*(int *)(iVar8 + 0xe0) == 0) {
        local_2c = 0;
      }
      else if (param_2 == 0x17) {
        local_2c = do_ssl3_write(param_1,0x17,param_3,0,1);
        if (local_2c < 1) {
          return -1;
        }
        if (0x55 < local_2c) {
          ERR_put_error(0x14,0x68,0x44,"s3_pkt.c",0x3a6);
          return -1;
        }
        iVar8 = param_1[0x16];
      }
      else {
        local_2c = 0;
      }
      *(undefined4 *)(iVar8 + 0xe4) = 1;
      if (local_2c != 0) {
        puVar5 = (undefined1 *)(*(int *)(iVar7 + 0xfc) + local_2c + *(int *)(iVar7 + 0x104));
        goto LAB_001279ac;
      }
    }
LAB_00127b4c:
    local_2c = 0;
    uVar4 = 3U - *(int *)(iVar7 + 0xfc) & 7;
    puVar5 = (undefined1 *)(*(int *)(iVar7 + 0xfc) + uVar4);
    *(uint *)(iVar7 + 0x104) = uVar4;
  }
  else {
    if (param_5 == 0) goto LAB_00127b4c;
    local_2c = 0;
    uVar4 = 6U - *(int *)(iVar7 + 0xfc) & 7;
    puVar5 = (undefined1 *)(*(int *)(iVar7 + 0xfc) + uVar4);
    *(uint *)(iVar7 + 0x104) = uVar4;
  }
LAB_001279ac:
  *puVar5 = (char)param_2;
  iVar8 = *param_1;
  *(int *)(iVar6 + 0x130) = param_2;
  puVar5[1] = (char)((uint)iVar8 >> 8);
  if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
    iVar9 = *param_1;
    iVar8 = iVar9;
    if (iVar9 >> 8 != 3) goto LAB_001279c8;
    if (0x301 < iVar9) {
      unaff_r11 = puVar5 + 3;
      iVar8 = 1;
    }
    uVar3 = (undefined1)iVar8;
    if (iVar9 < 0x302) goto LAB_001279c8;
  }
  else {
    iVar8 = *param_1;
LAB_001279c8:
    uVar3 = (undefined1)iVar8;
    unaff_r11 = puVar5 + 3;
  }
  puVar5[2] = uVar3;
  puVar5 = unaff_r11 + 2;
  if (((EVP_CIPHER_CTX *)param_1[0x23] == (EVP_CIPHER_CTX *)0x0) ||
     (-1 < *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1f)) {
LAB_001279e8:
    local_30 = 0;
  }
  else {
    uVar2 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
    if ((uVar2 & 0xf0007) == 2) {
      local_30 = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
      if (local_30 < 2) goto LAB_001279e8;
    }
    else {
      if ((uVar2 & 0xf0007) != 6) goto LAB_001279e8;
      local_30 = 8;
    }
  }
  ctx = (COMP_CTX *)param_1[0x25];
  *(size_t *)(iVar6 + 0x134) = param_4;
  *(undefined1 **)(iVar6 + 0x13c) = puVar5 + local_30;
  *(void **)(iVar6 + 0x140) = param_3;
  if (ctx == (COMP_CTX *)0x0) {
    memcpy(puVar5 + local_30,param_3,param_4);
    *(undefined4 *)(iVar6 + 0x140) = *(undefined4 *)(iVar6 + 0x13c);
  }
  else {
    iVar9 = param_1[0x16];
    iVar8 = COMP_compress_block(ctx,*(uchar **)(iVar9 + 0x13c),0x4400,*(uchar **)(iVar9 + 0x140),
                                *(int *)(iVar9 + 0x134));
    if (iVar8 < 0) {
      ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x3f4);
      return -1;
    }
    *(int *)(iVar9 + 0x134) = iVar8;
    *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
  }
  if (local_34 != 0) {
    iVar8 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,puVar5 + local_30 + *(int *)(iVar6 + 0x134),1);
    if (iVar8 < 0) {
      return -1;
    }
    *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_34;
  }
  *(undefined1 **)(iVar6 + 0x140) = puVar5;
  *(undefined1 **)(iVar6 + 0x13c) = puVar5;
  if (local_30 != 0) {
    *(int *)(iVar6 + 0x134) = *(int *)(iVar6 + 0x134) + local_30;
  }
  iVar8 = (*(code *)**(undefined4 **)(param_1[2] + 100))(param_1,1);
  if (iVar8 < 1) {
    return -1;
  }
  *unaff_r11 = (char)((uint)*(undefined4 *)(iVar6 + 0x134) >> 8);
  unaff_r11[1] = (char)*(undefined4 *)(iVar6 + 0x134);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])(1,0,0x100,unaff_r11 + -3,5,param_1,param_1[0x1a]);
  }
  *(int *)(iVar6 + 0x130) = param_2;
  iVar8 = *(int *)(iVar6 + 0x134) + 5;
  *(int *)(iVar6 + 0x134) = iVar8;
  if (param_5 != 0) {
    return iVar8;
  }
  iVar6 = param_1[0x16];
  *(int *)(iVar7 + 0x108) = local_2c + iVar8;
  *(size_t *)(iVar6 + 0x168) = param_4;
  *(void **)(iVar6 + 0x174) = param_3;
  *(int *)(iVar6 + 0x16c) = param_2;
  *(size_t *)(iVar6 + 0x170) = param_4;
LAB_00127ae2:
  iVar7 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar7;
}

