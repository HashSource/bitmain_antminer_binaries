
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_STATE * ERR_get_state(void)

{
  int iVar1;
  int iVar2;
  ERR_STATE *pEVar3;
  ERR_STATE *dest;
  void *ptr;
  char *pcVar4;
  CRYPTO_THREADID CStack_1b0;
  CRYPTO_THREADID aCStack_1a8 [50];
  
  iVar1 = DAT_000ad930;
  if (*(int *)(DAT_000ad930 + 0x2f4) == 0) {
    CRYPTO_lock(9,1,DAT_000ad934,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000adbf4;
    }
    CRYPTO_lock(10,1,DAT_000ad934,0x12a);
  }
  iVar2 = DAT_000ad930;
  CRYPTO_THREADID_current(&CStack_1b0);
  CRYPTO_THREADID_cpy(aCStack_1a8,&CStack_1b0);
  pEVar3 = (ERR_STATE *)(**(code **)(*(int *)(iVar1 + 0x2f4) + 0x1c))(aCStack_1a8);
  if (pEVar3 == (ERR_STATE *)0x0) {
    dest = (ERR_STATE *)CRYPTO_malloc(400,DAT_000ad934,0x403);
    if (dest == (ERR_STATE *)0x0) {
      pEVar3 = (ERR_STATE *)(iVar2 + 0x3f8);
    }
    else {
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)dest,&CStack_1b0);
      dest->top = 0;
      dest->bottom = 0;
      memset(dest->err_data,0,0x40);
      memset(dest->err_data_flags,0,0x40);
      ptr = (void *)(**(code **)(*(int *)(iVar2 + 0x2f4) + 0x20))(dest);
      pEVar3 = (ERR_STATE *)(**(code **)(*(int *)(iVar2 + 0x2f4) + 0x1c))(dest);
      if (pEVar3 == dest) {
        if (ptr != (void *)0x0) {
          if ((*(void **)((int)ptr + 0x88) != (void *)0x0) && (*(int *)((int)ptr + 200) << 0x1f < 0)
             ) {
            CRYPTO_free(*(void **)((int)ptr + 0x88));
            *(undefined4 *)((int)ptr + 0x88) = 0;
          }
          *(undefined4 *)((int)ptr + 200) = 0;
          if ((*(void **)((int)ptr + 0x8c) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xcc) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x8c));
            *(undefined4 *)((int)ptr + 0x8c) = 0;
          }
          *(undefined4 *)((int)ptr + 0xcc) = 0;
          if ((*(void **)((int)ptr + 0x90) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xd0) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x90));
            *(undefined4 *)((int)ptr + 0x90) = 0;
          }
          *(undefined4 *)((int)ptr + 0xd0) = 0;
          if ((*(void **)((int)ptr + 0x94) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xd4) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x94));
            *(undefined4 *)((int)ptr + 0x94) = 0;
          }
          *(undefined4 *)((int)ptr + 0xd4) = 0;
          if ((*(void **)((int)ptr + 0x98) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xd8) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x98));
            *(undefined4 *)((int)ptr + 0x98) = 0;
          }
          *(undefined4 *)((int)ptr + 0xd8) = 0;
          if ((*(void **)((int)ptr + 0x9c) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xdc) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x9c));
            *(undefined4 *)((int)ptr + 0x9c) = 0;
          }
          *(undefined4 *)((int)ptr + 0xdc) = 0;
          if ((*(void **)((int)ptr + 0xa0) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xe0) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xa0));
            *(undefined4 *)((int)ptr + 0xa0) = 0;
          }
          *(undefined4 *)((int)ptr + 0xe0) = 0;
          if ((*(void **)((int)ptr + 0xa4) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xe4) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xa4));
            *(undefined4 *)((int)ptr + 0xa4) = 0;
          }
          *(undefined4 *)((int)ptr + 0xe4) = 0;
          if ((*(void **)((int)ptr + 0xa8) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xe8) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xa8));
            *(undefined4 *)((int)ptr + 0xa8) = 0;
          }
          *(undefined4 *)((int)ptr + 0xe8) = 0;
          if ((*(void **)((int)ptr + 0xac) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xec) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xac));
            *(undefined4 *)((int)ptr + 0xac) = 0;
          }
          *(undefined4 *)((int)ptr + 0xec) = 0;
          if ((*(void **)((int)ptr + 0xb0) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xf0) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xb0));
            *(undefined4 *)((int)ptr + 0xb0) = 0;
          }
          *(undefined4 *)((int)ptr + 0xf0) = 0;
          if ((*(void **)((int)ptr + 0xb4) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xf4) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xb4));
            *(undefined4 *)((int)ptr + 0xb4) = 0;
          }
          *(undefined4 *)((int)ptr + 0xf4) = 0;
          if ((*(void **)((int)ptr + 0xb8) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xf8) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xb8));
            *(undefined4 *)((int)ptr + 0xb8) = 0;
          }
          *(undefined4 *)((int)ptr + 0xf8) = 0;
          if ((*(void **)((int)ptr + 0xbc) != (void *)0x0) &&
             (*(int *)((int)ptr + 0xfc) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xbc));
            *(undefined4 *)((int)ptr + 0xbc) = 0;
          }
          *(undefined4 *)((int)ptr + 0xfc) = 0;
          if ((*(void **)((int)ptr + 0xc0) != (void *)0x0) &&
             (*(int *)((int)ptr + 0x100) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xc0));
            *(undefined4 *)((int)ptr + 0xc0) = 0;
          }
          *(undefined4 *)((int)ptr + 0x100) = 0;
          if ((*(void **)((int)ptr + 0xc4) != (void *)0x0) &&
             (*(int *)((int)ptr + 0x104) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xc4));
            *(undefined4 *)((int)ptr + 0xc4) = 0;
          }
          *(undefined4 *)((int)ptr + 0x104) = 0;
          CRYPTO_free(ptr);
        }
      }
      else {
        if ((dest->err_data[0] != (char *)0x0) && (dest->err_data_flags[0] << 0x1f < 0)) {
          CRYPTO_free(dest->err_data[0]);
          dest->err_data[0] = (char *)0x0;
        }
        pcVar4 = dest->err_data[1];
        dest->err_data_flags[0] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[1] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[1] = (char *)0x0;
        }
        pcVar4 = dest->err_data[2];
        dest->err_data_flags[1] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[2] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[2] = (char *)0x0;
        }
        pcVar4 = dest->err_data[3];
        dest->err_data_flags[2] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[3] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[3] = (char *)0x0;
        }
        pcVar4 = dest->err_data[4];
        dest->err_data_flags[3] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[4] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[4] = (char *)0x0;
        }
        pcVar4 = dest->err_data[5];
        dest->err_data_flags[4] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[5] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[5] = (char *)0x0;
        }
        pcVar4 = dest->err_data[6];
        dest->err_data_flags[5] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[6] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[6] = (char *)0x0;
        }
        pcVar4 = dest->err_data[7];
        dest->err_data_flags[6] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[7] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[7] = (char *)0x0;
        }
        pcVar4 = dest->err_data[8];
        dest->err_data_flags[7] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[8] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[8] = (char *)0x0;
        }
        pcVar4 = dest->err_data[9];
        dest->err_data_flags[8] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[9] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[9] = (char *)0x0;
        }
        pcVar4 = dest->err_data[10];
        dest->err_data_flags[9] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[10] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[10] = (char *)0x0;
        }
        pcVar4 = dest->err_data[0xb];
        dest->err_data_flags[10] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[0xb] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[0xb] = (char *)0x0;
        }
        pcVar4 = dest->err_data[0xc];
        dest->err_data_flags[0xb] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[0xc] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[0xc] = (char *)0x0;
        }
        pcVar4 = dest->err_data[0xd];
        dest->err_data_flags[0xc] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[0xd] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[0xd] = (char *)0x0;
        }
        pcVar4 = dest->err_data[0xe];
        dest->err_data_flags[0xd] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[0xe] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[0xe] = (char *)0x0;
        }
        pcVar4 = dest->err_data[0xf];
        dest->err_data_flags[0xe] = 0;
        if ((pcVar4 != (char *)0x0) && (dest->err_data_flags[0xf] << 0x1f < 0)) {
          CRYPTO_free(pcVar4);
          dest->err_data[0xf] = (char *)0x0;
        }
        dest->err_data_flags[0xf] = 0;
        CRYPTO_free(dest);
        pEVar3 = DAT_000ad938;
      }
    }
  }
  return pEVar3;
}

