
void fmtint(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
           int param_6,int param_7,int param_8,uint param_9,uint param_10)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  int extraout_r2;
  int extraout_r2_00;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  bool bVar8;
  longlong lVar9;
  char *local_68;
  int local_58;
  undefined4 local_4c;
  char local_44 [32];
  
  param_9 = param_9 & ~((int)param_9 >> 0x1f);
  if ((int)(param_10 << 0x19) < 0) {
    local_58 = 0;
    local_4c = 0;
  }
  else if (param_6 < 0) {
    bVar8 = param_5 != 0;
    param_5 = -param_5;
    param_6 = -param_6 - (uint)bVar8;
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
  lVar9 = CONCAT44(param_6,param_5);
  if ((int)(param_10 << 0x1c) < 0) {
    if (param_7 == 8) {
      local_68 = "0";
    }
    else {
      local_68 = "0x";
      if (param_7 != 0x10) {
        local_68 = "";
      }
    }
  }
  else {
    local_68 = "";
  }
  if ((param_10 & 0x20) == 0) {
    uVar4 = param_10 & 0x20;
    do {
      uVar5 = uVar4;
      uVar7 = (undefined4)((ulonglong)lVar9 >> 0x20);
      __aeabi_uldivmod((int)lVar9,uVar7,param_7,0);
      uVar4 = uVar5 + 1;
      local_44[uVar5] = "0123456789abcdef"[extraout_r2_00];
      lVar9 = __aeabi_uldivmod((int)lVar9,uVar7,param_7,0);
    } while ((int)uVar4 < 0x1a && lVar9 != 0);
  }
  else {
    uVar4 = 0;
    do {
      uVar5 = uVar4;
      uVar7 = (undefined4)((ulonglong)lVar9 >> 0x20);
      __aeabi_uldivmod((int)lVar9,uVar7,param_7,0);
      uVar4 = uVar5 + 1;
      local_44[uVar5] = "0123456789ABCDEF"[extraout_r2];
      lVar9 = __aeabi_uldivmod((int)lVar9,uVar7,param_7,0);
    } while ((int)uVar4 < 0x1a && lVar9 != 0);
  }
  if (uVar4 == 0x1a) {
    uVar4 = uVar5;
  }
  local_44[uVar4] = '\0';
  uVar5 = param_9 - uVar4 & ~((int)(param_9 - uVar4) >> 0x1f);
  sVar2 = strlen(local_68);
  if ((int)param_9 <= (int)uVar4) {
    param_9 = uVar4;
  }
  uVar3 = ((param_8 - param_9) - local_58) - sVar2;
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)(param_10 << 0x1b) < 0) {
    if ((int)uVar5 < (int)uVar3) {
      uVar5 = uVar3;
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
  cVar1 = *local_68;
  while (cVar1 != '\0') {
    doapr_outch(param_1,param_2,param_3,param_4,cVar1);
    local_68 = local_68 + 1;
    cVar1 = *local_68;
  }
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    doapr_outch_constprop_0(param_1,param_2,param_3,param_4);
  }
  if (uVar4 != 0) {
    pcVar6 = local_44 + uVar4;
    do {
      pcVar6 = pcVar6 + -1;
      uVar4 = uVar4 - 1;
      doapr_outch(param_1,param_2,param_3,param_4,*pcVar6);
    } while (uVar4 != 0);
  }
  for (; uVar3 != 0; uVar3 = uVar3 + 1) {
    doapr_outch_constprop_1(param_1,param_2,param_3,param_4);
  }
  return;
}

