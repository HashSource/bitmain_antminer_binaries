
char * set_schedtime(char *arg,schedtime *st)

{
  int iVar1;
  char *pcVar2;
  schedtime *st_local;
  char *arg_local;
  
  iVar1 = sscanf(arg,"%d:%d",&(st->tm).tm_hour,&(st->tm).tm_min);
  if (iVar1 == 2) {
    if (((((st->tm).tm_hour < 0x18) && ((st->tm).tm_min < 0x3c)) && (-1 < (st->tm).tm_hour)) &&
       (-1 < (st->tm).tm_min)) {
      st->enable = true;
      pcVar2 = (char *)0x0;
    }
    else {
      pcVar2 = "Invalid time set.";
    }
  }
  else {
    pcVar2 = "Invalid time set, should be HH:MM";
  }
  return pcVar2;
}

