
uint parse_job_to_c5(undefined4 *param_1,int param_2,undefined4 param_3)

{
  byte *__dest;
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  size_t __n;
  undefined4 uVar10;
  uint __nmemb;
  void *pvVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  bool bVar16;
  undefined4 local_888;
  undefined4 uStack_884;
  undefined1 local_880;
  undefined1 local_87f;
  int local_87c;
  undefined1 local_878;
  byte local_877;
  undefined1 local_876;
  undefined4 local_874;
  undefined1 auStack_870 [4];
  undefined1 auStack_86c [32];
  undefined1 auStack_84c [4];
  undefined1 auStack_848 [4];
  undefined2 local_844;
  undefined2 local_842;
  undefined2 local_840;
  undefined2 local_83e;
  undefined4 local_838;
  undefined4 uStack_834;
  undefined1 local_830;
  undefined4 local_82c;
  char local_828 [2052];
  byte *pbVar6;
  
  local_830 = *(undefined1 *)(param_2 + 0x284);
  local_82c = *(undefined4 *)(param_2 + 0x288);
  local_880 = 0x52;
  local_877 = local_877 & 0xfe | *(byte *)(param_2 + 0x2a8) & 1 | 2;
  local_878 = (undefined1)(uint)pool_send_nu_14834;
  local_876 = 0xf;
  local_87f = 0;
  local_874 = param_3;
  hex2bin(auStack_870,param_2 + 0x6f4,4);
  hex2bin(auStack_86c,param_2 + 0x6b0,0x20);
  hex2bin(auStack_848,param_2 + 0x700,4);
  hex2bin(auStack_84c,param_2 + 0x70c,4);
  pvVar11 = *(void **)(param_2 + 0x620);
  __n = *(size_t *)(param_2 + 0x624);
  puVar3 = (undefined4 *)((int)pvVar11 + *(int *)(param_2 + 0x628));
  local_842 = (undefined2)*(int *)(param_2 + 0x628);
  local_844 = (undefined2)__n;
  local_840 = (undefined2)*(size_t *)(param_2 + 0x278);
  local_838 = *puVar3;
  uStack_834 = puVar3[1];
  local_888 = *(undefined4 *)(param_2 + 0x270);
  uStack_884 = *(undefined4 *)(param_2 + 0x274);
  memcpy(&local_838,&local_888,*(size_t *)(param_2 + 0x278));
  iVar13 = *(int *)(param_2 + 0x6ac);
  local_83e = (undefined2)iVar13;
  iVar12 = __n + iVar13 * 0x20;
  __nmemb = iVar12 + 0x5a;
  __dest = (byte *)calloc(__nmemb,1);
  if (__dest == (byte *)0x0) {
    builtin_strncpy(local_828,"Failed to malloc tmp_buf",0x18);
    local_828[0x18] = 0;
    _applog(3,local_828,1);
    _quit(1);
    pvVar11 = *(void **)(param_2 + 0x620);
    __n = *(size_t *)(param_2 + 0x624);
    iVar13 = *(int *)(param_2 + 0x6ac);
  }
  local_87c = iVar12 + 0x52;
  memcpy(__dest,&local_880,0x58);
  memcpy(__dest + 0x58,pvVar11,__n);
  if (0 < iVar13) {
    iVar15 = 0;
    piVar14 = (int *)(*(int *)(param_2 + 0x2a4) + -4);
    pbVar6 = __dest + __n + 0x58;
    do {
      piVar14 = piVar14 + 1;
      puVar3 = (undefined4 *)*piVar14;
      iVar15 = iVar15 + 1;
      uVar10 = puVar3[1];
      uVar1 = puVar3[2];
      uVar4 = puVar3[3];
      *(undefined4 *)pbVar6 = *puVar3;
      *(undefined4 *)(pbVar6 + 4) = uVar10;
      *(undefined4 *)(pbVar6 + 8) = uVar1;
      *(undefined4 *)(pbVar6 + 0xc) = uVar4;
      uVar10 = puVar3[5];
      uVar1 = puVar3[6];
      uVar4 = puVar3[7];
      *(undefined4 *)(pbVar6 + 0x10) = puVar3[4];
      *(undefined4 *)(pbVar6 + 0x14) = uVar10;
      *(undefined4 *)(pbVar6 + 0x18) = uVar1;
      *(undefined4 *)(pbVar6 + 0x1c) = uVar4;
      pbVar6 = pbVar6 + 0x20;
    } while (iVar15 != iVar13);
  }
  if ((__nmemb & 0xffff) == 2) {
    uVar8 = 0xffff;
  }
  else {
    uVar2 = 0xff;
    uVar7 = 0xff;
    pbVar6 = __dest;
    do {
      pbVar5 = pbVar6 + 1;
      uVar9 = *pbVar6 ^ uVar7;
      uVar7 = (byte)chCRCHTalbe[uVar9] ^ uVar2;
      uVar2 = (uint)(byte)chCRCLTalbe[uVar9];
      pbVar6 = pbVar5;
    } while (pbVar5 != __dest + ((__nmemb & 0xffff) - 3 & 0xffff) + 1);
    uVar8 = (ushort)uVar7 | (ushort)(byte)chCRCLTalbe[uVar9] << 8;
  }
  *(ushort *)(__dest + iVar12 + 0x58) = uVar8;
  bVar16 = 0xfffffffe < (uint)pool_send_nu_14834;
  pool_send_nu_14834._0_4_ = (uint)pool_send_nu_14834 + 1;
  pool_send_nu_14834._4_4_ = pool_send_nu_14834._4_4_ + (uint)bVar16;
  pvVar11 = malloc(__nmemb);
  *param_1 = pvVar11;
  memcpy(pvVar11,__dest,__nmemb);
  memcpy(last_job_buffer,__dest,__nmemb);
  free(__dest);
  return __nmemb;
}

