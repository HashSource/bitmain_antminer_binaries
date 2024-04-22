
undefined4
do_dtls1_write_part_2(int *param_1,undefined4 param_2,void *param_3,size_t param_4,int param_5)

{
  EVP_MD *pEVar1;
  ulong uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined uVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  undefined *puVar10;
  bool bVar11;
  int local_30;
  int local_2c;
  
  iVar9 = param_1[0x16];
  if (((param_1[0x30] == 0) || (param_1[0x23] == 0)) ||
     (pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]), pEVar1 == (EVP_MD *)0x0)) {
    local_30 = 0;
  }
  else {
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    local_30 = EVP_MD_size(pEVar1);
    if (local_30 < 0) {
      return 0xffffffff;
    }
  }
  puVar8 = *(undefined **)(iVar9 + 0xfc);
  *puVar8 = (char)param_2;
  piVar4 = (int *)param_1[2];
  *(undefined4 *)(iVar9 + 0x130) = param_2;
  iVar5 = *piVar4;
  bVar11 = iVar5 == 0x1ffff;
  if (bVar11) {
    iVar5 = 0xfe;
    iVar7 = 0xff;
  }
  else {
    iVar7 = *param_1;
  }
  if (bVar11) {
    puVar8[1] = (char)iVar5;
  }
  puVar10 = puVar8 + 0xd;
  if (!bVar11) {
    iVar7 = iVar7 >> 8;
  }
  uVar6 = (undefined)iVar7;
  if (!bVar11) {
    puVar8[1] = uVar6;
    uVar6 = (undefined)*param_1;
  }
  puVar8[2] = uVar6;
  if ((EVP_CIPHER_CTX *)param_1[0x23] != (EVP_CIPHER_CTX *)0x0) {
    uVar2 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x23]);
    if ((uVar2 & 0xf0007) == 2) {
      local_2c = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0x23]);
      if (1 < local_2c) goto LAB_00076b36;
    }
    else if ((uVar2 & 0xf0007) == 6) {
      local_2c = 8;
      goto LAB_00076b36;
    }
  }
  local_2c = 0;
LAB_00076b36:
  iVar5 = param_1[0x25];
  *(size_t *)(iVar9 + 0x134) = param_4;
  *(void **)(iVar9 + 0x140) = param_3;
  *(undefined **)(iVar9 + 0x13c) = puVar10 + local_2c;
  if (iVar5 == 0) {
    memcpy(puVar10 + local_2c,param_3,param_4);
    *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
  }
  else {
    iVar5 = ssl3_do_compress(param_1);
    if (iVar5 == 0) {
      ERR_put_error(0x14,0xf5,0x8d,DAT_00076cac,0x656);
      return 0xffffffff;
    }
  }
  if (local_30 != 0) {
    iVar5 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                      (param_1,puVar10 + local_2c + *(int *)(iVar9 + 0x134),1);
    if (iVar5 < 0) {
      return 0xffffffff;
    }
    *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_30;
  }
  *(undefined **)(iVar9 + 0x140) = puVar10;
  *(undefined **)(iVar9 + 0x13c) = puVar10;
  if (local_2c != 0) {
    *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_2c;
  }
  iVar5 = (***(code ***)(param_1[2] + 100))(param_1,1);
  if (iVar5 < 1) {
    return 0xffffffff;
  }
  puVar8[3] = (char)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
  puVar8[4] = (char)*(undefined2 *)(param_1[0x17] + 0x20a);
  iVar5 = param_1[0x16];
  *(undefined4 *)(puVar8 + 5) = *(undefined4 *)(iVar5 + 0x56);
  *(undefined2 *)(puVar8 + 9) = *(undefined2 *)(iVar5 + 0x5a);
  puVar8[0xb] = (char)((uint)*(undefined4 *)(iVar9 + 0x134) >> 8);
  puVar8[0xc] = (char)*(undefined4 *)(iVar9 + 0x134);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])(1,0,0x100,puVar8,0xd,param_1,param_1[0x1a]);
  }
  iVar5 = param_1[0x16];
  *(undefined4 *)(iVar9 + 0x130) = param_2;
  *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + 0xd;
  ssl3_record_sequence_update(iVar5 + 0x54);
  if (param_5 == 0) {
    iVar5 = param_1[0x16];
    *(undefined4 *)(iVar9 + 0x104) = 0;
    *(undefined4 *)(iVar9 + 0x108) = *(undefined4 *)(iVar9 + 0x134);
    *(size_t *)(iVar5 + 0x168) = param_4;
    *(void **)(iVar5 + 0x174) = param_3;
    *(undefined4 *)(iVar5 + 0x16c) = param_2;
    *(size_t *)(iVar5 + 0x170) = param_4;
    uVar3 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return uVar3;
  }
  return *(undefined4 *)(iVar9 + 0x134);
}

