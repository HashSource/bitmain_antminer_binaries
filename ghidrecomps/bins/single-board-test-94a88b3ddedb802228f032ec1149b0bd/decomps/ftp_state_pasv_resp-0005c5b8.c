
int ftp_state_pasv_resp(int *param_1,int param_2)

{
  char *pcVar1;
  code **ppcVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  undefined4 *local_138;
  uint local_134;
  int local_130;
  undefined4 uStack_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c [62];
  
  local_138 = (undefined4 *)0x0;
  iVar6 = *param_1;
  (**DAT_0005c884)(param_1[0x112]);
  param_1[0x112] = 0;
  pcVar3 = (char *)(iVar6 + 0x5a0);
  if (param_1[0x107] != 0) {
    if ((param_1[0x107] != 1) || (param_2 != 0xe3)) {
      Curl_failf(iVar6,DAT_0005c888,param_2);
      return 0xd;
    }
    if (*(char *)(iVar6 + 0x5a0) != '\0') {
      do {
        iVar4 = __isoc99_sscanf(pcVar3,DAT_0005c88c,&local_128,&local_124,&local_120,local_11c,
                                &local_130,&uStack_12c);
        if (iVar4 == 6) {
          if (*pcVar3 != '\0') {
            if (*(char *)(iVar6 + 0x328) == '\0') {
              iVar4 = curl_maprintf(DAT_0005c8ac,local_128,local_124,local_120,local_11c[0]);
              param_1[0x112] = iVar4;
            }
            else {
              Curl_infof(iVar6,DAT_0005c890,local_128,local_124,local_120,local_11c[0],param_1[0x26]
                        );
              if ((((*(char *)((int)param_1 + 0x1fa) == '\0') && (iVar4 = param_1[0x4e], iVar4 != 5)
                   ) && (iVar4 != 7)) && ((iVar4 != 4 && (iVar4 != 6)))) {
                piVar5 = param_1 + 0x16;
              }
              else {
                piVar5 = (int *)param_1[0x26];
              }
              iVar4 = (**DAT_0005c894)(piVar5);
              param_1[0x112] = iVar4;
            }
            if (iVar4 == 0) {
              return 0x1b;
            }
            *(short *)(param_1 + 0x113) = (short)uStack_12c + (short)(local_130 << 8);
            goto LAB_0005c6d2;
          }
          break;
        }
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    Curl_failf(iVar6,DAT_0005c8a4);
    return 0xe;
  }
  if (param_2 != 0xe5) {
LAB_0005c5e6:
    iVar6 = ftp_epsv_disable(param_1);
    return iVar6;
  }
  pcVar3 = strchr(pcVar3,0x28);
  if (pcVar3 != (char *)0x0) {
    iVar4 = __isoc99_sscanf(pcVar3 + 1,DAT_0005c898,&local_128,(int)&local_128 + 1,
                            (int)&local_128 + 2,&local_134,(int)&local_128 + 3);
    ppcVar2 = DAT_0005c894;
    if (iVar4 == 5) {
      if ((((char)local_128 == local_128._1_1_) && (local_128._2_1_ == (char)local_128)) &&
         (local_128._3_1_ == local_128._2_1_)) {
        if (0xffff < local_134) {
LAB_0005c876:
          Curl_failf(iVar6,DAT_0005c8b4);
          return 0xd;
        }
        if (pcVar3 + 1 != (char *)0x0) {
          *(short *)(param_1 + 0x113) = (short)local_134;
          if ((((*(char *)((int)param_1 + 0x1fa) == '\0') && (iVar4 = param_1[0x4e], iVar4 != 5)) &&
              (iVar4 != 7)) && ((iVar4 != 4 && (iVar4 != 6)))) {
            piVar5 = param_1 + 0x16;
          }
          else {
            piVar5 = (int *)param_1[0x26];
          }
          iVar4 = (**ppcVar2)(piVar5);
          param_1[0x112] = iVar4;
          if (iVar4 == 0) {
            return 0x1b;
          }
LAB_0005c6d2:
          if (*(char *)((int)param_1 + 0x1ef) == '\0') {
            Curl_resolv(param_1,param_1[0x112],*(undefined2 *)(param_1 + 0x113),&local_138);
            uVar7 = *(undefined2 *)(param_1 + 0x113);
            if (local_138 == (undefined4 *)0x0) {
              Curl_failf(iVar6,DAT_0005c8a0,param_1[0x112],uVar7);
              return 0xf;
            }
          }
          else {
            Curl_resolv(param_1,param_1[0x2a],param_1[0x2c],&local_138);
            uVar7 = *(undefined2 *)(param_1 + 0x2c);
            if (local_138 == (undefined4 *)0x0) {
              Curl_failf(iVar6,DAT_0005c8b0,param_1[0x2a],uVar7);
              return 0xf;
            }
          }
          *(undefined *)((int)param_1 + 0x1f7) = 0;
          iVar4 = Curl_connecthost(param_1,local_138);
          if (iVar4 == 0) {
            if (*(char *)(iVar6 + 0x310) != '\0') {
              iVar4 = param_1[0x112];
              Curl_printable_address(*local_138,&local_128,0x100);
              Curl_infof(*param_1,DAT_0005c8a8,iVar4,&local_128,uVar7);
            }
            Curl_resolv_unlock(iVar6,local_138);
            *(undefined *)((int)param_1 + 0x1f5) = 1;
            param_1[0x10a] = 0;
            return 0;
          }
          Curl_resolv_unlock(iVar6,local_138);
          if (param_1[0x107] != 0) {
            return iVar4;
          }
          if (param_2 != 0xe5) {
            return iVar4;
          }
          goto LAB_0005c5e6;
        }
      }
      else if (0xffff < local_134) goto LAB_0005c876;
    }
  }
  Curl_failf(iVar6,DAT_0005c89c);
  return 0xd;
}

