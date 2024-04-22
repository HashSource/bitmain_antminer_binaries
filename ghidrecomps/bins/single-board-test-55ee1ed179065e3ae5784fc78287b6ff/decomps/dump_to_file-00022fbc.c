
undefined4 dump_to_file(void *param_1,size_t param_2,FILE *param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = fwrite(param_1,param_2,1,param_3);
  if (sVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

