
undefined4 setup_range(int param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  bool bVar4;
  
  *(int *)(param_1 + 0x8698) = *(int *)(param_1 + 0x238);
  *(int *)(param_1 + 0x869c) = *(int *)(param_1 + 0x23c);
  if ((*(int *)(param_1 + 0x238) == 0 && *(int *)(param_1 + 0x23c) == 0) &&
     (*(int *)(param_1 + 900) == 0)) {
    *(undefined1 *)(param_1 + 0x8691) = 0;
    return 0;
  }
  if (*(char *)(param_1 + 0x8692) != '\0') {
    (*Curl_cfree)(*(undefined4 *)(param_1 + 0x8694));
  }
  if (*(int *)(param_1 + 0x8698) == 0 && *(int *)(param_1 + 0x869c) == 0) {
    uVar1 = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 900));
    *(undefined4 *)(param_1 + 0x8694) = uVar1;
  }
  else {
    uVar1 = curl_maprintf("%llu-");
    *(undefined4 *)(param_1 + 0x8694) = uVar1;
  }
  iVar3 = *(int *)(param_1 + 0x8694);
  bVar4 = iVar3 == 0;
  if (bVar4) {
    iVar3 = 0;
  }
  uVar2 = (undefined1)iVar3;
  if (!bVar4) {
    uVar2 = 1;
  }
  *(undefined1 *)(param_1 + 0x8692) = uVar2;
  if (!bVar4) {
    *(undefined1 *)(param_1 + 0x8691) = 1;
    return 0;
  }
  return 0x1b;
}

