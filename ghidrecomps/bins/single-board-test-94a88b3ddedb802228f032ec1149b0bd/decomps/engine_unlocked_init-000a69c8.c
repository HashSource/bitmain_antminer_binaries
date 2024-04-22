
int engine_unlocked_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x5c);
  if ((iVar2 == 0) && (*(code **)(param_1 + 0x38) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x38))();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x5c);
  }
  else {
    iVar1 = 1;
  }
  *(int *)(param_1 + 0x5c) = iVar2 + 1;
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return iVar1;
}

