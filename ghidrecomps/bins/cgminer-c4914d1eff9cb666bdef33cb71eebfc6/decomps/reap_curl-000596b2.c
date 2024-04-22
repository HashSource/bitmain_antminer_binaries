
void reap_curl(pool *pool)

{
  list_head *plVar1;
  undefined1 *puVar2;
  pool *pool_local;
  char tmp42 [2048];
  timeval now;
  int reaped;
  curl_ent *iter;
  curl_ent *ent;
  
  reaped = 0;
  cgtime(&now);
  _mutex_lock(&pool->pool_lock,"cgminer.c","reap_curl",0x2772);
  plVar1 = (pool->curlring).next;
  ent = (curl_ent *)&plVar1[-1].prev;
  plVar1 = plVar1->next;
  while( true ) {
    iter = (curl_ent *)&plVar1[-1].prev;
    if (&ent->node == &pool->curlring) {
      _mutex_unlock(&pool->pool_lock,"cgminer.c","reap_curl",0x2784);
      if (((reaped != 0) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        if (reaped < 2) {
          puVar2 = &DAT_0008a828;
        }
        else {
          puVar2 = &DAT_0008dba8;
        }
        snprintf(tmp42,0x800,"Reaped %d curl%s from pool %d",reaped,puVar2,pool->pool_no);
        _applog(7,tmp42,false);
      }
      return;
    }
    if (pool->curls < 2) break;
    if (300 < now.tv_sec - (ent->tv).tv_sec) {
      reaped = reaped + 1;
      pool->curls = pool->curls + -1;
      list_del(&ent->node);
      free(ent);
    }
    ent = iter;
    plVar1 = plVar1->next;
  }
  return;
}

