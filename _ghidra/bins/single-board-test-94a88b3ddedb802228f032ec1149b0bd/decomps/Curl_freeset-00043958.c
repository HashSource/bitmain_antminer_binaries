
void Curl_freeset(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0x2e;
  puVar2 = (undefined4 *)(param_1 + 0x340);
  do {
    (*Curl_cfree)(*puVar2);
    iVar1 = iVar1 + -1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar1 != 0);
  if (*(char *)(param_1 + 0x45c) != '\0') {
    (*Curl_cfree)(*(undefined4 *)(param_1 + 0x458));
    *(undefined1 *)(param_1 + 0x45c) = 0;
  }
  *(undefined4 *)(param_1 + 0x458) = 0;
  if (*(char *)(param_1 + 0x454) != '\0') {
    (*Curl_cfree)(*(undefined4 *)(param_1 + 0x450));
    *(undefined1 *)(param_1 + 0x454) = 0;
  }
  *(undefined4 *)(param_1 + 0x450) = 0;
  return;
}

