
undefined4
Curl_SOCKS5(char *param_1,char *param_2,char *param_3,undefined4 param_4,int param_5,
           undefined4 *param_6)

{
  bool bVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  int iVar4;
  size_t __n_00;
  size_t __n_01;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char *local_298;
  undefined4 local_294;
  int local_28c;
  int local_288;
  int *local_284;
  char local_280 [604];
  
  iVar5 = param_6[0x4e];
  uVar6 = *param_6;
  uVar7 = param_6[param_5 + 0x55];
  __n = strlen(param_3);
  bVar1 = 0xff < __n && iVar5 != 5;
  if (bVar1) {
    Curl_infof(uVar6,DAT_0004f180,__n);
  }
  iVar2 = Curl_timeleft(uVar6,0,1);
  if (iVar2 < 0) {
    Curl_failf(uVar6,DAT_0004f17c);
    return 0x1c;
  }
  curlx_nonblock(uVar7,1);
  uVar3 = Curl_socket_check(0xffffffff,0xffffffff,uVar7,iVar2);
  if (uVar3 == 0xffffffff) {
    Curl_failf(*param_6,DAT_0004f184);
    return 7;
  }
  if (uVar3 == 0) {
    Curl_failf(*param_6,DAT_0004f18c);
    return 0x1c;
  }
  if ((uVar3 & 4) != 0) {
    Curl_failf(*param_6,DAT_0004f188);
    return 7;
  }
  if (param_1 == (char *)0x0) {
    local_280[1] = 1;
  }
  else {
    local_280[1] = 2;
  }
  local_280[2] = 0;
  local_280[3] = 2;
  local_280[0] = '\x05';
  curlx_nonblock(uVar7,0);
  iVar4 = Curl_write_plain(param_6,uVar7,local_280,(byte)local_280[1] + 2,&local_288);
  if ((iVar4 != 0) || ((byte)local_280[1] + 2 != local_288)) {
    Curl_failf(uVar6,DAT_0004f178);
    return 7;
  }
  curlx_nonblock(uVar7,1);
  uVar3 = Curl_socket_check(uVar7,0xffffffff,0xffffffff,iVar2);
  if (uVar3 == 0xffffffff) {
    Curl_failf(*param_6,DAT_0004f198);
    return 7;
  }
  if (uVar3 == 0) {
    Curl_failf(*param_6,DAT_0004f194);
    return 0x1c;
  }
  if ((uVar3 & 4) != 0) {
    Curl_failf(*param_6,DAT_0004f190);
    return 0x38;
  }
  curlx_nonblock(uVar7);
  iVar2 = Curl_blockread_all(param_6,uVar7,local_280,2,&local_28c);
  if ((iVar2 != 0) || (local_28c != 2)) {
    Curl_failf(uVar6,DAT_0004f19c);
    return 7;
  }
  if (local_280[0] != '\x05') {
    Curl_failf(uVar6,DAT_0004f1a0);
    return 7;
  }
  local_294 = param_4;
  if (local_280[1] != 0) {
    if (local_280[1] != 2) {
      if (local_280[1] == 1) {
        Curl_failf(uVar6,DAT_0004f1b4);
        return 7;
      }
      if (local_280[1] == 0xff) {
        if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
          Curl_failf(uVar6,DAT_0004f3ac);
          return 7;
        }
        Curl_failf(uVar6,DAT_0004f39c);
        return 7;
      }
      Curl_failf(uVar6,DAT_0004f1a4);
      return 7;
    }
    if ((param_2 == (char *)0x0) || (param_1 == (char *)0x0)) {
      __n_01 = 0;
      local_280[0] = '\x01';
      iVar2 = 3;
      local_280[1] = '\0';
      local_280[2] = 0;
    }
    else {
      __n_00 = strlen(param_1);
      __n_01 = strlen(param_2);
      local_280[0] = '\x01';
      local_280[1] = (char)__n_00;
      if (__n_00 != 0) {
        memcpy(local_280 + 2,param_1,__n_00);
      }
      iVar2 = __n_00 + 3;
      local_298 = param_2;
      local_280[__n_00 + 2] = (char)__n_01;
      if (__n_01 != 0) {
        memcpy(local_280 + __n_00 + 3,local_298,__n_01);
      }
    }
    iVar4 = Curl_write_plain(param_6,uVar7,local_280,iVar2 + __n_01,&local_288);
    if ((iVar4 != 0) || (iVar2 + __n_01 != local_288)) {
      Curl_failf(uVar6,DAT_0004f1b8);
      return 7;
    }
    iVar2 = Curl_blockread_all(param_6,uVar7,local_280,2,&local_28c);
    if ((iVar2 != 0) || (local_28c != 2)) {
      Curl_failf(uVar6,DAT_0004f3a0);
      return 7;
    }
    if (local_280[1] != '\0') {
      Curl_failf(uVar6,DAT_0004f3a4,local_280[0]);
      return 7;
    }
  }
  local_280[0] = '\x05';
  local_280[1] = '\x01';
  local_280[2] = 0;
  if (bVar1 || iVar5 == 5) {
    iVar5 = Curl_resolv(param_6,param_3,local_294,&local_284);
    if (iVar5 == -1) {
      return 6;
    }
    if (iVar5 == 1) {
      return 6;
    }
    if ((local_284 == (int *)0x0) || (iVar5 = *local_284, iVar5 == 0)) {
LAB_0004f088:
      Curl_failf(uVar6,DAT_0004f1ac,param_3);
      return 6;
    }
    if (*(int *)(iVar5 + 4) == 2) {
      local_280[3] = '\x01';
      iVar2 = *(int *)(iVar5 + 0x18);
      iVar5 = 0;
      do {
        iVar4 = iVar5 + 1;
        local_280[iVar5 + 4] = *(char *)(iVar2 + iVar5 + 4);
        Curl_infof(uVar6,DAT_0004f1b0);
        iVar5 = iVar4;
      } while (iVar4 != 4);
      iVar2 = 8;
    }
    else {
      if (*(int *)(iVar5 + 4) != 10) {
        Curl_resolv_unlock(uVar6);
        goto LAB_0004f088;
      }
      iVar2 = 4;
      local_280[3] = '\x04';
      iVar5 = *(int *)(iVar5 + 0x18);
      do {
        local_280[iVar2] = *(char *)(iVar5 + iVar2 + 4);
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x14);
    }
    Curl_resolv_unlock(uVar6,local_284);
  }
  else {
    local_280[4] = (char)__n;
    iVar2 = __n + 5;
    local_280[3] = '\x03';
    memcpy(local_280 + 5,param_3,__n);
  }
  local_280[iVar2] = (char)((uint)local_294 >> 8);
  local_280[iVar2 + 1] = (char)local_294;
  iVar5 = Curl_write_plain(param_6,uVar7,local_280,iVar2 + 2,&local_288);
  if ((iVar5 != 0) || (iVar2 + 2 != local_288)) {
    Curl_failf(uVar6,DAT_0004f1a8);
    return 7;
  }
  iVar5 = Curl_blockread_all(param_6,uVar7,local_280,10,&local_28c);
  if ((iVar5 == 0) && (local_28c == 10)) {
    if (local_280[0] != '\x05') {
      Curl_failf(uVar6,DAT_0004f3b0);
      return 7;
    }
    if (local_280[1] != '\0') {
      if (local_280[3] == '\x01') {
        Curl_failf(uVar6,DAT_0004f3bc,local_280[4],local_280[5],local_280[6],local_280[7],
                   CONCAT11(local_280[8],local_280[9]),local_280[1]);
        return 7;
      }
      if (local_280[3] == '\x03') {
        Curl_failf(uVar6,DAT_0004f3b8,param_3,CONCAT11(local_280[8],local_280[9]),local_280[1]);
        return 7;
      }
      if (local_280[3] == '\x04') {
        Curl_failf(uVar6,DAT_0004f3b4,local_280[4],local_280[5],local_280[6],local_280[7],
                   local_280[8],local_280[9],local_280[10],local_280[11],local_280[12],local_280[13]
                   ,local_280[14],local_280[15],local_280[16],local_280[17],local_280[18],
                   local_280[19],CONCAT11(local_280[8],local_280[9]),local_280[1]);
        return 7;
      }
      return 7;
    }
    if (local_280[3] == '\x03') {
      uVar3 = (byte)local_280[4] + 7;
      if (10 < uVar3) goto LAB_0004f31e;
    }
    else if (local_280[3] == '\x04') {
      uVar3 = 0x16;
LAB_0004f31e:
      iVar5 = Curl_blockread_all(param_6,uVar7,local_280 + 10,uVar3 - 10,&local_28c);
      if ((iVar5 != 0) || (uVar3 - 10 != local_28c)) goto LAB_0004f246;
    }
    curlx_nonblock(uVar7,1);
    uVar6 = 0;
  }
  else {
LAB_0004f246:
    Curl_failf(uVar6,DAT_0004f3a8);
    uVar6 = 7;
  }
  return uVar6;
}

