
/* WARNING: Type propagation algorithm not settling */

int rtsp_do(int *param_1,undefined1 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  size_t sVar8;
  char *pcVar9;
  int iVar10;
  undefined2 *puVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  size_t local_60;
  int local_5c;
  size_t local_58;
  int local_54;
  char *local_4c;
  undefined1 *local_48;
  char *local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  
  iVar14 = *param_1;
  uVar12 = *(uint *)(iVar14 + 0x40c);
  uVar2 = *(undefined4 *)(iVar14 + 0x86a0);
  iVar13 = *(int *)(iVar14 + 0x14c);
  *param_2 = 1;
  *(undefined4 *)(iVar13 + 0x60) = uVar2;
  *(undefined4 *)(iVar13 + 100) = 0;
  *(undefined1 *)(iVar14 + 0x307) = 1;
  switch(uVar12) {
  case 1:
    local_4c = "OPTIONS";
    break;
  case 2:
    *(undefined1 *)(iVar14 + 0x307) = 0;
    local_4c = "DESCRIBE";
    break;
  case 3:
    local_4c = "ANNOUNCE";
    break;
  case 4:
    local_4c = "SETUP";
    break;
  case 5:
    local_4c = "PLAY";
    break;
  case 6:
    local_4c = "PAUSE";
    break;
  case 7:
    local_4c = "TEARDOWN";
    break;
  case 8:
    *(undefined1 *)(iVar14 + 0x307) = 0;
    local_4c = "GET_PARAMETER";
    break;
  case 9:
    local_4c = "SET_PARAMETER";
    break;
  case 10:
    local_4c = "RECORD";
    break;
  case 0xb:
    *(undefined1 *)(iVar14 + 0x307) = 0;
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,iVar13 + 0x20,0xffffffff,0);
    return 0;
  case 0xc:
    Curl_failf(iVar14,"Got invalid RTSP request: RTSPREQ_LAST");
    return 0x2b;
  default:
    Curl_failf(iVar14,"Got invalid RTSP request");
    return 0x2b;
  }
  iVar10 = *(int *)(iVar14 + 0x3cc);
  if ((iVar10 == 0) && ((uVar12 & 0xfffffff8) != 0)) {
    Curl_failf(iVar14,"Refusing to issue an RTSP request [%s] without a session ID.",local_4c);
    return 0x2b;
  }
  puVar11 = *(undefined2 **)(iVar14 + 0x3d0);
  if (puVar11 == (undefined2 *)0x0) {
    puVar11 = &DAT_00136778;
  }
  puVar3 = (undefined1 *)Curl_checkheaders(param_1,"Transport:");
  if (puVar3 == (undefined1 *)0x0 && uVar12 == 4) {
    if (*(int *)(iVar14 + 0x3d4) == 0) {
      Curl_failf(iVar14,"Refusing to issue an RTSP SETUP without a Transport: header.");
      return 0x2b;
    }
    (*Curl_cfree)(param_1[0x93]);
    param_1[0x93] = 0;
    puVar3 = (undefined1 *)curl_maprintf("Transport: %s\r\n",*(undefined4 *)(iVar14 + 0x3d4));
    param_1[0x93] = (int)puVar3;
    if (puVar3 == (undefined1 *)0x0) {
      return 0x1b;
    }
    local_48 = (undefined1 *)0x0;
    local_44 = (char *)0x0;
  }
  else {
    local_48 = (undefined1 *)0x0;
    if (uVar12 == 2) {
      iVar4 = Curl_checkheaders(param_1,"Accept:");
      local_44 = "Accept: application/sdp\r\n";
      if (iVar4 != 0) {
        local_44 = (char *)0x0;
      }
      iVar4 = Curl_checkheaders(param_1,"Accept-Encoding:");
      if (iVar4 == 0) {
        if (*(int *)(iVar14 + 0x35c) == 0) {
          local_48 = (undefined1 *)0x0;
        }
        else {
          (*Curl_cfree)(param_1[0x8d]);
          uVar2 = *(undefined4 *)(iVar14 + 0x35c);
          param_1[0x8d] = 0;
          local_48 = (undefined1 *)curl_maprintf("Accept-Encoding: %s\r\n",uVar2);
          param_1[0x8d] = (int)local_48;
          if (local_48 == (undefined1 *)0x0) {
            return 0x1b;
          }
        }
      }
    }
    else {
      local_44 = (char *)0x0;
    }
  }
  iVar4 = Curl_checkheaders(param_1,"User-Agent:");
  if ((iVar4 == 0) || (param_1[0x8c] == 0)) {
    iVar4 = Curl_checkheaders(param_1,"User-Agent:");
    if (iVar4 == 0) {
      if (*(int *)(iVar14 + 0x3a8) == 0) {
        local_40 = (undefined1 *)0x0;
      }
      else {
        local_40 = (undefined1 *)param_1[0x8c];
      }
    }
    else {
      local_40 = (undefined1 *)0x0;
    }
  }
  else {
    (*Curl_cfree)();
    param_1[0x8c] = 0;
    local_40 = (undefined1 *)0x0;
  }
  iVar4 = Curl_http_output_auth(param_1,local_4c,puVar11,0);
  if (iVar4 != 0) {
    return iVar4;
  }
  puVar7 = (undefined1 *)param_1[0x8b];
  puVar6 = (undefined1 *)param_1[0x8e];
  (*Curl_cfree)(param_1[0x90]);
  iVar4 = *(int *)(iVar14 + 0x458);
  param_1[0x90] = 0;
  if ((iVar4 == 0) || (iVar4 = Curl_checkheaders(param_1,"Referer:"), iVar4 != 0)) {
    local_3c = (undefined1 *)0x0;
    param_1[0x90] = 0;
  }
  else {
    local_3c = (undefined1 *)curl_maprintf("Referer: %s\r\n",*(undefined4 *)(iVar14 + 0x458));
    param_1[0x90] = (int)local_3c;
  }
  if ((((*(char *)(iVar14 + 0x8691) == '\0') || ((uVar12 & 0xf) == 0)) ||
      (iVar4 = Curl_checkheaders(param_1,"Range:"), iVar4 != 0)) || (*(int *)(iVar14 + 0x8694) == 0)
     ) {
    local_38 = (undefined1 *)0x0;
  }
  else {
    (*Curl_cfree)(param_1[0x8f]);
    uVar2 = *(undefined4 *)(iVar14 + 0x8694);
    param_1[0x8f] = 0;
    local_38 = (undefined1 *)curl_maprintf("Range: %s\r\n",uVar2);
    param_1[0x8f] = (int)local_38;
  }
  iVar4 = Curl_checkheaders(param_1,"CSeq:");
  if (iVar4 != 0) {
    Curl_failf(iVar14,"CSeq cannot be set as a custom header.");
    return 0x55;
  }
  iVar4 = Curl_checkheaders(param_1,"Session:");
  if (iVar4 != 0) {
    Curl_failf(iVar14,"Session ID cannot be set as a custom header.");
    return 0x2b;
  }
  iVar4 = Curl_add_buffer_init();
  if (iVar4 == 0) {
    return 0x1b;
  }
  iVar5 = Curl_add_bufferf(iVar4,"%s %s RTSP/1.0\r\nCSeq: %ld\r\n",local_4c,puVar11,
                           *(undefined4 *)(iVar13 + 0x60));
  if (iVar5 != 0) {
    return iVar5;
  }
  if ((iVar10 != 0) && (iVar10 = Curl_add_bufferf(iVar4,"Session: %s\r\n",iVar10), iVar10 != 0)) {
    return iVar10;
  }
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_0013a6fc;
  }
  if (local_48 == (undefined1 *)0x0) {
    local_48 = &DAT_0013a6fc;
  }
  if (local_38 == (undefined1 *)0x0) {
    local_38 = &DAT_0013a6fc;
  }
  if (local_3c == (undefined1 *)0x0) {
    local_3c = &DAT_0013a6fc;
  }
  if (local_40 == (undefined1 *)0x0) {
    local_40 = &DAT_0013a6fc;
  }
  if (puVar7 == (undefined1 *)0x0) {
    puVar7 = &DAT_0013a6fc;
  }
  if (puVar6 == (undefined1 *)0x0) {
    puVar6 = &DAT_0013a6fc;
  }
  pcVar9 = "";
  if (local_44 != (char *)0x0) {
    pcVar9 = local_44;
  }
  iVar10 = Curl_add_bufferf(iVar4,"%s%s%s%s%s%s%s%s",puVar3,pcVar9,local_48,local_38,local_3c,
                            local_40,puVar7,puVar6);
  (*Curl_cfree)(param_1[0x8e]);
  param_1[0x8e] = 0;
  if (iVar10 != 0) {
    return iVar10;
  }
  if (((uVar12 == 2) || (uVar12 == 4)) &&
     (iVar10 = Curl_add_timecondition(iVar14,iVar4), iVar10 != 0)) {
    return iVar10;
  }
  iVar10 = Curl_add_custom_headers(param_1,0,iVar4);
  if (iVar10 != 0) {
    return iVar10;
  }
  if (((uVar12 != 9) && (uVar12 != 3)) && (uVar12 != 8)) {
    *(undefined1 *)(iVar14 + 0x14b) = 1;
    iVar10 = Curl_add_buffer(iVar4,&DAT_0013c1d4,2);
    if (iVar10 != 0) {
      return iVar10;
    }
    local_58 = 0;
    local_54 = 0;
    goto LAB_0005363e;
  }
  if (*(char *)(iVar14 + 0x309) == '\0') {
    local_60 = *(size_t *)(iVar14 + 0x86b0);
    local_5c = *(int *)(iVar14 + 0x86b4);
    if (local_5c == -1 && local_60 == 0xffffffff) {
      if (*(char **)(iVar14 + 0x18c) == (char *)0x0) {
        local_60 = 0;
        local_5c = 0;
      }
      else {
        local_60 = strlen(*(char **)(iVar14 + 0x18c));
        local_5c = 0;
      }
    }
    local_58 = 0;
    local_54 = 0;
    *(undefined4 *)(iVar14 + 0x278) = 2;
  }
  else {
    local_58 = *(size_t *)(iVar14 + 0x86b0);
    local_54 = *(int *)(iVar14 + 0x86b4);
    *(undefined4 *)(iVar14 + 0x278) = 4;
    local_60 = 0;
    local_5c = 0;
  }
  uVar2 = 0;
  bVar1 = -local_5c < (int)(uint)(local_60 != 0);
  if ((bVar1) || (-local_54 < (int)(uint)(local_58 != 0))) {
    iVar10 = Curl_checkheaders(param_1,"Content-Length:");
    if (iVar10 == 0) {
      sVar8 = local_60;
      if (*(char *)(iVar14 + 0x309) != '\0') {
        sVar8 = local_58;
        local_5c = local_54;
      }
      iVar10 = Curl_add_bufferf(iVar4,"Content-Length: %lld\r\n",sVar8,local_5c);
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    if (uVar12 - 8 < 2) {
      iVar10 = Curl_checkheaders(param_1,"Content-Type:");
      if (iVar10 == 0) {
        iVar10 = Curl_add_bufferf(iVar4,"Content-Type: text/parameters\r\n");
        goto joined_r0x000537fa;
      }
    }
    else if ((uVar12 == 3) && (iVar10 = Curl_checkheaders(param_1,"Content-Type:"), iVar10 == 0)) {
      iVar10 = Curl_add_bufferf(iVar4,"Content-Type: application/sdp\r\n");
joined_r0x000537fa:
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    *(undefined1 *)(iVar14 + 0x867c) = 0;
  }
  else {
    bVar15 = uVar12 == 8;
    if (bVar15) {
      uVar2 = 5;
    }
    if (bVar15) {
      *(undefined4 *)(iVar14 + 0x278) = uVar2;
      *(bool *)(iVar14 + 0x307) = bVar15;
    }
  }
  *(undefined1 *)(iVar14 + 0x14b) = 1;
  iVar10 = Curl_add_buffer(iVar4,&DAT_0013c1d4,2);
  if (iVar10 != 0) {
    return iVar10;
  }
  if ((bVar1) &&
     (iVar10 = Curl_add_buffer(iVar4,*(undefined4 *)(iVar14 + 0x18c),local_60), iVar10 != 0)) {
    return iVar10;
  }
LAB_0005363e:
  iVar10 = Curl_add_buffer_send(iVar4,param_1,iVar14 + 0x870c,0,0);
  if (iVar10 == 0) {
    if (local_54 == 0 && local_58 == 0) {
      uVar2 = 0xffffffff;
      iVar4 = 0;
    }
    else {
      iVar4 = iVar13 + 0x28;
      uVar2 = 0;
    }
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,iVar13 + 0x20,uVar2,iVar4);
    iVar4 = *(int *)(iVar13 + 0x28);
    iVar13 = *(int *)(iVar13 + 0x2c);
    *(int *)(iVar14 + 0x86a0) = *(int *)(iVar14 + 0x86a0) + 1;
    if (iVar4 != 0 || iVar13 != 0) {
      Curl_pgrsSetUploadCounter(iVar14);
      iVar13 = Curl_pgrsUpdate(param_1);
      if (iVar13 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = 0x2a;
      }
    }
  }
  else {
    Curl_failf(iVar14,"Failed sending RTSP request");
  }
  return iVar10;
}

