
undefined4 dtls1_buffer_record_part_1(int param_1,int param_2,uchar *param_3)

{
  undefined4 *data;
  pitem *item;
  pitem *ppVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int line;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  data = (undefined4 *)CRYPTO_malloc(0x3c,DAT_00076a84,0xe6);
  item = pitem_new(param_3,data);
  if (data == (undefined4 *)0x0 || item == (pitem *)0x0) {
    if (data != (undefined4 *)0x0) {
      CRYPTO_free(data);
    }
    if (item != (pitem *)0x0) {
      pitem_free(item);
    }
    ERR_put_error(0x14,0xf7,0x44,DAT_00076a84,0xee);
  }
  else {
    iVar4 = *(int *)(param_1 + 0x58);
    puVar7 = data + 6;
    uVar2 = *(undefined4 *)(param_1 + 0x50);
    *data = *(undefined4 *)(param_1 + 0x4c);
    data[1] = uVar2;
    uVar3 = *(undefined4 *)(iVar4 + 0xf4);
    uVar2 = *(undefined4 *)(iVar4 + 0xf0);
    uVar5 = *(undefined4 *)(iVar4 + 0xf8);
    data[2] = *(undefined4 *)(iVar4 + 0xec);
    data[3] = uVar2;
    data[5] = uVar5;
    data[4] = uVar3;
    iVar4 = *(int *)(param_1 + 0x58);
    puVar6 = (undefined4 *)(iVar4 + 0x10c);
    do {
      uVar5 = *puVar6;
      uVar8 = puVar6[1];
      uVar2 = puVar6[2];
      uVar3 = puVar6[3];
      puVar6 = puVar6 + 4;
      *puVar7 = uVar5;
      puVar7[1] = uVar8;
      puVar7[2] = uVar2;
      puVar7[3] = uVar3;
      puVar7 = puVar7 + 4;
    } while (puVar6 != (undefined4 *)(iVar4 + 300));
    *puVar7 = *puVar6;
    iVar4 = *(int *)(param_1 + 0x58);
    item->data = data;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    memset((void *)(iVar4 + 0xec),0,0x10);
    memset((void *)(*(int *)(param_1 + 0x58) + 0x10c),0,0x24);
    iVar4 = ssl3_setup_buffers(param_1);
    line = 0x109;
    if (iVar4 != 0) {
      ppVar1 = pqueue_insert(*(pqueue *)(param_2 + 4),item);
      if (ppVar1 != (pitem *)0x0) {
        return 1;
      }
      line = 0x113;
    }
    ERR_put_error(0x14,0xf7,0x44,DAT_00076a84,line);
    if ((void *)data[2] != (void *)0x0) {
      CRYPTO_free((void *)data[2]);
    }
    CRYPTO_free(data);
    pitem_free(item);
  }
  return 0xffffffff;
}

