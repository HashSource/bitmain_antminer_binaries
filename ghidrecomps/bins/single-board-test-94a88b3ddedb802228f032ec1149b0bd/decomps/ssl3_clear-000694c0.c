
void ssl3_clear(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  ssl3_cleanup_key_block();
  iVar1 = param_1[0x16];
  if (*(_STACK **)(iVar1 + 0x36c) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)(iVar1 + 0x36c),DAT_000695c0);
    iVar1 = param_1[0x16];
  }
  if (*(void **)(iVar1 + 0x120) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar1 + 0x120));
    iVar1 = param_1[0x16];
    *(undefined4 *)(iVar1 + 0x120) = 0;
  }
  if (*(DH **)(iVar1 + 0x348) != (DH *)0x0) {
    DH_free(*(DH **)(iVar1 + 0x348));
    iVar1 = param_1[0x16];
    *(undefined4 *)(iVar1 + 0x348) = 0;
  }
  if (*(EC_KEY **)(iVar1 + 0x34c) != (EC_KEY *)0x0) {
    EC_KEY_free(*(EC_KEY **)(iVar1 + 0x34c));
    iVar1 = param_1[0x16];
    *(undefined4 *)(iVar1 + 0x34c) = 0;
  }
  *(undefined *)(iVar1 + 0x420) = 0;
  pvVar2 = (void *)param_1[0x16];
  uVar7 = *(undefined4 *)((int)pvVar2 + 0xec);
  uVar6 = *(undefined4 *)((int)pvVar2 + 0xfc);
  uVar5 = *(undefined4 *)((int)pvVar2 + 0xf0);
  uVar4 = *(undefined4 *)((int)pvVar2 + 0x100);
  uVar3 = *(undefined4 *)((int)pvVar2 + 0xe8);
  if (*(BIO **)((int)pvVar2 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)((int)pvVar2 + 0x178));
    pvVar2 = (void *)param_1[0x16];
    *(undefined4 *)((int)pvVar2 + 0x178) = 0;
  }
  if (*(int *)((int)pvVar2 + 0x17c) != 0) {
    ssl3_free_digest_list(param_1);
    pvVar2 = (void *)param_1[0x16];
  }
  if (*(void **)((int)pvVar2 + 0x424) != (void *)0x0) {
    free(*(void **)((int)pvVar2 + 0x424));
    pvVar2 = (void *)param_1[0x16];
    *(undefined4 *)((int)pvVar2 + 0x424) = 0;
  }
  memset(pvVar2,0,0x42c);
  iVar1 = param_1[0x16];
  *(undefined4 *)(iVar1 + 0xec) = uVar7;
  *(undefined4 *)(iVar1 + 0xfc) = uVar6;
  *(undefined4 *)(iVar1 + 0xf0) = uVar5;
  *(undefined4 *)(iVar1 + 0x100) = uVar4;
  *(undefined4 *)(iVar1 + 0xe8) = uVar3;
  ssl_free_wbio_buffer(param_1);
  iVar1 = param_1[0x16];
  pvVar2 = (void *)param_1[0x5d];
  param_1[0x14] = 0;
  *(undefined4 *)(iVar1 + 0x194) = 0;
  *(undefined4 *)(iVar1 + 0x198) = 0;
  *(undefined4 *)(iVar1 + 0x19c) = 0;
  *(undefined4 *)(iVar1 + 0x1a0) = 0;
  *param_1 = 0x300;
  if (pvVar2 != (void *)0x0) {
    CRYPTO_free(pvVar2);
    param_1[0x5d] = 0;
    *(undefined *)(param_1 + 0x5e) = 0;
  }
  return;
}

