
/* WARNING: Unknown calling convention */

char * json_array_string(json_t *val,uint entry)

{
  char *pcVar1;
  
  pcVar1 = __json_array_string(val,entry);
  if (pcVar1 == (char *)0x0) {
    return (char *)0x0;
  }
  pcVar1 = (char *)(*(code *)(undefined *)0x0)();
  return pcVar1;
}

