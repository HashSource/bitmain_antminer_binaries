
int smb_send_and_recv(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_1c;
  
  uVar4 = param_1[0xf9];
  if (param_1[0xf9] == 0) {
    uVar4 = param_1[0xf8];
    if (uVar4 != 0) {
      if (0x3fff < uVar4) {
        uVar4 = 0x4000;
      }
      *(int *)(*param_1 + 0x144) = *param_1 + 0x459d;
      local_1c = uVar4;
      iVar1 = Curl_fillreadbuffer(param_1,uVar4,&local_1c);
      if (iVar1 != 0x51 && iVar1 != 0) {
        return iVar1;
      }
      if (local_1c == 0) {
        return 0;
      }
      param_1[0xf9] = local_1c;
      param_1[0xfa] = 0;
      param_1[0xf8] = param_1[0xf8] - local_1c;
      uVar4 = local_1c;
      goto LAB_0005697a;
    }
LAB_000569c6:
    iVar5 = param_1[0xf7];
    iVar1 = Curl_read(param_1,0,iVar5 + param_1[0xfb],0x9000 - param_1[0xfb],&local_1c);
    if (((iVar1 == 0) && (local_1c != 0)) &&
       (iVar2 = param_1[0xfb], param_1[0xfb] = local_1c + iVar2, 3 < local_1c + iVar2)) {
      iVar2 = Curl_read16_be(iVar5 + 2);
      uVar4 = iVar2 + 4;
      if (uVar4 <= (uint)param_1[0xfb]) {
        if (0x24 < uVar4) {
          iVar2 = (uint)*(byte *)(iVar5 + 0x24) * 2;
          uVar3 = iVar2 + 0x27;
          if ((uVar3 <= uVar4) &&
             (iVar2 = Curl_read16_le(iVar2 + 0x25 + iVar5), uVar4 < iVar2 + uVar3)) {
            return 0x1a;
          }
        }
        *param_2 = iVar5;
      }
    }
  }
  else {
LAB_0005697a:
    uVar4 = uVar4 - param_1[0xfa];
    iVar1 = Curl_write(param_1,0,*param_1 + param_1[0xfa] + 0x459d,uVar4,&local_1c);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (uVar4 == local_1c) {
      param_1[0xf9] = 0;
LAB_00056a76:
      if (param_1[0xf8] == 0) goto LAB_000569c6;
    }
    else {
      param_1[0xfa] = param_1[0xfa] + local_1c;
      if (param_1[0xf9] == 0) goto LAB_00056a76;
    }
    iVar1 = 0x51;
  }
  return iVar1;
}

