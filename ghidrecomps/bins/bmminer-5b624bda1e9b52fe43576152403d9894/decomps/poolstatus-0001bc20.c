
/* WARNING: Unknown calling convention */

void poolstatus(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  time_t tVar2;
  uint uVar3;
  undefined1 precom;
  pool_enable pVar4;
  pool *ppVar5;
  int iVar6;
  api_data *paVar7;
  char *pcVar8;
  double dVar9;
  char *local_150;
  int local_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  char lasttime [256];
  
  memset(lasttime,0,0x100);
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,7,0,(char *)0x0,isjson);
    if (isjson) {
      _Var1 = io_add(io_data,",\"POOLS\":[");
    }
    else {
      _Var1 = false;
    }
    local_13c = 0;
    if (0 < total_pools) {
      paVar7 = (api_data *)0x0;
      do {
        ppVar5 = pools[local_13c];
        if (ppVar5->removed == false) {
          pVar4 = ppVar5->enabled;
          if (pVar4 == POOL_ENABLED) {
            local_150 = "Alive";
            if (ppVar5->idle != false) {
              local_150 = "Dead";
            }
          }
          else if (pVar4 == POOL_DISABLED) {
            local_150 = "Disabled";
          }
          else {
            local_150 = "Rejecting";
            if (pVar4 != POOL_REJECTING) {
              local_150 = "Unknown";
            }
          }
          if (ppVar5->hdr_path == (char *)0x0) {
            pcVar8 = "N";
          }
          else {
            pcVar8 = "Y";
          }
          if (ppVar5->last_share_time < 1) {
            lasttime[0] = '0';
            lasttime[1] = '\0';
          }
          else {
            tVar2 = time((time_t *)0x0);
            uVar3 = tVar2 - ppVar5->last_share_time;
            uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
            iVar6 = (int)uVar3 % 0xe10;
            sprintf(lasttime,"%d:%02d:%02d",(int)uVar3 / 0xe10,iVar6 / 0x3c,iVar6 % 0x3c);
          }
          paVar7 = api_add_int(paVar7,"POOL",&local_13c,false);
          paVar7 = api_add_escape(paVar7,"URL",ppVar5->rpc_url,false);
          paVar7 = api_add_string(paVar7,"Status",local_150,false);
          paVar7 = api_add_int(paVar7,"Priority",&ppVar5->prio,false);
          paVar7 = api_add_int(paVar7,"Quota",&ppVar5->quota,false);
          paVar7 = api_add_string(paVar7,"Long Poll",pcVar8,false);
          paVar7 = api_add_uint(paVar7,"Getworks",&ppVar5->getwork_requested,false);
          paVar7 = api_add_int64(paVar7,"Accepted",&ppVar5->accepted,false);
          paVar7 = api_add_int64(paVar7,"Rejected",&ppVar5->rejected,false);
          paVar7 = api_add_uint(paVar7,"Discarded",&ppVar5->discarded_work,false);
          paVar7 = api_add_uint(paVar7,"Stale",&ppVar5->stale_shares,false);
          paVar7 = api_add_uint(paVar7,"Get Failures",&ppVar5->getfail_occasions,false);
          paVar7 = api_add_uint(paVar7,"Remote Failures",&ppVar5->remotefail_occasions,false);
          paVar7 = api_add_escape(paVar7,"User",ppVar5->rpc_user,false);
          paVar7 = api_add_string(paVar7,"Last Share Time",lasttime,false);
          paVar7 = api_add_string(paVar7,"Diff",ppVar5->diff,false);
          paVar7 = api_add_int64(paVar7,"Diff1 Shares",&ppVar5->diff1,false);
          if (ppVar5->rpc_proxy == (char *)0x0) {
            paVar7 = api_add_const(paVar7,"Proxy Type","",false);
            paVar7 = api_add_const(paVar7,"Proxy","",false);
          }
          else {
            pcVar8 = proxytype(ppVar5->rpc_proxytype);
            paVar7 = api_add_const(paVar7,"Proxy Type",pcVar8,false);
            paVar7 = api_add_escape(paVar7,"Proxy",ppVar5->rpc_proxy,false);
          }
          paVar7 = api_add_diff(paVar7,"Difficulty Accepted",&ppVar5->diff_accepted,false);
          paVar7 = api_add_diff(paVar7,"Difficulty Rejected",&ppVar5->diff_rejected,false);
          paVar7 = api_add_diff(paVar7,"Difficulty Stale",&ppVar5->diff_stale,false);
          paVar7 = api_add_diff(paVar7,"Last Share Difficulty",&ppVar5->last_share_diff,false);
          paVar7 = api_add_bool(paVar7,"Has Stratum",&ppVar5->has_stratum,false);
          paVar7 = api_add_bool(paVar7,"Stratum Active",&ppVar5->stratum_active,false);
          if (ppVar5->stratum_active == false) {
            paVar7 = api_add_const(paVar7,"Stratum URL","",false);
          }
          else {
            paVar7 = api_add_escape(paVar7,"Stratum URL",ppVar5->stratum_url,false);
          }
          paVar7 = api_add_bool(paVar7,"Has GBT",&ppVar5->has_gbt,false);
          paVar7 = api_add_uint64(paVar7,"Best Share",&ppVar5->best_diff,true);
          dVar9 = ppVar5->diff_rejected + ppVar5->diff_accepted + ppVar5->diff_stale;
          if (dVar9 == 0.0) {
            dVar9 = 0.0;
          }
          else {
            dVar9 = ppVar5->diff_rejected / dVar9;
          }
          uStack_134 = (undefined4)((ulonglong)dVar9 >> 0x20);
          local_138 = SUB84(dVar9,0);
          paVar7 = api_add_percent(paVar7,"Pool Rejected%",(double *)&local_138,false);
          dVar9 = ppVar5->diff_accepted + ppVar5->diff_rejected + ppVar5->diff_stale;
          if (dVar9 == 0.0) {
            dVar9 = 0.0;
          }
          else {
            dVar9 = ppVar5->diff_stale / dVar9;
          }
          uStack_12c = (undefined4)((ulonglong)dVar9 >> 0x20);
          local_130 = SUB84(dVar9,0);
          paVar7 = api_add_percent(paVar7,"Pool Stale%",(double *)&local_130,false);
          precom = isjson;
          if (isjson) {
            iVar6 = local_13c;
            if (local_13c < 1) {
              iVar6 = 0;
            }
            precom = (undefined1)iVar6;
            if (0 < local_13c) {
              precom = true;
            }
          }
          paVar7 = print_data(io_data,paVar7,isjson,(_Bool)precom);
        }
        local_13c = local_13c + 1;
      } while (local_13c < total_pools);
    }
    if (_Var1 != false) {
      io_data->close = true;
    }
  }
  return;
}

