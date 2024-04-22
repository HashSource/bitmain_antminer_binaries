
void opt_show_charp(undefined *param_1,char **param_2)

{
  size_t __n;
  
  __n = strlen(*param_2);
  *param_1 = 0x22;
  if (__n < 0x4f) {
    strncpy(param_1 + 1,*param_2,__n);
    param_1[__n + 1] = 0x22;
    if (__n != 0x4e) {
      param_1[__n + 2] = 0;
      return;
    }
  }
  else {
    strncpy(param_1 + 1,*param_2,0x4e);
    param_1[0x4f] = 0x22;
  }
  return;
}

