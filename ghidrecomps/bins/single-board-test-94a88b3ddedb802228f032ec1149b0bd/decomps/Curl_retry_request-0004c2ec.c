
undefined4 Curl_retry_request(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  *param_2 = 0;
  if ((*(char *)(iVar4 + 0x309) == '\0') || ((*(uint *)(param_1[0x86] + 0x3c) & 0x40003) != 0)) {
    uVar3 = *(uint *)(iVar4 + 0x80);
    if (((*(uint *)(iVar4 + 0x70) + uVar3 |
         *(int *)(iVar4 + 0x74) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(*(uint *)(iVar4 + 0x70),uVar3)
         ) == 0) &&
       (((*(char *)((int)param_1 + 0x1ee) != '\0' && (*(char *)(iVar4 + 0x307) == '\0')) &&
        (*(int *)(iVar4 + 0x40c) != 0xb)))) {
      Curl_infof(*param_1,DAT_0004c384);
      iVar1 = (**DAT_0004c388)(*(undefined4 *)(*param_1 + 0x450));
      *param_2 = iVar1;
      if (iVar1 == 0) {
        return 0x1b;
      }
      *(undefined *)((int)param_1 + 0x1ed) = 1;
      *(undefined *)((int)param_1 + 0x1f9) = 1;
      if ((*(uint *)(param_1[0x86] + 0x3c) & 3) != 0) {
        if ((*(uint *)(*(int *)(iVar4 + 0x14c) + 0x28) | *(uint *)(*(int *)(iVar4 + 0x14c) + 0x2c))
            != 0) {
          uVar2 = Curl_readrewind(param_1);
          return uVar2;
        }
      }
    }
  }
  return 0;
}

