
undefined4 get_eth_mac(char *param_1,int param_2)

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
    printf("%s:%d","get_eth_mac",0x8f);
    printf("error sock");
    uVar2 = 0xffffffff;
  }
  else {
    strcpy(acStack_30,param_1);
    iVar1 = ioctl(local_10,0x8927,acStack_30);
    if (iVar1 < 0) {
      printf("%s:%d","get_eth_mac",0x95);
      printf("error ioctl");
      close(local_10);
      uVar2 = 0xfffffffe;
    }
    else {
      for (local_c = 0; local_c < 6; local_c = local_c + 1) {
        *(undefined *)(param_2 + local_c) = auStack_1e[local_c];
      }
      close(local_10);
      uVar2 = 0;
    }
  }
  return uVar2;
}

