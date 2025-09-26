
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
      ERR_print_errors_cb((cb *)0x1aaab5,ui);
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
            if (iVar1 == -1) goto LAB_001ab434;
            if (iVar1 == 0) goto LAB_001ab3d8;
          }
          iVar1 = 0;
          goto LAB_001ab400;
        }
        pcVar5 = *(code **)(*(int *)ui + 8);
        iVar1 = iVar4 + 1;
      } while (pcVar5 == (code *)0x0);
      pvVar2 = sk_value(*(_STACK **)(ui + 4),iVar4);
      iVar3 = (*pcVar5)(ui,pvVar2);
    } while (iVar3 != 0);
LAB_001ab3d8:
    iVar1 = -1;
    goto LAB_001ab3dc;
  }
  goto LAB_001ab43a;
LAB_001ab400:
  iVar4 = sk_num(*(_STACK **)(ui + 4));
  if (iVar4 <= iVar1) goto LAB_001ab440;
  pcVar5 = *(code **)(*(int *)ui + 0x10);
  if (pcVar5 != (code *)0x0) {
    pvVar2 = sk_value(*(_STACK **)(ui + 4),iVar1);
    iVar4 = (*pcVar5)(ui,pvVar2);
    if (iVar4 == -1) goto LAB_001ab434;
    if (iVar4 == 0) goto LAB_001ab3d8;
  }
  iVar1 = iVar1 + 1;
  goto LAB_001ab400;
LAB_001ab440:
  iVar1 = 0;
  goto LAB_001ab3dc;
LAB_001ab434:
  iVar1 = -2;
LAB_001ab3dc:
  if ((*(code **)(*(int *)ui + 0x14) != (code *)0x0) &&
     (iVar4 = (**(code **)(*(int *)ui + 0x14))(ui), iVar4 == 0)) {
LAB_001ab43a:
    iVar1 = -1;
  }
  return iVar1;
}

