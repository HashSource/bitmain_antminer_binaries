
void dump_str(FILE *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__ptr;
  
  if (param_1 != (FILE *)0x0) {
    __ptr = (void *)bin2hex(param_3,param_4);
    if (param_2 == 0) {
      fprintf(param_1,"%s\n",__ptr);
    }
    else {
      fprintf(param_1,"%s %s len=%d\n",param_2,__ptr,param_4);
    }
    fflush(param_1);
    free(__ptr);
  }
  return;
}

