
undefined4 Curl_closesocket(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x38);
    if (iVar2 != 0) {
      uVar3 = *(uint *)(param_1 + 0x158);
      if ((uVar3 != param_2) || (uVar3 = (uint)*(byte *)(param_1 + 0x165), uVar3 == 0)) {
        Curl_multi_closed(param_1,param_2,param_3,uVar3,param_4);
        uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),param_2);
        return uVar1;
      }
      iVar2 = 0;
      *(undefined *)(param_1 + 0x165) = 0;
    }
    Curl_multi_closed(param_1,param_2,param_3,iVar2,param_4);
  }
  close(param_2);
  return 0;
}

