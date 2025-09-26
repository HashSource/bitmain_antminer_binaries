
int do_dtls1_write(undefined4 *param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                  int param_5,int *param_6)

{
  uint uVar1;
  EVP_MD *pEVar2;
  EVP_CIPHER *cipher;
  ulong uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 *local_68;
  uint local_64;
  int local_5c;
  undefined1 auStack_58 [4];
  undefined4 local_54;
  uint local_50;
  undefined1 *local_44;
  undefined1 *local_40;
  
  if (param_1[0x1a2] != 0) {
    ossl_statem_fatal(param_1,0x50,0xf5,0x44,"ssl/record/rec_layer_d1.c",0x333);
    return 0;
  }
  if ((*(int *)(param_1[0x1f] + 0xe8) != 0) &&
     (iVar4 = (**(code **)(param_1[1] + 0x40))(), iVar4 < 1)) {
    return iVar4;
  }
  if (param_4 == 0 && param_5 == 0) {
    return 0;
  }
  uVar1 = ssl_get_max_send_fragment(param_1);
  if (uVar1 < param_4) {
    ossl_statem_fatal(param_1,0x50,0xf5,0xc2,"ssl/record/rec_layer_d1.c",0x344);
    return 0;
  }
  if (((param_1[0x11d] == 0) || (param_1[0xfb] == 0)) ||
     (pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x100]), pEVar2 == (EVP_MD *)0x0)) {
    local_64 = 0;
  }
  else {
    pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x100]);
    local_64 = EVP_MD_size(pEVar2);
    if ((int)local_64 < 0) {
      uVar8 = 0x354;
      uVar6 = 0xc2;
      goto LAB_000deb5c;
    }
  }
  puVar5 = (undefined1 *)param_1[0x19e];
  *puVar5 = (char)param_2;
  if ((*(int *)param_1[1] == 0x1ffff) && (param_1[0x13e] != 0x100)) {
    puVar5[1] = 0xfe;
    puVar5[2] = 0xff;
  }
  else {
    puVar5[1] = (char)((uint)*param_1 >> 8);
    puVar5[2] = (char)*param_1;
  }
  puVar7 = puVar5 + 0xd;
  local_54 = param_2;
  if ((EVP_CIPHER_CTX *)param_1[0xfb] == (EVP_CIPHER_CTX *)0x0) {
LAB_000de93a:
    local_5c = 0;
  }
  else {
    cipher = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)param_1[0xfb]);
    uVar3 = EVP_CIPHER_flags(cipher);
    if ((uVar3 & 0xf0007) == 2) {
      local_5c = EVP_CIPHER_CTX_iv_length((EVP_CIPHER_CTX *)param_1[0xfb]);
      if (local_5c < 2) goto LAB_000de93a;
    }
    else {
      if (1 < (uVar3 & 0xf0007) - 6) goto LAB_000de93a;
      local_5c = 8;
    }
  }
  local_44 = puVar7 + local_5c;
  local_50 = param_4;
  local_40 = param_3;
  if (param_1[0xf9] == 0) {
    memcpy(local_44,param_3,param_4);
    local_40 = local_44;
  }
  else {
    iVar4 = ssl3_do_compress(param_1,auStack_58);
    if (iVar4 == 0) {
      uVar8 = 0x390;
      uVar6 = 0x8d;
      goto LAB_000deb5c;
    }
  }
  local_68 = auStack_58;
  uVar1 = local_64;
  if (local_64 != 0) {
    uVar1 = 1;
  }
  if ((uVar1 & (*(uint *)param_1[0x1f] ^ 0x400) >> 10) != 0) {
    iVar4 = (**(code **)(*(int *)(param_1[1] + 100) + 4))
                      (param_1,local_68,puVar7 + local_50 + local_5c,1);
    if (iVar4 == 0) {
      uVar8 = 0x3a4;
      uVar6 = 0x44;
      goto LAB_000deb5c;
    }
    local_50 = local_50 + local_64;
  }
  if (local_5c != 0) {
    local_50 = local_50 + local_5c;
  }
  local_44 = puVar7;
  local_40 = puVar7;
  iVar4 = (*(code *)**(undefined4 **)(param_1[1] + 100))(param_1,local_68,1);
  if (iVar4 < 1) {
    iVar4 = ossl_statem_in_error(param_1);
    if (iVar4 != 0) {
      return -1;
    }
    uVar8 = 0x3b4;
    uVar6 = 0x44;
LAB_000deb5c:
    ossl_statem_fatal(param_1,0x50,0xf5,uVar6,"ssl/record/rec_layer_d1.c",uVar8);
    return -1;
  }
  if ((uVar1 & *(uint *)param_1[0x1f] >> 10) != 0) {
    iVar4 = (**(code **)(*(int *)(param_1[1] + 100) + 4))(param_1,local_68,puVar7 + local_50,1);
    if (iVar4 == 0) {
      uVar8 = 0x3bd;
      uVar6 = 0x44;
      goto LAB_000deb5c;
    }
    local_50 = local_50 + local_64;
  }
  puVar5[3] = (char)((ushort)*(undefined2 *)(param_1[0x3ce] + 2) >> 8);
  puVar5[4] = (char)*(undefined2 *)(param_1[0x3ce] + 2);
  *(undefined4 *)(puVar5 + 5) = *(undefined4 *)((int)param_1 + 0xf2a);
  *(undefined2 *)(puVar5 + 9) = *(undefined2 *)((int)param_1 + 0xf2e);
  puVar5[0xb] = (char)(local_50 >> 8);
  puVar5[0xc] = (char)local_50;
  if ((code *)param_1[0x21] != (code *)0x0) {
    (*(code *)param_1[0x21])(1,0,0x100,puVar5,0xd,param_1,param_1[0x22]);
  }
  local_50 = local_50 + 0xd;
  local_54 = param_2;
  ssl3_record_sequence_update(param_1 + 0x3ca);
  if (param_5 != 0) {
    *param_6 = local_50;
    return 1;
  }
  param_1[0x3c4] = param_4;
  param_1[0x3c6] = param_4;
  param_1[0x1a1] = 0;
  param_1[0x3c7] = param_3;
  param_1[0x3c5] = param_2;
  param_1[0x1a2] = local_50;
  iVar4 = ssl3_write_pending(param_1,param_2,param_3,param_4,param_6);
  return iVar4;
}

