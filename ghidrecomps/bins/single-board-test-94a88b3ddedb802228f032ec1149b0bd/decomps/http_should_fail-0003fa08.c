
undefined http_should_fail(int *param_1)

{
  char cVar1;
  undefined uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  iVar3 = *(int *)(iVar4 + 200);
  if (*(char *)(iVar4 + 0x300) == '\0') {
    return 0;
  }
  if (iVar3 < 400) {
    return 0;
  }
  if (iVar3 == 0x197 || iVar3 == 0x191) {
    if (iVar3 == 0x191) {
      cVar1 = *(char *)((int)param_1 + 0x1f1);
joined_r0x0003fa4e:
      if (cVar1 == '\0') goto LAB_0003fa50;
    }
    else if (iVar3 == 0x197) {
      cVar1 = *(char *)((int)param_1 + 0x1f2);
      goto joined_r0x0003fa4e;
    }
    uVar2 = *(undefined *)(iVar4 + 0x8640);
  }
  else {
LAB_0003fa50:
    uVar2 = 1;
  }
  return uVar2;
}

