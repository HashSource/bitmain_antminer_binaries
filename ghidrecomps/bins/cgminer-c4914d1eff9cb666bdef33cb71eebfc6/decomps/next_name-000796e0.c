
char * next_name(char *names,uint *len)

{
  char *pcVar1;
  uint *len_local;
  char *names_local;
  
  pcVar1 = names + *len;
  if (((*pcVar1 == ' ') || (*pcVar1 == '=')) || (*pcVar1 == '\0')) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = first_name(pcVar1 + 1,len);
  }
  return pcVar1;
}

