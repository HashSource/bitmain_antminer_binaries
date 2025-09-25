
int i2o_SCT_signature(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = SCT_signature_is_complete();
  if (iVar1 == 0) {
    ERR_put_error(0x32,0x6d,0x6b,"crypto/ct/ct_oct.c",0x9f);
  }
  else {
    if (*param_1 == 0) {
      iVar1 = param_1[0xc] + 4;
      if (param_2 == (undefined4 *)0x0) {
        return iVar1;
      }
      puVar2 = (undefined1 *)*param_2;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = (undefined1 *)CRYPTO_malloc(iVar1,"crypto/ct/ct_oct.c",0xb4);
        if (puVar2 == (undefined1 *)0x0) {
          ERR_put_error(0x32,0x6d,0x41,"crypto/ct/ct_oct.c",0xb6);
          goto LAB_00110600;
        }
        *param_2 = puVar2;
      }
      else {
        *param_2 = puVar2 + iVar1;
      }
      *puVar2 = (char)param_1[10];
      puVar2[1] = *(undefined1 *)((int)param_1 + 0x29);
      puVar2[2] = (char)((uint)param_1[0xc] >> 8);
      puVar2[3] = (char)param_1[0xc];
      memcpy(puVar2 + 4,(void *)param_1[0xb],param_1[0xc]);
      return iVar1;
    }
    ERR_put_error(0x32,0x6d,0x67,"crypto/ct/ct_oct.c",0xa4);
  }
LAB_00110600:
  CRYPTO_free((void *)0x0);
  return -1;
}

