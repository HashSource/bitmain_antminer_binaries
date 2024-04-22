
uint read_string_inner(UI *param_1,UI_STRING *param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  FILE *__stream;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  char acStack_20bc [8];
  sigaction local_20b4;
  char local_2028 [8196];
  undefined4 *puVar10;
  
  piVar1 = DAT_000d51c4;
  *DAT_000d51c4 = 0;
  iVar7 = 2;
  piVar1[3] = 0;
  iVar6 = 1;
  memset(&local_20b4,0,0x8c);
  local_20b4.__sigaction_handler = DAT_000d51c0;
  do {
    piVar2 = DAT_000d51c4;
    if ((iVar6 != 10) && (iVar6 != 0xc)) {
      if ((iVar6 != 9) &&
         (sigaction(iVar6,&local_20b4,(sigaction *)(piVar1 + iVar6 * 0x23 + 4)), iVar7 == 0x20))
      break;
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 1;
  } while( true );
  signal(0x1c,(__sighandler_t)0x0);
  piVar2[3] = 1;
  iVar6 = DAT_000d51c8;
  if (param_3 == 0) {
    puVar9 = (undefined4 *)(DAT_000d51c8 + 0xd8);
    uVar4 = *(undefined4 *)(DAT_000d51c8 + 0xdc);
    uVar5 = *(undefined4 *)(DAT_000d51c8 + 0xe0);
    puVar10 = (undefined4 *)(DAT_000d51c8 + 0xe4);
    *(undefined4 *)(DAT_000d51c8 + 0x98) = *(undefined4 *)(DAT_000d51c8 + 0xd4);
    *(undefined4 *)(iVar6 + 0x9c) = *puVar9;
    *(undefined4 *)(iVar6 + 0xa0) = uVar4;
    *(undefined4 *)(iVar6 + 0xa4) = uVar5;
    uVar4 = *puVar10;
    *(uint *)(iVar6 + 0xa4) = *(uint *)(iVar6 + 0xa4) & 0xfffffff7;
    *(undefined4 *)(iVar6 + 0xa8) = uVar4;
    *(undefined4 *)(iVar6 + 0xac) = *(undefined4 *)(iVar6 + 0xe8);
    *(undefined4 *)(iVar6 + 0xb0) = *(undefined4 *)(iVar6 + 0xec);
    *(undefined4 *)(iVar6 + 0xb4) = *(undefined4 *)(iVar6 + 0xf0);
    *(undefined4 *)(iVar6 + 0xb8) = *(undefined4 *)(iVar6 + 0xf4);
    *(undefined4 *)(iVar6 + 0xbc) = *(undefined4 *)(iVar6 + 0xf8);
    *(undefined4 *)(iVar6 + 0xc0) = *(undefined4 *)(iVar6 + 0xfc);
    *(undefined4 *)(iVar6 + 0xc4) = *(undefined4 *)(iVar6 + 0x100);
    *(undefined4 *)(iVar6 + 200) = *(undefined4 *)(iVar6 + 0x104);
    *(undefined4 *)(iVar6 + 0xcc) = *(undefined4 *)(iVar6 + 0x108);
    *(undefined4 *)(iVar6 + 0xd0) = *(undefined4 *)(iVar6 + 0x10c);
    if (*(int *)(iVar6 + 0x110) == 0) goto LAB_000d5056;
    iVar7 = fileno((FILE *)piVar2[1]);
    iVar6 = tcsetattr(iVar7,0,(termios *)(iVar6 + 0x98));
    if (iVar6 != -1) goto LAB_000d5056;
LAB_000d5080:
    uVar8 = 0;
  }
  else {
LAB_000d5056:
    local_2028[0] = '\0';
    piVar1[3] = 2;
    piVar2 = DAT_000d51c4;
    pcVar3 = fgets(local_2028,0x1fff,(FILE *)piVar1[1]);
    if (pcVar3 == (char *)0x0) goto LAB_000d5080;
    __stream = (FILE *)piVar2[1];
    iVar6 = feof(__stream);
    if ((iVar6 != 0) || (iVar6 = ferror(__stream), iVar6 != 0)) goto LAB_000d5080;
    pcVar3 = strchr(local_2028,10);
    if (pcVar3 == (char *)0x0) {
      do {
        pcVar3 = fgets(acStack_20bc,4,__stream);
        if (pcVar3 == (char *)0x0) goto LAB_000d5080;
        pcVar3 = strchr(acStack_20bc,10);
      } while (pcVar3 == (char *)0x0);
    }
    else if (param_4 != 0) {
      *pcVar3 = '\0';
    }
    uVar8 = UI_set_result(param_1,param_2,local_2028);
    uVar8 = ~uVar8 >> 0x1f;
  }
  if (*piVar1 == 2) {
    uVar8 = 0xffffffff;
  }
  if (param_3 == 0) {
    fputc(10,(FILE *)piVar1[2]);
    iVar6 = DAT_000d51c8;
    piVar2 = DAT_000d51c4;
    iVar7 = piVar1[3];
    if (iVar7 < 2) goto LAB_000d5198;
    puVar9 = (undefined4 *)(DAT_000d51c8 + 0xd8);
    uVar4 = *(undefined4 *)(DAT_000d51c8 + 0xdc);
    uVar5 = *(undefined4 *)(DAT_000d51c8 + 0xe0);
    puVar10 = (undefined4 *)(DAT_000d51c8 + 0xe4);
    *(undefined4 *)(DAT_000d51c8 + 0x98) = *(undefined4 *)(DAT_000d51c8 + 0xd4);
    *(undefined4 *)(iVar6 + 0x9c) = *puVar9;
    *(undefined4 *)(iVar6 + 0xa0) = uVar4;
    *(undefined4 *)(iVar6 + 0xa4) = uVar5;
    uVar4 = *puVar10;
    *(uint *)(iVar6 + 0xa4) = *(uint *)(iVar6 + 0xa4) | 8;
    *(undefined4 *)(iVar6 + 0xa8) = uVar4;
    *(undefined4 *)(iVar6 + 0xac) = *(undefined4 *)(iVar6 + 0xe8);
    *(undefined4 *)(iVar6 + 0xb0) = *(undefined4 *)(iVar6 + 0xec);
    *(undefined4 *)(iVar6 + 0xb4) = *(undefined4 *)(iVar6 + 0xf0);
    *(undefined4 *)(iVar6 + 0xb8) = *(undefined4 *)(iVar6 + 0xf4);
    *(undefined4 *)(iVar6 + 0xbc) = *(undefined4 *)(iVar6 + 0xf8);
    *(undefined4 *)(iVar6 + 0xc0) = *(undefined4 *)(iVar6 + 0xfc);
    *(undefined4 *)(iVar6 + 0xc4) = *(undefined4 *)(iVar6 + 0x100);
    *(undefined4 *)(iVar6 + 200) = *(undefined4 *)(iVar6 + 0x104);
    *(undefined4 *)(iVar6 + 0xcc) = *(undefined4 *)(iVar6 + 0x108);
    *(undefined4 *)(iVar6 + 0xd0) = *(undefined4 *)(iVar6 + 0x10c);
    if (*(int *)(iVar6 + 0x110) != 0) {
      iVar7 = fileno((FILE *)piVar2[1]);
      iVar6 = tcsetattr(iVar7,0,(termios *)(iVar6 + 0x98));
      if (iVar6 == -1) {
        uVar8 = 0;
      }
    }
  }
  else {
    iVar7 = piVar1[3];
    if (iVar7 < 2) {
LAB_000d5198:
      if (iVar7 != 1) goto LAB_000d50c6;
    }
  }
  iVar6 = 1;
  for (iVar7 = 2;
      ((iVar6 == 10 || (iVar6 == 0xc)) ||
      (sigaction(iVar6,(sigaction *)(piVar1 + iVar6 * 0x23 + 4),(sigaction *)0x0), iVar7 != 0x20));
      iVar7 = iVar7 + 1) {
    iVar6 = iVar6 + 1;
  }
LAB_000d50c6:
  OPENSSL_cleanse(local_2028,0x2000);
  return uVar8;
}

