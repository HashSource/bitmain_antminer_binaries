
void write_config(FILE *fcfg)

{
  uint uVar1;
  uint uVar2;
  pool *ppVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  FILE *fcfg_local;
  pool *pool;
  char *carg;
  char *name;
  char *p;
  int i;
  opt_table *opt;
  
  fwrite("{\n\"pools\" : [",1,0xd,(FILE *)fcfg);
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar3 = priority_pool(i);
    if (ppVar3->quota == 1) {
      if (i < 1) {
        uVar1 = 0x1bd4;
      }
      else {
        uVar1 = 0x2074;
      }
      if (ppVar3->rpc_proxy == (char *)0x0) {
        pcVar5 = "";
      }
      else {
        pcVar5 = proxytype(ppVar3->rpc_proxytype);
        pcVar5 = json_escape(pcVar5);
      }
      if (ppVar3->rpc_proxy == (char *)0x0) {
        pcVar6 = "";
      }
      else {
        pcVar6 = json_escape(ppVar3->rpc_proxy);
      }
      if (ppVar3->rpc_proxy == (char *)0x0) {
        uVar2 = 0x1bd4;
      }
      else {
        uVar2 = 0x32bc;
      }
      pcVar4 = json_escape(ppVar3->rpc_url);
      fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",",uVar1 | 0xa0000,pcVar5,pcVar6,
              uVar2 | 0xa0000,pcVar4);
    }
    else {
      if (i < 1) {
        uVar1 = 0x1bd4;
      }
      else {
        uVar1 = 0x2074;
      }
      if (ppVar3->rpc_proxy == (char *)0x0) {
        pcVar5 = "";
      }
      else {
        pcVar5 = proxytype(ppVar3->rpc_proxytype);
        pcVar5 = json_escape(pcVar5);
      }
      if (ppVar3->rpc_proxy == (char *)0x0) {
        pcVar6 = "";
      }
      else {
        pcVar6 = json_escape(ppVar3->rpc_proxy);
      }
      if (ppVar3->rpc_proxy == (char *)0x0) {
        uVar2 = 0x1bd4;
      }
      else {
        uVar2 = 0x32bc;
      }
      iVar7 = ppVar3->quota;
      pcVar4 = json_escape(ppVar3->rpc_url);
      fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",",uVar1 | 0xa0000,pcVar5,pcVar6
              ,uVar2 | 0xa0000,iVar7,pcVar4);
    }
    if (ppVar3->extranonce_subscribe != false) {
      fwrite("\n\t\t\"extranonce-subscribe\" : true,",1,0x21,(FILE *)fcfg);
    }
    pcVar5 = json_escape(ppVar3->rpc_user);
    fprintf((FILE *)fcfg,"\n\t\t\"user\" : \"%s\",",pcVar5);
    pcVar5 = json_escape(ppVar3->rpc_pass);
    fprintf((FILE *)fcfg,"\n\t\t\"pass\" : \"%s\"\n\t}",pcVar5);
  }
  fwrite(&DAT_000a3fcc,1,3,(FILE *)fcfg);
  for (opt = opt_config_table; opt->type != OPT_END; opt = opt + 1) {
    pcVar5 = strdup(opt->names);
    p = strtok(pcVar5,"|");
    while (p != (char *)0x0) {
      if ((p[1] == '-') && ((undefined4 *)opt->desc != &opt_hidden)) {
                    /* WARNING: Load size is inaccurate */
        if (((opt->type & OPT_NOARG) == 0) ||
           (((opt->cb != opt_set_bool && (opt->cb != opt_set_invbool)) ||
            ((bool)*(opt->u).carg != (opt->cb == opt_set_bool))))) {
          if (((opt->type & OPT_HASARG) == 0) ||
             (((((opt->cb_arg != opt_set_intval && (opt->cb_arg != set_int_0_to_9999)) &&
                ((opt->cb_arg != set_int_1_to_65535 &&
                 ((opt->cb_arg != set_int_0_to_10 && (opt->cb_arg != set_int_1_to_10)))))) &&
               (opt->cb_arg != set_int_0_to_100)) &&
              ((((((opt->cb_arg != set_int_0_to_255 && (opt->cb_arg != set_int_1_to_255)) &&
                  (opt->cb_arg != set_int_0_to_7680)) &&
                 ((opt->cb_arg != set_int_0_to_200 && (opt->cb_arg != set_int_0_to_4)))) &&
                ((opt->cb_arg != set_int_32_to_63 &&
                 ((opt->cb_arg != set_int_22_to_75 && (opt->cb_arg != set_int_42_to_85)))))) &&
               ((opt->cb_arg != set_int_22_to_55 && (opt->cb_arg != set_int_42_to_65)))))))) {
            if (((opt->type & OPT_HASARG) == 0) ||
               ((opt->cb_arg != set_float_125_to_500 && (opt->cb_arg != set_float_100_to_250)))) {
                    /* WARNING: Load size is inaccurate */
              if (((opt->type & (OPT_HASARG|OPT_PROCESSARG)) != 0) &&
                 (((char **)(opt->u).carg != &opt_set_null && (*(opt->u).carg != (char *)0x0)))) {
                pcVar6 = json_escape(*(opt->u).carg);
                fprintf((FILE *)fcfg,",\n\"%s\" : \"%s\"",p + 2,pcVar6);
              }
            }
            else {
                    /* WARNING: Load size is inaccurate */
              fprintf((FILE *)fcfg,",\n\"%s\" : \"%.1f\"",p + 2,(opt->u).carg,(double)*(opt->u).carg
                     );
            }
          }
          else {
                    /* WARNING: Load size is inaccurate */
            fprintf((FILE *)fcfg,",\n\"%s\" : \"%d\"",p + 2,*(opt->u).carg);
          }
        }
        else {
          fprintf((FILE *)fcfg,",\n\"%s\" : true",p + 2);
        }
      }
      p = strtok((char *)0x0,"|");
    }
    free(pcVar5);
  }
  if (pool_strategy == POOL_BALANCE) {
    fwrite(",\n\"balance\" : true",1,0x12,(FILE *)fcfg);
  }
  if (pool_strategy == POOL_LOADBALANCE) {
    fwrite(",\n\"load-balance\" : true",1,0x17,(FILE *)fcfg);
  }
  if (pool_strategy == POOL_ROUNDROBIN) {
    fwrite(",\n\"round-robin\" : true",1,0x16,(FILE *)fcfg);
  }
  if (pool_strategy == POOL_ROTATE) {
    fprintf((FILE *)fcfg,",\n\"rotate\" : \"%d\"",opt_rotate_period);
  }
  fwrite(&DAT_000a4068,1,3,(FILE *)fcfg);
  json_escape_free();
  return;
}

