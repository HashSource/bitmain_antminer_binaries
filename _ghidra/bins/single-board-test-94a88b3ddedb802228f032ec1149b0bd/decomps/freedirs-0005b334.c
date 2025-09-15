
void freedirs(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  if (iVar2 != 0) {
    if (0 < *(int *)(param_1 + 0x40)) {
      iVar4 = 0;
      do {
        (*Curl_cfree)(*(undefined4 *)(iVar2 + iVar4 * 4));
        iVar3 = *(int *)(param_1 + 0x40);
        *(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar4 * 4) = 0;
        iVar4 = iVar4 + 1;
        iVar2 = *(int *)(param_1 + 0x3c);
      } while (iVar4 < iVar3);
    }
    (*Curl_cfree)();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x48));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x48) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x88));
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}

