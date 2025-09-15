
/* WARNING: Unknown calling convention */

void write_config(FILE *fcfg)

{
  int *piVar1;
  JE *__ptr;
  pool *ppVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  JE *pJVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined2 *local_2c;
  
  fwrite(&DAT_0004bea8,1,0xd,(FILE *)fcfg);
  if (0 < total_pools) {
    iVar8 = 0;
    do {
      ppVar2 = priority_pool(iVar8);
      iVar7 = ppVar2->quota;
      if (iVar7 == 1) {
        puVar10 = &DAT_0004bf30;
        if (iVar8 == 0) {
          puVar10 = &DAT_00046bb8;
        }
        if (ppVar2->rpc_proxy == (char *)0x0) {
          pcVar4 = "";
LAB_0001f454:
          pcVar3 = "";
LAB_0001f458:
          puVar11 = (undefined2 *)&DAT_00046bb8;
        }
        else {
          pcVar4 = proxytype(ppVar2->rpc_proxytype);
          pcVar4 = json_escape(pcVar4);
          if (ppVar2->rpc_proxy == (char *)0x0) goto LAB_0001f454;
          pcVar3 = json_escape(ppVar2->rpc_proxy);
          puVar11 = &DAT_000472e4;
          if (ppVar2->rpc_proxy == (char *)0x0) goto LAB_0001f458;
        }
        pcVar5 = json_escape(ppVar2->rpc_url);
        fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",",puVar10,pcVar4,pcVar3,puVar11,
                pcVar5);
      }
      else {
        if (iVar8 == 0) {
          puVar10 = &DAT_00046bb8;
        }
        else {
          puVar10 = &DAT_0004bf30;
        }
        if (ppVar2->rpc_proxy == (char *)0x0) {
          pcVar4 = "";
LAB_0001f1f4:
          pcVar3 = "";
LAB_0001f1f8:
          local_2c = (undefined2 *)&DAT_00046bb8;
        }
        else {
          pcVar4 = proxytype(ppVar2->rpc_proxytype);
          pcVar4 = json_escape(pcVar4);
          if (ppVar2->rpc_proxy == (char *)0x0) {
            iVar7 = ppVar2->quota;
            goto LAB_0001f1f4;
          }
          pcVar3 = json_escape(ppVar2->rpc_proxy);
          iVar7 = ppVar2->quota;
          if (ppVar2->rpc_proxy == (char *)0x0) goto LAB_0001f1f8;
          local_2c = &DAT_000472e4;
        }
        pcVar5 = json_escape(ppVar2->rpc_url);
        fprintf((FILE *)fcfg,"%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",",puVar10,pcVar4,pcVar3,
                local_2c,iVar7,pcVar5);
      }
      if (ppVar2->extranonce_subscribe != false) {
        fwrite("\n\t\t\"extranonce-subscribe\" : true,",1,0x21,(FILE *)fcfg);
      }
      iVar8 = iVar8 + 1;
      pcVar4 = json_escape(ppVar2->rpc_user);
      fprintf((FILE *)fcfg,"\n\t\t\"user\" : \"%s\",",pcVar4);
      pcVar4 = json_escape(ppVar2->rpc_pass);
      fprintf((FILE *)fcfg,"\n\t\t\"pass\" : \"%s\"\n\t}",pcVar4);
    } while (iVar8 < total_pools);
  }
  fwrite(&DAT_0004beb8,1,3,(FILE *)fcfg);
  if (opt_config_table[0].type != OPT_END) {
    iVar8 = 0x5ffec;
    do {
      pcVar3 = (char *)__strdup(*(undefined4 *)(iVar8 + -0x1c));
      pcVar4 = strtok(pcVar3,"|");
      while (pcVar4 != (char *)0x0) {
        if ((pcVar4[1] == '-') && (*(char **)(iVar8 + -4) != opt_hidden)) {
          uVar6 = *(uint *)(iVar8 + -0x18);
          if (((int)(uVar6 << 0x1f) < 0) &&
             (((iVar7 = *(int *)(iVar8 + -0x14), iVar7 == 0x3aa85 || (iVar7 == 0x3aa95)) &&
              ((bool)**(char **)(iVar8 + -8) == (iVar7 == 0x3aa85))))) {
            fprintf((FILE *)fcfg,",\n\"%s\" : true",pcVar4 + 2);
          }
          else if ((int)(uVar6 << 0x1e) < 0) {
            iVar7 = *(int *)(iVar8 + -0x10);
            if (((((iVar7 == 0x3aba9) || (iVar7 == 0x1eab1)) ||
                 ((iVar7 == 0x1eac5 || ((iVar7 == 0x1eb2d || (iVar7 == 0x1eb25)))))) ||
                (iVar7 == 0x1eabd)) ||
               ((((((iVar7 == 0x1eb1d || (iVar7 == 0x1eb15)) || (iVar7 == 0x1eb09)) ||
                  ((iVar7 == 0x1eb01 || (iVar7 == 0x1eaf9)))) ||
                 ((iVar7 == 0x1eaf1 || ((iVar7 == 0x1eae9 || (iVar7 == 0x1eae1)))))) ||
                ((iVar7 == 0x1ead9 || (iVar7 == 0x1ead1)))))) {
              fprintf((FILE *)fcfg,",\n\"%s\" : \"%d\"",pcVar4 + 2,**(undefined4 **)(iVar8 + -8));
            }
            else {
              if ((iVar7 != 0x1e83d) && (iVar7 != 0x1e801)) goto LAB_0001f2e8;
              fprintf((FILE *)fcfg,",\n\"%s\" : \"%.1f\"",pcVar4 + 2,*(float **)(iVar8 + -8),
                      (double)**(float **)(iVar8 + -8));
            }
          }
          else {
LAB_0001f2e8:
            if (((uVar6 & 6) != 0) &&
               ((*(char ***)(iVar8 + -8) != &opt_set_null &&
                (pcVar5 = **(char ***)(iVar8 + -8), pcVar5 != (char *)0x0)))) {
              pcVar5 = json_escape(pcVar5);
              fprintf((FILE *)fcfg,",\n\"%s\" : \"%s\"",pcVar4 + 2,pcVar5);
            }
          }
        }
        pcVar4 = strtok((char *)0x0,"|");
      }
      free(pcVar3);
      piVar1 = (int *)(iVar8 + 4);
      iVar8 = iVar8 + 0x1c;
    } while (*piVar1 != 0x10);
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
  fwrite(&DAT_0004bfe0,1,3,(FILE *)fcfg);
  __ptr = jedata;
  jedata = (JE *)0x0;
  while (__ptr != (JE *)0x0) {
    pJVar9 = __ptr->next;
    free(__ptr->buf);
    free(__ptr);
    __ptr = pJVar9;
  }
  return;
}

