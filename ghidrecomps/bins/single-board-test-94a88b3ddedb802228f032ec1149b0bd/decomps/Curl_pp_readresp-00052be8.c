
char * Curl_pp_readresp(undefined4 param_1,void **param_2,undefined4 *param_3,void **param_4)

{
  bool bVar1;
  code **ppcVar2;
  int iVar3;
  char *__dest;
  int iVar4;
  bool bVar5;
  char *pcVar6;
  size_t __n;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  char *__dest_00;
  int *piVar10;
  char *pcVar11;
  char *local_2c [2];
  
  piVar10 = (int *)param_2[0xb];
  pcVar11 = (char *)0x0;
  iVar3 = *piVar10;
  pvVar8 = param_2[3];
  *param_3 = 0;
  __dest = (char *)(iVar3 + 0x59c);
  bVar1 = true;
  *param_4 = (void *)0x0;
  ppcVar2 = DAT_00052df0;
  pcVar6 = (char *)param_2[2];
  __dest_00 = pcVar6 + iVar3 + 0x59c;
  pcVar9 = __dest_00 + -(int)pvVar8;
joined_r0x00052c30:
  if ((char *)0x3fff < pcVar6) {
LAB_00052d52:
    *(undefined *)(param_2 + 4) = 0;
    return pcVar11;
  }
  do {
    bVar5 = bVar1;
    if (pcVar11 != (char *)0x0) {
      bVar5 = false;
    }
    if (!bVar5) goto LAB_00052d52;
    if (*param_2 == (void *)0x0) {
      pcVar11 = (char *)Curl_read(piVar10,param_1,__dest_00,0x4000 - (int)pcVar6,local_2c);
      if (pcVar11 == (char *)0x51) {
        return (char *)0x0;
      }
      if (pcVar11 != (char *)0x0) {
        pcVar6 = (char *)param_2[2];
        bVar1 = false;
        goto joined_r0x00052c30;
      }
    }
    else {
      memcpy(__dest_00,*param_2,(size_t)param_2[1]);
      local_2c[0] = (char *)param_2[1];
      (**ppcVar2)(*param_2);
      *param_2 = (void *)0x0;
      param_2[1] = (void *)0x0;
    }
    if ((int)local_2c[0] < 1) {
      Curl_failf(iVar3,DAT_00052de8);
      pcVar11 = (char *)0x38;
      pcVar6 = (char *)param_2[2];
      bVar1 = false;
      goto joined_r0x00052c30;
    }
    iVar7 = 0;
    pvVar8 = param_2[2];
    *(char **)(iVar3 + 0x80) = local_2c[0] + *(int *)(iVar3 + 0x80);
    param_2[2] = (char *)((int)pvVar8 + (int)local_2c[0]);
    pcVar11 = local_2c[0];
    pcVar6 = __dest_00;
    do {
      while( true ) {
        __dest_00 = pcVar6 + 1;
        pcVar9 = pcVar9 + 1;
        if (*pcVar6 != '\n') break;
        if (*(char *)(iVar3 + 0x310) != '\0') {
          Curl_debug(iVar3,1,param_2[3],pcVar9,piVar10);
        }
        pcVar11 = (char *)Curl_client_write(piVar10,2,param_2[3],pcVar9);
        if (pcVar11 != (char *)0x0) {
          return pcVar11;
        }
        iVar4 = (*(code *)param_2[0xd])(piVar10,param_2[3],pcVar9,param_3);
        bVar5 = false;
        if (iVar4 != 0) {
          pcVar11 = (char *)(iVar7 + 1);
          __n = (int)pcVar6 - (int)param_2[3];
          memmove(__dest,param_2[3],__n);
          *(undefined *)(iVar3 + __n + 0x59c) = 0;
          param_2[3] = pcVar6 + 1;
          *param_4 = param_2[2];
          if (pcVar11 == local_2c[0]) {
            bVar1 = bVar5;
          }
          param_2[2] = (void *)0x0;
          if ((pcVar11 == local_2c[0]) ||
             (pcVar9 = local_2c[0] + -(int)pcVar11, bVar1 = bVar5, pcVar9 == (char *)0x0))
          goto LAB_00052d06;
          goto LAB_00052cea;
        }
        iVar7 = iVar7 + 1;
        param_2[3] = __dest_00;
        pcVar9 = (char *)0x0;
        pcVar11 = local_2c[0];
        pcVar6 = __dest_00;
        if ((int)local_2c[0] <= iVar7) goto LAB_00052cda;
      }
      iVar7 = iVar7 + 1;
      pcVar6 = __dest_00;
    } while (iVar7 < (int)pcVar11);
LAB_00052cda:
    bVar5 = bVar1;
    if ((pcVar9 == pcVar11) && (0x2000 < (int)pcVar9)) {
      Curl_infof(iVar3,DAT_00052dec,pcVar9);
      pcVar9 = (char *)0x28;
LAB_00052cea:
      param_2[1] = pcVar9;
      pvVar8 = (void *)(*Curl_cmalloc)();
      *param_2 = pvVar8;
      if (pvVar8 == (void *)0x0) {
        return (char *)0x1b;
      }
      memcpy(pvVar8,param_2[3],(size_t)param_2[1]);
      bVar1 = bVar5;
    }
    else {
      pcVar6 = (char *)param_2[2];
      if (pcVar6 < (char *)0x2001) break;
      if (pcVar9 != (char *)0x0) goto LAB_00052cea;
    }
LAB_00052d06:
    pcVar6 = (char *)0x0;
    param_2[2] = (void *)0x0;
    param_2[3] = __dest;
    pcVar9 = pcVar6;
    __dest_00 = __dest;
    pcVar11 = pcVar6;
  } while( true );
  pcVar11 = (char *)0x0;
  goto joined_r0x00052c30;
}

