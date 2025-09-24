
undefined4 X509_NAME_get0_der(X509_NAME *param_1,undefined4 *param_2,size_t *param_3)

{
  int iVar1;
  
  iVar1 = i2d_X509_NAME(param_1,(uchar **)0x0);
  if (iVar1 < 1) {
    return 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1->bytes->data;
  }
  if (param_3 != (size_t *)0x0) {
    *param_3 = param_1->bytes->length;
    return 1;
  }
  return 1;
}

