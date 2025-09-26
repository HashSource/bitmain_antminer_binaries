
void X509_VERIFY_PARAM_add1_host(int param_1,undefined4 param_2,undefined4 param_3)

{
  int_x509_param_set_hosts(*(undefined4 *)(param_1 + 0x20),1,param_2,param_3);
  return;
}

