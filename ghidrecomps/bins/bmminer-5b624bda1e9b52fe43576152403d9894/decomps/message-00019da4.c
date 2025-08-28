
/* WARNING: Unknown calling convention */

void message(io_data *io_data,int messageid,int paramid,char *param2,_Bool isjson)

{
  CODES *pCVar1;
  api_data *paVar2;
  CODES *pCVar3;
  char *pcVar4;
  code_severity cVar5;
  int iVar6;
  int local_202c;
  char severity [2];
  int local_2024;
  char buf [8192];
  
  local_202c = messageid;
  if (isjson) {
    io_add(io_data,"{\"STATUS\":[");
  }
  if (codes[0].severity == SEVERITY_FAIL) {
LAB_00019dea:
    paVar2 = api_add_string((api_data *)0x0,"STATUS","F",false);
    paVar2 = api_add_time(paVar2,"When",&when,false);
    local_2024 = -1;
    paVar2 = api_add_int(paVar2,"Code",&local_2024,false);
    sprintf(buf,"%d",local_202c);
  }
  else {
    if (codes[0].code == local_202c) {
      iVar6 = 0;
      cVar5 = codes[0].severity;
    }
    else {
      iVar6 = 0;
      pCVar3 = codes;
      do {
        cVar5 = pCVar3[1].severity;
        iVar6 = iVar6 + 1;
        if (cVar5 == SEVERITY_FAIL) goto LAB_00019dea;
        pCVar1 = pCVar3 + 1;
        pCVar3 = pCVar3 + 1;
      } while (pCVar1->code != local_202c);
    }
    if (cVar5 == SEVERITY_INFO) {
      severity[0] = 'I';
    }
    else if (cVar5 == SEVERITY_SUCC) {
      severity[0] = 'S';
    }
    else if (cVar5 == SEVERITY_WARN) {
      severity[0] = 'W';
    }
    else {
      severity[0] = 'E';
    }
    severity[1] = '\0';
    switch(codes[iVar6].params) {
    case PARAM_PGA:
    case PARAM_ASC:
    case PARAM_PID:
    case PARAM_INT:
      sprintf(buf,codes[iVar6].description,paramid);
      break;
    default:
      strcpy(buf,codes[iVar6].description);
      break;
    case PARAM_PMAX:
      sprintf(buf,codes[iVar6].description,total_pools);
      break;
    case PARAM_POOLMAX:
      sprintf(buf,codes[iVar6].description,paramid,total_pools + -1);
      break;
    case PARAM_DMAX:
      sprintf(buf,codes[iVar6].description);
      break;
    case PARAM_CMD:
      sprintf(buf,codes[iVar6].description,"command");
      break;
    case PARAM_POOL:
      sprintf(buf,codes[iVar6].description,paramid,pools[paramid]->rpc_url);
      break;
    case PARAM_STR:
      sprintf(buf,codes[iVar6].description,param2);
      break;
    case PARAM_BOTH:
      sprintf(buf,codes[iVar6].description,paramid,param2);
      break;
    case PARAM_BOOL:
      pcVar4 = "false";
      if (paramid != 0) {
        pcVar4 = "true";
      }
      sprintf(buf,codes[iVar6].description,pcVar4);
      break;
    case PARAM_SET:
      sprintf(buf,codes[iVar6].description,param2,paramid);
    }
    paVar2 = api_add_string((api_data *)0x0,"STATUS",severity,false);
    paVar2 = api_add_time(paVar2,"When",&when,false);
    paVar2 = api_add_int(paVar2,"Code",&local_202c,false);
  }
  paVar2 = api_add_escape(paVar2,"Msg",buf,false);
  paVar2 = api_add_escape(paVar2,"Description",opt_api_description,false);
  print_data(io_data,paVar2,isjson,false);
  if (isjson) {
    io_add(io_data,"]");
  }
  return;
}

