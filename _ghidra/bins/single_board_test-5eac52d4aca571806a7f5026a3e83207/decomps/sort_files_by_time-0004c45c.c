
void sort_files_by_time(char (*logs) [128],int left,int right)

{
  int iVar1;
  int right_local;
  int left_local;
  char (*logs_local) [128];
  int pivot;
  
  if (left < right) {
    iVar1 = paritition(logs,left,right);
    sort_files_by_time(logs,left,iVar1 + -1);
    sort_files_by_time(logs,iVar1 + 1,right);
  }
  return;
}

