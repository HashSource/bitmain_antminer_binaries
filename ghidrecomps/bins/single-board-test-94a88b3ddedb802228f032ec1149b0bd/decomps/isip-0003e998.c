
int isip(char *param_1)

{
  int iVar1;
  undefined auStack_1c [4];
  undefined auStack_18 [16];
  
  iVar1 = inet_pton(2,param_1,auStack_1c);
  if (iVar1 == 0) {
    iVar1 = inet_pton(10,param_1,auStack_18);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

