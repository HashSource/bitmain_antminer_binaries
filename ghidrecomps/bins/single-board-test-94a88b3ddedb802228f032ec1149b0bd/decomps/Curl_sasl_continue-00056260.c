
int Curl_sasl_continue(int *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  code **ppcVar5;
  int iVar6;
  int iVar7;
  char *__s;
  int local_4c;
  char *local_48;
  char *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  
  iVar4 = param_1[1];
  iVar6 = *param_2;
  local_4c = 0;
  *param_4 = 1;
  ppcVar5 = DAT_00056604;
  local_44 = (char *)0x0;
  local_40 = 0;
  local_3c = 0;
  if (iVar4 == 0x10) {
    iVar4 = *(int *)(*param_1 + 8);
    *param_4 = 2;
    param_1[1] = 0;
    if (iVar4 == param_3) {
      return 0;
    }
    return 0x43;
  }
  if ((1 < iVar4 - 0xeU) && (*(int *)(*param_1 + 4) != param_3)) {
    *param_4 = 2;
    param_1[1] = 0;
    return 0x43;
  }
  switch(iVar4) {
  case 0:
    *param_4 = 2;
    return 0;
  case 1:
    iVar7 = sasl_create_plain_message(iVar6,param_2[0x48],param_2[0x49],&local_4c,&local_3c);
    iVar4 = 0x10;
    ppcVar5 = DAT_00056604;
    break;
  case 2:
    iVar7 = sasl_create_login_message(iVar6,param_2[0x48],&local_4c,&local_3c);
    iVar4 = 3;
    ppcVar5 = DAT_00056604;
    break;
  case 3:
    iVar4 = param_2[0x49];
    goto LAB_00056384;
  case 4:
    iVar4 = param_2[0x48];
LAB_00056384:
    iVar7 = sasl_create_login_message(iVar6,iVar4,&local_4c,&local_3c);
    iVar4 = 0x10;
    ppcVar5 = DAT_00056604;
    break;
  case 5:
    (**(code **)(*param_1 + 0x18))(iVar6 + 0x59c,&local_48);
    sVar2 = strlen(local_48);
    local_44 = (char *)0x0;
    local_40 = 0;
    if ((sVar2 == 0) || (*local_48 == '=')) {
      iVar4 = param_2[0x48];
      __s = (char *)param_2[0x49];
LAB_00056504:
      strlen(__s);
      uVar3 = curlx_uztoui();
      iVar7 = Curl_HMAC_init(DAT_000565fc,__s,uVar3);
      if (iVar7 != 0) {
LAB_00056520:
        Curl_HMAC_final(iVar7,&local_38);
        iVar4 = curl_maprintf(DAT_00056600,iVar4,local_38,local_37,local_36,local_35,local_34,
                              local_33,local_32,local_31,local_30,local_2f,local_2e,local_2d,
                              local_2c,local_2b,local_2a,local_29);
        ppcVar5 = DAT_00056604;
        if (iVar4 != 0) {
          iVar7 = Curl_base64_encode(iVar6,iVar4,0,&local_4c,&local_3c);
          (**ppcVar5)(iVar4);
          goto LAB_000563de;
        }
      }
LAB_0005663c:
      iVar7 = 0x1b;
      ppcVar5 = DAT_00056604;
    }
    else {
      iVar7 = Curl_base64_decode(local_48,&local_44,&local_40);
      pcVar1 = local_44;
      ppcVar5 = DAT_00056604;
      if (iVar7 == 0) {
        iVar4 = param_2[0x48];
        __s = (char *)param_2[0x49];
        if (local_44 == (char *)0x0) goto LAB_00056504;
        sVar2 = strlen(local_44);
        strlen(__s);
        uVar3 = curlx_uztoui();
        iVar7 = Curl_HMAC_init(DAT_000566a8,__s,uVar3);
        if (iVar7 != 0) {
          if (sVar2 != 0) {
            uVar3 = curlx_uztoui(sVar2);
            Curl_HMAC_update(iVar7,pcVar1,uVar3);
          }
          goto LAB_00056520;
        }
        goto LAB_0005663c;
      }
    }
LAB_000563de:
    iVar4 = 0x10;
    (**ppcVar5)(local_44);
    break;
  case 6:
    iVar4 = 7;
    (**(code **)(*param_1 + 0x18))(iVar6 + 0x59c,&local_48);
    iVar7 = Curl_sasl_create_digest_md5_message
                      (iVar6,local_48,param_2[0x48],param_2[0x49],*(undefined4 *)*param_1,&local_4c,
                       &local_3c);
    break;
  case 7:
    uVar3 = DAT_000565f4;
    ppcVar5 = DAT_000565f0;
    goto LAB_00056428;
  case 8:
    iVar7 = Curl_sasl_create_ntlm_type1_message
                      (param_2[0x48],param_2[0x49],param_2 + 0x9d,&local_4c,&local_3c);
    iVar4 = 9;
    ppcVar5 = DAT_00056604;
    break;
  case 9:
    (**(code **)(*param_1 + 0x18))(iVar6 + 0x59c,&local_48);
    iVar7 = Curl_sasl_decode_ntlm_type2_message(iVar6,local_48,param_2 + 0x9d);
    if (iVar7 == 0) {
      iVar4 = 0x10;
      iVar7 = Curl_sasl_create_ntlm_type3_message
                        (iVar6,param_2[0x48],param_2[0x49],param_2 + 0x9d,&local_4c,&local_3c);
      ppcVar5 = DAT_00056604;
    }
    else {
      iVar4 = 0x10;
      ppcVar5 = DAT_00056604;
    }
    break;
  default:
    Curl_failf(iVar6,DAT_000565ec);
    iVar7 = 1;
    ppcVar5 = DAT_00056604;
    goto LAB_00056332;
  case 0xd:
    if (param_1[4] == 0x100) {
      iVar4 = 0xe;
      iVar7 = sasl_create_oauth_bearer_message
                        (iVar6,param_2[0x48],param_2[0x26],param_2[0x2c],param_2[0x4b],&local_4c,
                         &local_3c);
      ppcVar5 = DAT_000566ac;
    }
    else {
      iVar4 = 0x10;
      iVar7 = sasl_create_oauth_bearer_message
                        (iVar6,param_2[0x48],0,0,param_2[0x4b],&local_4c,&local_3c);
      ppcVar5 = DAT_00056604;
    }
    break;
  case 0xe:
    if (*(int *)(*param_1 + 8) == param_3) {
      *param_4 = 2;
      param_1[1] = 0;
      return 0;
    }
    uVar3 = DAT_000566a4;
    ppcVar5 = DAT_000566a0;
    if (*(int *)(*param_1 + 4) != param_3) {
      *param_4 = 2;
      param_1[1] = 0;
      return 0x43;
    }
LAB_00056428:
    local_4c = (**ppcVar5)(uVar3);
    if (local_4c == 0) {
      iVar7 = 0x1b;
      ppcVar5 = DAT_000566ac;
      goto LAB_00056332;
    }
    iVar4 = 0x10;
    ppcVar5 = DAT_00056604;
    goto LAB_00056308;
  case 0xf:
    param_1[2] = param_1[4] ^ param_1[2];
    iVar7 = Curl_sasl_start(param_1,param_2,*(undefined *)((int)param_1 + 0x16),param_4);
    iVar4 = param_1[1];
  }
  if (iVar7 == 0) {
    if (local_4c != 0) {
LAB_00056308:
      iVar7 = (**(code **)(*param_1 + 0x14))(param_2);
    }
  }
  else if (iVar7 == 0x3d) {
    iVar4 = 0xf;
    iVar7 = (**(code **)(*param_1 + 0x14))(param_2,DAT_000565f8);
  }
  else {
LAB_00056332:
    iVar4 = 0;
    *param_4 = 2;
  }
  (**ppcVar5)(local_4c);
  param_1[1] = iVar4;
  return iVar7;
}

