
undefined4 get_mac(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_30 [18];
  undefined auStack_1e [14];
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_10 = socket(2,1,0);
  if (local_10 < 0) {
    perror("error sock");
    uVar2 = 2;
  }
  else {
    strcpy(acStack_30,param_1);
    iVar1 = ioctl(local_10,0x8927,acStack_30);
    if (iVar1 < 0) {
      perror("error ioctl");
      close(local_10);
      uVar2 = 3;
    }
    else {
      for (local_c = 0; local_c < 6; local_c = local_c + 1) {
        *(undefined *)(local_c + param_2) = auStack_1e[local_c];
      }
      close(local_10);
      uVar2 = 0;
    }
  }
  return uVar2;
}

