
void dev_error(int param_1,undefined4 param_2)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  *(undefined4 *)(param_1 + 0xf8) = param_2;
  *(time_t *)(param_1 + 0xf4) = tVar1;
  switch(param_2) {
  case 0:
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    return;
  case 1:
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
    return;
  case 2:
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
    return;
  case 3:
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
    return;
  case 4:
    *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
    return;
  case 5:
    *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
    return;
  case 6:
    *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    return;
  case 7:
    *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + 1;
    return;
  case 8:
    *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
    return;
  case 9:
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + 1;
  }
  return;
}

