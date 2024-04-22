
int itemstats(io_data *io_data,int i,char *id,cgminer_stats *stats,cgminer_pool_stats *pool_stats,
             api_data *extra,cgpu_info *cgpu,_Bool isjson)

{
  double *data;
  api_data *paVar1;
  cgminer_pool_stats *pcVar2;
  cgminer_pool_stats *root;
  undefined precom;
  api_data *paVar3;
  api_data *tmp;
  int iVar4;
  int local_2c;
  double ghs;
  
  data = DAT_0001b450;
  ghs = ((*DAT_0001b448 - *DAT_0001b44c) / DAT_0001b440) / (*DAT_0001b450 - *DAT_0001b454);
  local_2c = i;
  paVar1 = api_add_int((api_data *)0x0,DAT_0001b458,&local_2c,false);
  paVar1 = api_add_string(paVar1,DAT_0001b45c,id,false);
  paVar1 = api_add_elapsed(paVar1,DAT_0001b460,data,false);
  paVar1 = api_add_uint32(paVar1,DAT_0001b464,&stats->getwork_calls,false);
  paVar1 = api_add_timeval(paVar1,DAT_0001b468,&stats->getwork_wait,false);
  paVar1 = api_add_timeval(paVar1,DAT_0001b46c,&stats->getwork_wait_max,false);
  paVar1 = api_add_timeval(paVar1,DAT_0001b470,&stats->getwork_wait_min,false);
  paVar1 = api_add_string(paVar1,DAT_0001b474,DAT_0001b478,false);
  pcVar2 = (cgminer_pool_stats *)api_add_mhs(paVar1,DAT_0001b47c,&ghs,false);
  root = pcVar2;
  if ((pool_stats != (cgminer_pool_stats *)0x0) &&
     (root = pool_stats, pcVar2 != (cgminer_pool_stats *)0x0)) {
    paVar3 = (api_data *)(pool_stats->getwork_wait_max).tv_sec;
    (pool_stats->getwork_wait_max).tv_sec = (__time_t)(pcVar2->getwork_wait_max).tv_sec;
    paVar1 = (api_data *)(pcVar2->getwork_wait_max).tv_sec;
    (pcVar2->getwork_wait_max).tv_sec = (__time_t)paVar3;
    paVar1->next = (api_data *)pool_stats;
    paVar3->next = (api_data *)pcVar2;
    root = pcVar2;
  }
  precom = extra._0_1_;
  if (extra._0_1_ != false) {
    iVar4 = local_2c;
    if (local_2c < 1) {
      iVar4 = 0;
    }
    precom = (undefined)iVar4;
    if (0 < local_2c) {
      precom = true;
    }
  }
  print_data(io_data,(api_data *)root,extra._0_1_,(_Bool)precom);
  return local_2c + 1;
}

