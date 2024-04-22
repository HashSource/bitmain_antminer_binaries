
/* WARNING: Unknown calling convention */

void removepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  long paramid;
  pool *ppVar2;
  char *param2;
  char *rpc_url;
  pool *pool_00;
  pool *pool;
  int id;
  
  piVar1 = DAT_0001a81c;
  if (*DAT_0001a81c == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
    return;
  }
  paramid = strtol(param,(char **)0x0,10);
  if ((paramid < 0) || (*piVar1 <= paramid)) {
    message(io_data,0x1a,paramid,(char *)0x0,isjson);
    return;
  }
  if (*piVar1 < 2) {
    message(io_data,0x42,paramid,(char *)0x0,isjson);
    return;
  }
  pool_00 = *(pool **)(*DAT_0001a820 + paramid * 4);
  ppVar2 = current_pool();
  if (pool_00 == ppVar2) {
    switch_pools((pool *)0x0);
  }
  ppVar2 = current_pool();
  if (pool_00 == ppVar2) {
    message(io_data,0x43,paramid,(char *)0x0,isjson);
    return;
  }
  pool_00->enabled = POOL_DISABLED;
  param2 = escape_string(pool_00->rpc_url,isjson);
  if (param2 == pool_00->rpc_url) {
    remove_pool(pool_00);
    message(io_data,0x44,paramid,param2,isjson);
    return;
  }
  remove_pool(pool_00);
  message(io_data,0x44,paramid,param2,isjson);
                    /* WARNING: Could not recover jumptable at 0x0000a260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f208)(param2);
  return;
}

