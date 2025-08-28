
uint Curl_pp_readresp(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4
                     )

{
  bool bVar1;
  int iVar2;
  char *__dest;
  void *__dest_00;
  bool bVar3;
  uint uVar4;
  char *pcVar5;
  size_t __n;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *__dest_01;
  int *piVar9;
  uint uVar10;
  uint local_2c [2];
  
  piVar9 = (int *)param_2[0xb];
  uVar10 = 0;
  iVar2 = *piVar9;
  iVar7 = param_2[3];
  *param_3 = 0;
  __dest = (char *)(iVar2 + 0x59c);
  bVar1 = true;
  *param_4 = 0;
  uVar4 = param_2[2];
  __dest_01 = (char *)(iVar2 + uVar4 + 0x59c);
  uVar8 = (int)__dest_01 - iVar7;
joined_r0x00052c30:
  if (0x3fff < uVar4) {
LAB_00052d52:
    *(undefined1 *)(param_2 + 4) = 0;
    return uVar10;
  }
  do {
    bVar3 = bVar1;
    if (uVar10 != 0) {
      bVar3 = false;
    }
    if (!bVar3) goto LAB_00052d52;
    if ((void *)*param_2 == (void *)0x0) {
      uVar10 = Curl_read(piVar9,param_1,__dest_01,0x4000 - uVar4,local_2c);
      if (uVar10 == 0x51) {
        return 0;
      }
      if (uVar10 != 0) {
        uVar4 = param_2[2];
        bVar1 = false;
        goto joined_r0x00052c30;
      }
    }
    else {
      memcpy(__dest_01,(void *)*param_2,param_2[1]);
      local_2c[0] = param_2[1];
      (*Curl_cfree)(*param_2);
      *param_2 = 0;
      param_2[1] = 0;
    }
    if ((int)local_2c[0] < 1) {
      Curl_failf(iVar2,"response reading failed");
      uVar10 = 0x38;
      uVar4 = param_2[2];
      bVar1 = false;
      goto joined_r0x00052c30;
    }
    iVar6 = 0;
    iVar7 = param_2[2];
    *(uint *)(iVar2 + 0x80) = *(int *)(iVar2 + 0x80) + local_2c[0];
    param_2[2] = iVar7 + local_2c[0];
    uVar10 = local_2c[0];
    pcVar5 = __dest_01;
    do {
      while( true ) {
        __dest_01 = pcVar5 + 1;
        uVar8 = uVar8 + 1;
        if (*pcVar5 != '\n') break;
        if (*(char *)(iVar2 + 0x310) != '\0') {
          Curl_debug(iVar2,1,param_2[3],uVar8,piVar9);
        }
        uVar10 = Curl_client_write(piVar9,2,param_2[3],uVar8);
        if (uVar10 != 0) {
          return uVar10;
        }
        iVar7 = (*(code *)param_2[0xd])(piVar9,param_2[3],uVar8,param_3);
        bVar3 = false;
        if (iVar7 != 0) {
          uVar8 = iVar6 + 1;
          __n = (int)pcVar5 - (int)param_2[3];
          memmove(__dest,(void *)param_2[3],__n);
          *(undefined1 *)(iVar2 + __n + 0x59c) = 0;
          param_2[3] = pcVar5 + 1;
          *param_4 = param_2[2];
          if (uVar8 == local_2c[0]) {
            bVar1 = bVar3;
          }
          param_2[2] = 0;
          if ((uVar8 == local_2c[0]) || (uVar8 = local_2c[0] - uVar8, bVar1 = bVar3, uVar8 == 0))
          goto LAB_00052d06;
          goto LAB_00052cea;
        }
        iVar6 = iVar6 + 1;
        param_2[3] = __dest_01;
        uVar8 = 0;
        uVar10 = local_2c[0];
        pcVar5 = __dest_01;
        if ((int)local_2c[0] <= iVar6) goto LAB_00052cda;
      }
      iVar6 = iVar6 + 1;
      pcVar5 = __dest_01;
    } while (iVar6 < (int)uVar10);
LAB_00052cda:
    bVar3 = bVar1;
    if ((uVar8 == uVar10) && (0x2000 < (int)uVar8)) {
      Curl_infof(iVar2,"Excessive server response line length received, %zd bytes. Stripping\n",
                 uVar8);
      uVar8 = 0x28;
LAB_00052cea:
      param_2[1] = uVar8;
      __dest_00 = (void *)(*Curl_cmalloc)();
      *param_2 = __dest_00;
      if (__dest_00 == (void *)0x0) {
        return 0x1b;
      }
      memcpy(__dest_00,(void *)param_2[3],param_2[1]);
      bVar1 = bVar3;
    }
    else {
      uVar4 = param_2[2];
      if (uVar4 < 0x2001) break;
      if (uVar8 != 0) goto LAB_00052cea;
    }
LAB_00052d06:
    uVar4 = 0;
    param_2[2] = 0;
    param_2[3] = __dest;
    uVar8 = uVar4;
    __dest_01 = __dest;
    uVar10 = uVar4;
  } while( true );
  uVar10 = 0;
  goto joined_r0x00052c30;
}

