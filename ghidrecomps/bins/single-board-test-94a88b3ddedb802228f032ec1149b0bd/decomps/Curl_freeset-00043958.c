
void Curl_freeset(int param_1)

{
  code **ppcVar1;
  code **ppcVar2;
  int iVar3;
  undefined4 *puVar4;
  
  ppcVar1 = DAT_000439b0;
  iVar3 = 0x2e;
  puVar4 = (undefined4 *)(param_1 + 0x340);
  do {
    (**ppcVar1)(*puVar4);
    ppcVar2 = DAT_000439b0;
    iVar3 = iVar3 + -1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  } while (iVar3 != 0);
  if (*(char *)(param_1 + 0x45c) != '\0') {
    (**ppcVar2)(*(undefined4 *)(param_1 + 0x458));
    *(undefined *)(param_1 + 0x45c) = 0;
  }
  *(undefined4 *)(param_1 + 0x458) = 0;
  if (*(char *)(param_1 + 0x454) != '\0') {
    (**ppcVar1)(*(undefined4 *)(param_1 + 0x450));
    *(undefined *)(param_1 + 0x454) = 0;
  }
  *(undefined4 *)(param_1 + 0x450) = 0;
  return;
}

