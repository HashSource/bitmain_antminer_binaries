
void conn_is_conn(int param_1,int *param_2)

{
  undefined uVar1;
  bool bVar2;
  
  bVar2 = *param_2 == param_1;
  if (bVar2) {
    param_1 = 1;
  }
  uVar1 = (undefined)param_1;
  if (!bVar2) {
    uVar1 = 0;
  }
  if (bVar2) {
    *(undefined *)(param_2 + 1) = uVar1;
  }
  return;
}

