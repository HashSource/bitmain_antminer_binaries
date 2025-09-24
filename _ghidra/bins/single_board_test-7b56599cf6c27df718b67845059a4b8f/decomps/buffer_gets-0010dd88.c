
int buffer_gets(BIO *param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  bio_st *pbVar8;
  int iVar9;
  char *pcVar10;
  
  pbVar8 = param_1->next_bio;
  param_3 = param_3 + -1;
  iVar9 = 0;
  BIO_clear_flags(param_1,0xf);
  iVar4 = pbVar8->init;
  do {
    while (iVar4 < 1) {
      iVar4 = BIO_read(param_1->prev_bio,pbVar8->cb_arg,(int)pbVar8->method);
      if (iVar4 < 1) {
        BIO_copy_next_retry(param_1);
        *param_2 = '\0';
        if (iVar4 != 0 && iVar9 < 1) {
          iVar9 = iVar4;
        }
        return iVar9;
      }
      pbVar8->init = iVar4;
      pbVar8->shutdown = 0;
    }
    pcVar6 = pbVar8->cb_arg;
    iVar3 = pbVar8->shutdown;
    if (param_3 < 1) {
      iVar7 = 0;
    }
    else {
      pcVar5 = pcVar6 + iVar3;
      pcVar10 = param_2 + 1;
      *param_2 = pcVar6[iVar3];
      if (pcVar6[iVar3] == '\n') {
        iVar3 = 1;
LAB_0010ddfc:
        iVar9 = iVar9 + iVar3;
        pbVar8->init = pbVar8->init - iVar3;
        pbVar8->shutdown = iVar3 + pbVar8->shutdown;
        param_2 = pcVar10;
        break;
      }
      iVar7 = 0;
      param_2 = pcVar10;
      while( true ) {
        iVar3 = iVar7;
        iVar4 = pbVar8->init;
        iVar7 = iVar3 + 1;
        iVar1 = param_3 - iVar7;
        iVar2 = param_3;
        if (iVar7 < param_3) {
          iVar1 = iVar4 - iVar7;
          iVar2 = iVar4;
        }
        if (iVar2 == iVar7 || iVar1 < 0 != SBORROW4(iVar2,iVar7)) break;
        pcVar10 = param_2 + 1;
        *param_2 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
        param_2 = pcVar10;
        if (*pcVar5 == '\n') {
          iVar3 = iVar3 + 2;
          goto LAB_0010ddfc;
        }
      }
      iVar3 = pbVar8->shutdown;
    }
    param_3 = param_3 - iVar7;
    iVar4 = iVar4 - iVar7;
    pbVar8->init = iVar4;
    iVar9 = iVar9 + iVar7;
    pbVar8->shutdown = iVar3 + iVar7;
  } while (param_3 != 0);
  *param_2 = '\0';
  return iVar9;
}

