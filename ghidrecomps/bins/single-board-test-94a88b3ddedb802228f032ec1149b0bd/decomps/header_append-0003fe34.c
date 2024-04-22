
undefined4 header_append(int param_1,int param_2,size_t param_3)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = param_3 + *(int *)(param_2 + 0x58);
  if (uVar4 < *(uint *)(param_1 + 0x598)) {
    __dest = *(void **)(param_2 + 0x54);
  }
  else {
    if (0x19000 < uVar4) {
      Curl_failf(param_1,DAT_0003fec4,0x19000);
      return 0x1b;
    }
    iVar5 = *(int *)(param_1 + 0x594);
    uVar2 = *(uint *)(param_1 + 0x598) << 1;
    iVar3 = *(int *)(param_2 + 0x54);
    uVar4 = uVar4 * 3 >> 1;
    if (uVar4 < uVar2) {
      uVar4 = uVar2;
    }
    iVar1 = (**DAT_0003fec8)(iVar5,uVar4);
    if (iVar1 == 0) {
      Curl_failf(param_1,DAT_0003fecc);
      return 0x1b;
    }
    __dest = (void *)(iVar1 + (iVar3 - iVar5));
    *(uint *)(param_1 + 0x598) = uVar4;
    *(int *)(param_1 + 0x594) = iVar1;
    *(void **)(param_2 + 0x54) = __dest;
  }
  memcpy(__dest,*(void **)(param_2 + 0x60),param_3);
  iVar3 = *(int *)(param_2 + 0x54);
  *(size_t *)(param_2 + 0x54) = iVar3 + param_3;
  *(size_t *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + param_3;
  *(undefined *)(iVar3 + param_3) = 0;
  return 0;
}

