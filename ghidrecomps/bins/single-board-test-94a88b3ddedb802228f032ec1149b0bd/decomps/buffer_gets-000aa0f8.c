
int buffer_gets(BIO *param_1,undefined *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  int *piVar8;
  int iVar9;
  
  piVar8 = (int *)param_1->ptr;
  param_3 = param_3 + -1;
  BIO_clear_flags(param_1,0xf);
  iVar6 = piVar8[3];
  iVar9 = 0;
  do {
    while (iVar6 < 1) {
      iVar6 = BIO_read(param_1->next_bio,(void *)piVar8[2],*piVar8);
      if (iVar6 < 1) {
        BIO_copy_next_retry(param_1);
        *param_2 = 0;
        if (iVar6 == 0) {
          return iVar9;
        }
        if (0 < iVar9) {
          return iVar9;
        }
        return iVar6;
      }
      piVar8[3] = iVar6;
      piVar8[4] = 0;
    }
    iVar2 = piVar8[4];
    iVar3 = piVar8[2];
    if (param_3 < 1) {
      iVar4 = 0;
    }
    else {
      puVar7 = param_2 + 1;
      *param_2 = *(undefined *)(iVar3 + iVar2);
      if (*(char *)(iVar3 + iVar2) == '\n') {
        iVar2 = 1;
LAB_000aa19a:
        iVar9 = iVar9 + iVar2;
        piVar8[3] = piVar8[3] - iVar2;
        piVar8[4] = piVar8[4] + iVar2;
        param_2 = puVar7;
        break;
      }
      iVar4 = 0;
      puVar5 = (undefined *)(iVar3 + iVar2);
      param_2 = puVar7;
      while( true ) {
        iVar2 = iVar4;
        iVar6 = piVar8[3];
        iVar4 = iVar2 + 1;
        if (iVar6 <= iVar4) break;
        if (iVar4 == param_3) {
          iVar9 = iVar9 + iVar4;
          piVar8[3] = iVar6 - iVar4;
          piVar8[4] = iVar4 + piVar8[4];
          goto LAB_000aa18e;
        }
        puVar7 = param_2 + 1;
        *param_2 = puVar5[1];
        pcVar1 = puVar5 + 1;
        puVar5 = puVar5 + 1;
        param_2 = puVar7;
        if (*pcVar1 == '\n') {
          iVar2 = iVar2 + 2;
          goto LAB_000aa19a;
        }
      }
      iVar2 = piVar8[4];
    }
    param_3 = param_3 - iVar4;
    iVar6 = iVar6 - iVar4;
    piVar8[3] = iVar6;
    iVar9 = iVar9 + iVar4;
    piVar8[4] = iVar2 + iVar4;
  } while (param_3 != 0);
LAB_000aa18e:
  *param_2 = 0;
  return iVar9;
}

