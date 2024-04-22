
bool verifyconnect(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int local_18;
  socklen_t local_14;
  
  local_14 = 4;
  local_18 = 0;
  iVar1 = getsockopt(param_1,1,4,&local_18,&local_14);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    local_18 = *piVar2;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = local_18;
  }
  return local_18 == 0 || local_18 == 0x6a;
}

