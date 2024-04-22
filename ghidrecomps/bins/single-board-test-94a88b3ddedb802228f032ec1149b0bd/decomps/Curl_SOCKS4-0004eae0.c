
undefined4
Curl_SOCKS4(char *param_1,char *param_2,undefined4 param_3,int param_4,undefined4 *param_5,
           byte param_6)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint __n;
  int *local_184;
  int local_180;
  int local_17c;
  undefined local_178 [2];
  undefined local_176 [2];
  undefined local_174 [2];
  undefined local_172 [2];
  undefined auStack_170 [64];
  char local_130;
  byte local_12f;
  undefined local_12e;
  undefined local_12d;
  undefined local_12c;
  undefined local_12b;
  undefined local_12a;
  undefined local_129;
  char local_128;
  undefined local_127 [259];
  
  uVar4 = *param_5;
  uVar6 = (uint)param_6;
  uVar7 = param_5[param_4 + 0x55];
  iVar1 = Curl_timeleft(uVar4,0,1);
  if (iVar1 < 0) {
    Curl_failf(uVar4,DAT_0004eda8);
    return 0x1c;
  }
  curlx_nonblock(uVar7,0);
  Curl_infof(uVar4,DAT_0004eda0,param_2,param_3);
  local_12d = (undefined)param_3;
  local_12e = (undefined)((uint)param_3 >> 8);
  local_130 = '\x04';
  local_12f = 1;
  if (uVar6 == 0) {
    iVar1 = Curl_resolv(param_5,param_2,param_3,&local_184);
    if (iVar1 == -1) {
      return 5;
    }
    if ((local_184 == (int *)0x0) || (*local_184 == 0)) {
LAB_0004ebbc:
      Curl_failf(uVar4,DAT_0004edb4,param_2);
      return 6;
    }
    Curl_printable_address(*local_184,auStack_170,0x40);
    iVar1 = __isoc99_sscanf(auStack_170,DAT_0004edac,local_178,local_176,local_174,local_172);
    if (iVar1 != 4) {
      Curl_infof(uVar4,DAT_0004edb0,auStack_170);
      Curl_resolv_unlock(uVar4,local_184);
      goto LAB_0004ebbc;
    }
    local_12c = local_178[0];
    local_12b = local_176[0];
    local_12a = local_174[0];
    local_129 = local_172[0];
    Curl_infof(uVar4,DAT_0004edb0,auStack_170);
    Curl_resolv_unlock(uVar4,local_184);
  }
  local_128 = '\0';
  if (param_1 != (char *)0x0) {
    sVar2 = strlen(param_1);
    if (0xfd < sVar2) {
      Curl_failf(uVar4,DAT_0004eda4);
      return 7;
    }
    memcpy(&local_128,param_1,sVar2 + 1);
  }
  sVar2 = strlen(&local_128);
  iVar5 = sVar2 + 9;
  iVar1 = iVar5;
  __n = uVar6;
  if (uVar6 != 0) {
    local_129 = 1;
    local_12c = 0;
    local_12b = 0;
    local_12a = 0;
    sVar3 = strlen(param_2);
    __n = sVar3 + 1;
    iVar1 = iVar5 + __n;
    if (iVar1 < 0x107) {
      memcpy(local_127 + sVar2,param_2,__n);
    }
    else {
      __n = 0;
      iVar1 = iVar5;
    }
  }
  iVar5 = Curl_write_plain(param_5,uVar7,&local_130,iVar1,&local_17c);
  if ((iVar5 == 0) && (local_17c == iVar1)) {
    if (__n == 0) {
      uVar6 = uVar6 & 1;
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 != 0) {
      sVar2 = strlen(param_2);
      iVar1 = Curl_write_plain(param_5,uVar7,param_2,sVar2 + 1,&local_17c);
      if ((iVar1 != 0) || (local_17c != sVar2 + 1)) goto LAB_0004ec22;
    }
    iVar1 = Curl_blockread_all(param_5,uVar7,&local_130,8,&local_180);
    if ((iVar1 == 0) && (local_180 == 8)) {
      if (local_130 == '\0') {
        uVar6 = (uint)local_12f;
        if (uVar6 - 0x5a < 4) {
                    /* WARNING: Could not recover jumptable at 0x0004ece8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (*(code *)(&UNK_0004ecec + (uint)*(byte *)(uVar6 + 0x4ec92) * 2))();
          return uVar4;
        }
        Curl_failf(uVar4,DAT_0004ee10,local_12c,local_12b,local_12a,local_129,
                   CONCAT11(local_128,local_127[0]),uVar6);
      }
      else {
        Curl_failf(uVar4,DAT_0004ee14);
      }
    }
    else {
      Curl_failf(uVar4,DAT_0004edbc);
    }
  }
  else {
LAB_0004ec22:
    Curl_failf(uVar4,DAT_0004edb8);
  }
  return 7;
}

