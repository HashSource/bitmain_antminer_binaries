
char * json_escape(char *str)

{
  size_t sVar1;
  char *pcVar2;
  JE *pJVar3;
  char *str_local;
  JE *jeptr;
  char *buf;
  char *ptr;
  
  sVar1 = strlen(str);
  pcVar2 = (char *)_cgmalloc(sVar1 * 2 + 1,"cgminer.c","json_escape",0x170a);
  pJVar3 = (JE *)_cgmalloc(8,"cgminer.c","json_escape",0x170b);
  pJVar3->buf = pcVar2;
  pJVar3->next = jedata;
  jedata = pJVar3;
  str_local = str;
  ptr = pcVar2;
  while (*str_local != '\0') {
    if ((*str_local == '\\') || (*str_local == '\"')) {
      *ptr = '\\';
      ptr = ptr + 1;
    }
    *ptr = *str_local;
    str_local = str_local + 1;
    ptr = ptr + 1;
  }
  *ptr = '\0';
  return pcVar2;
}

