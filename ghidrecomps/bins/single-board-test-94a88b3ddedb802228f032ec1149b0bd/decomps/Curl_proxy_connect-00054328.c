
uint Curl_proxy_connect(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined auStack_78 [96];
  
  uVar1 = (uint)*(byte *)((int)param_1 + 0x1fa);
  if ((uVar1 != 0) && (uVar1 = (uint)*(byte *)(param_1 + 0x7c), uVar1 != 0)) {
    iVar4 = *param_1;
    uVar5 = *(undefined4 *)(iVar4 + 0x14c);
    memset(auStack_78,0,0x60);
    iVar3 = param_1[0x2d];
    iVar2 = param_1[0x26];
    *(undefined **)(iVar4 + 0x14c) = auStack_78;
    *(undefined *)((int)param_1 + 0x1ed) = 0;
    uVar1 = Curl_proxyCONNECT(param_1,0,iVar2,iVar3,0);
    *(undefined4 *)(*param_1 + 0x14c) = uVar5;
    if (uVar1 == 0) {
      (**DAT_00054390)(param_1[0x8b]);
      param_1[0x8b] = 0;
    }
  }
  return uVar1;
}

