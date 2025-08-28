
void getFileSysComplieTime(char *param_1)

{
  FILE *__stream;
  size_t sVar1;
  uint local_14;
  
  __stream = fopen("/usr/bin/compile_time","r");
  if (__stream == (FILE *)0x0) {
    builtin_strncpy(param_1,"unkown version",0xf);
  }
  else {
    memset(param_1,0,0x100);
    fgets(param_1,0x100,__stream);
    for (local_14 = 0; sVar1 = strlen(param_1), local_14 < sVar1; local_14 = local_14 + 1) {
      if ((param_1[local_14] == '\r') || (param_1[local_14] == '\n')) {
        param_1[local_14] = '\0';
      }
    }
  }
  return;
}

