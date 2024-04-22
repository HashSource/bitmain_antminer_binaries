
void sort_pair(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_10;
  
  iVar2 = param_2 * 4 + param_1;
  bVar1 = false;
  local_10 = 0;
  do {
    if (param_2 <= local_10) {
      return;
    }
    if ((bVar1) || (*(uint *)(local_10 * 4 + iVar2) < *(uint *)(local_10 * 4 + param_1))) {
      bVar1 = true;
      uVar3 = *(undefined4 *)(local_10 * 4 + param_1);
      *(undefined4 *)(local_10 * 4 + param_1) = *(undefined4 *)(local_10 * 4 + iVar2);
      *(undefined4 *)(local_10 * 4 + iVar2) = uVar3;
    }
    else if (*(uint *)(local_10 * 4 + param_1) < *(uint *)(local_10 * 4 + iVar2)) {
      return;
    }
    local_10 = local_10 + 1;
  } while( true );
}

