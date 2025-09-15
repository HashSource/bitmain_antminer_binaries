
/* WARNING: Unknown calling convention */

void jsonp_error_set_source(json_error_t *error,char *source)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 in_r3;
  undefined4 unaff_lr;
  
  if (error == (json_error_t *)0x0 || source == (char *)0x0) {
    return;
  }
  sVar2 = strlen(source);
  if (sVar2 < 0x50) {
    pcVar1 = error->source;
    sVar2 = sVar2 + 1;
  }
  else {
    source = source + (sVar2 - 0x4c);
    builtin_strncpy(error->source,"...",4);
    pcVar1 = error->source + 3;
  }
  (*(code *)(undefined *)0x0)(pcVar1,source,sVar2,in_r3,unaff_lr);
  return;
}

