
void append_err_code(char *err_strs,char *err_str)

{
  size_t sVar1;
  char *err_str_local;
  char *err_strs_local;
  
  if (*err_strs == '\0') {
    strcpy(err_strs,err_str);
  }
  else {
    sVar1 = strlen(err_strs);
    (err_strs + sVar1)[0] = '#';
    (err_strs + sVar1)[1] = '\0';
    strncat(err_strs,err_str,0x40);
  }
  return;
}

