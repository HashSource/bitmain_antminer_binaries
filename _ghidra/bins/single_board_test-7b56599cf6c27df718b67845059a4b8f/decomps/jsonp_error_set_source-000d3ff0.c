
/* WARNING: Unknown calling convention */

void jsonp_error_set_source(json_error_t *error,char *source)

{
  int iVar1;
  size_t sVar2;
  
  if (error == (json_error_t *)0x0 || source == (char *)0x0) {
    return;
  }
  sVar2 = strlen(source);
  if (sVar2 < 0x50) {
    iVar1 = 0xc;
    sVar2 = sVar2 + 1;
  }
  else {
    source = source + (sVar2 - 0x4c);
    iVar1 = 0xf;
    sVar2 = 0x4d;
    error->source[0] = '.';
    error->source[1] = '.';
    error->source[2] = '.';
  }
  strncpy(error->source + iVar1 + -0xc,source,sVar2);
  return;
}

