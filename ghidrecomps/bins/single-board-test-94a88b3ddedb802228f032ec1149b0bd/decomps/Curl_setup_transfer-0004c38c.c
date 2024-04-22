
void Curl_setup_transfer(int *param_1,int param_2,int param_3,int param_4,char param_5,
                        undefined4 param_6,int param_7,undefined4 param_8)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  if (param_2 != -1) {
    param_2 = param_1[param_2 + 0x55];
  }
  iVar2 = *param_1;
  param_1[0x89] = param_2;
  if (param_7 != -1) {
    param_7 = param_1[param_7 + 0x55];
  }
  param_1[0x8a] = param_7;
  *(char *)(iVar2 + 0x14a) = param_5;
  *(int *)(iVar2 + 0x50) = param_3;
  *(int *)(iVar2 + 0x54) = param_4;
  *(undefined4 *)(iVar2 + 0x58) = param_6;
  *(undefined4 *)(iVar2 + 0x68) = param_8;
  if ((param_5 != '\0') ||
     (((*(undefined *)(iVar2 + 0x98) = 0,
       (int)(param_4 - (uint)(param_3 == 0)) < 0 ==
       (SBORROW4(param_4,(uint)(param_3 == 0)) != false) &&
       (Curl_pgrsSetDownloadSize(iVar2), *(char *)(iVar2 + 0x14a) != '\0')) ||
      (*(char *)(iVar2 + 0x307) == '\0')))) {
    uVar1 = param_1[0x89] + 1;
    bVar3 = uVar1 != 0;
    if (bVar3) {
      uVar1 = *(uint *)(iVar2 + 0x130) | 1;
    }
    if (bVar3) {
      *(uint *)(iVar2 + 0x130) = uVar1;
    }
    if (param_1[0x8a] != -1) {
      if (*(char *)(iVar2 + 0x867c) != '\0') {
        if (((*(uint *)(param_1[0x86] + 0x3c) & 3) != 0) &&
           (*(int *)(*(int *)(iVar2 + 0x14c) + 0x58) == 2)) {
          *(undefined4 *)(iVar2 + 0xd4) = 1;
          curlx_tvnow(&local_20);
          *(undefined4 *)(iVar2 + 0xcc) = local_20;
          *(undefined4 *)(iVar2 + 0xd0) = uStack_1c;
          Curl_expire(iVar2,*(undefined4 *)(iVar2 + 0x440));
          return;
        }
        *(undefined4 *)(iVar2 + 0xd4) = 2;
      }
      *(uint *)(iVar2 + 0x130) = *(uint *)(iVar2 + 0x130) | 2;
    }
  }
  return;
}

