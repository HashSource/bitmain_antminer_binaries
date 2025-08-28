
void ssl_tls_trace(uint param_1,int param_2,int param_3,undefined1 *param_4,undefined4 param_5,
                  undefined4 param_6,int *param_7)

{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined *puVar6;
  undefined1 uVar7;
  char acStack_438 [32];
  undefined1 auStack_418 [1024];
  
  if (param_7 == (int *)0x0) {
    return;
  }
  iVar5 = *param_7;
  if (iVar5 == 0) {
    return;
  }
  if (*(int *)(iVar5 + 0x1c8) == 0) {
    return;
  }
  if (1 < param_1) {
    return;
  }
  if (param_2 == 0x300) {
    pcVar4 = "SSLv3";
  }
  else if (param_2 < 0x301) {
    if (param_2 == 0) goto LAB_000576e0;
    if (param_2 == 2) {
      pcVar4 = "SSLv2";
    }
    else {
LAB_0005770e:
      curl_msnprintf(acStack_438,0x20,&DAT_0013ac98,param_2);
      if (param_2 == 0) goto LAB_000576e0;
      pcVar4 = acStack_438;
    }
  }
  else if (param_2 == 0x302) {
    pcVar4 = "TLSv1.1";
  }
  else if (param_2 < 0x302) {
    pcVar4 = "TLSv1.0";
  }
  else {
    if (param_2 != 0x303) goto LAB_0005770e;
    pcVar4 = "TLSv1.2";
  }
  param_2 = param_2 >> 8;
  if (param_3 != 0 && param_2 == 3) {
    if (param_3 == 0x16) {
      pcVar2 = "TLS handshake";
    }
    else if (param_3 < 0x17) {
      if (param_3 == 0x14) {
        pcVar2 = "TLS change cipher";
      }
      else if (param_3 == 0x15) {
        pcVar2 = "TLS alert";
      }
      else {
LAB_00057754:
        pcVar2 = "TLS Unknown";
      }
    }
    else if (param_3 == 0x17) {
      pcVar2 = "TLS app data";
    }
    else {
      if (param_3 != 0x100) goto LAB_00057754;
      pcVar2 = "TLS header";
    }
    uVar7 = *param_4;
LAB_0005775c:
    pcVar3 = pcVar2;
    switch(uVar7) {
    case 0:
      pcVar3 = "Hello request";
      break;
    case 1:
switchD_00057764_caseD_1:
      pcVar3 = "Client hello";
      break;
    case 2:
switchD_00057764_caseD_2:
      pcVar3 = "Server hello";
      break;
    default:
      goto switchD_00057764_caseD_3;
    case 4:
      pcVar3 = "Newsession Ticket";
      break;
    case 0xb:
      pcVar3 = "Certificate";
      break;
    case 0xc:
      pcVar3 = "Server key exchange";
      break;
    case 0xd:
switchD_00057764_caseD_d:
      pcVar3 = "Request CERT";
      break;
    case 0xe:
switchD_00057764_caseD_e:
      pcVar3 = "Server finished";
      break;
    case 0xf:
      pcVar3 = "CERT verify";
      break;
    case 0x10:
      pcVar3 = "Client key exchange";
      break;
    case 0x14:
      pcVar3 = "Finished";
      break;
    case 0x16:
      pcVar3 = "Certificate Status";
    }
    goto LAB_000576b2;
  }
  uVar7 = *param_4;
  pcVar3 = "";
  if (param_2 == 0) {
    pcVar2 = "";
    switch(uVar7) {
    case 0:
      pcVar3 = "Error";
      break;
    case 1:
      goto switchD_00057764_caseD_1;
    case 2:
      pcVar3 = "Client key";
      break;
    case 3:
      pcVar3 = "Client finished";
      break;
    case 4:
      goto switchD_00057764_caseD_2;
    case 5:
      pcVar3 = "Server verify";
      break;
    case 6:
      goto switchD_00057764_caseD_e;
    case 7:
      goto switchD_00057764_caseD_d;
    case 8:
      pcVar3 = "Client CERT";
      break;
    default:
      goto switchD_00057764_caseD_3;
    }
  }
  else {
    pcVar2 = pcVar3;
    if (param_2 == 3) goto LAB_0005775c;
switchD_00057764_caseD_3:
    pcVar2 = pcVar3;
    pcVar3 = "Unknown";
  }
LAB_000576b2:
  puVar6 = &DAT_0013ac10;
  if (param_1 == 0) {
    puVar6 = &DAT_0013ac14;
  }
  uVar1 = curl_msnprintf(auStack_418,0x400,"%s (%s), %s, %s (%d):\n",pcVar4,puVar6,pcVar2,pcVar3,
                         uVar7);
  Curl_debug(iVar5,0,auStack_418,uVar1,0);
LAB_000576e0:
  if (param_1 == 1) {
    uVar1 = 6;
  }
  else {
    uVar1 = 5;
  }
  Curl_debug(iVar5,uVar1,param_4,param_5,0);
  return;
}

