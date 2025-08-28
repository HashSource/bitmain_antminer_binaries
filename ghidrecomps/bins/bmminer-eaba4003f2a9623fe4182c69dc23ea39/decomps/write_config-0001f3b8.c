
void write_config(FILE *fcfg)

{
  pool *ppVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  FILE *fcfg_local;
  char *carg;
  char *name;
  pool *pool;
  char *p;
  int i;
  opt_table *opt;
  
  fwrite("{\n\"pools\" : [",1,0xd,(FILE *)fcfg);
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar1 = priority_pool(i);
    if (ppVar1->quota == 1) {
      if (i < 1) {
        puVar5 = &DAT_00071100;
      }
      else {
        puVar5 = &DAT_000715b0;
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
        puVar6 = &DAT_00071100;
      }
      else {
        puVar6 = &DAT_000726d4;
      }
      pcVar2 = json_escape(ppVar1->rpc_url);
      fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",",puVar5,pcVar3,pcVar4,puVar6,pcVar2
             );
    }
    else {
      if (i < 1) {
        puVar5 = &DAT_00071100;
      }
      else {
        puVar5 = &DAT_000715b0;
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
        puVar6 = &DAT_00071100;
      }
      else {
        puVar6 = &DAT_000726d4;
      }
      iVar7 = ppVar1->quota;
      pcVar2 = json_escape(ppVar1->rpc_url);
      fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",",puVar5,pcVar3,pcVar4,puVar6,
              iVar7,pcVar2);
    }
    if (ppVar1->extranonce_subscribe != false) {
      fwrite("\n\t\t\"extranonce-subscribe\" : true,",1,0x21,(FILE *)fcfg);
    }
    pcVar3 = json_escape(ppVar1->rpc_user);
    fprintf((FILE *)fcfg,"\n\t\t\"user\" : \"%s\",",pcVar3);
    pcVar3 = json_escape(ppVar1->rpc_pass);
    fprintf((FILE *)fcfg,"\n\t\t\"pass\" : \"%s\"\n\t}",pcVar3);
  }
  fwrite(&DAT_000733d8,1,3,(FILE *)fcfg);
  for (opt = opt_config_table; opt->type != OPT_END; opt = opt + 1) {
    pcVar3 = strdup(opt->names);
    p = strtok(pcVar3,"|");
    while (p != (char *)0x0) {
      if ((p[1] == '-') && (opt->desc != opt_hidden)) {
                    /* WARNING: Load size is inaccurate */
        if (((opt->type & OPT_NOARG) == 0) ||
           (((opt->cb != (_func_char_ptr_void_ptr *)0x62e85 &&
             (opt->cb != (_func_char_ptr_void_ptr *)0x62ebd)) ||
            ((bool)*(opt->u).carg != (opt->cb == (_func_char_ptr_void_ptr *)0x62e85))))) {
          if (((opt->type & OPT_HASARG) == 0) ||
             (((((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x62fbd &&
                 (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16a45)) &&
                ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16a69 &&
                 ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16a8d &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16c19)))))) &&
               (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16ab1)) &&
              ((((((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16ad5 &&
                   (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16af9)) &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16b1d)) &&
                 ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16b41 &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16c3d)))) &&
                ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16b65 &&
                 ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16b89 &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16bad)))))) &&
               ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16bd1 &&
                (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x16bf5)))))))) {
            if (((opt->type & OPT_HASARG) == 0) ||
               ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x179e5 &&
                (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x17a49)))) {
                    /* WARNING: Load size is inaccurate */
              if (((opt->type & (OPT_PROCESSARG|OPT_HASARG)) != 0) &&
                 (((char **)(opt->u).carg != &opt_set_null && (*(opt->u).carg != (char *)0x0)))) {
                pcVar4 = json_escape(*(opt->u).carg);
                fprintf((FILE *)fcfg,",\n\"%s\" : \"%s\"",p + 2,pcVar4);
              }
            }
            else {
                    /* WARNING: Load size is inaccurate */
              fprintf((FILE *)fcfg,",\n\"%s\" : \"%.1f\"",p + 2,p + 2,(double)*(opt->u).carg);
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
  fwrite(&DAT_00073474,1,3,(FILE *)fcfg);
  json_escape_free();
  return;
}

