
int ftp_state_pasv_resp(int *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined2 uVar6;
  undefined4 *local_138;
  uint local_134;
  int local_130;
  short asStack_12c [2];
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c [62];
  
  local_138 = (undefined4 *)0x0;
  iVar5 = *param_1;
  (*Curl_cfree)(param_1[0x112]);
  param_1[0x112] = 0;
  pcVar2 = (char *)(iVar5 + 0x5a0);
  if (param_1[0x107] != 0) {
    if ((param_1[0x107] != 1) || (param_2 != 0xe3)) {
      Curl_failf(iVar5,"Bad PASV/EPSV response: %03d",param_2);
      return 0xd;
    }
    if (*(char *)(iVar5 + 0x5a0) != '\0') {
      do {
        iVar3 = __isoc99_sscanf(pcVar2,"%d,%d,%d,%d,%d,%d",&local_128,&local_124,&local_120,
                                local_11c,&local_130,asStack_12c);
        if (iVar3 == 6) {
          if (*pcVar2 != '\0') {
            if (*(char *)(iVar5 + 0x328) == '\0') {
              iVar3 = curl_maprintf("%d.%d.%d.%d",local_128,local_124,local_120,local_11c[0]);
              param_1[0x112] = iVar3;
            }
            else {
              Curl_infof(iVar5,"Skip %d.%d.%d.%d for data connection, re-use %s instead\n",local_128
                         ,local_124,local_120,local_11c[0],param_1[0x26]);
              if ((((*(char *)((int)param_1 + 0x1fa) == '\0') && (iVar3 = param_1[0x4e], iVar3 != 5)
                   ) && (iVar3 != 7)) && ((iVar3 != 4 && (iVar3 != 6)))) {
                piVar4 = param_1 + 0x16;
              }
              else {
                piVar4 = (int *)param_1[0x26];
              }
              iVar3 = (*Curl_cstrdup)(piVar4);
              param_1[0x112] = iVar3;
            }
            if (iVar3 == 0) {
              return 0x1b;
            }
            *(short *)(param_1 + 0x113) = asStack_12c[0] + (short)(local_130 << 8);
            goto LAB_0005c6d2;
          }
          break;
        }
        pcVar1 = pcVar2 + 1;
        pcVar2 = pcVar2 + 1;
      } while (*pcVar1 != '\0');
    }
    Curl_failf(iVar5,"Couldn\'t interpret the 227-response");
    return 0xe;
  }
  if (param_2 != 0xe5) {
LAB_0005c5e6:
    iVar5 = ftp_epsv_disable(param_1);
    return iVar5;
  }
  pcVar2 = strchr(pcVar2,0x28);
  if (pcVar2 != (char *)0x0) {
    iVar3 = __isoc99_sscanf(pcVar2 + 1,"%c%c%c%u%c",&local_128,(int)&local_128 + 1,
                            (int)&local_128 + 2,&local_134,(int)&local_128 + 3);
    if (iVar3 == 5) {
      if ((((char)local_128 == local_128._1_1_) && (local_128._2_1_ == (char)local_128)) &&
         (local_128._3_1_ == local_128._2_1_)) {
        if (0xffff < local_134) {
LAB_0005c876:
          Curl_failf(iVar5,"Illegal port number in EPSV reply");
          return 0xd;
        }
        if (pcVar2 + 1 != (char *)0x0) {
          *(short *)(param_1 + 0x113) = (short)local_134;
          if ((((*(char *)((int)param_1 + 0x1fa) == '\0') && (iVar3 = param_1[0x4e], iVar3 != 5)) &&
              (iVar3 != 7)) && ((iVar3 != 4 && (iVar3 != 6)))) {
            piVar4 = param_1 + 0x16;
          }
          else {
            piVar4 = (int *)param_1[0x26];
          }
          iVar3 = (*Curl_cstrdup)(piVar4);
          param_1[0x112] = iVar3;
          if (iVar3 == 0) {
            return 0x1b;
          }
LAB_0005c6d2:
          if (*(char *)((int)param_1 + 0x1ef) == '\0') {
            Curl_resolv(param_1,param_1[0x112],(short)param_1[0x113],&local_138);
            uVar6 = (undefined2)param_1[0x113];
            if (local_138 == (undefined4 *)0x0) {
              Curl_failf(iVar5,"Can\'t resolve new host %s:%hu",param_1[0x112],uVar6);
              return 0xf;
            }
          }
          else {
            Curl_resolv(param_1,param_1[0x2a],param_1[0x2c],&local_138);
            uVar6 = (undefined2)param_1[0x2c];
            if (local_138 == (undefined4 *)0x0) {
              Curl_failf(iVar5,"Can\'t resolve proxy host %s:%hu",param_1[0x2a],uVar6);
              return 0xf;
            }
          }
          *(undefined1 *)((int)param_1 + 0x1f7) = 0;
          iVar3 = Curl_connecthost(param_1,local_138);
          if (iVar3 == 0) {
            if (*(char *)(iVar5 + 0x310) != '\0') {
              iVar3 = param_1[0x112];
              Curl_printable_address(*local_138,&local_128,0x100);
              Curl_infof(*param_1,"Connecting to %s (%s) port %d\n",iVar3,&local_128,uVar6);
            }
            Curl_resolv_unlock(iVar5,local_138);
            *(undefined1 *)((int)param_1 + 0x1f5) = 1;
            param_1[0x10a] = 0;
            return 0;
          }
          Curl_resolv_unlock(iVar5,local_138);
          if (param_1[0x107] != 0) {
            return iVar3;
          }
          if (param_2 != 0xe5) {
            return iVar3;
          }
          goto LAB_0005c5e6;
        }
      }
      else if (0xffff < local_134) goto LAB_0005c876;
    }
  }
  Curl_failf(iVar5,"Weirdly formatted EPSV reply");
  return 0xd;
}

