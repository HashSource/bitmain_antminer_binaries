
void save_chain_data_to_file(undefined4 param_1,void *param_2,size_t param_3)

{
  FILE *__s;
  char acStack_d8 [200];
  
  if (param_2 != (void *)0x0) {
    memset(acStack_d8,0,200);
    sprintf(acStack_d8,"/config/hashBoardData_chain%d",param_1);
    __s = fopen(acStack_d8,"wb+");
    if (__s != (FILE *)0x0) {
      fwrite(param_2,param_3,1,__s);
      fclose(__s);
    }
    return;
  }
  return;
}

