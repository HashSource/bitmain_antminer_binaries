
void get_chain_data_file_path(undefined4 param_1,char *param_2)

{
  if (param_2 == (char *)0x0) {
    return;
  }
  sprintf(param_2,"/config/hashBoardData_chain%d",param_1);
  return;
}

