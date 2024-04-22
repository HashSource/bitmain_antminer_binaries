
int UI_set_result(UI *ui,UI_STRING *uis,char *result)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *__s;
  char *pcVar5;
  int line;
  char acStack_38 [16];
  char acStack_28 [16];
  
  sVar1 = strlen(result);
  *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) & 0xfffffffe;
  if (uis == (UI_STRING *)0x0) {
LAB_000d4eea:
    iVar2 = -1;
  }
  else {
    uVar4 = *(uint *)uis;
    if (uVar4 != 0) {
      if (uVar4 < 3) {
        BIO_snprintf(acStack_38,0xd,DAT_000d4f18,*(undefined4 *)(uis + 0x10));
        BIO_snprintf(acStack_28,0xd,DAT_000d4f18,*(undefined4 *)(uis + 0x14));
        pcVar5 = DAT_000d4f1c;
        if ((int)sVar1 < *(int *)(uis + 0x10)) {
          iVar2 = 0x65;
          uVar4 = *(uint *)(ui + 0x14);
          line = 0x337;
        }
        else {
          if ((int)sVar1 <= *(int *)(uis + 0x14)) {
            iVar2 = 0x346;
            if (*(char **)(uis + 0xc) == (char *)0x0) goto LAB_000d4f08;
            BUF_strlcpy(*(char **)(uis + 0xc),result,*(int *)(uis + 0x14) + 1);
            goto LAB_000d4e24;
          }
          uVar4 = *(uint *)(ui + 0x14);
          line = 0x33e;
          iVar2 = 100;
        }
        *(uint *)(ui + 0x14) = uVar4 | 1;
        ERR_put_error(0x28,0x69,iVar2,pcVar5,line);
        ERR_add_error_data(5,DAT_000d4f24,acStack_38,DAT_000d4f28,acStack_28,DAT_000d4f20);
        goto LAB_000d4eea;
      }
      if (uVar4 == 3) {
        if (*(undefined **)(uis + 0xc) == (undefined *)0x0) {
          iVar2 = 0x352;
LAB_000d4f08:
          ERR_put_error(0x28,0x69,0x69,DAT_000d4f1c,iVar2);
          goto LAB_000d4eea;
        }
        **(undefined **)(uis + 0xc) = 0;
        uVar4 = (uint)(byte)*result;
        if (uVar4 == 0) {
          return 0;
        }
        pcVar5 = *(char **)(uis + 0x14);
        do {
          pcVar3 = strchr(pcVar5,uVar4);
          if (pcVar3 != (char *)0x0) {
            **(char **)(uis + 0xc) = *pcVar5;
            return 0;
          }
          __s = *(char **)(uis + 0x18);
          pcVar3 = strchr(__s,uVar4);
          if (pcVar3 != (char *)0x0) {
            **(char **)(uis + 0xc) = *__s;
            return 0;
          }
          result = (char *)((byte *)result + 1);
          uVar4 = (uint)(byte)*result;
        } while (uVar4 != 0);
      }
    }
LAB_000d4e24:
    iVar2 = 0;
  }
  return iVar2;
}

