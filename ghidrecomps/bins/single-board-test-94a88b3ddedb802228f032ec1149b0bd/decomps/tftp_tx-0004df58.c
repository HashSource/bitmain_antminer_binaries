
int tftp_tx(undefined4 *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  ssize_t sVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  
  uVar5 = DAT_0004e14c;
  sVar8 = (short)param_2 + -4;
  iVar9 = *(int *)param_1[4];
  switch(param_2) {
  case 4:
  case 6:
    if (param_2 != 4) {
      sVar8 = 1;
    }
    if (param_2 != 4) {
      *(short *)(param_1 + 0xc) = sVar8;
    }
    else {
      sVar8 = CONCAT11(*(undefined *)(param_1[0x52] + 2),*(undefined *)(param_1[0x52] + 3));
      if ((*(short *)(param_1 + 0xc) != sVar8) &&
         ((*(short *)(param_1 + 0xc) != 0 || (sVar8 != -1)))) {
        Curl_infof(iVar9,DAT_0004e154);
        iVar2 = param_1[6];
        param_1[6] = iVar2 + 1;
        if ((int)param_1[8] < iVar2 + 1) {
          Curl_failf(iVar9,DAT_0004e158,*(undefined2 *)(param_1 + 0xc));
          return 0x37;
        }
        sVar3 = sendto(param_1[5],(void *)param_1[0x53],param_1[0x4f] + 4,0x4000,
                       (sockaddr *)(param_1 + 0x2d),param_1[0x4d]);
        if (-1 < sVar3) {
          return 0;
        }
        break;
      }
      time(param_1 + 0xb);
      *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    }
    param_1[6] = 0;
    *(undefined *)param_1[0x53] = 0;
    *(undefined *)(param_1[0x53] + 1) = 3;
    uVar1 = *(undefined2 *)(param_1 + 0xc);
    *(char *)(param_1[0x53] + 2) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_1[0x53] + 3) = (char)uVar1;
    if ((1 < *(ushort *)(param_1 + 0xc)) && ((int)param_1[0x4f] < (int)param_1[0x50])) {
      *param_1 = 3;
      return 0;
    }
    iVar2 = Curl_fillreadbuffer(param_1[4],param_1[0x50],param_1 + 0x4f);
    if (iVar2 != 0) {
      return iVar2;
    }
    sVar3 = sendto(param_1[5],(void *)param_1[0x53],param_1[0x4f] + 4,0x4000,
                   (sockaddr *)(param_1 + 0x2d),param_1[0x4d]);
    if (-1 < sVar3) {
      uVar6 = param_1[0x4f];
      uVar7 = *(uint *)(iVar9 + 0x78);
      *(uint *)(iVar9 + 0x78) = uVar7 + uVar6;
      *(uint *)(iVar9 + 0x7c) =
           *(int *)(iVar9 + 0x7c) + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar7,uVar6);
      Curl_pgrsSetUploadCounter(iVar9);
      return 0;
    }
    break;
  case 5:
    *param_1 = 3;
    *(undefined *)param_1[0x53] = 0;
    *(undefined *)(param_1[0x53] + 1) = 5;
    uVar1 = *(undefined2 *)(param_1 + 0xc);
    *(char *)(param_1[0x53] + 2) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_1[0x53] + 3) = (char)uVar1;
    sendto(param_1[5],(void *)param_1[0x53],4,0x4000,(sockaddr *)(param_1 + 0x2d),param_1[0x4d]);
    *param_1 = 3;
    return 0;
  case 7:
    param_1[6] = param_1[6] + 1;
    Curl_infof(iVar9,uVar5,*(short *)(param_1 + 0xc) + 1);
    if ((int)param_1[8] < (int)param_1[6]) {
      param_1[2] = 0xffffff9d;
      *param_1 = 3;
      return 0;
    }
    sVar3 = sendto(param_1[5],(void *)param_1[0x53],param_1[0x4f] + 4,0x4000,
                   (sockaddr *)(param_1 + 0x2d),param_1[0x4d]);
    if (-1 < sVar3) {
      Curl_pgrsSetUploadCounter(iVar9);
      return 0;
    }
    break;
  default:
    Curl_failf(iVar9,DAT_0004e150,param_2);
    return 0;
  }
  piVar4 = __errno_location();
  uVar5 = Curl_strerror(param_1[4],*piVar4);
  Curl_failf(iVar9,DAT_0004e15c,uVar5);
  return 0x37;
}

