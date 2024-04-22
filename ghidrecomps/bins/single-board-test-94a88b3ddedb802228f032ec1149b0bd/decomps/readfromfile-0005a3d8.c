
size_t readfromfile(int **param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  size_t sVar1;
  FILE *__stream;
  int iVar2;
  
  iVar2 = (int)*param_1;
  if (*(int *)(iVar2 + 4) == 2) {
    if (param_1[3] == (int *)0x0) {
      return 0;
    }
    sVar1 = (*(code *)param_1[3])(param_2,1,param_3,*(undefined4 *)(iVar2 + 8),param_4);
  }
  else {
    __stream = (FILE *)param_1[2];
    if (__stream == (FILE *)0x0) {
      __stream = fopen64(*(char **)(iVar2 + 8),DAT_0005a43c);
      param_1[2] = &__stream->_flags;
      if (__stream == (FILE *)0x0) {
        return 0xffffffff;
      }
    }
    sVar1 = fread(param_2,1,param_3,__stream);
  }
  if (sVar1 == 0) {
    if ((FILE *)param_1[2] != (FILE *)0x0) {
      fclose((FILE *)param_1[2]);
      param_1[2] = (int *)0x0;
    }
    *param_1 = (int *)**param_1;
  }
  return sVar1;
}

