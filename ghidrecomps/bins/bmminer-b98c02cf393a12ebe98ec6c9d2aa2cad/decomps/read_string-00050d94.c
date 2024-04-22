
char * read_string(int param_1,size_t **param_2,undefined4 param_3,size_t *param_4,
                  undefined4 *param_5)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  char **ppcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_34;
  size_t local_30;
  
  puVar5 = (undefined4 *)(param_1 + 0x18);
  puVar8 = (undefined4 *)(param_1 + 0x28);
  next_token();
  puVar7 = (undefined4 *)(param_1 + 8);
  bVar1 = *(byte *)(param_1 + 0x24);
  *puVar8 = *puVar5;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
  *puVar5 = *puVar7;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
  if ((bVar1 & 0xf7) == 0x23 || bVar1 == 0x25) {
    strbuffer_init(&local_34);
    do {
      ppcVar4 = (char **)*param_2;
      *param_2 = (size_t *)(ppcVar4 + 1);
      pcVar6 = *ppcVar4;
      if (pcVar6 == (char *)0x0) {
        set_error(param_1,"<args>","NULL string argument");
        strbuffer_close(&local_34);
        return (char *)0x0;
      }
      next_token();
      if ((*(char *)(param_1 + 0x24) == '#') || (*(char *)(param_1 + 0x24) == '%')) {
        sVar2 = **param_2;
        *param_2 = *param_2 + 1;
      }
      else {
        *puVar8 = *puVar5;
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
        *puVar5 = *puVar7;
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
        sVar2 = strlen(pcVar6);
      }
      iVar3 = strbuffer_append_bytes(&local_34,pcVar6,sVar2);
      if (iVar3 == -1) {
        set_error(param_1,"<internal>","Out of memory");
        strbuffer_close(&local_34);
        return (char *)0x0;
      }
      next_token();
    } while (*(char *)(param_1 + 0x24) == '+');
    *puVar8 = *puVar5;
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
    *puVar5 = *puVar7;
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
    iVar3 = utf8_check_string(local_34,local_30);
    if (iVar3 != 0) {
      *param_4 = local_30;
      *param_5 = 1;
      pcVar6 = (char *)strbuffer_steal_value(&local_34);
      return pcVar6;
    }
    set_error(param_1,"<args>","Invalid UTF-8 %s",param_3);
    strbuffer_close(&local_34);
    pcVar6 = (char *)0x0;
  }
  else {
    ppcVar4 = (char **)*param_2;
    *param_2 = (size_t *)(ppcVar4 + 1);
    pcVar6 = *ppcVar4;
    if (pcVar6 == (char *)0x0) {
      set_error(param_1,"<args>","NULL string argument");
    }
    else {
      sVar2 = strlen(pcVar6);
      iVar3 = utf8_check_string(pcVar6,sVar2);
      if (iVar3 == 0) {
        set_error(param_1,"<args>","Invalid UTF-8 %s",param_3);
        pcVar6 = (char *)0x0;
      }
      else {
        *param_4 = sVar2;
        *param_5 = 0;
      }
    }
  }
  return pcVar6;
}

