
void get_chain_data_file_path(byte param_1,char *param_2)

{
  if (param_2 != (char *)0x0) {
    sprintf(param_2,"/config/hashBoardData_chain%d",(uint)param_1);
  }
  return;
}

