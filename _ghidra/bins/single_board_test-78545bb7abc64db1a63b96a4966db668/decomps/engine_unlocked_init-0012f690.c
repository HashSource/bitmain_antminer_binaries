
int engine_unlocked_init(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if ((*(int *)(param_1 + 0x54) == 0) && (*(code **)(param_1 + 0x30) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x30))();
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = 1;
  }
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  piVar2 = (int *)(param_1 + 0x50);
  iVar3 = *(int *)(param_1 + 0x50);
  do {
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar2);
      iVar4 = *piVar2;
      bVar5 = iVar4 == iVar3;
      if (!bVar5) goto LAB_0012f6d6;
      bVar5 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar5);
    *piVar2 = iVar3 + 1;
LAB_0012f6d6:
    DataMemoryBarrier(0x1b);
    iVar3 = iVar4;
    if (bVar5) {
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      return iVar1;
    }
  } while( true );
}

