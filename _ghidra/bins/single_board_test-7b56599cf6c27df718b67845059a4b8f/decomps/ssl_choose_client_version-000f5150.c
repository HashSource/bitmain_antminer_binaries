
undefined4 ssl_choose_client_version(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  bool bVar10;
  int local_2c;
  int local_28;
  int local_24 [2];
  
  iVar9 = *param_1;
  *param_1 = param_2;
  iVar2 = tls_parse_extension(param_1,0x11,0x300,param_3,0,0);
  if (iVar2 == 0) {
    *param_1 = iVar9;
    return 0;
  }
  if ((param_1[0x113] != 0) && (*param_1 != 0x304)) {
    *param_1 = iVar9;
    ossl_statem_fatal(param_1,0x46,0x25f,0x10a,"ssl/statem/statem_lib.c",0x77e);
    return 0;
  }
  iVar2 = *(int *)param_1[1];
  if (iVar2 == 0x10000) {
    puVar8 = (undefined1 *)&tls_version_table;
  }
  else {
    if (iVar2 != 0x1ffff) {
      if (iVar2 == *param_1) {
        return 1;
      }
      *param_1 = iVar9;
      uVar7 = 0x788;
      iVar2 = 0x10a;
      goto LAB_000f52c0;
    }
    puVar8 = dtls_version_table;
  }
  iVar2 = ssl_get_min_max_version(param_1,&local_2c,&local_28,local_24);
  if (iVar2 != 0) {
    *param_1 = iVar9;
    uVar7 = 0x79f;
    goto LAB_000f52c0;
  }
  iVar2 = *param_1;
  uVar6 = *(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8;
  if (uVar6 == 0) {
    if (local_2c <= iVar2) {
      bVar10 = local_28 < iVar2;
      goto LAB_000f5206;
    }
LAB_000f534e:
    uVar7 = 0x7a6;
  }
  else {
    if (iVar2 == 0x100) {
      if (local_2c != 0x100) {
        iVar4 = 0xff00;
        goto LAB_000f51de;
      }
      iVar4 = 0xff00;
    }
    else {
      iVar4 = iVar2;
      if (local_2c == 0x100) {
        local_2c = 0xff00;
      }
LAB_000f51de:
      if (local_2c < iVar4) goto LAB_000f534e;
      iVar4 = iVar2;
      if (iVar2 == 0x100) {
        iVar4 = 0xff00;
      }
    }
    iVar3 = local_28;
    if (local_28 == 0x100) {
      iVar3 = 0xff00;
    }
    if (iVar4 < iVar3) {
      bVar10 = true;
    }
    else {
      bVar10 = false;
    }
LAB_000f5206:
    if (bVar10) {
      uVar7 = 0x7ac;
    }
    else {
      if (-1 < param_1[0x13c] << 0x18) {
        local_24[0] = local_28;
      }
      if (iVar2 == 0x303) {
        if ((0x303 < local_24[0]) &&
           (iVar4 = memcmp(&tls12downgrade,(void *)(param_1[0x1f] + 0xa4),8), iVar4 == 0)) {
          uVar7 = 0x7bc;
          goto LAB_000f5250;
        }
      }
      else {
        bVar10 = iVar2 == 0x302;
        if (iVar2 < 0x303) {
          bVar10 = uVar6 == 0;
        }
        if (((bVar10) && (iVar2 < local_24[0])) &&
           (iVar4 = memcmp(&tls11downgrade,(void *)(param_1[0x1f] + 0xa4),8), iVar4 == 0)) {
          uVar7 = 0x7c9;
LAB_000f5250:
          *param_1 = iVar9;
          ossl_statem_fatal(param_1,0x2f,0x25f,0x175,"ssl/statem/statem_lib.c",uVar7);
          return 0;
        }
      }
      if (*(int *)puVar8 != 0) {
        pcVar5 = *(code **)((int)puVar8 + 4);
        if (iVar2 != *(int *)puVar8 || pcVar5 == (code *)0x0) {
          do {
            piVar1 = (int *)((int)puVar8 + 0xc);
            if (*piVar1 == 0) goto LAB_000f533a;
            pcVar5 = *(code **)((int)puVar8 + 0x10);
            puVar8 = (undefined1 *)((int)puVar8 + 0xc);
          } while (iVar2 != *piVar1 || pcVar5 == (code *)0x0);
        }
        iVar2 = (*pcVar5)();
        param_1[1] = iVar2;
        return 1;
      }
LAB_000f533a:
      uVar7 = 0x7d8;
    }
  }
  *param_1 = iVar9;
  iVar2 = 0x102;
LAB_000f52c0:
  ossl_statem_fatal(param_1,0x46,0x25f,iVar2,"ssl/statem/statem_lib.c",uVar7);
  return 0;
}

