
int UI_process(UI *ui)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  if ((*(code **)(*(int *)ui + 4) == (code *)0x0) ||
     (iVar1 = (**(code **)(*(int *)ui + 4))(), iVar1 != 0)) {
    if (*(int *)(ui + 0x14) << 0x17 < 0) {
      ERR_print_errors_cb(DAT_000d4be0,ui);
    }
    iVar1 = 0;
    do {
      do {
        iVar4 = iVar1;
        iVar1 = sk_num(*(_STACK **)(ui + 4));
        if (iVar1 <= iVar4) {
          pcVar5 = *(code **)(*(int *)ui + 0xc);
          if (pcVar5 != (code *)0x0) {
            iVar1 = (*pcVar5)(ui);
            if (iVar1 == -1) goto LAB_000d4bd0;
            if (iVar1 == 0) goto LAB_000d4b74;
          }
          iVar1 = 0;
          goto LAB_000d4b9c;
        }
        pcVar5 = *(code **)(*(int *)ui + 8);
        iVar1 = iVar4 + 1;
      } while (pcVar5 == (code *)0x0);
      pvVar2 = sk_value(*(_STACK **)(ui + 4),iVar4);
      iVar3 = (*pcVar5)(ui,pvVar2);
    } while (iVar3 != 0);
LAB_000d4b74:
    iVar1 = -1;
    goto LAB_000d4b78;
  }
  goto LAB_000d4bd6;
LAB_000d4b9c:
  iVar4 = sk_num(*(_STACK **)(ui + 4));
  if (iVar4 <= iVar1) goto LAB_000d4bdc;
  pcVar5 = *(code **)(*(int *)ui + 0x10);
  if (pcVar5 != (code *)0x0) {
    pvVar2 = sk_value(*(_STACK **)(ui + 4),iVar1);
    iVar4 = (*pcVar5)(ui,pvVar2);
    if (iVar4 == -1) goto LAB_000d4bd0;
    if (iVar4 == 0) goto LAB_000d4b74;
  }
  iVar1 = iVar1 + 1;
  goto LAB_000d4b9c;
LAB_000d4bdc:
  iVar1 = 0;
  goto LAB_000d4b78;
LAB_000d4bd0:
  iVar1 = -2;
LAB_000d4b78:
  if ((*(code **)(*(int *)ui + 0x14) != (code *)0x0) &&
     (iVar4 = (**(code **)(*(int *)ui + 0x14))(ui), iVar4 == 0)) {
LAB_000d4bd6:
    iVar1 = -1;
  }
  return iVar1;
}

