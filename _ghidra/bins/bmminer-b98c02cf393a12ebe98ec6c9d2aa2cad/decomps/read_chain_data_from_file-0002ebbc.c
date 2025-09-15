
void read_chain_data_from_file(undefined4 param_1,void *param_2,size_t param_3)

{
  FILE *__stream;
  char acStack_d8 [200];
  
  if (param_2 != (void *)0x0) {
    memset(acStack_d8,0,200);
    sprintf(acStack_d8,"/config/hashBoardData_chain%d",param_1);
    __stream = fopen(acStack_d8,"rb");
    if (__stream != (FILE *)0x0) {
      fread(param_2,param_3,1,__stream);
      fclose(__stream);
    }
    return;
  }
  return;
}

