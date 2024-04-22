
undefined4 Curl_readrewind(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *(undefined *)(param_1 + 0x7f) = 0;
  *(uint *)(iVar2 + 0x130) = *(uint *)(iVar2 + 0x130) & 0xfffffffd;
  if ((*(int *)(iVar2 + 0x18c) == 0) && (*(int *)(iVar2 + 0x278) != 3)) {
    if (*(code **)(iVar2 + 400) == (code *)0x0) {
      if (*(code **)(iVar2 + 0x1cc) == (code *)0x0) {
        if ((*(int *)(iVar2 + 0x86c0) != DAT_0004b03c) ||
           (iVar1 = fseek(*(FILE **)(iVar2 + 0x86c4),0,0), iVar1 == -1)) {
          Curl_failf(iVar2,DAT_0004b040);
          return 0x41;
        }
      }
      else {
        iVar1 = (**(code **)(iVar2 + 0x1cc))(iVar2,1,*(undefined4 *)(iVar2 + 0x1fc));
        Curl_infof(iVar2,DAT_0004b034,iVar1);
        if (iVar1 != 0) {
          Curl_failf(iVar2,DAT_0004b038,iVar1);
          return 0x41;
        }
      }
    }
    else {
      iVar1 = (**(code **)(iVar2 + 400))(*(undefined4 *)(iVar2 + 0x1e8),0,0,0,0);
      if (iVar1 != 0) {
        Curl_failf(iVar2,DAT_0004b030,iVar1);
        return 0x41;
      }
    }
  }
  return 0;
}

