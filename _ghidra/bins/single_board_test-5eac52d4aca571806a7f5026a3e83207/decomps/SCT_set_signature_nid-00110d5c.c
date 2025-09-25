
undefined4 SCT_set_signature_nid(int param_1,int param_2)

{
  if (param_2 == 0x29c) {
    *(undefined1 *)(param_1 + 0x28) = 4;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return 1;
  }
  if (param_2 == 0x31a) {
    *(undefined1 *)(param_1 + 0x28) = 4;
    *(undefined1 *)(param_1 + 0x29) = 3;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return 1;
  }
  ERR_put_error(0x32,0x67,0x65,"crypto/ct/ct_sct.c",0x8a);
  return 0;
}

