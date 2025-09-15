
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aging_start(void)

{
  char *pcVar1;
  float fVar2;
  time_t curtime;
  
  memset(&aging_info,0,0x99c0);
  time(&curtime);
  pcVar1 = ctime(&curtime);
  strcpy(aging_info.start_time,pcVar1);
  cgtime(&aging_info.tv_start_time);
  fVar2 = get_env_temperature();
  aging_info.sweep_temp = (int)fVar2;
  pcVar1 = ctime(&curtime);
  strcpy(aging_info.finish_time,pcVar1);
  aging_info.is_aging_finished = true;
  cgtime(&aging_info.tv_finish_time);
  aging_save_info();
  return;
}

