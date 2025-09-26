
bool ssl_check_version_downgrade(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar3 = **(int **)param_1[0x134];
  if (*param_1 == iVar3) {
    return true;
  }
  piVar1 = (int *)TLS_method();
  if (iVar3 == *piVar1) {
    puVar4 = (undefined1 *)&tls_version_table;
  }
  else {
    iVar3 = **(int **)param_1[0x134];
    piVar1 = (int *)DTLS_method();
    if (iVar3 != *piVar1) {
      return false;
    }
    puVar4 = dtls_version_table;
  }
  do {
    if (*(code **)((int)puVar4 + 8) == (code *)0x0) goto LAB_000fe466;
    piVar1 = (int *)(**(code **)((int)puVar4 + 8))();
    iVar3 = param_1[0x13d];
    iVar5 = *piVar1;
    if ((iVar3 == 0) || (iVar5 == iVar3)) {
LAB_000fe456:
      iVar3 = ssl_security(param_1,9,0,iVar5,0);
      if (iVar3 != 0) {
        iVar3 = param_1[0x13e];
        if ((iVar3 == 0) || (iVar5 == iVar3)) {
LAB_000fe4da:
          if (((param_1[0x13b] & piVar1[2]) == 0) &&
             ((-1 < piVar1[1] << 0x1e || ((*(uint *)(param_1[0x101] + 0x10) & 0x30000) == 0)))) {
            return *param_1 == *(int *)puVar4;
          }
        }
        else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
          if (iVar5 < iVar3) goto LAB_000fe4da;
        }
        else {
          if (iVar5 == 0x100) {
            if (iVar3 == 0x100) goto LAB_000fe466;
            iVar5 = 0xff00;
          }
          else if (iVar3 == 0x100) {
            iVar3 = 0xff00;
          }
          if (iVar3 < iVar5) goto LAB_000fe4da;
        }
      }
    }
    else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
      if (iVar3 <= iVar5) goto LAB_000fe456;
    }
    else {
      if (iVar5 == 0x100) {
        if (iVar3 == 0x100) goto LAB_000fe456;
        iVar2 = 0xff00;
      }
      else {
        iVar2 = iVar5;
        if (iVar3 == 0x100) {
          iVar3 = 0xff00;
        }
      }
      if (iVar2 <= iVar3) goto LAB_000fe456;
    }
LAB_000fe466:
    HintPreloadData((int *)((int)puVar4 + 0x30));
    puVar4 = (undefined1 *)((int)puVar4 + 0xc);
    if (*(int *)puVar4 == 0) {
      return false;
    }
  } while( true );
}

