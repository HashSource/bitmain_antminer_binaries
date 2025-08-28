
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aging_stop(void)

{
  char *__src;
  time_t curtime;
  
  time(&curtime);
  __src = ctime(&curtime);
  strcpy(aging_info.finish_time,__src);
  aging_info.is_aging_finished = true;
  cgtime(&aging_info.tv_finish_time);
  aging_info.avg_hashrate_when_finish = getAVGhashrate();
  aging_save_info();
  return;
}

