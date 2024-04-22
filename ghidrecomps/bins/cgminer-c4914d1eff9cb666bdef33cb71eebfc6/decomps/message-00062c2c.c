
void message(io_data *io_data,int messageid,int paramid,char *param2,_Bool isjson)

{
  int iVar1;
  api_data *paVar2;
  char *pcVar3;
  code_severity cVar4;
  char *param2_local;
  int paramid_local;
  int messageid_local;
  io_data *io_data_local;
  int id;
  char severity [2];
  char buf [8192];
  int asc;
  api_data *root;
  int i;
  
  messageid_local = messageid;
  io_data_local = io_data;
  if (isjson) {
    io_add(io_data,"{\"STATUS\":[");
  }
  i = 0;
  while( true ) {
    if (codes[i].severity == SEVERITY_FAIL) {
      paVar2 = api_add_string((api_data *)0x0,"STATUS","F",false);
      paVar2 = api_add_time(paVar2,"When",&when,false);
      id = -1;
      paVar2 = api_add_int(paVar2,"Code",&id,false);
      sprintf(buf,"%d",messageid_local);
      paVar2 = api_add_escape(paVar2,"Msg",buf,false);
      paVar2 = api_add_escape(paVar2,"Description",opt_api_description,false);
      print_data(io_data_local,paVar2,isjson,false);
      if (isjson) {
        io_add(io_data_local,(char *)&DAT_00092f40);
      }
      return;
    }
    if (codes[i].code == messageid_local) break;
    i = i + 1;
  }
  cVar4 = codes[i].severity;
  if (cVar4 == SEVERITY_INFO) {
    severity[0] = 'I';
  }
  else if (cVar4 == SEVERITY_SUCC) {
    severity[0] = 'S';
  }
  else if (cVar4 == SEVERITY_WARN) {
    severity[0] = 'W';
  }
  else {
    severity[0] = 'E';
  }
  severity[1] = '\0';
  switch(codes[i].params) {
  case PARAM_PGA:
  case PARAM_ASC:
  case PARAM_PID:
  case PARAM_INT:
    sprintf(buf,codes[i].description,paramid);
    break;
  default:
    strcpy(buf,codes[i].description);
    break;
  case PARAM_ASCMAX:
    iVar1 = numascs();
    sprintf(buf,codes[i].description,paramid,iVar1 + -1);
    break;
  case PARAM_PMAX:
    sprintf(buf,codes[i].description,total_pools);
    break;
  case PARAM_POOLMAX:
    sprintf(buf,codes[i].description,paramid,total_pools + -1);
    break;
  case PARAM_DMAX:
    iVar1 = numascs();
    sprintf(buf,codes[i].description,iVar1);
    break;
  case PARAM_CMD:
    sprintf(buf,codes[i].description,JSON_COMMAND);
    break;
  case PARAM_POOL:
    sprintf(buf,codes[i].description,paramid,pools[paramid]->rpc_url);
    break;
  case PARAM_STR:
    sprintf(buf,codes[i].description,param2);
    break;
  case PARAM_BOTH:
    sprintf(buf,codes[i].description,paramid,param2);
    break;
  case PARAM_BOOL:
    pcVar3 = FALSESTR;
    if (paramid != 0) {
      pcVar3 = TRUESTR;
    }
    sprintf(buf,codes[i].description,pcVar3);
    break;
  case PARAM_SET:
    sprintf(buf,codes[i].description,param2,paramid);
  }
  paVar2 = api_add_string((api_data *)0x0,"STATUS",severity,false);
  paVar2 = api_add_time(paVar2,"When",&when,false);
  paVar2 = api_add_int(paVar2,"Code",&messageid_local,false);
  paVar2 = api_add_escape(paVar2,"Msg",buf,false);
  paVar2 = api_add_escape(paVar2,"Description",opt_api_description,false);
  print_data(io_data_local,paVar2,isjson,false);
  if (!isjson) {
    return;
  }
  io_add(io_data_local,(char *)&DAT_00092f40);
  return;
}

