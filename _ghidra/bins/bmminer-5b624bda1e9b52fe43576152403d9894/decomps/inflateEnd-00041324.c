
undefined4 inflateEnd(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) &&
     (pcVar2 = *(code **)(param_1 + 0x24), pcVar2 != (code *)0x0)) {
    if (*(int *)(iVar1 + 0x34) != 0) {
      (*pcVar2)(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar1 + 0x34));
      pcVar2 = *(code **)(param_1 + 0x24);
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    (*pcVar2)(*(undefined4 *)(param_1 + 0x28),iVar1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}

