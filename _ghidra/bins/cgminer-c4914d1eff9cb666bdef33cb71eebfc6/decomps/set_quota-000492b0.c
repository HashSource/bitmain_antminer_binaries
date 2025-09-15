
char * set_quota(char *arg)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  pool *pool_00;
  char *arg_local;
  char tmp42 [2048];
  pool *pool;
  char *url;
  int quota;
  int qlen;
  int len;
  char *semicolon;
  
  pcVar1 = strchr(arg,0x3b);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "No semicolon separated quota;URL pair found";
  }
  else {
    sVar2 = strlen(arg);
    *pcVar1 = '\0';
    sVar3 = strlen(arg);
    if (sVar3 == 0) {
      pcVar1 = "No parameter for quota found";
    }
    else if ((int)(sVar2 - (sVar3 + 1)) < 1) {
      pcVar1 = "No parameter for URL found";
    }
    else {
      iVar4 = atoi(arg);
      if (iVar4 < 0) {
        pcVar1 = "Invalid negative parameter for quota set";
      }
      else {
        pool_00 = add_url();
        setup_url(pool_00,arg + sVar3 + 1);
        pool_00->quota = iVar4;
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"Setting pool %d to quota %d",pool_00->pool_no,pool_00->quota);
          _applog(6,tmp42,false);
        }
        adjust_quota_gcd();
        pcVar1 = (char *)0x0;
      }
    }
  }
  return pcVar1;
}

