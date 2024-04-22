
void poolstatus(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  time_t tVar1;
  char *data;
  _Bool precom;
  pool_enable pVar2;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  double stalep;
  double rejp;
  char lasttime [256];
  int i;
  pool *pool;
  int second;
  int minute;
  int hour;
  long timediff;
  char *lp;
  char *status;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  io_open = false;
  hour = 0;
  minute = 0;
  second = 0;
  memset(lasttime,0,0x100);
  timediff = 0;
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,7,0,(char *)0x0,isjson);
    if (isjson) {
      io_open = io_add(io_data,",\"POOLS\":[");
    }
    for (i = 0; i < total_pools; i = i + 1) {
      pool = pools[i];
      if (pool->removed == false) {
        pVar2 = pool->enabled;
        if (pVar2 == POOL_ENABLED) {
          if (pool->idle == false) {
            status = ALIVE;
          }
          else {
            status = DEAD;
          }
        }
        else if (pVar2 == POOL_DISABLED) {
          status = DISABLED;
        }
        else if (pVar2 == POOL_REJECTING) {
          status = REJECTING;
        }
        else {
          status = UNKNOWN;
        }
        if (pool->hdr_path == (char *)0x0) {
          lp = NO;
        }
        else {
          lp = YES;
        }
        if (pool->last_share_time < 1) {
          lasttime[0] = '0';
          lasttime[1] = '\0';
        }
        else {
          tVar1 = time((time_t *)0x0);
          timediff = tVar1 - pool->last_share_time;
          if (timediff < 0) {
            timediff = 0;
          }
          hour = timediff / 0xe10;
          minute = (timediff % 0xe10) / 0x3c;
          second = (timediff % 0xe10) % 0x3c;
          sprintf(lasttime,"%d:%02d:%02d",hour,minute,second);
        }
        root = api_add_int(root,"POOL",&i,false);
        root = api_add_escape(root,"URL",pool->rpc_url,false);
        root = api_add_string(root,"Status",status,false);
        root = api_add_int(root,"Priority",&pool->prio,false);
        root = api_add_int(root,"Quota",&pool->quota,false);
        root = api_add_string(root,"Long Poll",lp,false);
        root = api_add_uint(root,"Getworks",&pool->getwork_requested,false);
        root = api_add_int64(root,"Accepted",&pool->accepted,false);
        root = api_add_int64(root,"Rejected",&pool->rejected,false);
        root = api_add_uint(root,"Discarded",&pool->discarded_work,false);
        root = api_add_uint(root,"Stale",&pool->stale_shares,false);
        root = api_add_uint(root,"Get Failures",&pool->getfail_occasions,false);
        root = api_add_uint(root,"Remote Failures",&pool->remotefail_occasions,false);
        root = api_add_escape(root,"User",pool->rpc_user,false);
        root = api_add_string(root,"Last Share Time",lasttime,false);
        root = api_add_string(root,"Diff",pool->diff,false);
        root = api_add_int64(root,"Diff1 Shares",&pool->diff1,false);
        if (pool->rpc_proxy == (char *)0x0) {
          root = api_add_const(root,"Proxy Type",BLANK,false);
          root = api_add_const(root,"Proxy",BLANK,false);
        }
        else {
          data = proxytype(pool->rpc_proxytype);
          root = api_add_const(root,"Proxy Type",data,false);
          root = api_add_escape(root,"Proxy",pool->rpc_proxy,false);
        }
        root = api_add_diff(root,"Difficulty Accepted",&pool->diff_accepted,false);
        root = api_add_diff(root,"Difficulty Rejected",&pool->diff_rejected,false);
        root = api_add_diff(root,"Difficulty Stale",&pool->diff_stale,false);
        root = api_add_diff(root,"Last Share Difficulty",&pool->last_share_diff,false);
        root = api_add_bool(root,"Has Stratum",&pool->has_stratum,false);
        root = api_add_bool(root,"Stratum Active",&pool->stratum_active,false);
        if (pool->stratum_active == false) {
          root = api_add_const(root,"Stratum URL",BLANK,false);
        }
        else {
          root = api_add_escape(root,"Stratum URL",pool->stratum_url,false);
        }
        root = api_add_bool(root,"Has GBT",&pool->has_gbt,false);
        root = api_add_uint64(root,"Best Share",&pool->best_diff,true);
        rejp = DAT_0000dcd8;
        if (pool->diff_accepted + pool->diff_rejected + pool->diff_stale != 0.0) {
          rejp = pool->diff_rejected /
                 (pool->diff_accepted + pool->diff_rejected + pool->diff_stale);
        }
        root = api_add_percent(root,"Pool Rejected%",&rejp,false);
        stalep = DAT_0000dcd8;
        if (pool->diff_accepted + pool->diff_rejected + pool->diff_stale != 0.0) {
          stalep = pool->diff_stale / (pool->diff_accepted + pool->diff_rejected + pool->diff_stale)
          ;
        }
        root = api_add_percent(root,"Pool Stale%",&stalep,false);
        if ((isjson) && (0 < i)) {
          precom = true;
        }
        else {
          precom = false;
        }
        root = print_data(io_data,root,isjson,precom);
      }
    }
    if ((isjson) && (io_open != false)) {
      io_close(io_data);
    }
  }
  return;
}

