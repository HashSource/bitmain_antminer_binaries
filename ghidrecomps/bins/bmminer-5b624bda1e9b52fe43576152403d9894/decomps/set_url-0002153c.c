
/* WARNING: Unknown calling convention */

char * set_url(char *arg)

{
  pool *pool_00;
  pool *pool;
  char *pcVar1;
  char *__haystack;
  char tmp42 [2048];
  
  pool_00 = add_url();
  setup_url(pool_00,arg);
  __haystack = pool_00->rpc_url;
  pcVar1 = strstr(__haystack,DAT_000215b0);
  if ((((pcVar1 != (char *)0x0) || (pcVar1 = strstr(__haystack,DAT_000215c8), pcVar1 != (char *)0x0)
       ) && (pcVar1 = DAT_000215b4, pool_00->extranonce_subscribe = true, *pcVar1 != '\0')) &&
     (((*DAT_000215b8 != '\0' || (*DAT_000215bc != '\0')) || (6 < *DAT_000215c0)))) {
    snprintf(tmp42,0x800,DAT_000215c4,pool_00->pool_no);
    _applog(7,tmp42,false);
  }
  return (char *)0x0;
}

