
void my_log_curses(int prio,char *datetime,char *str,_Bool force)

{
  code **ppcVar1;
  char *file;
  char *file_00;
  int line;
  code *line_00;
  undefined8 uVar2;
  
  ppcVar1 = DAT_0000f7bc;
  uVar2 = CONCAT44(datetime,prio);
  line_00 = (code *)(uint)force;
  if (str != (char *)0x0) {
    pthread_mutex_trylock(DAT_0000f7c8);
    _mutex_unlock_noyield((pthread_mutex_t *)0x26,file_00,str,(int)line_00);
    line_00 = *ppcVar1;
    uVar2 = (*line_00)();
  }
  _mutex_lock((pthread_mutex_t *)uVar2,(char *)((ulonglong)uVar2 >> 0x20),str,(int)line_00);
  line = DAT_0000f7c0;
  printf(DAT_0000f7c4,prio);
  _mutex_unlock_noyield((pthread_mutex_t *)0x33,file,datetime,line);
  (**ppcVar1)();
  return;
}

