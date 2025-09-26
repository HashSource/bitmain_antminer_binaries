
undefined4 tls_construct_ctos_session_ticket(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  ushort *puVar3;
  int *piVar4;
  uint __n;
  undefined4 uVar5;
  
  iVar1 = tls_use_ticket();
  if (iVar1 == 0) {
    return 2;
  }
  piVar4 = *(int **)(param_1 + 0x474);
  if (*(int *)(param_1 + 0x20) == 0) {
    if (piVar4 != (int *)0x0) {
      if ((piVar4[0x74] == 0) || (*piVar4 == 0x304)) goto LAB_000f1adc;
      __n = piVar4[0x75];
LAB_000f1b20:
      if (__n != 0) goto LAB_000f1b30;
    }
LAB_000f1b22:
    if ((*(int *)(param_1 + 0x580) != 0) && (*(int *)(*(int *)(param_1 + 0x580) + 4) == 0)) {
      return 2;
    }
  }
  else {
    if (piVar4 == (int *)0x0) goto LAB_000f1b22;
LAB_000f1adc:
    puVar3 = *(ushort **)(param_1 + 0x580);
    if (puVar3 != (ushort *)0x0) {
      if (*(int *)(puVar3 + 2) == 0) {
        return 2;
      }
      __n = (uint)*puVar3;
      pvVar2 = CRYPTO_malloc(__n,"ssl/statem/extensions_clnt.c",0xfa);
      iVar1 = *(int *)(param_1 + 0x474);
      piVar4[0x74] = (int)pvVar2;
      pvVar2 = *(void **)(iVar1 + 0x1d0);
      if (pvVar2 == (void *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x1dc,0x44,"ssl/statem/extensions_clnt.c",0xfe);
        return 0;
      }
      memcpy(pvVar2,*(void **)(*(int *)(param_1 + 0x580) + 4),__n);
      *(uint *)(*(int *)(param_1 + 0x474) + 0x1d4) = __n;
      goto LAB_000f1b20;
    }
  }
  __n = 0;
LAB_000f1b30:
  uVar5 = 2;
  iVar1 = WPACKET_put_bytes__(param_2);
  if ((iVar1 != 0) &&
     (iVar1 = WPACKET_sub_memcpy__
                        (param_2,*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x1d0),__n,2,uVar5),
     iVar1 != 0)) {
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x1dc,0x44,"ssl/statem/extensions_clnt.c",0x10f);
  return 0;
}

