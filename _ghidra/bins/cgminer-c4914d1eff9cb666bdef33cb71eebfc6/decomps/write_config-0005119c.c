
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
      if ((p[1] == '-') && (opt->desc != (char *)&opt_hidden)) {
                    /* WARNING: Load size is inaccurate */
        if (((opt->type & OPT_NOARG) == 0) ||
           (((opt->cb != (_func_char_ptr_void_ptr *)0x79453 &&
             (opt->cb != (_func_char_ptr_void_ptr *)0x7948b)) ||
            ((bool)*(opt->u).carg != (opt->cb == (_func_char_ptr_void_ptr *)0x79453))))) {
          if (((opt->type & OPT_HASARG) == 0) ||
             (((((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x794c5 &&
                 (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48de9)) &&
                ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48e0b &&
                 ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48e2d &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48f8f)))))) &&
               (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48e4d)) &&
              ((((((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48e6d &&
                   (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48e8d)) &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48ead)) &&
                 ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48ecf &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48faf)))) &&
                ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48eef &&
                 ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48f0f &&
                  (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48f2f)))))) &&
               ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48f4f &&
                (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x48f6f)))))))) {
            if (((opt->type & OPT_HASARG) == 0) ||
               ((opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x49c99 &&
                (opt->cb_arg != (_func_char_ptr_char_ptr_void_ptr *)0x49cfd)))) {
                    /* WARNING: Load size is inaccurate */
              if (((opt->type & (OPT_PROCESSARG|OPT_HASARG)) != 0) &&
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

