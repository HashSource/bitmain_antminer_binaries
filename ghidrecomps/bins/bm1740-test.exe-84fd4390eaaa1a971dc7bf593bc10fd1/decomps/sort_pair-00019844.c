
void sort_pair(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_10;
  
  iVar2 = param_1 + param_2 * 4;
  bVar1 = false;
  local_10 = 0;
  do {
    if (param_2 <= local_10) {
      return;
    }
    if ((bVar1) || (*(uint *)(iVar2 + local_10 * 4) < *(uint *)(param_1 + local_10 * 4))) {
      bVar1 = true;
      uVar3 = *(undefined4 *)(param_1 + local_10 * 4);
      *(undefined4 *)(param_1 + local_10 * 4) = *(undefined4 *)(iVar2 + local_10 * 4);
      *(undefined4 *)(iVar2 + local_10 * 4) = uVar3;
    }
    else if (*(uint *)(param_1 + local_10 * 4) < *(uint *)(iVar2 + local_10 * 4)) {
      return;
    }
    local_10 = local_10 + 1;
  } while( true );
}

