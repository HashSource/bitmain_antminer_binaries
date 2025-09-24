
undefined4 sock_free(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      BIO_closesocket(*(undefined4 *)(param_1 + 0x20));
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    return 1;
  }
  return 1;
}

