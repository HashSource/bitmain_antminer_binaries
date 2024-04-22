
/* WARNING: Unknown calling convention */

void aging_start(void)

{
  char *pcVar1;
  float fVar2;
  time_t curtime;
  
  memset(&aging_info,0,0x99c0);
  time(&curtime);
  pcVar1 = ctime(&curtime);
  strcpy(DAT_0001ed1c,pcVar1);
  cgtime(DAT_0001ed20);
  fVar2 = get_env_temperature();
  aging_info.sweep_temp = (int)fVar2;
  pcVar1 = ctime(&curtime);
  strcpy(DAT_0001ed24,pcVar1);
  aging_info.is_aging_finished = true;
  cgtime(DAT_0001ed28);
  aging_save_info();
  return;
}

