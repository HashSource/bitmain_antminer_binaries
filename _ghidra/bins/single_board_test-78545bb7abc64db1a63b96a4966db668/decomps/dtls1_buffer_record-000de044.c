
undefined4 dtls1_buffer_record(int param_1,int param_2,uchar *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *data;
  pitem *item;
  int iVar3;
  pitem *ppVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar1 = pqueue_size(*(pqueue *)(param_2 + 4));
  if (uVar1 < 100) {
    data = (undefined4 *)CRYPTO_malloc(0x4c,"ssl/record/rec_layer_d1.c",0x97);
    item = pitem_new(param_3,data);
    if (item == (pitem *)0x0 || data == (undefined4 *)0x0) {
      CRYPTO_free(data);
      pitem_free(item);
      ossl_statem_fatal(param_1,0x50,0xf7,0x44,"ssl/record/rec_layer_d1.c",0x9d);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0xefc);
      *data = *(undefined4 *)(param_1 + 0xef8);
      data[1] = uVar2;
      uVar9 = *(undefined4 *)(param_1 + 0x664);
      uVar2 = *(undefined4 *)(param_1 + 0x66c);
      uVar8 = *(undefined4 *)(param_1 + 0x670);
      data[3] = *(undefined4 *)(param_1 + 0x668);
      data[4] = uVar2;
      data[5] = uVar8;
      data[2] = uVar9;
      data[6] = *(undefined4 *)(param_1 + 0x674);
      puVar5 = data + 7;
      puVar6 = (undefined4 *)(param_1 + 0x8f8);
      do {
        puVar7 = puVar6 + 4;
        uVar8 = puVar6[1];
        uVar9 = puVar6[2];
        uVar2 = puVar6[3];
        *puVar5 = *puVar6;
        puVar5[1] = uVar8;
        puVar5[2] = uVar9;
        puVar5[3] = uVar2;
        puVar5 = puVar5 + 4;
        puVar6 = puVar7;
      } while (puVar7 != (undefined4 *)(param_1 + 0x928));
      item->data = data;
      *(undefined4 *)(param_1 + 0xef8) = 0;
      *(undefined4 *)(param_1 + 0xefc) = 0;
      *(undefined4 *)(param_1 + 0x664) = 0;
      *(undefined4 *)(param_1 + 0x668) = 0;
      *(undefined4 *)(param_1 + 0x66c) = 0;
      *(undefined4 *)(param_1 + 0x670) = 0;
      *(undefined4 *)(param_1 + 0x674) = 0;
      memset((undefined4 *)(param_1 + 0x8f8),0,0x600);
      iVar3 = ssl3_setup_buffers(param_1);
      if (iVar3 == 0) {
        CRYPTO_free((void *)data[2]);
        CRYPTO_free(data);
        pitem_free(item);
        uVar2 = 0xffffffff;
      }
      else {
        ppVar4 = pqueue_insert(*(pqueue *)(param_2 + 4),item);
        if (ppVar4 != (pitem *)0x0) {
          return 1;
        }
        CRYPTO_free((void *)data[2]);
        CRYPTO_free(data);
        pitem_free(item);
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

