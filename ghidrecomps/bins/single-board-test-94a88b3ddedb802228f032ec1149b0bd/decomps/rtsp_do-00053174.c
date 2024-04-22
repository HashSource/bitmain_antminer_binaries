
int rtsp_do(int *param_1,undefined *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  size_t local_60;
  uint local_5c;
  size_t local_58;
  uint local_54;
  undefined4 local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  
  iVar13 = *param_1;
  uVar11 = *(uint *)(iVar13 + 0x40c);
  uVar2 = *(undefined4 *)(iVar13 + 0x86a0);
  iVar12 = *(int *)(iVar13 + 0x14c);
  *param_2 = 1;
  *(undefined4 *)(iVar12 + 0x60) = uVar2;
  *(undefined4 *)(iVar12 + 100) = 0;
  *(undefined *)(iVar13 + 0x307) = 1;
  local_4c = DAT_000534b4;
  uVar2 = DAT_0005349c;
  switch(uVar11) {
  case 1:
    local_4c = DAT_00053478;
    break;
  case 2:
    *(undefined *)(iVar13 + 0x307) = 0;
    local_4c = uVar2;
    break;
  case 3:
    local_4c = DAT_000534a0;
    break;
  case 4:
    local_4c = DAT_000534a4;
    break;
  case 5:
    local_4c = DAT_000534a8;
    break;
  case 6:
    local_4c = DAT_000534ac;
    break;
  case 7:
    local_4c = DAT_000534b0;
    break;
  case 8:
    *(undefined *)(iVar13 + 0x307) = 0;
    break;
  case 9:
    local_4c = DAT_000534b8;
    break;
  case 10:
    local_4c = DAT_000534bc;
    break;
  case 0xb:
    *(undefined *)(iVar13 + 0x307) = 0;
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,iVar12 + 0x20,0xffffffff,0);
    return 0;
  case 0xc:
    Curl_failf(iVar13,DAT_00053470);
    return 0x2b;
  default:
    Curl_failf(iVar13,DAT_00053474);
    return 0x2b;
  }
  iVar10 = *(int *)(iVar13 + 0x3cc);
  if ((iVar10 == 0) && ((uVar11 & 0xfffffff8) != 0)) {
    Curl_failf(iVar13,DAT_000534cc,local_4c);
    return 0x2b;
  }
  iVar4 = *(int *)(iVar13 + 0x3d0);
  if (*(int *)(iVar13 + 0x3d0) == 0) {
    iVar4 = DAT_0005347c;
  }
  iVar3 = Curl_checkheaders(param_1,DAT_00053480);
  if (iVar3 == 0 && uVar11 == 4) {
    if (*(int *)(iVar13 + 0x3d4) == 0) {
      Curl_failf(iVar13,DAT_000534d0);
      return 0x2b;
    }
    (**DAT_00053484)(param_1[0x93]);
    param_1[0x93] = 0;
    iVar3 = curl_maprintf(DAT_00053488,*(undefined4 *)(iVar13 + 0x3d4));
    param_1[0x93] = iVar3;
    if (iVar3 == 0) {
      return 0x1b;
    }
    local_48 = 0;
  }
  else {
    local_48 = 0;
    if (uVar11 == 2) {
      Curl_checkheaders(param_1,DAT_000534c0);
      iVar3 = Curl_checkheaders(param_1,DAT_000534c8);
      if (iVar3 == 0) {
        if (*(int *)(iVar13 + 0x35c) == 0) {
          local_48 = 0;
        }
        else {
          (**DAT_00053484)(param_1[0x8d]);
          uVar2 = DAT_000534d4;
          uVar5 = *(undefined4 *)(iVar13 + 0x35c);
          param_1[0x8d] = 0;
          local_48 = curl_maprintf(uVar2,uVar5);
          param_1[0x8d] = local_48;
          if (local_48 == 0) {
            return 0x1b;
          }
        }
      }
    }
  }
  iVar3 = Curl_checkheaders(param_1,DAT_0005348c);
  if ((iVar3 == 0) || (param_1[0x8c] == 0)) {
    iVar3 = Curl_checkheaders(param_1,DAT_0005348c);
    if (iVar3 == 0) {
      if (*(int *)(iVar13 + 0x3a8) == 0) {
        local_40 = 0;
      }
      else {
        local_40 = param_1[0x8c];
      }
    }
    else {
      local_40 = 0;
    }
  }
  else {
    (**DAT_00053484)();
    param_1[0x8c] = 0;
    local_40 = 0;
  }
  iVar3 = Curl_http_output_auth(param_1,local_4c,iVar4,0);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar6 = param_1[0x8b];
  iVar3 = param_1[0x8e];
  (*Curl_cfree)(param_1[0x90]);
  iVar8 = *(int *)(iVar13 + 0x458);
  param_1[0x90] = 0;
  if ((iVar8 == 0) || (iVar8 = Curl_checkheaders(param_1,DAT_00053490), iVar8 != 0)) {
    local_3c = 0;
    param_1[0x90] = 0;
  }
  else {
    local_3c = curl_maprintf(DAT_00053770,*(undefined4 *)(iVar13 + 0x458));
    param_1[0x90] = local_3c;
  }
  if ((((*(char *)(iVar13 + 0x8691) == '\0') || ((uVar11 & 0xf) == 0)) ||
      (iVar8 = Curl_checkheaders(param_1,DAT_000534d8), iVar8 != 0)) ||
     (*(int *)(iVar13 + 0x8694) == 0)) {
    local_38 = 0;
  }
  else {
    (*Curl_cfree)(param_1[0x8f]);
    uVar2 = DAT_000534dc;
    uVar5 = *(undefined4 *)(iVar13 + 0x8694);
    param_1[0x8f] = 0;
    local_38 = curl_maprintf(uVar2,uVar5);
    param_1[0x8f] = local_38;
  }
  iVar8 = Curl_checkheaders(param_1,DAT_00053494);
  if (iVar8 != 0) {
    Curl_failf(iVar13,DAT_00053498);
    return 0x55;
  }
  iVar8 = Curl_checkheaders(param_1,DAT_00053768);
  if (iVar8 != 0) {
    Curl_failf(iVar13,DAT_0005376c);
    return 0x2b;
  }
  iVar8 = Curl_add_buffer_init();
  if (iVar8 == 0) {
    return 0x1b;
  }
  iVar4 = Curl_add_bufferf(iVar8,DAT_00053774,local_4c,iVar4,*(undefined4 *)(iVar12 + 0x60));
  if (iVar4 != 0) {
    return iVar4;
  }
  if ((iVar10 != 0) && (iVar10 = Curl_add_bufferf(iVar8,DAT_00053778,iVar10), iVar10 != 0)) {
    return iVar10;
  }
  if (local_48 == 0) {
    local_48 = DAT_0005377c;
  }
  if (local_38 == 0) {
    local_38 = DAT_0005377c;
  }
  if (local_3c == 0) {
    local_3c = DAT_0005377c;
  }
  if (local_40 == 0) {
    local_40 = DAT_0005377c;
  }
  if (iVar6 == 0) {
    iVar6 = DAT_0005377c;
  }
  if (iVar3 == 0) {
    iVar3 = DAT_0005377c;
  }
  iVar10 = Curl_add_bufferf(iVar8,DAT_00053780);
  (*Curl_cfree)(param_1[0x8e]);
  param_1[0x8e] = 0;
  if (iVar10 != 0) {
    return iVar10;
  }
  if (((uVar11 == 2) || (uVar11 == 4)) &&
     (iVar10 = Curl_add_timecondition(iVar13,iVar8), iVar10 != 0)) {
    return iVar10;
  }
  iVar10 = Curl_add_custom_headers(param_1,0,iVar8);
  if (iVar10 != 0) {
    return iVar10;
  }
  if (((uVar11 != 9) && (uVar11 != 3)) && (uVar11 != 8)) {
    *(undefined *)(iVar13 + 0x14b) = 1;
    iVar10 = Curl_add_buffer(iVar8,DAT_00053784,2,1,local_48,local_38,local_3c,local_40,iVar6,iVar3)
    ;
    if (iVar10 != 0) {
      return iVar10;
    }
    local_58 = 0;
    local_54 = 0;
    goto LAB_0005363e;
  }
  if (*(char *)(iVar13 + 0x309) == '\0') {
    local_60 = *(size_t *)(iVar13 + 0x86b0);
    local_5c = *(uint *)(iVar13 + 0x86b4);
    if (local_5c == 0xffffffff && local_60 == 0xffffffff) {
      if (*(char **)(iVar13 + 0x18c) == (char *)0x0) {
        local_60 = 0;
        local_5c = 0;
      }
      else {
        local_60 = strlen(*(char **)(iVar13 + 0x18c));
        local_5c = 0;
      }
    }
    local_58 = 0;
    local_54 = 0;
    *(undefined4 *)(iVar13 + 0x278) = 2;
  }
  else {
    local_58 = *(size_t *)(iVar13 + 0x86b0);
    local_54 = *(uint *)(iVar13 + 0x86b4);
    *(undefined4 *)(iVar13 + 0x278) = 4;
    local_60 = 0;
    local_5c = 0;
  }
  uVar2 = 0;
  bVar1 = (int)(-(uint)(local_60 != 0) - local_5c) < 0 !=
          (SBORROW4(-local_5c,(uint)(local_60 != 0)) != false);
  if ((bVar1) ||
     ((int)(-(uint)(local_58 != 0) - local_54) < 0 !=
      (SBORROW4(-local_54,(uint)(local_58 != 0)) != false))) {
    iVar10 = Curl_checkheaders(param_1,DAT_0005378c);
    if (iVar10 == 0) {
      sVar7 = local_60;
      if (*(char *)(iVar13 + 0x309) != '\0') {
        sVar7 = local_58;
        local_5c = local_54;
      }
      iVar10 = Curl_add_bufferf(iVar8,DAT_00053834,sVar7,local_5c);
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    if (uVar11 - 8 < 2) {
      iVar10 = Curl_checkheaders(param_1,DAT_00053828);
      if (iVar10 == 0) {
        iVar10 = Curl_add_bufferf(iVar8,DAT_00053830);
        goto joined_r0x000537fa;
      }
    }
    else if ((uVar11 == 3) && (iVar10 = Curl_checkheaders(param_1,DAT_00053828), iVar10 == 0)) {
      iVar10 = Curl_add_bufferf(iVar8,DAT_0005382c);
joined_r0x000537fa:
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    *(undefined *)(iVar13 + 0x867c) = 0;
  }
  else {
    bVar14 = uVar11 == 8;
    if (bVar14) {
      uVar2 = 5;
    }
    if (bVar14) {
      *(undefined4 *)(iVar13 + 0x278) = uVar2;
      *(bool *)(iVar13 + 0x307) = bVar14;
    }
  }
  *(undefined *)(iVar13 + 0x14b) = 1;
  iVar10 = Curl_add_buffer(iVar8,DAT_00053784,2);
  if (iVar10 != 0) {
    return iVar10;
  }
  if ((bVar1) &&
     (iVar10 = Curl_add_buffer(iVar8,*(undefined4 *)(iVar13 + 0x18c),local_60), iVar10 != 0)) {
    return iVar10;
  }
LAB_0005363e:
  iVar10 = Curl_add_buffer_send(iVar8,param_1,iVar13 + 0x870c,0,0);
  if (iVar10 == 0) {
    if ((local_54 | local_58) == 0) {
      uVar2 = 0xffffffff;
      iVar4 = 0;
    }
    else {
      iVar4 = iVar12 + 0x28;
      uVar2 = 0;
    }
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,iVar12 + 0x20,uVar2,iVar4);
    uVar11 = *(uint *)(iVar12 + 0x28);
    uVar9 = *(uint *)(iVar12 + 0x2c);
    *(int *)(iVar13 + 0x86a0) = *(int *)(iVar13 + 0x86a0) + 1;
    if ((uVar11 | uVar9) != 0) {
      Curl_pgrsSetUploadCounter(iVar13);
      iVar12 = Curl_pgrsUpdate(param_1);
      if (iVar12 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = 0x2a;
      }
    }
  }
  else {
    Curl_failf(iVar13,DAT_00053788);
  }
  return iVar10;
}

