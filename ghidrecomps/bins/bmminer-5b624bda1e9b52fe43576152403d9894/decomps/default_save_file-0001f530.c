
/* WARNING: Unknown calling convention */

void default_save_file(char *filename)

{
  char cVar1;
  undefined2 uVar2;
  char *pcVar3;
  size_t sVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if ((*(char **)(DAT_0001f5b0 + 4) != (char *)0x0) && (**(char **)(DAT_0001f5b0 + 4) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x0000a3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f280)();
    return;
  }
  pcVar3 = getenv(DAT_0001f5b4);
  if ((pcVar3 == (char *)0x0) || (pcVar3 = getenv(DAT_0001f5b4), *pcVar3 == '\0')) {
    *filename = '\0';
  }
  else {
    pcVar3 = getenv(DAT_0001f5b4);
    puVar5 = (undefined2 *)stpcpy(filename,pcVar3);
    *puVar5 = *DAT_0001f5c0;
  }
  sVar4 = strlen(filename);
  uVar6 = DAT_0001f5b8[1];
  uVar2 = *(undefined2 *)(DAT_0001f5b8 + 2);
  *(undefined4 *)(filename + sVar4) = *DAT_0001f5b8;
  *(undefined4 *)(filename + sVar4 + 4) = uVar6;
  *(undefined2 *)(filename + sVar4 + 8) = uVar2;
  mkdir(filename,0x1ff);
  sVar4 = strlen(filename);
  uVar6 = DAT_0001f5bc[1];
  uVar7 = DAT_0001f5bc[2];
  cVar1 = *(char *)(DAT_0001f5bc + 3);
  *(undefined4 *)(filename + sVar4) = *DAT_0001f5bc;
  *(undefined4 *)(filename + sVar4 + 4) = uVar6;
  filename[sVar4 + 0xc] = cVar1;
  *(undefined4 *)(filename + sVar4 + 8) = uVar7;
  return;
}

