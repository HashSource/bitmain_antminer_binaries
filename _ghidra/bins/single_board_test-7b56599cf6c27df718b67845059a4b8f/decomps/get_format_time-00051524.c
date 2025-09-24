
void get_format_time(char *time_str)

{
  char *time_str_local;
  time_t rawtime;
  tm *info;
  
  time(&rawtime);
  info = (tm *)localtime(&rawtime);
  printf("month:%d\n",((tm *)info)->tm_mon);
  strftime(time_str,0x18,"%m-%d-%H-%M-%S-%Z",(tm *)info);
  return;
}

