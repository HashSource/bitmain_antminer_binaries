
undefined4 set_url(undefined4 param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  char *__haystack;
  char acStack_810 [2052];
  
  puVar1 = (undefined4 *)add_url();
  setup_url(puVar1,param_1);
  __haystack = (char *)puVar1[0x29];
  pcVar2 = strstr(__haystack,".nicehash.com");
  if ((((pcVar2 != (char *)0x0) || (pcVar2 = strstr(__haystack,"#xnsub"), pcVar2 != (char *)0x0)) &&
      (*(undefined *)(puVar1 + 0x91) = 1, opt_debug != '\0')) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_810,0x800,"Pool %d extranonce subscribing enabled.",*puVar1);
    _applog(7,acStack_810,0);
  }
  return 0;
}

