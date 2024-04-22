
undefined4 dtls1_buffer_message(int *param_1,int param_2)

{
  undefined uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined *ptr;
  pitem *item;
  int iVar4;
  int iVar5;
  void *__dest;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_28;
  int local_24;
  
  if (param_1[0x12] != 0) {
    OpenSSLDie(DAT_00078d28,0x45e,DAT_00078d34);
  }
  __dest = (void *)param_1[0x11];
  ptr = (undefined *)CRYPTO_malloc(0x34,DAT_00078d28,0xb5);
  if (ptr != (undefined *)0x0) {
    if ((__dest == (void *)0x0) ||
       (__dest = CRYPTO_malloc((int)__dest,DAT_00078d28,0xba), __dest != (void *)0x0)) {
      iVar5 = param_1[0xf];
      *(undefined4 *)(ptr + 0x30) = 0;
      *(void **)(ptr + 0x2c) = __dest;
      memcpy(__dest,*(void **)(iVar5 + 4),param_1[0x11]);
      iVar5 = param_1[0x17];
      if (param_2 == 0) {
        iVar4 = *(int *)(iVar5 + 0x264);
        if (iVar4 + 0xc != param_1[0x11]) {
          OpenSSLDie(DAT_00078d28,0x46d,DAT_00078d2c);
          iVar5 = param_1[0x17];
          iVar4 = *(int *)(iVar5 + 0x264);
        }
      }
      else {
        iVar4 = *(int *)(iVar5 + 0x264);
        if (*param_1 == 0x100) {
          iVar6 = 3;
        }
        else {
          iVar6 = 1;
        }
        if (iVar6 + iVar4 != param_1[0x11]) {
          OpenSSLDie(DAT_00078d28,0x46a,DAT_00078d30);
          iVar5 = param_1[0x17];
          iVar4 = *(int *)(iVar5 + 0x264);
        }
      }
      uVar1 = *(undefined *)(iVar5 + 0x260);
      *(int *)(ptr + 4) = iVar4;
      uVar2 = *(ushort *)(iVar5 + 0x268);
      *ptr = uVar1;
      local_28 = 0;
      iVar9 = (uint)uVar2 * 2 - param_2;
      uVar7 = *(undefined4 *)(param_1[0x17] + 0x264);
      uVar3 = *(undefined2 *)(param_1[0x17] + 0x20a);
      iVar5 = param_1[0x25];
      *(ushort *)(ptr + 8) = uVar2;
      iVar4 = param_1[0x30];
      *(int *)(ptr + 0x14) = param_2;
      *(undefined4 *)(ptr + 0x10) = uVar7;
      iVar6 = param_1[0x23];
      iVar8 = param_1[0x24];
      *(undefined4 *)(ptr + 0xc) = 0;
      *(int *)(ptr + 0x18) = iVar6;
      *(int *)(ptr + 0x1c) = iVar8;
      *(int *)(ptr + 0x20) = iVar5;
      *(undefined2 *)(ptr + 0x28) = uVar3;
      *(int *)(ptr + 0x24) = iVar4;
      local_24 = (uint)CONCAT11((char)iVar9,(char)((uint)iVar9 >> 8)) << 0x10;
      item = pitem_new((uchar *)&local_28,ptr);
      if (item != (pitem *)0x0) {
        pqueue_insert(*(pqueue *)(param_1[0x17] + 0x248),item);
        return 1;
      }
      if (*(int *)(ptr + 0x14) != 0) {
        EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(ptr + 0x18));
        EVP_MD_CTX_destroy(*(EVP_MD_CTX **)(ptr + 0x1c));
      }
      if (*(void **)(ptr + 0x2c) != (void *)0x0) {
        CRYPTO_free(*(void **)(ptr + 0x2c));
      }
      if (*(void **)(ptr + 0x30) != (void *)0x0) {
        CRYPTO_free(*(void **)(ptr + 0x30));
      }
      CRYPTO_free(ptr);
      return 0;
    }
    CRYPTO_free(ptr);
  }
  return 0;
}

