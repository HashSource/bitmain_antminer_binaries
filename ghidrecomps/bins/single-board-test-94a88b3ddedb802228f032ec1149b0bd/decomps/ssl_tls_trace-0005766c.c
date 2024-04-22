
void ssl_tls_trace(uint param_1,int param_2,int param_3,undefined *param_4,undefined4 param_5,
                  undefined4 param_6,int *param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined uVar6;
  undefined auStack_438 [32];
  undefined auStack_418 [1024];
  
  if (param_7 == (int *)0x0) {
    return;
  }
  iVar4 = *param_7;
  if (iVar4 == 0) {
    return;
  }
  if (*(int *)(iVar4 + 0x1c8) == 0) {
    return;
  }
  if (1 < param_1) {
    return;
  }
  puVar3 = DAT_000578e4;
  if (param_2 != 0x300) {
    if (param_2 < 0x301) {
      if (param_2 == 0) goto LAB_000576e0;
      puVar3 = DAT_00057878;
      if (param_2 != 2) goto LAB_0005770e;
    }
    else {
      puVar3 = DAT_00057890;
      if (((param_2 != 0x302) && (puVar3 = DAT_000578e0, 0x301 < param_2)) &&
         (puVar3 = DAT_000578dc, param_2 != 0x303)) {
LAB_0005770e:
        curl_msnprintf(auStack_438,0x20,DAT_00057888,param_2);
        if (param_2 == 0) goto LAB_000576e0;
        puVar3 = auStack_438;
      }
    }
  }
  param_2 = param_2 >> 8;
  uVar1 = DAT_0005789c;
  if (param_3 != 0 && param_2 == 3) {
    uVar2 = DAT_000578f0;
    if (param_3 != 0x16) {
      if (param_3 < 0x17) {
        uVar2 = DAT_000578f4;
        if ((param_3 != 0x14) && (uVar2 = DAT_000578ec, param_3 != 0x15)) {
LAB_00057754:
          uVar2 = DAT_0005788c;
        }
      }
      else {
        uVar2 = DAT_000578f8;
        if ((param_3 != 0x17) && (uVar2 = DAT_000578e8, param_3 != 0x100)) goto LAB_00057754;
      }
    }
    uVar6 = *param_4;
LAB_0005775c:
    switch(uVar6) {
    case 0:
      uVar1 = DAT_000578a4;
      break;
    case 1:
switchD_00057764_caseD_1:
      uVar1 = DAT_00057894;
      break;
    case 2:
switchD_00057764_caseD_2:
      uVar1 = DAT_00057898;
      break;
    default:
      goto switchD_00057764_caseD_3;
    case 4:
      uVar1 = DAT_000578a8;
      break;
    case 0xb:
      uVar1 = DAT_000578b0;
      break;
    case 0xc:
      uVar1 = DAT_000578ac;
      break;
    case 0xd:
switchD_00057764_caseD_d:
      uVar1 = DAT_000578a0;
      break;
    case 0xe:
      break;
    case 0xf:
      uVar1 = DAT_000578c0;
      break;
    case 0x10:
      uVar1 = DAT_000578bc;
      break;
    case 0x14:
      uVar1 = DAT_000578b8;
      break;
    case 0x16:
      uVar1 = DAT_000578b4;
    }
    goto LAB_000576b2;
  }
  uVar6 = *param_4;
  uVar2 = DAT_000578c4;
  if (param_2 == 0) {
    switch(uVar6) {
    case 0:
      uVar1 = DAT_000578c8;
      break;
    case 1:
      goto switchD_00057764_caseD_1;
    case 2:
      uVar1 = DAT_000578d8;
      break;
    case 3:
      uVar1 = DAT_000578d4;
      break;
    case 4:
      goto switchD_00057764_caseD_2;
    case 5:
      uVar1 = DAT_000578d0;
      break;
    case 6:
      break;
    case 7:
      goto switchD_00057764_caseD_d;
    case 8:
      uVar1 = DAT_000578cc;
      break;
    default:
      goto switchD_00057764_caseD_3;
    }
  }
  else {
    if (param_2 == 3) goto LAB_0005775c;
switchD_00057764_caseD_3:
    uVar1 = DAT_0005787c;
  }
LAB_000576b2:
  uVar5 = DAT_00057880;
  if (param_1 == 0) {
    uVar5 = DAT_000578fc;
  }
  uVar1 = curl_msnprintf(auStack_418,0x400,DAT_00057884,puVar3,uVar5,uVar2,uVar1,uVar6);
  Curl_debug(iVar4,0,auStack_418,uVar1,0);
LAB_000576e0:
  if (param_1 == 1) {
    uVar1 = 6;
  }
  else {
    uVar1 = 5;
  }
  Curl_debug(iVar4,uVar1,param_4,param_5,0);
  return;
}

