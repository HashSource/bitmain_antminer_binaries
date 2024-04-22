
char * set_quota(char *param_1)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  long lVar4;
  undefined4 *puVar5;
  char acStack_818 [2052];
  
  pcVar1 = strchr(param_1,0x3b);
  if (pcVar1 == (char *)0x0) {
    return "No semicolon separated quota;URL pair found";
  }
  sVar2 = strlen(param_1);
  *pcVar1 = '\0';
  sVar3 = strlen(param_1);
  if (sVar3 == 0) {
    return "No parameter for quota found";
  }
  if ((int)(sVar2 - (sVar3 + 1)) < 1) {
    return "No parameter for URL found";
  }
  lVar4 = strtol(param_1,(char **)0x0,10);
  if (lVar4 < 0) {
    pcVar1 = "Invalid negative parameter for quota set";
  }
  else {
    puVar5 = (undefined4 *)add_url(lVar4);
    setup_url(puVar5,param_1 + sVar3 + 1);
    puVar5[0xe] = lVar4;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      snprintf(acStack_818,0x800,"Setting pool %d to quota %d",*puVar5,lVar4);
      _applog(6,acStack_818,0);
    }
    adjust_quota_gcd();
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

