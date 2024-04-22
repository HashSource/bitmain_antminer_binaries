
void read_chain_data_from_file(undefined param_1,void *param_2,size_t param_3)

{
  char acStack_d4 [200];
  FILE *local_c;
  
  if (param_2 != (void *)0x0) {
    memset(acStack_d4,0,200);
    get_chain_data_file_path(param_1,acStack_d4);
    local_c = fopen(acStack_d4,"rb");
    if (local_c != (FILE *)0x0) {
      fread(param_2,param_3,1,local_c);
      fclose(local_c);
    }
  }
  return;
}

