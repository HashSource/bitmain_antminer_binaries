
int itemstats(io_data *io_data,int i,char *id,cgminer_stats *stats,cgminer_pool_stats *pool_stats,
             api_data *extra,cgpu_info *cgpu,_Bool isjson)

{
  _Bool precom;
  cgminer_stats *stats_local;
  char *id_local;
  int i_local;
  io_data *io_data_local;
  double ghs;
  api_data *root;
  
  root = (api_data *)0x0;
  i_local = i;
  io_data_local = io_data;
  ghs = getAVGhashrate();
  root = api_add_int(root,"STATS",&i_local,false);
  root = api_add_string(root,"ID",id,false);
  root = api_add_elapsed(root,"Elapsed",&total_secs,false);
  root = api_add_uint32(root,"Calls",&stats->getwork_calls,false);
  root = api_add_timeval(root,"Wait",&stats->getwork_wait,false);
  root = api_add_timeval(root,"Max",&stats->getwork_wait_max,false);
  root = api_add_timeval(root,"Min",&stats->getwork_wait_min,false);
  root = api_add_string(root,"GHS 5s",displayed_hash_rate,false);
  root = api_add_mhs(root,"GHS av",&ghs,false);
  if (extra != (api_data *)0x0) {
    root = api_add_extra(root,extra);
  }
  if ((isjson) && (0 < i_local)) {
    precom = true;
  }
  else {
    precom = false;
  }
  print_data(io_data_local,root,isjson,precom);
  return i_local + 1;
}

