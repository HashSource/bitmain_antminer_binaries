
undefined4 sock_full(int param_1)

{
  undefined4 uVar1;
  
  if (**(char **)(param_1 + 0x250) != '\0') {
    return 1;
  }
  uVar1 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c));
  return uVar1;
}

