
undefined4 hwcrhk_ctrl(undefined4 param_1,int param_2,int param_3,char *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = DAT_000dc76c;
  if (param_2 == 0x65) {
    CRYPTO_lock(9,0x1e,DAT_000dc770,0x2e9);
    pcVar3 = DAT_000dc770;
    *(undefined4 *)(iVar4 + 0x40) = 1;
    CRYPTO_lock(10,0x1e,pcVar3,0x2eb);
    return 1;
  }
  if (param_2 < 0x66) {
    if (param_2 == 4) {
LAB_000dc66e:
      CRYPTO_lock(9,0x1e,DAT_000dc770,0x2ca);
      pcVar3 = DAT_000dc770;
      *(char **)(iVar4 + 0xc) = param_4;
      CRYPTO_lock(10,0x1e,pcVar3,0x2cc);
      return 1;
    }
    if (param_2 < 5) {
      if (param_2 == 1) {
        CRYPTO_lock(9,0x1e,DAT_000dc770,0x2b7);
        if (*(BIO **)(iVar4 + 0x44) != (BIO *)0x0) {
          BIO_free(*(BIO **)(iVar4 + 0x44));
          *(undefined4 *)(iVar4 + 0x44) = 0;
        }
        iVar2 = CRYPTO_add_lock((int *)(param_4 + 0x2c),1,0x15,DAT_000dc770,700);
        iVar1 = DAT_000dc76c;
        if (iVar2 < 2) {
          iVar4 = *(int *)(iVar4 + 0x1c);
          if (iVar4 == 0) {
            iVar4 = ERR_get_next_error_library();
            *(int *)(iVar1 + 0x1c) = iVar4;
          }
          ERR_put_error(iVar4,100,0x65,DAT_000dc770,0x2bf);
        }
        else {
          *(char **)(iVar4 + 0x44) = param_4;
        }
        CRYPTO_lock(10,0x1e,DAT_000dc770,0x2c1);
        return 1;
      }
      if (param_2 == 2) {
        CRYPTO_lock(9,0x1e,DAT_000dc770,0x2c4);
        pcVar3 = DAT_000dc770;
        *(undefined4 *)(DAT_000dc76c + 8) = param_5;
        CRYPTO_lock(10,0x1e,pcVar3,0x2c6);
        return 1;
      }
    }
    else {
      if (param_2 == 5) goto LAB_000dc5ce;
      if (param_2 == 100) goto LAB_000dc596;
    }
  }
  else {
    if (param_2 == 0xca) {
      CRYPTO_lock(9,0x1e,DAT_000dc770,0x2ee);
      pcVar3 = DAT_000dc770;
      if (param_3 != 0) {
        param_3 = 1;
      }
      *(int *)(iVar4 + 0x40) = param_3;
      CRYPTO_lock(10,0x1e,pcVar3,0x2f0);
      return 1;
    }
    if (param_2 < 0xcb) {
      if (param_2 == 200) {
        if (*(int *)(DAT_000dc76c + 0x20) != 0) {
          iVar1 = *(int *)(DAT_000dc76c + 0x1c);
          if (iVar1 == 0) {
            iVar1 = ERR_get_next_error_library();
            *(int *)(iVar4 + 0x1c) = iVar1;
          }
          ERR_put_error(iVar1,100,100,DAT_000dc770,0x2ab);
          return 0;
        }
        if (param_4 != (char *)0x0) {
          if (*(void **)(DAT_000dc76c + 0x18) != (void *)0x0) {
            CRYPTO_free(*(void **)(DAT_000dc76c + 0x18));
          }
          *(undefined4 *)(iVar4 + 0x18) = 0;
          pcVar3 = BUF_strdup(param_4);
          *(char **)(iVar4 + 0x18) = pcVar3;
          if (pcVar3 == (char *)0x0) {
            return 0;
          }
          return 1;
        }
        iVar1 = *(int *)(DAT_000dc76c + 0x1c);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar4 + 0x1c) = iVar1;
        }
        ERR_put_error(iVar1,100,0x43,DAT_000dc770,0x2af);
        return 0;
      }
      if (param_2 == 0xc9) {
LAB_000dc596:
        CRYPTO_lock(9,0x1e,DAT_000dc770,0x2da);
        pcVar3 = DAT_000dc770;
        if (param_3 == 0) {
          uVar5 = *(uint *)(DAT_000dc774 + 4) & 0xffffffef;
        }
        else {
          uVar5 = *(uint *)(DAT_000dc774 + 4) | 0x10;
        }
        *(uint *)(DAT_000dc774 + 4) = uVar5;
        CRYPTO_lock(10,0x1e,pcVar3,0x2df);
        return 1;
      }
    }
    else {
      if (param_2 == 0xcb) goto LAB_000dc66e;
      if (param_2 == 0xcc) {
LAB_000dc5ce:
        CRYPTO_lock(9,0x1e,DAT_000dc770,0x2d0);
        pcVar3 = DAT_000dc770;
        *(char **)(iVar4 + 0x10) = param_4;
        CRYPTO_lock(10,0x1e,pcVar3,0x2d2);
        return 1;
      }
    }
  }
  iVar1 = *(int *)(DAT_000dc76c + 0x1c);
  if (iVar1 == 0) {
    iVar1 = ERR_get_next_error_library();
    *(int *)(iVar4 + 0x1c) = iVar1;
  }
  ERR_put_error(iVar1,100,0x67,DAT_000dc770,0x2f6);
  return 0;
}

