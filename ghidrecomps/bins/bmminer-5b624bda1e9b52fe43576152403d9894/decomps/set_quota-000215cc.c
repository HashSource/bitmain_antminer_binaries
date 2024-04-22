
/* WARNING: Unknown calling convention */

char * set_quota(char *arg)

{
  char *pcVar1;
  char *semicolon;
  size_t sVar2;
  int len;
  size_t sVar3;
  int qlen;
  long lVar4;
  char *pcVar5;
  pool *pool_00;
  pool *pool;
  char *url;
  int quota;
  char tmp42 [2048];
  
  pcVar1 = strchr(arg,0x3b);
  pcVar5 = DAT_00021678;
  if (pcVar1 != (char *)0x0) {
    sVar2 = strlen(arg);
    *pcVar1 = '\0';
    sVar3 = strlen(arg);
    pcVar5 = DAT_00021674;
    if (((sVar3 != 0) && (pcVar5 = DAT_00021670, 0 < (int)(~sVar3 + sVar2))) &&
       (lVar4 = strtol(arg,(char **)0x0,10), pcVar5 = DAT_0002166c, -1 < lVar4)) {
      pool_00 = add_url();
      setup_url(pool_00,arg + sVar3 + 1);
      pcVar5 = DAT_0002167c;
      pool_00->quota = lVar4;
      if (((*pcVar5 != '\0') || (*DAT_00021680 != '\0')) || (5 < *DAT_00021684)) {
        snprintf(tmp42,0x800,DAT_00021688,pool_00->pool_no,lVar4);
        _applog(6,tmp42,false);
      }
      adjust_quota_gcd();
      pcVar5 = (char *)0x0;
    }
  }
  return pcVar5;
}

