
undefined4
Curl_SOCKS4(char *param_1,char *param_2,undefined4 param_3,int param_4,undefined4 *param_5,
           byte param_6)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int *local_184;
  int local_180;
  int local_17c;
  undefined1 local_178 [2];
  undefined1 local_176 [2];
  undefined1 local_174 [2];
  undefined1 local_172 [2];
  undefined1 auStack_170 [64];
  char local_130;
  undefined1 local_12f;
  undefined1 local_12e;
  undefined1 local_12d;
  undefined1 local_12c;
  undefined1 local_12b;
  undefined1 local_12a;
  undefined1 local_129;
  char local_128;
  undefined1 local_127 [259];
  
  uVar5 = *param_5;
  uVar7 = (uint)param_6;
  uVar8 = param_5[param_4 + 0x55];
  iVar1 = Curl_timeleft(uVar5,0,1);
  if (iVar1 < 0) {
    Curl_failf(uVar5,"Connection time-out");
    return 0x1c;
  }
  curlx_nonblock(uVar8,0);
  Curl_infof(uVar5,"SOCKS4 communication to %s:%d\n",param_2,param_3);
  local_12d = (undefined1)param_3;
  local_12e = (undefined1)((uint)param_3 >> 8);
  local_130 = '\x04';
  local_12f = 1;
  if (uVar7 == 0) {
    iVar1 = Curl_resolv(param_5,param_2,param_3,&local_184);
    if (iVar1 == -1) {
      return 5;
    }
    if ((local_184 == (int *)0x0) || (*local_184 == 0)) {
LAB_0004ebbc:
      Curl_failf(uVar5,"Failed to resolve \"%s\" for SOCKS4 connect.",param_2);
      return 6;
    }
    Curl_printable_address(*local_184,auStack_170,0x40);
    iVar1 = __isoc99_sscanf(auStack_170,"%hu.%hu.%hu.%hu",local_178,local_176,local_174,local_172);
    if (iVar1 != 4) {
      Curl_infof(uVar5,"SOCKS4 connect to %s (locally resolved)\n",auStack_170);
      Curl_resolv_unlock(uVar5,local_184);
      goto LAB_0004ebbc;
    }
    local_12c = local_178[0];
    local_12b = local_176[0];
    local_12a = local_174[0];
    local_129 = local_172[0];
    Curl_infof(uVar5,"SOCKS4 connect to %s (locally resolved)\n",auStack_170);
    Curl_resolv_unlock(uVar5,local_184);
  }
  local_128 = '\0';
  if (param_1 != (char *)0x0) {
    sVar2 = strlen(param_1);
    if (0xfd < sVar2) {
      Curl_failf(uVar5,"Too long SOCKS proxy name, can\'t use!\n");
      return 7;
    }
    memcpy(&local_128,param_1,sVar2 + 1);
  }
  sVar2 = strlen(&local_128);
  iVar6 = sVar2 + 9;
  iVar1 = iVar6;
  uVar9 = uVar7;
  if (uVar7 != 0) {
    local_129 = 1;
    local_12c = 0;
    local_12b = 0;
    local_12a = 0;
    sVar3 = strlen(param_2);
    uVar9 = sVar3 + 1;
    iVar1 = iVar6 + uVar9;
    if (iVar1 < 0x107) {
      memcpy(local_127 + sVar2,param_2,uVar9);
    }
    else {
      uVar9 = 0;
      iVar1 = iVar6;
    }
  }
  iVar6 = Curl_write_plain(param_5,uVar8,&local_130,iVar1,&local_17c);
  if ((iVar6 == 0) && (local_17c == iVar1)) {
    if (uVar9 == 0) {
      uVar9 = uVar7 & 1;
    }
    else {
      uVar9 = 0;
    }
    if (uVar9 != 0) {
      sVar2 = strlen(param_2);
      iVar1 = Curl_write_plain(param_5,uVar8,param_2,sVar2 + 1,&local_17c);
      if ((iVar1 != 0) || (local_17c != sVar2 + 1)) goto LAB_0004ec22;
    }
    iVar1 = Curl_blockread_all(param_5,uVar8,&local_130,8,&local_180);
    if ((iVar1 == 0) && (local_180 == 8)) {
      if (local_130 == '\0') {
        switch(local_12f) {
        case 0x5a:
          pcVar4 = "";
          if (uVar7 != 0) {
            pcVar4 = "a";
          }
          Curl_infof(uVar5,"SOCKS4%s request granted.\n",pcVar4);
          curlx_nonblock(uVar8,1);
          return 0;
        case 0x5b:
          Curl_failf(uVar5,
                     "Can\'t complete SOCKS4 connection to %d.%d.%d.%d:%d. (%d), request rejected or failed."
                     ,local_12c,local_12b,local_12a,local_129,CONCAT11(local_128,local_127[0]),0x5b)
          ;
          break;
        case 0x5c:
          Curl_failf(uVar5,
                     "Can\'t complete SOCKS4 connection to %d.%d.%d.%d:%d. (%d), request rejected because SOCKS server cannot connect to identd on the client."
                     ,local_12c,local_12b,local_12a,local_129,CONCAT11(local_128,local_127[0]),0x5c)
          ;
          break;
        case 0x5d:
          Curl_failf(uVar5,
                     "Can\'t complete SOCKS4 connection to %d.%d.%d.%d:%d. (%d), request rejected because the client program and identd report different user-ids."
                     ,local_12c,local_12b,local_12a,local_129,CONCAT11(local_128,local_127[0]),0x5d)
          ;
          break;
        default:
          Curl_failf(uVar5,"Can\'t complete SOCKS4 connection to %d.%d.%d.%d:%d. (%d), Unknown.",
                     local_12c,local_12b,local_12a,local_129,CONCAT11(local_128,local_127[0]),
                     local_12f);
        }
      }
      else {
        Curl_failf(uVar5,"SOCKS4 reply has wrong version, version should be 4.");
      }
    }
    else {
      Curl_failf(uVar5,"Failed to receive SOCKS4 connect request ack.");
    }
  }
  else {
LAB_0004ec22:
    Curl_failf(uVar5,"Failed to send SOCKS4 connect request.");
  }
  return 7;
}

