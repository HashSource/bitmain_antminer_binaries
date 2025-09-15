
char * first_name(char *names,uint *len)

{
  size_t sVar1;
  uint *len_local;
  char *names_local;
  
  sVar1 = strcspn(names + 1,"|= ");
  *len = sVar1;
  return names + 1;
}

