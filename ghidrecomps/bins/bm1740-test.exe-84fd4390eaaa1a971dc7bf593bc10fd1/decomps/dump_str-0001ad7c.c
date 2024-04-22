
void dump_str(FILE *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *__ptr;
  
  __ptr = (void *)bin2hex(param_3,param_4);
  if (param_2 == 0) {
    fprintf(param_1,"%s\n",__ptr);
  }
  else {
    fprintf(param_1,"%s %s\n",param_2,__ptr);
  }
  fflush(param_1);
  free(__ptr);
  return;
}

