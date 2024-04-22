
/* WARNING: Unknown calling convention */

void aging_stop(void)

{
  char *__src;
  time_t curtime;
  
  time(&curtime);
  __src = ctime(&curtime);
  strcpy(DAT_0001ed80,__src);
  aging_info.is_aging_finished = true;
  cgtime(DAT_0001ed84);
  aging_info.avg_hashrate_when_finish = getAVGhashrate();
  aging_save_info();
  return;
}

