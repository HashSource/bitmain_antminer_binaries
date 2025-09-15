
void poolquota(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *pcVar1;
  int iVar2;
  pool *ppVar3;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  int quota;
  pool *pool;
  int id;
  char *comma;
  
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
  }
  else {
    pcVar1 = strchr(param,0x2c);
    if (pcVar1 == (char *)0x0) {
      message(io_data,0x56,0,param,isjson);
    }
    else {
      *pcVar1 = '\0';
      iVar2 = atoi(param);
      if ((iVar2 < 0) || (total_pools <= iVar2)) {
        message(io_data,0x1a,iVar2,(char *)0x0,isjson);
      }
      else {
        ppVar3 = pools[iVar2];
        iVar2 = atoi(pcVar1 + 1);
        if (iVar2 < 0) {
          message(io_data,0x79,iVar2,ppVar3->rpc_url,isjson);
        }
        else {
          ppVar3->quota = iVar2;
          adjust_quota_gcd();
          message(io_data,0x7a,iVar2,ppVar3->rpc_url,isjson);
        }
      }
    }
  }
  return;
}

