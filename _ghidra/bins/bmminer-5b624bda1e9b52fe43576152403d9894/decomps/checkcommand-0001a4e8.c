
/* WARNING: Unknown calling convention */

void checkcommand(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  int iVar2;
  __int32_t **pp_Var3;
  char *pcVar4;
  api_data *paVar5;
  char *buf;
  char *pcVar6;
  undefined1 extraout_r3;
  undefined1 uVar7;
  __int32_t *p_Var8;
  CMDS *pCVar9;
  char cmdbuf [100];
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x47,0,(char *)0x0,isjson);
  }
  else {
    pcVar4 = cmds[0].name;
    pcVar6 = cmds[0].name;
    if (cmds[0].name != (char *)0x0) {
      pCVar9 = cmds;
      do {
        iVar2 = strcmp(pcVar4,param);
        if (iVar2 == 0) {
          sprintf(cmdbuf,"|%s|",param);
          pp_Var3 = __ctype_toupper_loc();
          p_Var8 = *pp_Var3;
          if (p_Var8[(byte)group] != p_Var8[0x57]) {
            pcVar4 = strstr(apigroups[p_Var8[(byte)group] - p_Var8[0x41]].commands,cmdbuf);
            pcVar6 = (char *)0x1;
            if (pcVar4 == (char *)0x0) break;
          }
          pcVar4 = (char *)0x1;
          pcVar6 = (char *)0x1;
          break;
        }
        pCVar9 = pCVar9 + 1;
        pcVar4 = pCVar9->name;
        pcVar6 = pcVar4;
      } while (pcVar4 != (char *)0x0);
    }
    message(io_data,0x48,0,(char *)0x0,isjson);
    buf = "CHECK,";
    if (isjson) {
      buf = ",\"CHECK\":[";
    }
    _Var1 = io_add(io_data,buf);
    if (pcVar6 == (char *)0x0) {
      pcVar6 = "N";
    }
    else {
      pcVar6 = "Y";
    }
    paVar5 = api_add_const((api_data *)0x0,"Exists",pcVar6,false);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = "N";
    }
    else {
      pcVar4 = "Y";
    }
    paVar5 = api_add_const(paVar5,"Access",pcVar4,false);
    print_data(io_data,paVar5,isjson,false);
    uVar7 = extraout_r3;
    if (_Var1 && isjson) {
      uVar7 = true;
    }
    if (_Var1 && isjson) {
      io_data->close = (_Bool)uVar7;
    }
  }
  return;
}

