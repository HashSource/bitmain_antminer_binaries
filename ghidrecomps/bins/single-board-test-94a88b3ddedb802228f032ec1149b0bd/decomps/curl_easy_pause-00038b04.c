
int curl_easy_pause(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_2 & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x10;
  }
  if ((param_2 & 4) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x20;
  }
  *(uint *)(param_1 + 0x130) = uVar3 | *(uint *)(param_1 + 0x130) & 0xffffffcf | uVar2;
  if ((uVar3 == 0) && (iVar4 = *(int *)(param_1 + 0x85b8), iVar4 != 0)) {
    *(undefined4 *)(param_1 + 0x85b8) = 0;
    iVar1 = Curl_client_chop_write
                      (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x85c0),iVar4,
                       *(undefined4 *)(param_1 + 0x85bc),param_4);
    (**(code **)(DAT_00038b7c + 4))(iVar4);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if ((uVar3 | uVar2) == 0x30) {
    return 0;
  }
  Curl_expire(param_1,1);
  return 0;
}

