
void get_chain_data_file_path(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return;
  }
  (*(code *)PTR_sprintf_0007d044)(param_2,"/config/hashBoardData_chain%d",param_1);
  return;
}

