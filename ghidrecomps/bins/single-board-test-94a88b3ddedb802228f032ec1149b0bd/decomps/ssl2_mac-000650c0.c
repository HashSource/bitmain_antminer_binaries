
void ssl2_mac(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  size_t cnt;
  undefined4 uVar2;
  size_t cnt_00;
  void *d;
  void *d_00;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  EVP_MD_CTX EStack_30;
  
  if (param_3 == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    uVar2 = *(undefined4 *)(iVar1 + 0xd0);
    d_00 = *(void **)(iVar1 + 0x5c);
    cnt_00 = *(size_t *)(iVar1 + 0x44);
    d = *(void **)(iVar1 + 0x50);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x54);
    uVar2 = *(undefined4 *)(iVar1 + 0xd4);
    d_00 = *(void **)(iVar1 + 0x60);
    cnt_00 = *(size_t *)(iVar1 + 0x4c);
    d = *(void **)(iVar1 + 0x54);
  }
  local_31 = (undefined)uVar2;
  local_34 = (undefined)((uint)uVar2 >> 0x18);
  local_32 = (undefined)((uint)uVar2 >> 8);
  local_33 = (undefined)((uint)uVar2 >> 0x10);
  EVP_MD_CTX_init(&EStack_30);
  EVP_MD_CTX_copy(&EStack_30,*(EVP_MD_CTX **)(param_1 + 0x84));
  cnt = EVP_CIPHER_CTX_key_length(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
  EVP_DigestUpdate(&EStack_30,d_00,cnt);
  EVP_DigestUpdate(&EStack_30,d,cnt_00);
  EVP_DigestUpdate(&EStack_30,&local_34,4);
  EVP_DigestFinal_ex(&EStack_30,param_2,(uint *)0x0);
  EVP_MD_CTX_cleanup(&EStack_30);
  return;
}

