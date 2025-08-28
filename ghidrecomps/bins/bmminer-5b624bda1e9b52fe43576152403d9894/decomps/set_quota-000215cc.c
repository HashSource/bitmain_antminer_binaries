
/* WARNING: Unknown calling convention */

char * set_quota(char *arg)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  long lVar4;
  pool *pool;
  char *url;
  int quota;
  char tmp42 [2048];
  
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
    else if ((int)(~sVar3 + sVar2) < 1) {
      pcVar1 = "No parameter for URL found";
    }
    else {
      lVar4 = strtol(arg,(char **)0x0,10);
      if (lVar4 < 0) {
        pcVar1 = "Invalid negative parameter for quota set";
      }
      else {
        pool = add_url();
        setup_url(pool,arg + sVar3 + 1);
        pool->quota = lVar4;
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"Setting pool %d to quota %d",pool->pool_no,lVar4);
          _applog(6,tmp42,false);
        }
        adjust_quota_gcd();
        pcVar1 = (char *)0x0;
      }
    }
  }
  return pcVar1;
}

