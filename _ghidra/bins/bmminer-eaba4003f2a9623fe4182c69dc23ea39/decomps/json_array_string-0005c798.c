
char * json_array_string(json_t *val,uint entry)

{
  char *pcVar1;
  uint entry_local;
  json_t *val_local;
  char *buf;
  
  pcVar1 = __json_array_string(val,entry);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = strdup(pcVar1);
  }
  return pcVar1;
}

