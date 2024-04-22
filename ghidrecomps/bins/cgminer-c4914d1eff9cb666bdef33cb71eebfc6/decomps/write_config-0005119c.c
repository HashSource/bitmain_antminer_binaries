
void write_config(FILE *fcfg)

{
  pool *ppVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  FILE *fcfg_local;
  pool *pool;
  char *carg;
  char *name;
  char *p;
  int i;
  opt_table *opt;
  
  fwrite("{\n\"pools\" : [",1,0xd,(FILE *)fcfg);
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar1 = priority_pool(i);
    if (ppVar1->quota == 1) {
      if (i < 1) {
        puVar7 = &DAT_0008a828;
      }
      else {
        puVar7 = &DAT_0008acc8;
      }
      if (ppVar1->rpc_proxy == (char *)0x0) {
        pcVar3 = "";
      }
      else {
        pcVar3 = proxytype(ppVar1->rpc_proxytype);
        pcVar3 = json_escape(pcVar3);
      }
      if (ppVar1->rpc_proxy == (char *)0x0) {
        pcVar4 = "";
      }
      else {
        pcVar4 = json_escape(ppVar1->rpc_proxy);
      }
      if (ppVar1->rpc_proxy == (char *)0x0) {
        puVar6 = &DAT_0008a828;
      }
      else {
        puVar6 = &DAT_0008bf10;
      }
      pcVar2 = json_escape(ppVar1->rpc_url);
      fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",",puVar7,pcVar3,pcVar4,puVar6,pcVar2
             );
    }
    else {
      if (i < 1) {
        puVar7 = &DAT_0008a828;
      }
      else {
        puVar7 = &DAT_0008acc8;
      }
      if (ppVar1->rpc_proxy == (char *)0x0) {
        pcVar3 = "";
      }
      else {
        pcVar3 = proxytype(ppVar1->rpc_proxytype);
        pcVar3 = json_escape(pcVar3);
      }
      if (ppVar1->rpc_proxy == (char *)0x0) {
        pcVar4 = "";
      }
      else {
        pcVar4 = json_escape(ppVar1->rpc_proxy);
      }
      if (ppVar1->rpc_proxy == (char *)0x0) {
        puVar6 = &DAT_0008a828;
      }
      else {
        puVar6 = &DAT_0008bf10;
      }
      iVar5 = ppVar1->quota;
      pcVar2 = json_escape(ppVar1->rpc_url);
      fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",",puVar7,pcVar3,pcVar4,puVar6,
              iVar5,pcVar2);
    }
    if (ppVar1->extranonce_subscribe != false) {
      fwrite("\n\t\t\"extranonce-subscribe\" : true,",1,0x21,(FILE *)fcfg);
    }
    pcVar3 = json_escape(ppVar1->rpc_user);
    fprintf((FILE *)fcfg,"\n\t\t\"user\" : \"%s\",",pcVar3);
    pcVar3 = json_escape(ppVar1->rpc_pass);
    fprintf((FILE *)fcfg,"\n\t\t\"pass\" : \"%s\"\n\t}",pcVar3);
  }
  fwrite(&DAT_0008cc10,1,3,(FILE *)fcfg);
  for (opt = opt_config_table; opt->type != OPT_END; opt = opt + 1) {
    pcVar3 = strdup(opt->names);
    p = strtok(pcVar3,"|");
    while (p != (char *)0x0) {
      if ((p[1] == '-') && ((undefined4 *)opt->desc != &opt_hidden)) {
                    /* WARNING: Load size is inaccurate */
        if (((opt->type & OPT_NOARG) == 0) ||
           (((opt->cb != opt_set_bool + 1 && (opt->cb != opt_set_invbool + 1)) ||
            ((bool)*(opt->u).carg != (opt->cb == opt_set_bool + 1))))) {
          if (((opt->type & OPT_HASARG) == 0) ||
             (((((opt->cb_arg != opt_set_intval + 1 && (opt->cb_arg != set_int_0_to_9999 + 1)) &&
                ((opt->cb_arg != set_int_1_to_65535 + 1 &&
                 ((opt->cb_arg != set_int_0_to_10 + 1 && (opt->cb_arg != set_int_1_to_10 + 1))))))
               && (opt->cb_arg != set_int_0_to_100 + 1)) &&
              ((((((opt->cb_arg != set_int_0_to_255 + 1 && (opt->cb_arg != set_int_1_to_255 + 1)) &&
                  (opt->cb_arg != set_int_0_to_7680 + 1)) &&
                 ((opt->cb_arg != set_int_0_to_200 + 1 && (opt->cb_arg != set_int_0_to_4 + 1)))) &&
                ((opt->cb_arg != set_int_32_to_63 + 1 &&
                 ((opt->cb_arg != set_int_22_to_75 + 1 && (opt->cb_arg != set_int_42_to_85 + 1))))))
               && ((opt->cb_arg != set_int_22_to_55 + 1 && (opt->cb_arg != set_int_42_to_65 + 1)))))
              ))) {
            if (((opt->type & OPT_HASARG) == 0) ||
               ((opt->cb_arg != set_float_125_to_500 + 1 &&
                (opt->cb_arg != set_float_100_to_250 + 1)))) {
                    /* WARNING: Load size is inaccurate */
              if (((opt->type & (OPT_HASARG|OPT_PROCESSARG)) != 0) &&
                 (((char **)(opt->u).carg != &opt_set_null && (*(opt->u).carg != (char *)0x0)))) {
                pcVar4 = json_escape(*(opt->u).carg);
                fprintf((FILE *)fcfg,",\n\"%s\" : \"%s\"",p + 2,pcVar4);
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
    free(pcVar3);
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
  fwrite(&DAT_0008ccac,1,3,(FILE *)fcfg);
  json_escape_free();
  return;
}

