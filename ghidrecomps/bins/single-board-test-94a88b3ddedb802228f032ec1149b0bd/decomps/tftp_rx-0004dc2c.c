
undefined4 tftp_rx(undefined4 *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  ssize_t sVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar7 = *(undefined4 *)param_1[4];
  switch(param_2) {
  case 3:
    uVar6 = *(ushort *)(param_1 + 0xc) + 1 & 0xffff;
    uVar2 = CONCAT11(*(undefined1 *)(param_1[0x52] + 2),*(undefined1 *)(param_1[0x52] + 3));
    uVar8 = (uint)uVar2;
    bVar9 = uVar6 == uVar8;
    if (bVar9) {
      uVar6 = 0;
    }
    if (bVar9) {
      param_1[6] = uVar6;
    }
    else {
      if (uVar8 != *(ushort *)(param_1 + 0xc)) {
        Curl_infof(uVar7,"Received unexpected DATA packet block %d, expecting block %d\n",uVar8);
        return 0;
      }
      Curl_infof(uVar7,"Received last DATA packet block %d again.\n",uVar8);
    }
    *(ushort *)(param_1 + 0xc) = uVar2;
    *(undefined1 *)param_1[0x53] = 0;
    *(undefined1 *)(param_1[0x53] + 1) = 4;
    uVar1 = *(undefined2 *)(param_1 + 0xc);
    *(char *)(param_1[0x53] + 2) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_1[0x53] + 3) = (char)uVar1;
    sVar3 = sendto(param_1[5],(void *)param_1[0x53],4,0x4000,(sockaddr *)(param_1 + 0x2d),
                   param_1[0x4d]);
    if (-1 < sVar3) {
      if (param_1[0x50] + 3 < (int)param_1[0x4e]) {
        uVar7 = 1;
      }
      else {
        uVar7 = 3;
      }
      *param_1 = uVar7;
      time(param_1 + 0xb);
      return 0;
    }
    break;
  default:
    Curl_failf(uVar7,"%s","tftp_rx: internal error");
    return 0x47;
  case 5:
    *(undefined1 *)param_1[0x53] = 0;
    *(undefined1 *)(param_1[0x53] + 1) = 5;
    uVar1 = *(undefined2 *)(param_1 + 0xc);
    *(char *)(param_1[0x53] + 2) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_1[0x53] + 3) = (char)uVar1;
    sendto(param_1[5],(void *)param_1[0x53],4,0x4000,(sockaddr *)(param_1 + 0x2d),param_1[0x4d]);
    *param_1 = 3;
    return 0;
  case 6:
    *(undefined2 *)(param_1 + 0xc) = 0;
    param_1[6] = 0;
    *(undefined1 *)param_1[0x53] = 0;
    *(undefined1 *)(param_1[0x53] + 1) = 4;
    uVar1 = *(undefined2 *)(param_1 + 0xc);
    *(char *)(param_1[0x53] + 2) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_1[0x53] + 3) = (char)uVar1;
    sVar3 = sendto(param_1[5],(void *)param_1[0x53],4,0x4000,(sockaddr *)(param_1 + 0x2d),
                   param_1[0x4d]);
    if (-1 < sVar3) {
      *param_1 = 1;
      time(param_1 + 0xb);
      return 0;
    }
    break;
  case 7:
    param_1[6] = param_1[6] + 1;
    Curl_infof(uVar7,"Timeout waiting for block %d ACK.  Retries = %d\n",
               *(short *)(param_1 + 0xc) + 1);
    if ((int)param_1[8] < (int)param_1[6]) {
      param_1[2] = 0xffffff9d;
      *param_1 = 3;
      return 0;
    }
    sVar3 = sendto(param_1[5],(void *)param_1[0x53],4,0x4000,(sockaddr *)(param_1 + 0x2d),
                   param_1[0x4d]);
    if (-1 < sVar3) {
      return 0;
    }
  }
  piVar4 = __errno_location();
  uVar5 = Curl_strerror(param_1[4],*piVar4);
  Curl_failf(uVar7,"%s",uVar5);
  return 0x37;
}

