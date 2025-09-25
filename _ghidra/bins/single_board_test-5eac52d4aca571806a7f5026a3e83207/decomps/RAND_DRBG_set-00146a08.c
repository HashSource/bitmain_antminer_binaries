
int RAND_DRBG_set(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (param_2 == 0 && param_3 == 0) {
    param_2 = rand_drbg_type;
    param_3 = rand_drbg_flags;
  }
  if ((*(int *)(param_1 + 0xc) != 0) &&
     ((param_2 != *(int *)(param_1 + 0xc) || (param_3 != *(ushort *)(param_1 + 0x14))))) {
    (**(code **)(*(int *)(param_1 + 0xf0) + 0xc))(param_1);
    rand_pool_free(*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(short *)(param_1 + 0x14) = (short)param_3;
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0xf0) = 0;
    return 1;
  }
  if ((param_2 < 0) || (2 < param_2 - 0x388U)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined2 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0xf0) = 0;
    ERR_put_error(0x24,0x68,0x78,"crypto/rand/drbg_lib.c",0x80);
    iVar1 = 0;
  }
  else {
    iVar1 = drbg_ctr_init(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x5c) = 2;
      ERR_put_error(0x24,0x68,0x6b,"crypto/rand/drbg_lib.c",0x8f);
      return 0;
    }
  }
  return iVar1;
}

