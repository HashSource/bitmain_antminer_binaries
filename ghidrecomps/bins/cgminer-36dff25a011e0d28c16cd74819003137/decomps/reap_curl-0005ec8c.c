
void reap_curl(pool *pool)

{
  uint uVar1;
  list_head *plVar2;
  pool *pool_local;
  char tmp42 [2048];
  timeval now;
  int reaped;
  curl_ent *iter;
  curl_ent *ent;
  
  reaped = 0;
  cgtime(&now);
  _mutex_lock(&pool->pool_lock,"cgminer.c","reap_curl",0x2772);
  plVar2 = (pool->curlring).next;
  ent = (curl_ent *)&plVar2[-1].prev;
  plVar2 = plVar2->next;
  while( true ) {
    iter = (curl_ent *)&plVar2[-1].prev;
    if (&ent->node == &pool->curlring) {
      _mutex_unlock(&pool->pool_lock,"cgminer.c","reap_curl",0x2784);
      if (((reaped != 0) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        if (reaped < 2) {
          uVar1 = 0x1bd4;
        }
        else {
          uVar1 = 0x4f60;
        }
        snprintf(tmp42,0x800,"Reaped %d curl%s from pool %d",reaped,uVar1 | 0xa0000,pool->pool_no);
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
    plVar2 = plVar2->next;
  }
  return;
}

