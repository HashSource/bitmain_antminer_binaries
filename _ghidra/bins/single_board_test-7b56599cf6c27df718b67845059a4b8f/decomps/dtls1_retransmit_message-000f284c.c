
undefined4 dtls1_retransmit_message(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  pitem *ppVar3;
  BIO *bp;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uchar local_30 [4];
  int local_2c;
  
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_2c = (uint)CONCAT11((char)param_2,(char)((uint)param_2 >> 8)) << 0x10;
  ppVar3 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x80) + 0x114),local_30);
  if (ppVar3 == (pitem *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x186,0x44,"ssl/statem/statem_dtls.c",0x45b);
    *param_3 = 0;
    uVar11 = 0;
  }
  else {
    puVar9 = (undefined1 *)ppVar3->data;
    *param_3 = 1;
    if (*(int *)(puVar9 + 0x14) == 0) {
      iVar10 = 0xc;
    }
    else {
      iVar10 = 1;
    }
    memcpy(*(void **)(*(int *)(param_1 + 0x6c) + 4),*(void **)(puVar9 + 0x2c),
           *(int *)(puVar9 + 4) + iVar10);
    iVar4 = *(int *)(puVar9 + 4);
    uVar2 = *(undefined2 *)(puVar9 + 8);
    iVar6 = *(int *)(param_1 + 0x80);
    uVar11 = *(undefined4 *)(puVar9 + 0x10);
    *(int *)(param_1 + 0x74) = iVar10 + iVar4;
    uVar1 = *puVar9;
    *(int *)(iVar6 + 0x124) = iVar4;
    *(undefined2 *)(iVar6 + 0x128) = uVar2;
    *(undefined1 *)(iVar6 + 0x120) = uVar1;
    uVar14 = *(undefined4 *)(puVar9 + 0x18);
    uVar15 = *(undefined4 *)(puVar9 + 0x1c);
    iVar4 = *(int *)(param_1 + 0xf38);
    iVar10 = *(int *)(param_1 + 0x80);
    *(undefined4 *)(iVar6 + 0x130) = uVar11;
    *(undefined4 *)(iVar6 + 300) = 0;
    uVar7 = *(undefined4 *)(param_1 + 0x3ec);
    uVar2 = *(undefined2 *)(iVar4 + 2);
    uVar13 = *(undefined4 *)(param_1 + 0x400);
    uVar5 = *(undefined4 *)(param_1 + 0x474);
    uVar12 = *(undefined4 *)(param_1 + 0x3e4);
    *(undefined4 *)(iVar10 + 400) = 1;
    uVar8 = *(undefined4 *)(puVar9 + 0x24);
    uVar11 = *(undefined4 *)(puVar9 + 0x20);
    *(undefined4 *)(param_1 + 0x3ec) = uVar14;
    *(undefined4 *)(param_1 + 0x400) = uVar15;
    *(undefined4 *)(param_1 + 0x474) = uVar8;
    *(undefined4 *)(param_1 + 0x3e4) = uVar11;
    DTLS_RECORD_LAYER_set_saved_w_epoch(param_1 + 0x650,*(undefined2 *)(puVar9 + 0x28));
    if (*(int *)(puVar9 + 0x14) == 0) {
      uVar11 = 0x16;
    }
    else {
      uVar11 = 0x14;
    }
    uVar11 = dtls1_do_write(param_1,uVar11);
    *(undefined4 *)(param_1 + 0x400) = uVar13;
    *(undefined4 *)(param_1 + 0x3ec) = uVar7;
    *(undefined4 *)(param_1 + 0x474) = uVar5;
    *(undefined4 *)(param_1 + 0x3e4) = uVar12;
    DTLS_RECORD_LAYER_set_saved_w_epoch(param_1 + 0x650,uVar2);
    bp = *(BIO **)(param_1 + 0xc);
    *(undefined4 *)(*(int *)(param_1 + 0x80) + 400) = 0;
    BIO_ctrl(bp,0xb,0,(void *)0x0);
  }
  return uVar11;
}

