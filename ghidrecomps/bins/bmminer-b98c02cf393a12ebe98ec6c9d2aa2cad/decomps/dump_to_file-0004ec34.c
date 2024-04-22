
int dump_to_file(void *param_1,size_t param_2,FILE *param_3)

{
  size_t sVar1;
  int iVar2;
  
  sVar1 = fwrite(param_1,param_2,1,param_3);
  iVar2 = sVar1 - 1;
  if (iVar2 != 0) {
    iVar2 = -1;
  }
  return iVar2;
}

