
size_t ssl3_get_finished(int param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  size_t len;
  int local_14;
  
  sVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))();
  if (local_14 != 0) {
    iVar2 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar2 + 0x180) == 0) {
      ERR_put_error(0x14,0x8c,0x9a,DAT_0006d29c,0x101);
      uVar3 = 10;
    }
    else {
      len = *(size_t *)(iVar2 + 0x338);
      *(undefined4 *)(iVar2 + 0x180) = 0;
      if (len == sVar1) {
        iVar2 = CRYPTO_memcmp(*(void **)(param_1 + 0x40),(void *)(iVar2 + 0x2b8),len);
        if (iVar2 == 0) {
          if (*(int *)(param_1 + 4) != 0x2000) {
            if (0x40 < (int)len) {
              OpenSSLDie(DAT_0006d29c,0x11d,DAT_0006d2a0);
            }
            memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),
                   (void *)(*(int *)(param_1 + 0x58) + 0x2b8),len);
            *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)len;
            return 1;
          }
          if (0x40 < (int)len) {
            OpenSSLDie(DAT_0006d29c,0x119,DAT_0006d2a0);
          }
          memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),
                 (void *)(*(int *)(param_1 + 0x58) + 0x2b8),len);
          *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)len;
          return 1;
        }
        ERR_put_error(0x14,0x8c,0x95,DAT_0006d29c,0x111);
        uVar3 = 0x33;
      }
      else {
        ERR_put_error(0x14,0x8c,0x6f,DAT_0006d29c,0x10b);
        uVar3 = 0x32;
      }
    }
    ssl3_send_alert(param_1,2,uVar3);
    sVar1 = 0;
  }
  return sVar1;
}

