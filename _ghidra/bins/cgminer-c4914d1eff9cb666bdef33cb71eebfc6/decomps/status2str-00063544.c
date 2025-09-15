
char * status2str(alive status)

{
  char *pcVar1;
  alive status_local;
  
  pcVar1 = UNKNOWN;
  switch(status) {
  case LIFE_WELL:
    pcVar1 = ALIVE;
    break;
  case LIFE_SICK:
    pcVar1 = SICK;
    break;
  case LIFE_DEAD:
    pcVar1 = DEAD;
    break;
  case LIFE_NOSTART:
    pcVar1 = NOSTART;
    break;
  case LIFE_INIT:
    pcVar1 = INIT;
  }
  return pcVar1;
}

