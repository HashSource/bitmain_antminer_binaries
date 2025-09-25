
uint ssl_get_split_send_fragment(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if ((*(int *)(param_1 + 0x474) != 0) &&
     (cVar1 = *(char *)(*(int *)(param_1 + 0x474) + 0x1ec), (byte)(cVar1 - 1U) < 4)) {
    uVar3 = *(uint *)(param_1 + 0x508);
    uVar2 = 0x200 << (uint)(byte)(cVar1 - 1);
    if ((uVar3 <= uVar2) &&
       (uVar2 = *(uint *)(param_1 + 0x50c), uVar3 <= *(uint *)(param_1 + 0x50c))) {
      uVar2 = uVar3;
    }
    return uVar2;
  }
  uVar2 = *(uint *)(param_1 + 0x50c);
  if (*(uint *)(param_1 + 0x508) <= *(uint *)(param_1 + 0x50c)) {
    uVar2 = *(uint *)(param_1 + 0x508);
  }
  return uVar2;
}

