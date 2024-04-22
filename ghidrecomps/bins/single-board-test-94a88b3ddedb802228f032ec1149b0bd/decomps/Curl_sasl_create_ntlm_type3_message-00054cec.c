
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffff78c : 0x00054f14 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int Curl_sasl_create_ntlm_type3_message
              (undefined4 param_1,char *param_2,undefined4 param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  void *__dest;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  uint __n;
  size_t local_8b0;
  char *local_8a4;
  undefined4 *local_89c;
  uint local_894;
  undefined4 *local_890;
  undefined4 local_88c;
  undefined4 local_888;
  undefined auStack_884 [16];
  undefined4 local_874;
  undefined4 uStack_870;
  int local_86c;
  int local_868;
  int local_864;
  int local_860;
  undefined4 local_85c;
  undefined4 local_858;
  undefined auStack_844 [24];
  int local_82c [255];
  char cStack_42d;
  undefined4 local_42c;
  undefined auStack_428 [1028];
  
  uVar9 = *(uint *)(param_4 + 4);
  local_890 = (undefined4 *)0x0;
  local_42c = 0;
  local_894 = 0x18;
  memset(auStack_428,0,0x3fd);
  pcVar2 = strchr(param_2,0x5c);
  if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(param_2,0x2f), pcVar2 == (char *)0x0)) {
    local_8a4 = DAT_0005511c;
    __n = 0;
    pcVar2 = param_2;
  }
  else {
    __n = (int)pcVar2 - (int)param_2;
    pcVar2 = pcVar2 + 1;
    local_8a4 = param_2;
  }
  pcVar3 = pcVar2;
  if (pcVar2 != (char *)0x0) {
    pcVar3 = (char *)strlen(pcVar2);
  }
  iVar4 = Curl_gethostname(&local_42c,0x401);
  if (iVar4 == 0) {
    local_8b0 = strlen((char *)&local_42c);
  }
  else {
    Curl_infof(param_1,DAT_00055118);
    local_8b0 = 0;
  }
  iVar4 = *(int *)(param_4 + 0x14);
  if (iVar4 == 0) {
    if (*(int *)(param_4 + 4) << 0xc < 0) {
      local_88c = Curl_rand(param_1);
      local_888 = Curl_rand(param_1);
      local_874 = local_88c;
      local_82c[0] = *(int *)(param_4 + 8);
      local_82c[1] = *(undefined4 *)(param_4 + 0xc);
      local_82c[2] = local_88c;
      local_86c = iVar4;
      local_868 = iVar4;
      local_864 = iVar4;
      local_860 = iVar4;
      local_82c[3] = local_888;
      uStack_870 = local_888;
      iVar4 = Curl_ssl_md5sum(local_82c,0x10,auStack_884,0x10);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = Curl_ntlm_core_mk_nt_hash(param_1,param_3,auStack_844);
      if (iVar4 != 0) {
        return iVar4;
      }
      local_89c = &local_85c;
      Curl_ntlm_core_lm_resp(auStack_844,auStack_884,&local_85c);
    }
    else {
      iVar4 = Curl_ntlm_core_mk_nt_hash(param_1,param_3,auStack_844);
      if (iVar4 != 0) {
        return iVar4;
      }
      Curl_ntlm_core_lm_resp(auStack_844,param_4 + 8,&local_85c);
      iVar4 = Curl_ntlm_core_mk_lm_hash(param_1,param_3,local_82c);
      if (iVar4 != 0) {
        return iVar4;
      }
      local_89c = &local_85c;
      Curl_ntlm_core_lm_resp(local_82c,param_4 + 8,&local_874);
    }
  }
  else {
    local_85c = Curl_rand(param_1);
    local_858 = Curl_rand(param_1);
    iVar4 = Curl_ntlm_core_mk_nt_hash(param_1,param_3,auStack_844);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = Curl_ntlm_core_mk_ntlmv2_hash(pcVar2,pcVar3,local_8a4,__n,auStack_844,local_82c);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = Curl_ntlm_core_mk_lmv2_resp(local_82c,&local_85c,param_4 + 8,&local_874);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = Curl_ntlm_core_mk_ntlmv2_resp(local_82c,&local_85c,param_4,&local_890,&local_894);
    if (iVar4 != 0) {
      return iVar4;
    }
    local_89c = local_890;
  }
  uVar9 = uVar9 & 1;
  uVar5 = uVar9;
  if (uVar9 != 0) {
    __n = __n << 1;
    uVar5 = local_8b0;
  }
  uVar6 = local_894 + 0x58;
  if (uVar9 != 0) {
    pcVar3 = (char *)((int)pcVar3 << 1);
    local_8b0 = uVar5 << 1;
  }
  uVar14 = *(uint *)(param_4 + 4);
  uVar5 = __n + uVar6;
  uVar10 = (local_894 << 0x10) >> 0x18;
  uVar7 = (__n << 0x10) >> 0x18;
  uVar11 = (uint)((int)pcVar3 << 0x10) >> 0x18;
  uVar8 = (local_8b0 << 0x10) >> 0x18;
  uVar6 = curl_msnprintf(local_82c,0x400,DAT_00055110,0,0,0,0,0x18,0,0x18,0,0x40,0,0,0,
                         local_894 & 0xff,uVar10,local_894 & 0xff,uVar10,0x58,0,0,0,__n & 0xff,uVar7
                         ,__n & 0xff,uVar7,uVar6 & 0xff,uVar6 * 0x10000 >> 0x18,0,0,
                         (uint)pcVar3 & 0xff,uVar11,(uint)pcVar3 & 0xff,uVar11,uVar5 & 0xff,
                         uVar5 * 0x10000 >> 0x18,0,0,local_8b0 & 0xff,uVar8,local_8b0 & 0xff,uVar8,
                         (uint)(pcVar3 + uVar5) & 0xff,
                         (uint)((int)(pcVar3 + uVar5) * 0x10000) >> 0x18,0,0,0,0,0,0,0,0,0,0,
                         uVar14 & 0xff,(uVar14 << 0x10) >> 0x18,(uVar14 << 8) >> 0x18,uVar14 >> 0x18
                        );
  uVar5 = uVar6;
  if (uVar6 < 1000) {
    *(undefined4 *)((int)local_82c + uVar6) = local_874;
    uVar5 = uVar6 + 0x18;
    *(undefined4 *)((int)local_82c + uVar6 + 4) = uStack_870;
    *(int *)((int)local_82c + uVar6 + 8) = local_86c;
    *(int *)((int)local_82c + uVar6 + 0xc) = local_868;
    *(int *)((int)local_82c + uVar6 + 0x10) = local_864;
    *(int *)((int)local_82c + uVar6 + 0x14) = local_860;
  }
  if (uVar5 < 0x400 - local_894) {
    __dest = (void *)((int)local_82c + uVar5);
    uVar5 = uVar5 + local_894;
    memcpy(__dest,local_89c,local_894);
  }
  (**DAT_00055114)(local_890);
  if (pcVar3 + uVar5 + __n + local_8b0 < (char *)0x400) {
    if (uVar9 == 0) {
      memcpy((void *)((int)local_82c + uVar5),local_8a4,__n);
      pcVar12 = pcVar3 + uVar5 + __n;
      memcpy((void *)((int)local_82c + uVar5 + __n),pcVar2,(size_t)pcVar3);
      memcpy((char *)((int)local_82c + (int)pcVar12),&local_42c,local_8b0);
    }
    else {
      pcVar12 = (char *)((int)local_82c + uVar5);
      if (__n >> 1 != 0) {
        pcVar13 = pcVar12 + (__n & 0xfffffffe);
        local_8a4 = local_8a4 + -1;
        do {
          local_8a4 = local_8a4 + 1;
          cVar1 = *local_8a4;
          pcVar12[1] = '\0';
          *pcVar12 = cVar1;
          pcVar12 = pcVar12 + 2;
        } while (pcVar12 != pcVar13);
      }
      pcVar12 = (char *)((int)local_82c + uVar5 + __n);
      if ((uint)pcVar3 >> 1 != 0) {
        pcVar13 = pcVar12 + ((uint)pcVar3 & 0xfffffffe);
        pcVar2 = pcVar2 + -1;
        do {
          pcVar2 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar12[1] = '\0';
          *pcVar12 = cVar1;
          pcVar12 = pcVar12 + 2;
        } while (pcVar12 != pcVar13);
      }
      pcVar12 = pcVar3 + uVar5 + __n;
      pcVar2 = (char *)((int)local_82c + (int)pcVar12);
      if (local_8b0 >> 1 != 0) {
        pcVar3 = &cStack_42d;
        pcVar13 = pcVar2 + (local_8b0 & 0xfffffffe);
        do {
          pcVar3 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar2[1] = '\0';
          *pcVar2 = cVar1;
          pcVar2 = pcVar2 + 2;
        } while (pcVar2 != pcVar13);
      }
    }
    iVar4 = Curl_base64_encode(0,local_82c,pcVar12 + local_8b0,param_5,param_6);
    Curl_sasl_ntlm_cleanup(param_4);
  }
  else {
    Curl_failf(param_1,DAT_00055120);
    iVar4 = 0x1b;
  }
  return iVar4;
}

