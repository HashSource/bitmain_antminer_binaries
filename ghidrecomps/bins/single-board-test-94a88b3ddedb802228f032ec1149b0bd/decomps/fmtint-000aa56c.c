
void fmtint(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
           int param_6,int param_7,int param_8,uint param_9,uint param_10)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  bool bVar9;
  longlong lVar10;
  int local_58;
  undefined4 local_4c;
  char local_44 [32];
  
  param_9 = param_9 & ~((int)param_9 >> 0x1f);
  if ((int)(param_10 << 0x19) < 0) {
    local_58 = 0;
    local_4c = 0;
  }
  else if (param_6 < 0) {
    bVar9 = param_5 != 0;
    param_5 = -param_5;
    param_6 = -param_6 - (uint)bVar9;
    local_58 = 1;
    local_4c = 0x2d;
  }
  else if ((int)(param_10 << 0x1e) < 0) {
    local_4c = 0x2b;
    local_58 = 1;
  }
  else if ((param_10 & 4) == 0) {
    local_58 = 0;
    local_4c = 0;
  }
  else {
    local_4c = 0x20;
    local_58 = 1;
  }
  lVar10 = CONCAT44(param_6,param_5);
  pcVar7 = DAT_000aa7d0;
  if ((((int)(param_10 << 0x1c) < 0) && (pcVar7 = DAT_000aa7d4, param_7 != 8)) &&
     (pcVar7 = DAT_000aa7cc, param_7 != 0x10)) {
    pcVar7 = DAT_000aa7d0;
  }
  if ((param_10 & 0x20) == 0) {
    uVar5 = param_10 & 0x20;
    do {
      uVar6 = uVar5;
      uVar8 = (undefined4)((ulonglong)lVar10 >> 0x20);
      iVar4 = param_7;
      __aeabi_uldivmod((int)lVar10,uVar8,param_7,0);
      uVar5 = uVar6 + 1;
      local_44[uVar6] = "0123456789abcdef"[iVar4];
      lVar10 = __aeabi_uldivmod((int)lVar10,uVar8,param_7);
    } while ((int)uVar5 < 0x1a && lVar10 != 0);
  }
  else {
    uVar5 = 0;
    do {
      uVar6 = uVar5;
      uVar8 = (undefined4)((ulonglong)lVar10 >> 0x20);
      iVar4 = param_7;
      __aeabi_uldivmod((int)lVar10,uVar8,param_7,0);
      uVar5 = uVar6 + 1;
      local_44[uVar6] = "0123456789ABCDEF"[iVar4];
      lVar10 = __aeabi_uldivmod((int)lVar10,uVar8,param_7);
    } while ((int)uVar5 < 0x1a && lVar10 != 0);
  }
  if (uVar5 == 0x1a) {
    uVar5 = uVar6;
  }
  local_44[uVar5] = '\0';
  uVar6 = param_9 - uVar5 & ~((int)(param_9 - uVar5) >> 0x1f);
  sVar2 = strlen(pcVar7);
  if ((int)param_9 <= (int)uVar5) {
    param_9 = uVar5;
  }
  uVar3 = ((param_8 - param_9) - local_58) - sVar2;
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)(param_10 << 0x1b) < 0) {
    if ((int)uVar6 < (int)uVar3) {
      uVar6 = uVar3;
    }
    uVar3 = 0;
  }
  if ((int)(param_10 << 0x1f) < 0) {
    uVar3 = -uVar3;
  }
  else if (0 < (int)uVar3) {
    do {
      doapr_outch_constprop_1(param_1,param_2,param_3,param_4);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (local_58 != 0) {
    doapr_outch(param_1,param_2,param_3,param_4,local_4c);
  }
  cVar1 = *pcVar7;
  while (cVar1 != '\0') {
    doapr_outch(param_1,param_2,param_3,param_4,cVar1);
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar7;
  }
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    doapr_outch_constprop_0(param_1,param_2,param_3,param_4);
  }
  if (uVar5 != 0) {
    pcVar7 = local_44 + uVar5;
    do {
      pcVar7 = pcVar7 + -1;
      uVar5 = uVar5 - 1;
      doapr_outch(param_1,param_2,param_3,param_4,*pcVar7);
    } while (uVar5 != 0);
  }
  for (; uVar3 != 0; uVar3 = uVar3 + 1) {
    doapr_outch_constprop_1(param_1,param_2,param_3,param_4);
  }
  return;
}

