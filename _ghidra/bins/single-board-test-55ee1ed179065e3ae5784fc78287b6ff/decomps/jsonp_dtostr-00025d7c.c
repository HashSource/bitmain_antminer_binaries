
char * jsonp_dtostr(char *param_1,char *param_2)

{
  char *pcVar1;
  char *local_14;
  char *local_10;
  char *local_c;
  
  local_14 = (char *)snprintf(param_1,(size_t)param_2,"%.17g");
  if ((int)local_14 < 0) {
    local_14 = (char *)0xffffffff;
  }
  else if (local_14 < param_2) {
    from_locale(param_1);
    pcVar1 = strchr(param_1,0x2e);
    if ((pcVar1 == (char *)0x0) && (pcVar1 = strchr(param_1,0x65), pcVar1 == (char *)0x0)) {
      if (param_2 <= local_14 + 3) {
        return (char *)0xffffffff;
      }
      param_1[(int)local_14] = '.';
      param_1[(int)(local_14 + 1)] = '0';
      param_1[(int)(local_14 + 2)] = '\0';
      local_14 = local_14 + 2;
    }
    pcVar1 = strchr(param_1,0x65);
    if (pcVar1 != (char *)0x0) {
      local_c = pcVar1 + 1;
      local_10 = pcVar1 + 2;
      if (*local_c == '-') {
        local_c = pcVar1 + 2;
      }
      for (; *local_10 == '0'; local_10 = local_10 + 1) {
      }
      if (local_10 != local_c) {
        memmove(local_c,local_10,(size_t)(param_1 + ((int)local_14 - (int)local_10)));
        local_14 = local_c + ((int)local_14 - (int)local_10);
      }
    }
  }
  else {
    local_14 = (char *)0xffffffff;
  }
  return local_14;
}

