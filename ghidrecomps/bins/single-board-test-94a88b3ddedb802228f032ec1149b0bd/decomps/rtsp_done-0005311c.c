
undefined4 rtsp_done(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x14c);
  if (*(int *)(iVar2 + 0x40c) == 0xb) {
    param_3 = 1;
  }
  uVar1 = Curl_http_done(param_1,param_2,param_3,*(int *)(iVar2 + 0x40c),param_4);
  if (iVar3 != 0) {
    if (*(int *)(iVar2 + 0x40c) == 0xb) {
      if (param_1[0xf2] == -1) {
        Curl_infof(iVar2,DAT_00053170,*(int *)(iVar3 + 100));
      }
    }
    else if (*(int *)(iVar3 + 0x60) != *(int *)(iVar3 + 100)) {
      uVar1 = 0x55;
      Curl_failf(iVar2,DAT_0005316c);
    }
  }
  return uVar1;
}

