
void write_config(FILE *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  char *__s;
  char *pcVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined2 *local_2c;
  
  fwrite(&DAT_0005c6c4,1,0xd,param_1);
  if (0 < total_pools) {
    local_2c = (undefined2 *)&DAT_0005c74c;
    iVar13 = 0;
    do {
      iVar2 = priority_pool(iVar13);
      iVar10 = *(int *)(iVar2 + 0x38);
      if (iVar10 == 1) {
        puVar7 = local_2c;
        if (iVar13 < 1) {
          puVar7 = (undefined2 *)&DAT_000609ec;
        }
        puVar9 = (undefined2 *)&DAT_000609ec;
        if (*(int *)(iVar2 + 0xb8) == 0) {
          puVar4 = (undefined2 *)&DAT_000609ec;
          puVar3 = &DAT_000609ec;
        }
        else {
          proxytype(*(undefined4 *)(iVar2 + 0xb4));
          puVar3 = (undefined1 *)json_escape();
          puVar4 = (undefined2 *)&DAT_000609ec;
          if (*(int *)(iVar2 + 0xb8) != 0) {
            puVar4 = (undefined2 *)json_escape();
            puVar9 = &DAT_00057a28;
            if (*(int *)(iVar2 + 0xb8) == 0) {
              puVar9 = (undefined2 *)&DAT_000609ec;
            }
          }
        }
        uVar5 = json_escape(*(undefined4 *)(iVar2 + 0xa4));
        fprintf(param_1,"%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",",puVar7,puVar3,puVar4,puVar9,uVar5);
      }
      else {
        puVar7 = local_2c;
        if (iVar13 < 1) {
          puVar7 = (undefined2 *)&DAT_000609ec;
        }
        puVar9 = (undefined2 *)&DAT_000609ec;
        if (*(int *)(iVar2 + 0xb8) == 0) {
          puVar4 = (undefined2 *)&DAT_000609ec;
          puVar3 = &DAT_000609ec;
        }
        else {
          proxytype(*(undefined4 *)(iVar2 + 0xb4));
          puVar3 = (undefined1 *)json_escape();
          if (*(int *)(iVar2 + 0xb8) == 0) {
            iVar10 = *(int *)(iVar2 + 0x38);
            puVar4 = (undefined2 *)&DAT_000609ec;
          }
          else {
            puVar4 = (undefined2 *)json_escape();
            iVar10 = *(int *)(iVar2 + 0x38);
            puVar9 = &DAT_00057a28;
            if (*(int *)(iVar2 + 0xb8) == 0) {
              puVar9 = (undefined2 *)&DAT_000609ec;
            }
          }
        }
        uVar5 = json_escape(*(undefined4 *)(iVar2 + 0xa4));
        fprintf(param_1,"%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",",puVar7,puVar3,puVar4,puVar9,
                iVar10,uVar5);
      }
      if (*(char *)(iVar2 + 0x244) != '\0') {
        fwrite("\n\t\t\"extranonce-subscribe\" : true,",1,0x21,param_1);
      }
      iVar13 = iVar13 + 1;
      uVar5 = json_escape(*(undefined4 *)(iVar2 + 0xac));
      fprintf(param_1,"\n\t\t\"user\" : \"%s\",",uVar5);
      uVar5 = json_escape(*(undefined4 *)(iVar2 + 0xb0));
      fprintf(param_1,"\n\t\t\"pass\" : \"%s\"\n\t}",uVar5);
    } while (iVar13 < total_pools);
  }
  fwrite(&DAT_0005c6d4,1,3,param_1);
  if (DAT_0007d6ac != 0x10) {
    puVar11 = &DAT_0007d6c4;
    do {
      __s = (char *)__strdup(puVar11[-7]);
      pcVar6 = strtok(__s,"|");
      while (pcVar6 != (char *)0x0) {
LAB_0001d1b2:
        if ((pcVar6[1] != '-') || ((undefined4 *)puVar11[-1] == &opt_hidden)) goto LAB_0001d1a2;
        uVar8 = puVar11[-6];
        if ((int)(uVar8 << 0x1f) < 0) {
          iVar13 = puVar11[-5];
          if ((iVar13 == 0x4dde9 || iVar13 == 0x4ddf9) &&
             ((bool)*(char *)puVar11[-2] == (iVar13 == 0x4dde9))) {
            fprintf(param_1,",\n\"%s\" : true",pcVar6 + 2);
            goto LAB_0001d1a2;
          }
        }
        if (-1 < (int)(uVar8 << 0x1e)) {
LAB_0001d316:
          if ((((uVar8 & 6) == 0) || ((int *)puVar11[-2] == &opt_set_null)) ||
             (*(int *)puVar11[-2] == 0)) goto LAB_0001d1a2;
          uVar5 = json_escape();
          fprintf(param_1,",\n\"%s\" : \"%s\"",pcVar6 + 2,uVar5);
          pcVar6 = strtok((char *)0x0,"|");
          if (pcVar6 == (char *)0x0) break;
          goto LAB_0001d1b2;
        }
        iVar13 = puVar11[-4];
        if (iVar13 != 0x1c519 &&
            (iVar13 != 0x1c539 &&
            (iVar13 != 0x1c559 &&
            (iVar13 != 0x1c579 &&
            (iVar13 != 0x1c599 &&
            (iVar13 != 0x1c5b9 &&
            (iVar13 != 0x1c5d9 &&
            (iVar13 != 0x1c5f9 &&
            (iVar13 != 0x1c619 &&
            (iVar13 != 0x1c639 &&
            (iVar13 != 0x1c659 &&
            (iVar13 != 0x1c679 &&
            (iVar13 != 0x1c699 && (iVar13 != 0x1c6b9 && (iVar13 != 0x4df21 && iVar13 != 0x1c6dd)))))
            )))))))))) {
          if (iVar13 == 0x1bfa9 || iVar13 == 0x1bff5) {
            fprintf(param_1,",\n\"%s\" : \"%.1f\"",pcVar6 + 2,(float *)puVar11[-2],
                    (double)*(float *)puVar11[-2]);
            goto LAB_0001d1a2;
          }
          goto LAB_0001d316;
        }
        fprintf(param_1,",\n\"%s\" : \"%d\"",pcVar6 + 2,*(undefined4 *)puVar11[-2]);
LAB_0001d1a2:
        pcVar6 = strtok((char *)0x0,"|");
      }
      free(__s);
      piVar1 = puVar11 + 1;
      puVar11 = puVar11 + 7;
    } while (*piVar1 != 0x10);
  }
  if (pool_strategy == 4) {
    fwrite(",\n\"balance\" : true",1,0x12,param_1);
  }
  if (pool_strategy == 3) {
    fwrite(",\n\"load-balance\" : true",1,0x17,param_1);
  }
  if (pool_strategy == 1) {
    fwrite(",\n\"round-robin\" : true",1,0x16,param_1);
  }
  if (pool_strategy == 2) {
    fprintf(param_1,",\n\"rotate\" : \"%d\"",opt_rotate_period);
  }
  fwrite(&DAT_0005c7fc,1,3,param_1);
  puVar11 = jedata;
  jedata = (undefined4 *)0x0;
  while (puVar11 != (undefined4 *)0x0) {
    puVar12 = (undefined4 *)puVar11[1];
    free((void *)*puVar11);
    free(puVar11);
    puVar11 = puVar12;
  }
  return;
}

