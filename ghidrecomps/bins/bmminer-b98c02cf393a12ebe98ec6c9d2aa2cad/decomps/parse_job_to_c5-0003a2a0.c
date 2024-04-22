
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t parse_job_to_c5(void **param_1,int param_2,undefined4 param_3)

{
  uint *puVar1;
  byte *__dest;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  byte *pbVar6;
  undefined4 *puVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  size_t __n;
  undefined4 uVar12;
  size_t __nmemb;
  void *pvVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  undefined4 local_888;
  undefined4 uStack_884;
  undefined local_880;
  undefined local_87f;
  int local_87c;
  undefined local_878;
  byte local_877;
  undefined local_876;
  undefined4 local_874;
  undefined auStack_870 [4];
  undefined auStack_86c [32];
  undefined auStack_84c [4];
  undefined auStack_848 [4];
  undefined2 local_844;
  undefined2 local_842;
  undefined2 local_840;
  undefined2 local_83e;
  undefined4 local_838;
  undefined4 uStack_834;
  undefined local_830;
  undefined4 local_82c;
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined local_810;
  byte *pbVar7;
  
  local_830 = *(undefined *)(param_2 + 0x284);
  local_82c = *(undefined4 *)(param_2 + 0x288);
  local_880 = 0x52;
  local_877 = local_877 & 0xfe | *(byte *)(param_2 + 0x2a8) & 1 | 2;
  local_878 = (undefined)(undefined4)pool_send_nu_14834;
  local_876 = 0xf;
  local_87f = 0;
  local_874 = param_3;
  hex2bin(auStack_870,param_2 + 0x6f4,4);
  hex2bin(auStack_86c,param_2 + 0x6b0,0x20);
  hex2bin(auStack_848,param_2 + 0x700,4);
  hex2bin(auStack_84c,param_2 + 0x70c,4);
  pvVar13 = *(void **)(param_2 + 0x620);
  __n = *(size_t *)(param_2 + 0x624);
  puVar4 = (undefined4 *)((int)pvVar13 + *(int *)(param_2 + 0x628));
  local_842 = (undefined2)*(int *)(param_2 + 0x628);
  local_844 = (undefined2)__n;
  local_840 = (undefined2)*(size_t *)(param_2 + 0x278);
  local_838 = *puVar4;
  uStack_834 = puVar4[1];
  local_888 = *(undefined4 *)(param_2 + 0x270);
  uStack_884 = *(undefined4 *)(param_2 + 0x274);
  memcpy(&local_838,&local_888,*(size_t *)(param_2 + 0x278));
  iVar15 = *(int *)(param_2 + 0x6ac);
  local_83e = (undefined2)iVar15;
  iVar14 = __n + iVar15 * 0x20;
  __nmemb = iVar14 + 0x5a;
  __dest = (byte *)calloc(__nmemb,1);
  if (__dest == (byte *)0x0) {
    local_828._0_1_ = s_Failed_to_malloc_tmp_buf_0006423c[0];
    local_828._1_1_ = s_Failed_to_malloc_tmp_buf_0006423c[1];
    local_828._2_1_ = s_Failed_to_malloc_tmp_buf_0006423c[2];
    local_828._3_1_ = s_Failed_to_malloc_tmp_buf_0006423c[3];
    uStack_824._0_1_ = s_Failed_to_malloc_tmp_buf_0006423c[4];
    uStack_824._1_1_ = s_Failed_to_malloc_tmp_buf_0006423c[5];
    uStack_824._2_1_ = s_Failed_to_malloc_tmp_buf_0006423c[6];
    uStack_824._3_1_ = s_Failed_to_malloc_tmp_buf_0006423c[7];
    uStack_820._0_1_ = s_Failed_to_malloc_tmp_buf_0006423c[8];
    uStack_820._1_1_ = s_Failed_to_malloc_tmp_buf_0006423c[9];
    uStack_820._2_1_ = s_Failed_to_malloc_tmp_buf_0006423c[10];
    uStack_820._3_1_ = s_Failed_to_malloc_tmp_buf_0006423c[11];
    uStack_81c._0_1_ = s_Failed_to_malloc_tmp_buf_0006423c[12];
    uStack_81c._1_1_ = s_Failed_to_malloc_tmp_buf_0006423c[13];
    uStack_81c._2_1_ = s_Failed_to_malloc_tmp_buf_0006423c[14];
    uStack_81c._3_1_ = s_Failed_to_malloc_tmp_buf_0006423c[15];
    local_818._0_1_ = s_Failed_to_malloc_tmp_buf_0006423c[16];
    local_818._1_1_ = s_Failed_to_malloc_tmp_buf_0006423c[17];
    local_818._2_1_ = s_Failed_to_malloc_tmp_buf_0006423c[18];
    local_818._3_1_ = s_Failed_to_malloc_tmp_buf_0006423c[19];
    uStack_814._0_1_ = s_Failed_to_malloc_tmp_buf_0006423c[20];
    uStack_814._1_1_ = s_Failed_to_malloc_tmp_buf_0006423c[21];
    uStack_814._2_1_ = s_Failed_to_malloc_tmp_buf_0006423c[22];
    uStack_814._3_1_ = s_Failed_to_malloc_tmp_buf_0006423c[23];
    local_810 = (undefined)ram0x00064254;
    _applog(3,&local_828,1);
    _quit(1);
    pvVar13 = *(void **)(param_2 + 0x620);
    __n = *(size_t *)(param_2 + 0x624);
    iVar15 = *(int *)(param_2 + 0x6ac);
  }
  local_87c = iVar14 + 0x52;
  memcpy(__dest,&local_880,0x58);
  memcpy(__dest + 0x58,pvVar13,__n);
  if (0 < iVar15) {
    iVar17 = 0;
    piVar16 = (int *)(*(int *)(param_2 + 0x2a4) + -4);
    puVar4 = (undefined4 *)(__dest + __n + 0x58);
    do {
      piVar16 = piVar16 + 1;
      puVar8 = (undefined4 *)*piVar16;
      iVar17 = iVar17 + 1;
      uVar12 = puVar8[1];
      uVar2 = puVar8[2];
      uVar5 = puVar8[3];
      *puVar4 = *puVar8;
      puVar4[1] = uVar12;
      puVar4[2] = uVar2;
      puVar4[3] = uVar5;
      uVar12 = puVar8[5];
      uVar2 = puVar8[6];
      uVar5 = puVar8[7];
      puVar4[4] = puVar8[4];
      puVar4[5] = uVar12;
      puVar4[6] = uVar2;
      puVar4[7] = uVar5;
      puVar4 = puVar4 + 8;
    } while (iVar17 != iVar15);
  }
  puVar1 = DAT_0003a4bc;
  if ((__nmemb & 0xffff) == 2) {
    uVar10 = 0xffff;
  }
  else {
    uVar3 = 0xff;
    uVar9 = 0xff;
    pbVar7 = __dest;
    do {
      pbVar6 = pbVar7 + 1;
      uVar11 = *pbVar7 ^ uVar9;
      uVar9 = (byte)chCRCHTalbe[uVar11] ^ uVar3;
      uVar3 = (uint)(byte)chCRCLTalbe[uVar11];
      pbVar7 = pbVar6;
    } while (pbVar6 != __dest + ((__nmemb & 0xffff) - 3 & 0xffff) + 1);
    uVar10 = (ushort)uVar9 | (ushort)(byte)chCRCLTalbe[uVar11] << 8;
  }
  uVar3 = *DAT_0003a4bc;
  uVar9 = DAT_0003a4bc[1];
  *(ushort *)(__dest + iVar14 + 0x58) = uVar10;
  *puVar1 = uVar3 + 1;
  puVar1[1] = uVar9 + (0xfffffffe < uVar3);
  pvVar13 = malloc(__nmemb);
  *param_1 = pvVar13;
  memcpy(pvVar13,__dest,__nmemb);
  memcpy(DAT_0003a4c0,__dest,__nmemb);
  free(__dest);
  return __nmemb;
}

