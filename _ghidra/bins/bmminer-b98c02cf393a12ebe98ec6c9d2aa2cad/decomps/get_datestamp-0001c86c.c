
void get_datestamp(char *param_1,size_t param_2,time_t *param_3)

{
  tm *ptVar1;
  int iVar2;
  time_t local_1c [2];
  
  iVar2 = param_3[1];
  local_1c[0] = *param_3;
  ptVar1 = localtime(local_1c);
  snprintf(param_1,param_2,"[%d-%02d-%02d %02d:%02d:%02d.%03d]",ptVar1->tm_year + 0x76c,
           ptVar1->tm_mon + 1,ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,
           iVar2 / 1000);
  return;
}

