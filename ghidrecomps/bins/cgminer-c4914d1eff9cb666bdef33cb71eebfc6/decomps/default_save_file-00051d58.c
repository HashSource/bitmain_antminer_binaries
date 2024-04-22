
void default_save_file(char *filename)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  size_t sVar4;
  undefined4 *puVar5;
  char *filename_local;
  
  if ((default_config == (char *)0x0) || (*default_config == '\0')) {
    pcVar3 = getenv("HOME");
    if ((pcVar3 == (char *)0x0) || (pcVar3 = getenv("HOME"), *pcVar3 == '\0')) {
      *filename = '\0';
    }
    else {
      pcVar3 = getenv("HOME");
      strcpy(filename,pcVar3);
      sVar4 = strlen(filename);
      *(undefined2 *)(filename + sVar4) = DAT_0008cd34;
    }
    sVar4 = strlen(filename);
    uVar1 = s__bmminer__0008cd38._4_4_;
    puVar5 = (undefined4 *)(filename + sVar4);
    *puVar5 = s__bmminer__0008cd38._0_4_;
    puVar5[1] = uVar1;
    *(undefined2 *)(puVar5 + 2) = s__bmminer__0008cd38._8_2_;
    mkdir(filename,0x1ff);
    sVar4 = strlen(filename);
    uVar2 = def_conf._8_4_;
    uVar1 = def_conf._4_4_;
    puVar5 = (undefined4 *)(filename + sVar4);
    *puVar5 = def_conf._0_4_;
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    *(char *)(puVar5 + 3) = def_conf[12];
  }
  else {
    strcpy(filename,default_config);
  }
  return;
}

