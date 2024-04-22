
size_t tftp_option_add(int param_1,int param_2,void *param_3,char *param_4)

{
  size_t sVar1;
  
  sVar1 = strlen(param_4);
  if (*(uint *)(param_1 + 0x140) < param_2 + 1 + sVar1) {
    sVar1 = 0;
  }
  else {
    sVar1 = sVar1 + 1;
    memcpy(param_3,param_4,sVar1);
  }
  return sVar1;
}

