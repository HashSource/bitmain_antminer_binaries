
void write_config(FILE *param_1)

{
  int *piVar1;
  void **__ptr;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  char *__s;
  char *pcVar7;
  undefined2 *puVar8;
  uint uVar9;
  undefined2 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  void **ppvVar13;
  int iVar14;
  undefined2 *local_2c;
  
  fwrite(&DAT_0005c6c4,1,0xd,param_1);
  if (0 < total_pools) {
    local_2c = (undefined2 *)&DAT_0005c74c;
    iVar14 = 0;
    do {
      iVar3 = priority_pool(iVar14);
      iVar11 = *(int *)(iVar3 + 0x38);
      if (iVar11 == 1) {
        puVar8 = local_2c;
        if (iVar14 < 1) {
          puVar8 = (undefined2 *)&DAT_000609ec;
        }
        puVar10 = (undefined2 *)&DAT_000609ec;
        if (*(int *)(iVar3 + 0xb8) == 0) {
          puVar5 = (undefined2 *)&DAT_000609ec;
          puVar4 = &DAT_000609ec;
        }
        else {
          proxytype(*(undefined4 *)(iVar3 + 0xb4));
          puVar4 = (undefined1 *)json_escape();
          puVar5 = (undefined2 *)&DAT_000609ec;
          if (*(int *)(iVar3 + 0xb8) != 0) {
            puVar5 = (undefined2 *)json_escape();
            puVar10 = &DAT_00057a28;
            if (*(int *)(iVar3 + 0xb8) == 0) {
              puVar10 = (undefined2 *)&DAT_000609ec;
            }
          }
        }
        uVar6 = json_escape(*(undefined4 *)(iVar3 + 0xa4));
        fprintf(param_1,"%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",",puVar8,puVar4,puVar5,puVar10,uVar6);
      }
      else {
        puVar8 = local_2c;
        if (iVar14 < 1) {
          puVar8 = (undefined2 *)&DAT_000609ec;
        }
        puVar10 = (undefined2 *)&DAT_000609ec;
        if (*(int *)(iVar3 + 0xb8) == 0) {
          puVar5 = (undefined2 *)&DAT_000609ec;
          puVar4 = &DAT_000609ec;
        }
        else {
          proxytype(*(undefined4 *)(iVar3 + 0xb4));
          puVar4 = (undefined1 *)json_escape();
          if (*(int *)(iVar3 + 0xb8) == 0) {
            iVar11 = *(int *)(iVar3 + 0x38);
            puVar5 = (undefined2 *)&DAT_000609ec;
          }
          else {
            puVar5 = (undefined2 *)json_escape();
            iVar11 = *(int *)(iVar3 + 0x38);
            puVar10 = &DAT_00057a28;
            if (*(int *)(iVar3 + 0xb8) == 0) {
              puVar10 = (undefined2 *)&DAT_000609ec;
            }
          }
        }
        uVar6 = json_escape(*(undefined4 *)(iVar3 + 0xa4));
        fprintf(param_1,"%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",",puVar8,puVar4,puVar5,puVar10,
                iVar11,uVar6);
      }
      if (*(char *)(iVar3 + 0x244) != '\0') {
        fwrite("\n\t\t\"extranonce-subscribe\" : true,",1,0x21,param_1);
      }
      iVar14 = iVar14 + 1;
      uVar6 = json_escape(*(undefined4 *)(iVar3 + 0xac));
      fprintf(param_1,"\n\t\t\"user\" : \"%s\",",uVar6);
      uVar6 = json_escape(*(undefined4 *)(iVar3 + 0xb0));
      fprintf(param_1,"\n\t\t\"pass\" : \"%s\"\n\t}",uVar6);
    } while (iVar14 < total_pools);
  }
  fwrite(&DAT_0005c6d4,1,3,param_1);
  piVar2 = DAT_0001d484;
  if (DAT_0007d6ac != 0x10) {
    puVar12 = &DAT_0007d6c4;
    do {
      __s = (char *)__strdup(puVar12[-7]);
      pcVar7 = strtok(__s,(char *)&DAT_00057a28);
      while (pcVar7 != (char *)0x0) {
LAB_0001d1b2:
        if ((pcVar7[1] != '-') || ((undefined4 *)puVar12[-1] == &opt_hidden)) goto LAB_0001d1a2;
        uVar9 = puVar12[-6];
        if ((int)(uVar9 << 0x1f) < 0) {
          iVar14 = puVar12[-5];
          if ((iVar14 == 0x4dde9 || iVar14 == 0x4ddf9) &&
             ((bool)*(char *)puVar12[-2] == (iVar14 == 0x4dde9))) {
            fprintf(param_1,",\n\"%s\" : true",pcVar7 + 2);
            goto LAB_0001d1a2;
          }
        }
        if (-1 < (int)(uVar9 << 0x1e)) {
LAB_0001d316:
          if ((((uVar9 & 6) == 0) || ((int *)puVar12[-2] == piVar2)) || (*(int *)puVar12[-2] == 0))
          goto LAB_0001d1a2;
          uVar6 = json_escape();
          fprintf(param_1,",\n\"%s\" : \"%s\"",pcVar7 + 2,uVar6);
          pcVar7 = strtok((char *)0x0,(char *)&DAT_00057a28);
          if (pcVar7 == (char *)0x0) break;
          goto LAB_0001d1b2;
        }
        iVar14 = puVar12[-4];
        if (iVar14 != 0x1c519 &&
            (iVar14 != 0x1c539 &&
            (iVar14 != 0x1c559 &&
            (iVar14 != 0x1c579 &&
            (iVar14 != 0x1c599 &&
            (iVar14 != 0x1c5b9 &&
            (iVar14 != 0x1c5d9 &&
            (iVar14 != 0x1c5f9 &&
            (iVar14 != 0x1c619 &&
            (iVar14 != 0x1c639 &&
            (iVar14 != 0x1c659 &&
            (iVar14 != 0x1c679 &&
            (iVar14 != 0x1c699 && (iVar14 != 0x1c6b9 && (iVar14 != 0x4df21 && iVar14 != 0x1c6dd)))))
            )))))))))) {
          if (iVar14 == 0x1bfa9 || iVar14 == 0x1bff5) {
            fprintf(param_1,",\n\"%s\" : \"%.1f\"",pcVar7 + 2,(float *)puVar12[-2],
                    (double)*(float *)puVar12[-2]);
            goto LAB_0001d1a2;
          }
          goto LAB_0001d316;
        }
        fprintf(param_1,",\n\"%s\" : \"%d\"",pcVar7 + 2,*(undefined4 *)puVar12[-2]);
LAB_0001d1a2:
        pcVar7 = strtok((char *)0x0,(char *)&DAT_00057a28);
      }
      free(__s);
      piVar1 = puVar12 + 1;
      puVar12 = puVar12 + 7;
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
  __ptr = jedata;
  jedata = (void **)0x0;
  while (__ptr != (void **)0x0) {
    ppvVar13 = (void **)__ptr[1];
    free(*__ptr);
    free(__ptr);
    __ptr = ppvVar13;
  }
  return;
}

