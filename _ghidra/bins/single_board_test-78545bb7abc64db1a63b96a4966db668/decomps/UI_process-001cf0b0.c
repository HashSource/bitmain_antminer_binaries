
int UI_process(UI *ui)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  code *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  
  if ((*(code **)(*(int *)ui + 4) == (code *)0x0) ||
     (iVar1 = (**(code **)(*(int *)ui + 4))(), 0 < iVar1)) {
    if (*(int *)(ui + 0x10) << 0x17 < 0) {
      ERR_print_errors_cb((cb *)0x1ce0f9,ui);
    }
    iVar1 = 0;
    do {
      do {
        iVar2 = OPENSSL_sk_num(*(undefined4 *)(ui + 4));
        iVar4 = iVar1 + 1;
        if (iVar2 <= iVar1) {
          pcVar6 = *(code **)(*(int *)ui + 0xc);
          if (pcVar6 != (code *)0x0) {
            uVar8 = (*pcVar6)(ui,iVar1);
            iVar1 = (int)((ulonglong)uVar8 >> 0x20);
            if ((int)uVar8 == -1) {
              pcVar5 = (char *)0xfffffffe;
              pcVar7 = "processing";
              *(uint *)(ui + 0x10) = *(uint *)(ui + 0x10) & 0xfffffffe;
              goto LAB_001cf18e;
            }
            if ((int)uVar8 == 0) {
              pcVar7 = "flushing";
              goto LAB_001cf0f6;
            }
          }
          iVar2 = 0;
          goto LAB_001cf13a;
        }
        pcVar6 = *(code **)(*(int *)ui + 8);
        iVar1 = iVar4;
      } while (pcVar6 == (code *)0x0);
      uVar3 = OPENSSL_sk_value(*(undefined4 *)(ui + 4));
      iVar2 = (*pcVar6)(ui,uVar3);
    } while (0 < iVar2);
    pcVar7 = "writing strings";
  }
  else {
    pcVar7 = "opening session";
  }
LAB_001cf0f6:
  if (*(code **)(*(int *)ui + 0x14) != (code *)0x0) {
    (**(code **)(*(int *)ui + 0x14))(ui);
  }
  goto LAB_001cf100;
LAB_001cf13a:
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(ui + 4),iVar1);
  if (iVar1 <= iVar2) goto LAB_001cf1b8;
  pcVar6 = *(code **)(*(int *)ui + 0x10);
  iVar1 = iVar2;
  if (pcVar6 != (code *)0x0) {
    uVar3 = OPENSSL_sk_value(*(undefined4 *)(ui + 4));
    uVar8 = (*pcVar6)(ui,uVar3);
    iVar1 = (int)((ulonglong)uVar8 >> 0x20);
    if ((int)uVar8 == -1) {
      pcVar5 = (char *)0xfffffffe;
      *(uint *)(ui + 0x10) = *(uint *)(ui + 0x10) & 0xfffffffe;
      pcVar7 = "processing";
      goto LAB_001cf18e;
    }
    if ((int)uVar8 == 0) {
      pcVar7 = "reading strings";
      goto LAB_001cf0f6;
    }
  }
  iVar2 = iVar2 + 1;
  goto LAB_001cf13a;
LAB_001cf1b8:
  pcVar5 = (char *)0x0;
  pcVar7 = pcVar5;
LAB_001cf18e:
  if (*(code **)(*(int *)ui + 0x14) == (code *)0x0) {
    return (int)pcVar5;
  }
  iVar1 = (**(code **)(*(int *)ui + 0x14))(ui);
  if (0 < iVar1) {
    return (int)pcVar5;
  }
  if (pcVar7 == (char *)0x0) {
    pcVar7 = "closing session";
  }
LAB_001cf100:
  ERR_put_error(0x28,0x71,0x6b,"crypto/ui/ui_lib.c",0x221);
  ERR_add_error_data(2,"while ",pcVar7);
  return -1;
}

