
undefined4 pooldetails(char *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  size_t sVar1;
  void *__ptr;
  char *local_824 [2];
  void *local_81c;
  char local_818 [2048];
  
  local_824[0] = param_1;
  sVar1 = strlen(param_1);
  __ptr = malloc(sVar1 + 1);
  local_81c = __ptr;
  if (__ptr == (void *)0x0) {
    builtin_strncpy(local_818,"Failed to malloc pooldetails buf",0x20);
    local_818[0x20] = 0;
    _applog(3,local_818,1);
    _quit(1);
  }
  *param_2 = local_81c;
  copyadvanceafter_constprop_20(local_824,&local_81c);
  if (*local_824[0] != '\0') {
    *param_3 = local_81c;
    copyadvanceafter_constprop_20(local_824,&local_81c);
    if (*local_824[0] != '\0') {
      *param_4 = local_81c;
      copyadvanceafter_constprop_20(local_824,&local_81c);
      return 1;
    }
  }
  free(__ptr);
  return 0;
}

