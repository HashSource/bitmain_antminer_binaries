
int Curl_sasl_continue(int *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  char *pcVar1;
  size_t sVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *__s;
  int local_4c;
  char *local_48;
  char *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  
  iVar5 = param_1[1];
  iVar6 = *param_2;
  local_4c = 0;
  *param_4 = 1;
  local_44 = (char *)0x0;
  local_40 = 0;
  local_3c = 0;
  if (iVar5 == 0x10) {
    iVar5 = *(int *)(*param_1 + 8);
    *param_4 = 2;
    param_1[1] = 0;
    if (iVar5 == param_3) {
      return 0;
    }
    return 0x43;
  }
  if ((1 < iVar5 - 0xeU) && (*(int *)(*param_1 + 4) != param_3)) {
    *param_4 = 2;
    param_1[1] = 0;
    return 0x43;
  }
  switch(iVar5) {
  case 0:
    *param_4 = 2;
    return 0;
  case 1:
    iVar7 = sasl_create_plain_message(iVar6,param_2[0x48],param_2[0x49],&local_4c,&local_3c);
    iVar5 = 0x10;
    break;
  case 2:
    iVar7 = sasl_create_login_message(iVar6,param_2[0x48],&local_4c,&local_3c);
    iVar5 = 3;
    break;
  case 3:
    iVar5 = param_2[0x49];
    goto LAB_00056384;
  case 4:
    iVar5 = param_2[0x48];
LAB_00056384:
    iVar7 = sasl_create_login_message(iVar6,iVar5,&local_4c,&local_3c);
    iVar5 = 0x10;
    break;
  case 5:
    (**(code **)(*param_1 + 0x18))(iVar6 + 0x59c,&local_48);
    sVar2 = strlen(local_48);
    local_44 = (char *)0x0;
    local_40 = 0;
    if ((sVar2 == 0) || (*local_48 == '=')) {
      iVar5 = param_2[0x48];
      __s = (char *)param_2[0x49];
LAB_00056504:
      strlen(__s);
      uVar4 = curlx_uztoui();
      iVar7 = Curl_HMAC_init(Curl_HMAC_MD5,__s,uVar4);
      if (iVar7 != 0) {
LAB_00056520:
        Curl_HMAC_final(iVar7,&local_38);
        iVar5 = curl_maprintf("%s %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                              iVar5,local_38,local_37,local_36,local_35,local_34,local_33,local_32,
                              local_31,local_30,local_2f,local_2e,local_2d,local_2c,local_2b,
                              local_2a,local_29);
        if (iVar5 != 0) {
          iVar7 = Curl_base64_encode(iVar6,iVar5,0,&local_4c,&local_3c);
          (*Curl_cfree)(iVar5);
          goto LAB_000563de;
        }
      }
LAB_0005663c:
      iVar7 = 0x1b;
    }
    else {
      iVar7 = Curl_base64_decode(local_48,&local_44,&local_40);
      pcVar1 = local_44;
      if (iVar7 == 0) {
        iVar5 = param_2[0x48];
        __s = (char *)param_2[0x49];
        if (local_44 == (char *)0x0) goto LAB_00056504;
        sVar2 = strlen(local_44);
        strlen(__s);
        uVar4 = curlx_uztoui();
        iVar7 = Curl_HMAC_init(Curl_HMAC_MD5,__s,uVar4);
        if (iVar7 != 0) {
          if (sVar2 != 0) {
            uVar4 = curlx_uztoui(sVar2);
            Curl_HMAC_update(iVar7,pcVar1,uVar4);
          }
          goto LAB_00056520;
        }
        goto LAB_0005663c;
      }
    }
LAB_000563de:
    iVar5 = 0x10;
    (*Curl_cfree)(local_44);
    break;
  case 6:
    iVar5 = 7;
    (**(code **)(*param_1 + 0x18))(iVar6 + 0x59c,&local_48);
    iVar7 = Curl_sasl_create_digest_md5_message
                      (iVar6,local_48,param_2[0x48],param_2[0x49],*(undefined4 *)*param_1,&local_4c,
                       &local_3c);
    break;
  case 7:
    puVar3 = &DAT_0013a6fc;
    goto LAB_00056428;
  case 8:
    iVar7 = Curl_sasl_create_ntlm_type1_message
                      (param_2[0x48],param_2[0x49],param_2 + 0x9d,&local_4c,&local_3c);
    iVar5 = 9;
    break;
  case 9:
    (**(code **)(*param_1 + 0x18))(iVar6 + 0x59c,&local_48);
    iVar7 = Curl_sasl_decode_ntlm_type2_message(iVar6,local_48,param_2 + 0x9d);
    if (iVar7 == 0) {
      iVar5 = 0x10;
      iVar7 = Curl_sasl_create_ntlm_type3_message
                        (iVar6,param_2[0x48],param_2[0x49],param_2 + 0x9d,&local_4c,&local_3c);
    }
    else {
      iVar5 = 0x10;
    }
    break;
  default:
    Curl_failf(iVar6,"Unsupported SASL authentication mechanism");
    iVar7 = 1;
    goto LAB_00056332;
  case 0xd:
    if (param_1[4] == 0x100) {
      iVar5 = 0xe;
      iVar7 = sasl_create_oauth_bearer_message
                        (iVar6,param_2[0x48],param_2[0x26],param_2[0x2c],param_2[0x4b],&local_4c,
                         &local_3c);
    }
    else {
      iVar5 = 0x10;
      iVar7 = sasl_create_oauth_bearer_message
                        (iVar6,param_2[0x48],0,0,param_2[0x4b],&local_4c,&local_3c);
    }
    break;
  case 0xe:
    if (*(int *)(*param_1 + 8) == param_3) {
      *param_4 = 2;
      param_1[1] = 0;
      return 0;
    }
    if (*(int *)(*param_1 + 4) != param_3) {
      *param_4 = 2;
      param_1[1] = 0;
      return 0x43;
    }
    puVar3 = &DAT_0013a9ec;
LAB_00056428:
    local_4c = (*Curl_cstrdup)(puVar3);
    if (local_4c == 0) {
      iVar7 = 0x1b;
      goto LAB_00056332;
    }
    iVar5 = 0x10;
    goto LAB_00056308;
  case 0xf:
    param_1[2] = param_1[4] ^ param_1[2];
    iVar7 = Curl_sasl_start(param_1,param_2,*(undefined1 *)((int)param_1 + 0x16),param_4);
    iVar5 = param_1[1];
  }
  if (iVar7 == 0) {
    if (local_4c != 0) {
LAB_00056308:
      iVar7 = (**(code **)(*param_1 + 0x14))(param_2);
    }
  }
  else if (iVar7 == 0x3d) {
    iVar5 = 0xf;
    iVar7 = (**(code **)(*param_1 + 0x14))(param_2,&DAT_00136778);
  }
  else {
LAB_00056332:
    iVar5 = 0;
    *param_4 = 2;
  }
  (*Curl_cfree)(local_4c);
  param_1[1] = iVar5;
  return iVar7;
}

