
void default_save_file(char *param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  char cVar4;
  char *pcVar5;
  size_t sVar6;
  undefined2 *puVar7;
  
  if ((default_config != (char *)0x0) && (*default_config != '\0')) {
    (*(code *)PTR_strcpy_0007cf08)();
    return;
  }
  pcVar5 = getenv("HOME");
  if ((pcVar5 == (char *)0x0) || (pcVar5 = getenv("HOME"), *pcVar5 == '\0')) {
    *param_1 = '\0';
  }
  else {
    pcVar5 = getenv("HOME");
    puVar7 = (undefined2 *)stpcpy(param_1,pcVar5);
    *puVar7 = s__bmminer__0005c808._8_2_;
  }
  sVar6 = strlen(param_1);
  uVar2 = s__bmminer__0005c808._8_2_;
  uVar1 = s__bmminer__0005c808._4_4_;
  *(undefined4 *)(param_1 + sVar6) = s__bmminer__0005c808._0_4_;
  *(undefined4 *)(param_1 + sVar6 + 4) = uVar1;
  *(undefined2 *)(param_1 + sVar6 + 8) = uVar2;
  mkdir(param_1,0x1ff);
  sVar6 = strlen(param_1);
  cVar4 = s_bmminer_conf_0005c814[12];
  uVar3 = s_bmminer_conf_0005c814._8_4_;
  uVar1 = s_bmminer_conf_0005c814._4_4_;
  *(undefined4 *)(param_1 + sVar6) = s_bmminer_conf_0005c814._0_4_;
  *(undefined4 *)(param_1 + sVar6 + 4) = uVar1;
  param_1[sVar6 + 0xc] = cVar4;
  *(undefined4 *)(param_1 + sVar6 + 8) = uVar3;
  return;
}

